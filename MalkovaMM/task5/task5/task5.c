#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define maxlength 10000
#define maxfiles 10000

void ClearInputBuffer(void);
double menu(char** fnames, long long* fsizes, int fcount);
int makelist_time(char* path, int* fcount);
void swapnames(char** s, char** s1);
void swapsizes(long long* sj, long long* sj1);
void simple(char** fnames, long long* fsizes, int fcount);
void choice(char** fnames, long long* fsizes, int fcount);
void insert(char** fnames, long long* fsizes, int fcount);
void merges(char** fnames, long long* fsizes, int fcount, int l, int r);
void merge(char** fnames, long long* fsizes, int fcount, int l, int m, int r);
void quick(char** fnames, long long* fsizes, int n1, int n2);
void fprint(char** fnames, long long* fsizes, int fcount);

void ClearInputBuffer(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int makelist_time(char* path, int* fcount) 
{
	double sorttime;
	int i;
	char sp[MAX_PATH]; //тут будет формирроваться путь в нужный формат
	WIN32_FIND_DATAA filedata; //структура где будет о файле информация
	HANDLE hf; //дескриптор - индентификатор для поиска файла
	snprintf(sp, sizeof(sp), "%s\\*", path); // создали путь в нужном формате
	hf = FindFirstFileA(sp, &filedata); //начало поиска, возвращает дескриптор
	*fcount = 0;
	do{
		(*fcount)++;
	} while (FindNextFileA(hf, &filedata) != 0); 
	FindClose(hf);
	char** fnames = malloc(*fcount * sizeof(char*));
	for (i = 0; i < *fcount; i++)
	{
		fnames[i] = malloc(maxlength * sizeof(char));
	}
	long long* fsizes = malloc(*fcount * sizeof(long long));
	hf = FindFirstFileA(sp, &filedata);
	i = 0;
	do {
		strncpy(fnames[i], filedata.cFileName, maxlength - 1);
		fnames[i][maxlength - 1] = '\0';
		fsizes[i] = ((long long)filedata.nFileSizeHigh << 32 | filedata.nFileSizeLow);
		i++;
	} while (FindNextFileA(hf, &filedata) != 0);
	FindClose(hf);
	if (fcount <= 0) return *fcount;
	sorttime = menu(fnames, fsizes, *fcount);
	if (sorttime != -1)
	{
		printf("Время сортировки: %9f секунд\n", sorttime);
		fprint(fnames, fsizes, *fcount);
	}
	else
		printf("Вы не выбрали метод сортировки\n");
	for (int i = 0; i < *fcount; i++) {
		if(fnames[i]!=NULL) free(fnames[i]);
	}
	free(fnames);
	free(fsizes);
	return *fcount;
}
double menu(char** fnames, long long* fsizes, int fcount)
{
	int metod = -1;
	double sorttime;
	LARGE_INTEGER fr, st, end;
	QueryPerformanceFrequency(&fr);
	do
	{
		printf("Выберите метод сортировки:\n");
		printf("Простейшая: 1\n");
		printf("Выбором: 2\n");
		printf("Вставками: 3\n");
		printf("Слияниями: 4\n");
		printf("Быстрая: 5\n");
		printf("Выход: 0\n");
		scanf_s("%d", &metod);
		ClearInputBuffer();
	} while ((metod < 0) || (metod > 5));
	QueryPerformanceCounter(&st);
	switch (metod) {
	case(0): return -1;
	case(1): 
		simple(fnames, fsizes, fcount);
		break;
	case(2):
		choice(fnames, fsizes, fcount);
		break;
	case(3):
		insert(fnames, fsizes, fcount);
		break;
	case(4):
		merges(fnames, fsizes,fcount, 0, fcount-1);
		break;
	case(5):
		quick(fnames, fsizes, 0, fcount-1);
		break;
	}
	QueryPerformanceCounter(&end);
	sorttime = ((double)(end.QuadPart - st.QuadPart)) / fr.QuadPart;
	return sorttime;
}
void simple(char** fnames, long long* fsizes, int fcount)
{
		for (int i = 0; i < fcount; i++) {
			for (int j = i + 1; j < fcount; j++) {
				if (fsizes[i] > fsizes[j]) {
					swapnames(&fnames[i], &fnames[j]);
					swapsizes(&fsizes[i], &fsizes[j]);
				}
			}
		}
}
void choice(char** fnames, long long* fsizes, int fcount)
{
	int i, j, min_i;
	for (i = 0; i < fcount - 1; i++)
	{
		min_i = i;
		for (j = i + 1; j < fcount; j++)
		{
			if (fsizes[j] < fsizes[min_i]) {
				min_i = j;
			}
		}
		if (min_i != i) {
			swapnames(&fnames[i], &fnames[min_i]);
			swapsizes(&fsizes[i], &fsizes[min_i]);
		}
	}
}
void insert(char** fnames, long long* fsizes, int fcount)
{
	int i, j;
	for (i = 1; i < fcount; i++) 
	{
		long long size = fsizes[i];
		char* name = fnames[i];
		if(name!=NULL)
			strcpy(name, fnames[i]);
		j = i - 1;
		while (j >= 0 && fsizes[j] > size) 
		{
			fsizes[j + 1] = fsizes[j];
			fnames[j + 1] = fnames[j];
			j--;
		}
		fsizes[j + 1] = size;
		fnames[j+1] = name;
	}
}
void merges(char** fnames, long long* fsizes, int fcount, int l, int r)
{
	int m;
	if (l >= r)
		return;
	m = l + (r - l) / 2;
	merges(fnames, fsizes, fcount, l, m);
	merges(fnames, fsizes, fcount, m+1, r);
	merge(fnames, fsizes, fcount, l, m, r);
}
void merge(char** fnames, long long* fsizes, int fcount, int l,int m, int r)
{
	long long* fsizes1 = (long long*)malloc((r-l+1)* sizeof(long long));
	char** fnames1 = (char**)malloc((r - l + 1) * sizeof(char*));
	int k = 0;
	int it1 = 0;
	int it2 = 0;
	while (it1 + l < m && it2 + m + 1 <= r)
	{
		if (fsizes[l + it1] < fsizes[m + 1 + it2])
		{
			fsizes1[k] = fsizes[l + it1];
			fnames1[k++] = fnames[l + it1++];
		}
		else
		{
			fsizes1[k] = fsizes[m + 1 + it2];
			fnames1[k++] = fnames[m + 1 + it2++];
		}
	}
	while (l + it1 <= m)
	{
		fsizes1[k] = fsizes[l + it1];
		fnames1[k++] = fnames[l + it1++];
	}
	while (m + 1 + it2 <= r)
	{
		fsizes1[k] = fsizes[m + 1 + it2];
		fnames1[k++] = fnames[m + 1 + it2++];
	}
	for (it1 = 0; it1 < k; it1++)
	{
		fsizes[l + it1] = fsizes1[it1];
		fnames[l + it1] = fnames1[it1];
	}
	free(fsizes1);
	free(fnames1);
}
void quick(char** fnames, long long* fsizes, int n1, int n2)
{
	int mid = n1 + (n2 - n1) / 2;
	int i = n1;
	int j = n2;
	long long p = fsizes[mid];
	do
	{
		while (fsizes[i] < p)
			i++;
		while (fsizes[j] > p)
			j--;
		if (i <= j) 
		{
			swapsizes(&fsizes[i], &fsizes[j]);
			swapnames(&fnames[i], &fnames[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (n1 < j)
		quick(fnames, fsizes, n1, j);
	if (n2 > i)
		quick(fnames, fsizes, i, n2);
}
void swapsizes(long long* sj, long long* sj1)
{
	long long tmp = *sj;
	*sj = *sj1;
	*sj1 = tmp;
}
void swapnames(char** s, char** s1)
{
	char* tmp = *s;
	*s = *s1;
	*s1 = tmp;
}
void fprint(char** fnames, long long* fsizes, int fcount) 
{
	for (int i = 0; i < fcount; i++) {
		printf("%s - %lld байт\n", fnames[i], fsizes[i]);
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	char path[maxlength];
	int fcount = 0;
	int ch = -1;
	printf("файловый менеджер \n");
	printf("Введите путь до нужного Вам каталога: ");
	if (fgets(path, sizeof(path), stdin) != NULL) //stdin входной поток для ввода с клавиатуры, а сам fgets читает строку и ставит в конце \0
	{
		size_t length = strlen(path);
		if ((length > 0) && (path[length - 1] == '\n'))
		{
			path[length - 1] = '\0';
		}
	}
	DWORD check = GetFileAttributesA(path);
	if ((check == INVALID_FILE_ATTRIBUTES) || !(check & FILE_ATTRIBUTE_DIRECTORY)) // вторая проверка: не ноль - директория, ноль - файл или что то другое
	{
		printf("ошибка (либо директории нет, либо она недоступна)");
		return 0;
	}
	while (1) 
	{
		fcount = makelist_time(path, &fcount);
		if (fcount < 0)
		{
			printf("ошибка при чтении директории и создании списка файлов");
			continue;
		}
		if (fcount == 0)
		{
			printf("В директории нет файлов");
			continue;
		}
		do {
			printf("Выйти из файлового менеджера - 0\n");
			printf("Выбрать следующий путь для просмотра/сортировки файлов - 1\n");
			scanf_s("%d", &ch);
		} while (ch != 0 && ch != 1);
		if (ch == 0)
			break;
	}
	return 0;
}