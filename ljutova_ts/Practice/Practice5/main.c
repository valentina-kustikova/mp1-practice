#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#define BUFFERSIZE 2048
#define CS 1000
//Список данных из директория
int ListDirectoryContents(const wchar_t *sDir, wchar_t **filesName,
	ULONGLONG *filesSize)
{
	int i = 0;
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t *sPath;
	sPath = (wchar_t*)malloc(BUFFERSIZE * sizeof(wchar_t));
	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
		return -1;
	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{
			ULONGLONG fileSize = fdFile.nFileSizeHigh;
			fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
			fileSize |= fdFile.nFileSizeLow;
			filesName[i] = (wchar_t*)malloc(BUFFERSIZE * sizeof(wchar_t));
			filesSize[i] = fileSize;
			wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
			wsprintf(filesName[i], L"%s", sPath);
			i++;
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);
	return i;
}

void Sort()
{
	printf("Выберите вид сортировки: \n");
	printf("1 - Сортировка выбором \n");
	printf("2 - Сортировка вставками \n");
	printf("3 - Пузырьковая сортировка \n");
	printf("4 - Сортировка подсчетом \n");
	printf("5 - Быстрая сортировка \n");
	printf("6 - Сортировка слиянием \n");
	printf("7 - Выход из программы \n");
}

void InputFiles(wchar_t **sDir)
{
	char *inputStr;
	*sDir = (wchar_t*)malloc(BUFFERSIZE * sizeof(wchar_t));
	inputStr = (char*)malloc(BUFFERSIZE * sizeof(char));
	fgets(inputStr, BUFFERSIZE, stdin); // считываем символы из файла
	inputStr[strlen(inputStr) - 1] = '\0'; //заменяем символ переноса строки на 0
	swprintf(*sDir, BUFFERSIZE, L"%hs", inputStr);
	free(inputStr);
}

void OutputFiles(ULONGLONG *fileSize, wchar_t **fileNames, unsigned long *fileIdx, int n)
{
	unsigned long i;
	for (i = 0; i < n; i++)
		wprintf(L"Файл:  %s (Размер: %lld байт) \n", fileNames[fileIdx[i]], fileSize[fileIdx[i]]);
}

// сортировка выбором
void chooseSort(ULONGLONG *fileSize, int *fileIdx, int n)
{
	int i, j, minidx;
	ULONGLONG tmp;
	for (i = 0; i < n; i++)
	{
		minidx = i;
		for (j = i + 1; j < n; j++)
		{
			if (fileSize[fileIdx[j]] < fileSize[fileIdx[minidx]])
				minidx = j;
		}
		tmp = fileIdx[minidx];                  //Мы меняем массив индексов, но при этом 
		fileIdx[minidx] = fileIdx[i];           //значения остаются
		fileIdx[i] = tmp;

	}
}
// сортировка вставками
void insertSort(ULONGLONG *fileSize, int *fileIdx, int n)
{
	int i, j, idx;
	ULONGLONG tmp;
	for (i = 1; i < n; i++)
	{
		tmp = fileSize[i];
		j = i - 1;
		while ((j >= 0) && (fileSize[j] > tmp))
		{
			fileSize[j + 1] = fileSize[j];
			j--;
		}
	}
}
// пузырьковая сортировка
void bubbleSort(ULONGLONG *fileSize, int *fileIdx, int n)
{
	int i, j, tmp;
	ULONGLONG tmp2;
	{
		for (i = 0; i < n; i++)
		{
			for (j = 1; j < n; j++)
				if (fileSize[j - 1] > fileSize[j])
				{
					tmp = fileIdx[j - 1];
					fileIdx[j - 1] = fileIdx[j];
					fileIdx[j] = tmp;
					tmp2 = fileSize[j - 1];
					fileSize[j - 1] = fileSize[j];
					fileSize[j] = tmp2;
				}
		}
	}
}
// сортировка подсчетом
void countSort(ULONGLONG *fileSize, int *fileIdx, int n)
{
	int i, idx = 0, j, r = 0;
	int *count = (int*)malloc(CS * sizeof(int));
	for (i = 0; i < CS; i++)
		count[i] = 0;
	for (i = 0; i < n; i++)
		if (fileSize[i] < CS)
			count[fileSize[fileIdx[i]]]++;
		else
		{
			printf("Размер файла слишком большой. ");
			printf("Попробуйте другую сортировку\n");
			return 0;
		}
	for (i = 0; i < CS; i++)
	{
		if (fileSize[i] > 0)
		{
			r = 0;
			for (j = 0; j < count[i]; j++)
			{
				while (fileSize[r] != i)
					r++;
				fileIdx[idx++] = r++;
			}
		}
	}
	free(count);
}
// быстрая сортировка (дополнительная функция)
void quick_split(ULONGLONG *fileSize, int fileIdx, int *i, int *j, int p)
{
	ULONGLONG tmp;
	do
	{
		while (fileSize[*i] < p)
			(*i)++;
		while (fileSize[*j] > p)
			(*j)--;
		if (*i <= *j)
		{
			tmp = fileSize[*i];
			fileSize[*i] = fileSize[*j];
			fileSize[*j] = tmp;
			(*i)++;
			(*j)--;
		}
	} while (*i <= *j);
}
//быстрая сортировка
void quick_sort(ULONGLONG *fileSize, int fileIdx, int n1, int n2)
{
	int m;
	int i = n1; int j = n2;
	m = (n1 + n2) / 2;
	quick_split(fileSize, fileIdx, &i, &j, fileSize[m]);
	if (i < n2)
		quick_sort(fileSize, fileIdx, n2, i);
	if (j > n1)
		quick_sort(fileSize, fileIdx, n1, j);
}
//сортировка слиянием (дополнительная функция)
void merge(ULONGLONG *fileSize, int *fileIdx, int l, int m, int r)
{
	int i, j, tmp, s;
	i = l;
	j = m + 1;
	for (i; ((i < r) && (j <= r)); i++)
	{
		if (fileSize[fileIdx[i]] > fileSize[fileIdx[j]])
		{
			tmp = fileIdx[j];
			for (s = j; s > i; s--)
				fileIdx[s] = fileIdx[s - 1];
			fileIdx[i] = tmp;
			j++;
		}
	}
}
//сортировка слиянием
void merge_sort(ULONGLONG *fileSize, int fileIdx, int l, int r)
{
	int m;
	if (l >= r)
		return;
	m = (l + r) / 2;
	merge_sort(fileSize, fileIdx, l, m);
	merge_sort(fileSize, fileIdx, m + 1, r);
	merge(fileSize, fileIdx, l, m, r);
}
void main()
{
	setlocale(LC_ALL, "Russian");
	unsigned long i = 0, number, N;
	unsigned long *filesIndex;
	ULONGLONG *filesSize;
	wchar_t **filesName;
	wchar_t *p;
	clock_t begin, end;
	float alltime = 0.0f;
	filesName = (wchar_t**)malloc(BUFFERSIZE * sizeof(wchar_t*));
	filesSize = (ULONGLONG*)malloc(BUFFERSIZE * sizeof(ULONGLONG));
	printf("---------- Ф А Й Л О В Ы Й   М Е Н Е Д Ж Е Р ----------\n");
	printf("Введите путь к папке: ");
	InputFiles(&p);
	N = ListDirectoryContents(p, filesName, filesSize);
	if (N == -1)
		printf("Ошибка. Путь не найден.");

	filesIndex = (unsigned long*)malloc(N * sizeof(unsigned long));
	for (i = 0; i < N; i++)
		filesIndex[i] = i; //заполнение массива индексов
	printf("Всего файлов: %d.\n", N);
	OutputFiles(filesSize, filesName, filesIndex, N);
	Sort();
	do
	{
		scanf("%d", &number);
		begin = clock();

		switch (number)
		{
		case 1:
			chooseSort(filesSize, filesIndex, N);
			break;
		case 2:
			insertSort(filesSize, filesIndex, N);
			break;
		case 3:
			bubbleSort(filesSize, filesIndex, N);
			break;
		case 4:
			countSort(filesSize, filesIndex, N);
			break;
		case 5:
			quick_sort(filesSize, filesIndex, 0, (N - 1));
			break;
		case 6:
			merge_sort(filesSize, filesIndex, 0, (N - 1));
			break;
		default:
			printf("Сортировка не найдена. Исходные файлы: \n ");
		}
		end = clock();
		alltime = (double)(end - begin) / CLOCKS_PER_SEC;
		OutputFiles(filesSize, filesName, filesIndex, N);
		printf("\n Time: %.5lf сек \n", alltime);
		printf("Вы можете выбрать другой метод сортировки или выйти: ");
		for (i = 0; i < N; i++)
			filesIndex[i] = i;
	} while (number != 7);
	free(filesName);
	free(filesSize);
	free(filesIndex);
}