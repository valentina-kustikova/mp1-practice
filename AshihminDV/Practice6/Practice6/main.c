#include<stdio.h>
#include<locale.h>
#include<windows.h>
#include <stdlib.h>
#include <omp.h>
#include <memory.h>

#define BUFFER 2048
#define test 1000000000
//1 выбором 2 пузырьком 3 быстрая
//D:\ttc\totalcmd

int Fill_the_List(char *adres, wchar_t** FileNames, ULONGLONG* FileSize, unsigned long* Index);

void bubble_sort(int dl, ULONGLONG* FileSize,unsigned long* Index);
void choose_sort(ULONGLONG* FileSize, int dl, unsigned long* Index);
void fast_sort(ULONGLONG* FileSize, unsigned long* Index, int left, int right);

void print_massiv(wchar_t** FileNames, ULONGLONG* FileSize, int k, unsigned long* Index);
void choose_the_sort();

int main() {
	int k=0, i=0, rezhim;
	char *adres[BUFFER];

	unsigned long* Index = (unsigned long*)malloc(sizeof(unsigned long)* BUFFER);
	unsigned long* copy_Index = (unsigned long*)malloc(sizeof(unsigned long) * BUFFER);

	ULONGLONG* FileSize = (ULONGLONG*)malloc(BUFFER * sizeof(ULONGLONG));
	ULONGLONG* copy_FileSize = (ULONGLONG*)malloc(BUFFER * sizeof(ULONGLONG));

	wchar_t** FileNames = (wchar_t**)malloc(BUFFER * sizeof(wchar_t*));

	double start, finish;
	double finaltime = 0.0 ;

	setlocale(LC_ALL, "Rus");
	printf("_ _ _ _ _ _ _ _ Файловый менеджер _ _ _ _ _ _ _ _\n");
	printf("Введите адресную строку: ");
	k = Fill_the_List(adres, FileNames, FileSize, Index);
	while (k == -1) {
		printf("ERROR: неверный путь\n");
		k = Fill_the_List(adres, FileNames, FileSize, Index);
	}

	printf("_ _ _ _ _ _ _ _ Список файлов _ _ _ _ _ _ _ _\n");
	printf("Количество файлов: %d\n", k);
	print_massiv(FileNames, FileSize, k, Index);
	printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
	choose_the_sort();
	do {
		scanf("%d", &rezhim);
		memcpy(copy_FileSize, FileSize, BUFFER);
		memcpy(copy_Index, Index, BUFFER);
		switch (rezhim)
		{
		case 1:
			printf("Сортировка выбором\n");
			start = omp_get_wtime();
			choose_sort(copy_FileSize, k, copy_Index);
			finish = omp_get_wtime();
			break;
		case 2:
			printf("Сортировка пузырьком\n");
			start = omp_get_wtime();
			bubble_sort(k, copy_FileSize, copy_Index);
			finish = omp_get_wtime();
			break;
		case 3:
			printf("Быстрая сортировка\n");
			start = omp_get_wtime();
			fast_sort(copy_FileSize, copy_Index, 0, k-1);
			finish = omp_get_wtime();
			break;
		case 4:
			continue;
			break;
		default:
			printf("Неверный ввод. Попробуйте заново\n");
			continue;
		}

		printf("_ _ _ _ _ _ _ _ Отсортировано _ _ _ _ _ _ _ _ \n");
		printf("Время Сортировки: %5.15lf секунды \n", finish-start);
		print_massiv(FileNames, copy_FileSize, k, copy_Index);
		printf("Можете выбрать другую сортировку) ");

	} while (rezhim != 4);
	free(FileSize);
	for (i = 0; i < k; i++)
	{
		free(FileNames[i]);
	}
	free(FileNames);
	free(copy_FileSize);
	free(Index);
	free(copy_Index);
	return 0;
}

int Fill_the_List(char* adres, wchar_t** FileNames, ULONGLONG* FileSize, unsigned long* Index) {
	int i = 0;
	WIN32_FIND_DATA fd;
	wchar_t* itog_adres;
	long fDataFSize;

	_getws(adres);
	itog_adres = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
	wsprintf(itog_adres, L"%s\\*", adres);

	HANDLE hFind = FindFirstFile(itog_adres, &fd);

	if (hFind == INVALID_HANDLE_VALUE) {
		FindClose(hFind);
		free(itog_adres);
		return -1;
	}

	if (hFind != INVALID_HANDLE_VALUE); {
		do {
			if (strcmp(fd.cFileName, ".") != 0 && strcmp(fd.cFileName, "..") != 0) {
				//SIZE
				FileSize[i] = (ULONGLONG)(fd.nFileSizeLow + ((fd.nFileSizeHigh) * (MAXDWORD + 1)));
				//NAME
				FileNames[i] = (wchar_t*)malloc(sizeof(wchar_t) * BUFFER);
				wsprintf(itog_adres, L"%s\\%s", adres, fd.cFileName);
				wsprintf(FileNames[i], L"%s", itog_adres);
				Index[i] = i;
				i++;
			}
		} while (FindNextFile(hFind, &fd));
		FindClose(hFind);
		free(itog_adres);
		return i;
	}
}

void choose_the_sort() {
	printf("Выберите режим сортировки\n");
	printf("1 - Сортировка выбором\n");
	printf("2 - Сортировка пузырьком\n");
	printf("3 - Сортировка быстрая\n");
	printf("4 - Выход из программы\n");
}

void print_massiv(wchar_t** FileNames, ULONGLONG* FileSize, int k, unsigned long* Index) {
	int i = 0; 
	for (i = 0; i < k; i++) {
		printf("%5d: %S размер (%llu байт)\n", i + 1, FileNames[Index[i]], FileSize[i]);
	}
}

void bubble_sort(int dl, ULONGLONG* FileSize, unsigned long* Index) {
	int i, j, copy_index;
	unsigned long long copy_size;
	for (i = 0; i < dl; i++) {
		for (j = 0; j < dl - 1; j++) {
			if(FileSize[j]>FileSize[j+1]){
				copy_size = FileSize[j];
				FileSize[j] = FileSize[j + 1];
				FileSize[j + 1] = copy_size;
				copy_index = Index[j];
				Index[j] = Index[j + 1];
				Index[j + 1] = copy_index;
			}
		}
	}
}

void choose_sort(ULONGLONG* FileSize, int dl, unsigned long* Index) {
	int i = 0, j=0, minind;
	unsigned long long min, copy_size;
	for (i = 0; i < dl; i++) {
		minind = i;
		for (j = i + 1; j < dl; j++) {
			if (FileSize[j]<FileSize[minind]) {
				minind = j;
			}
		}
		copy_size = FileSize[i];
		FileSize[i] = FileSize[minind];
		FileSize[minind] = copy_size;
	}
}

void fast_sort(ULONGLONG* FileSize, unsigned long* Index, int left, int right) {
	int i = left, j = right;
	unsigned long long pivot = FileSize[(left + right) / 2], tmp, tmp2;
	while (i <= j) {
		while (FileSize[i] < pivot) {
			i++;
		}
		while (FileSize[j] > pivot) {
			j--;
		}
		if (i <= j) {
			tmp = FileSize[i];
			FileSize[i] = FileSize[j];
			FileSize[j] = tmp;
			tmp2 = Index[i];
			Index[i] = Index[j];
			Index[j] = tmp2;
			i++;
			j--;
		}
	}
	if (left < j) {
		fast_sort(FileSize, Index, left, j);
	}
	if (i < right) {
		fast_sort(FileSize, Index, i, right);
	}
}