#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS   // разрешение на исп. scanf
#define N 50                      // количество элементов массива
#define BUFFER_SIZE 2048          // размер буфера
#define MAX_FILES_COUNT 1000      // предполагаемое кол-во файлов в папке

void user_input(wchar_t **wa);
int dir_contents(const wchar_t *sDir, wchar_t **fileNames,
	ULONGLONG *fileSizes);
void gen(int a[], int n, int min, int max);
void output(ULONGLONG *a, int n);
void output_by_idxes(int *filesIdxes, wchar_t **fileNames,
	 ULONGLONG *fileSizes, int filesCount, int is_format);
void output_formatted_size(ULONGLONG size);
void swap_int(int *var1, int *var2);
void swap_ULL(ULONGLONG *var1, ULONGLONG *var2);
void copy(int *copy_to, int *copy_from, int n);

int* choosing_sort(ULONGLONG *a, int *idxes, int n);
int* insert_sort(ULONGLONG *a, int *idxes, int n);
int* bubble_sort(ULONGLONG *a, int *idxes, int n);
void counting_sort(int a[], int n);
void quick_sort(int a[], int n1, int n2);
void quick_split(int a[], int* i, int* j, int p);
void merge_sort(int a[], int l, int r);
void merge_sorted(int a[], int l, int m, int r);

void main() 
{
    int algo, i, filesCount;
	int *filesIdxes, *newIdxes;
    wchar_t *path;
	wchar_t **fileNames;
	ULONGLONG *fileSizes;
	clock_t start, end;
	float total_time = 0.0f;
	int is_format = 0;
    setlocale(LC_ALL, "Russian");

	fileNames = (wchar_t**)malloc(MAX_FILES_COUNT * sizeof(wchar_t*));
	fileSizes = (ULONGLONG*)malloc(MAX_FILES_COUNT * sizeof(ULONGLONG));
	
	printf("====================== ФАЙЛОВЫЙ МЕНЕДЖЕР ======================");
	printf("\nВведите путь к папке: ");
    user_input(&path);
	filesCount = dir_contents(path, fileNames, fileSizes);
	if (filesCount == -1)
	{
		printf("Указанный путь не найден. Проверьте правильность ввода.\n");
		return;
	}
	filesIdxes = (int*)malloc((filesCount + 1) * sizeof(int));
	for (i = 0; i < filesCount; i++)
		filesIdxes[i] = i;
	printf("%d файлов найдено.\n", filesCount);
	for(i = 0; i < filesCount; i++)
		wprintf(L"Файл: %s Размер: %lld байт\n", fileNames[i], fileSizes[i]);

    //gen(a, N, 502, 692);
    //printf("Исходный массив:        ");
    //output(fileSizes, filesCount);
    printf("Выберите алгоритм сортировки: ");
    scanf("%d", &algo);
	printf("Отобразить размеры в удобном формате? (0 - нет, 1 - да) ");
	scanf("%d", &is_format);
	system("cls");
	printf("====================== ФАЙЛОВЫЙ МЕНЕДЖЕР ======================");
	printf("\nАлгортим сортировки: %d\nСписок файлов в папке:\n", algo);
	start = clock();
    switch (algo) 
    {
        case 1:
            newIdxes = choosing_sort(fileSizes, filesIdxes, filesCount);
            break;
        case 2:
			newIdxes = insert_sort(fileSizes, filesIdxes, filesCount);
            break;
        case 3:
			newIdxes = bubble_sort(fileSizes, filesIdxes, filesCount);
            break;
        case 4:
            counting_sort(fileSizes, filesCount);
            break;
        case 5:
            quick_sort(fileSizes, 0, filesCount - 1);
            break;
        case 6:
            merge_sort(fileSizes, 0, filesCount - 1);
            break;
        default:
            printf("Неверный номер.\n");
            return;
    }
	end = clock();
	total_time = (float)(end - start) / CLOCKS_PER_SEC;
	output_by_idxes(newIdxes, fileNames, fileSizes, filesCount, is_format);
	printf("Время сортировки: %.3f с\n", total_time);
    //printf("Отсортированный массив: ");
    //output(fileSizes, filesCount);
}

// Ввод пути с клавиатуры
void user_input(wchar_t **str_convert_to)
{
	char *input;
	*str_convert_to = (wchar_t*)malloc(BUFFER_SIZE * sizeof(wchar_t));
	input = (char*)malloc(BUFFER_SIZE * sizeof(char));
	fgets(input, BUFFER_SIZE, stdin);
	input[strlen(input) - 1] = '\0';
	swprintf(*str_convert_to, BUFFER_SIZE, L"%hs", input);
}

// Получение списка файлов и размеров из директории
int dir_contents(const wchar_t *sDir, wchar_t **fileNames, 
	             ULONGLONG *fileSizes)
{
	int i = 0;
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t *sPath;
	sPath = (wchar_t*)malloc(BUFFER_SIZE * sizeof(wchar_t));
    
	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
		return -1;

	//wprintf(L"Path: [%s]\n", sDir);
	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{
			ULONGLONG fileSize = fdFile.nFileSizeHigh;
			fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
			fileSize |= fdFile.nFileSizeLow;

			fileNames[i] = (wchar_t*)malloc(BUFFER_SIZE * sizeof(wchar_t));
			fileSizes[i] = fileSize;
			wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
			wsprintf(fileNames[i], L"%s", sPath);
			i++;
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);
	return i;
}

// Генерация массива
void gen(int a[], int n, int min, int max) 
{
    int i;
    srand((unsigned)time(0));
    for (i = 0; i < n; i++) 
        a[i] = rand() % (max - min + 1) + min;
}

// Вывод массива
void output(ULONGLONG *a, int n) 
{
    int i;
    for (i = 0; i < n - 1; i++) 
        printf("%lld ", a[i]);
    printf("%lld\n", a[n - 1]);
}

// Вывод списка файлов по карте индексов
void output_by_idxes(int *filesIdxes, wchar_t **fileNames, 
	                 ULONGLONG *fileSizes, int filesCount, int is_format)
{
	int i;
	for (i = 0; i < filesCount; i++)
	{
		wprintf(L"Файл: %s Размер: ", fileNames[filesIdxes[i]]);
		if (is_format)
			output_formatted_size(fileSizes[filesIdxes[i]]);
		else
			printf("%lld байт", fileSizes[filesIdxes[i]]);
		printf("\n");
	}
}

// Вывод форматированного размера
void output_formatted_size(ULONGLONG size)
{
	if (size < 1024)
		printf("%d байт", (int)size);
	else if (size < 1024 * 1024)
		printf("%.2f Кб", (float)size / 1024);
	else
		printf("%.2f Мб", (float)size / (1024 * 1024));
}

// Обмен значений целочисленных переменных
void swap_int(int *var1, int *var2)
{
	int tmp = *var1;
	*var2 = (*var1 = *var2, tmp);
}

// Обмен значений 64-битных переменных
void swap_ULL(ULONGLONG *var1, ULONGLONG *var2)
{
	ULONGLONG tmp = *var1;
	*var2 = (*var1 = *var2, tmp);
}

// Копирование целочисленного массива
void copy(int *copy_to, int *copy_from, int n)
{
	int i;
	for (i = 0; i < n; i++)
		copy_to[i] = copy_from[i];
}

// Сортировка выбором
int* choosing_sort(ULONGLONG *a, int *idxes, int n)
{
    int i, j, minidx, *newIdxes;
	ULONGLONG min, *sizes;
	newIdxes = (int*)malloc(n * sizeof(int));
	sizes = (ULONGLONG*)malloc(n * sizeof(ULONGLONG));
	for (i = 0; i < n; i++)
	{
		newIdxes[i] = i;
		sizes[i] = a[i];
	}
    for (i = 0; i < n; i++) 
    {
        min = sizes[i];
        minidx = i;
        for (j = i + 1; j < n; j++) 
            if (sizes[j] < min)
            {
                min = sizes[j];
                minidx = j;
            }
		sizes[minidx] = sizes[i];
		swap_int(newIdxes + minidx, newIdxes + i);
		sizes[i] = min;
    }
	free(sizes);
	return newIdxes;
}

// Сортировка простыми вставками
int* insert_sort(ULONGLONG *a, int *idxes, int n)
{
    int i, j, *newIdxes;
	ULONGLONG temp, *sizes;
	newIdxes = (int*)malloc(n * sizeof(int));
	sizes = (ULONGLONG*)malloc(n * sizeof(ULONGLONG));
	for (i = 0; i < n; i++)
	{
		newIdxes[i] = i;
		sizes[i] = a[i];
	}
    for (i = 1; i < n; i++) 
    {
        temp = sizes[i];
        j = i - 1;
        while ((j >= 0) && (sizes[j]>temp))
        {
			sizes[j + 1] = sizes[j];
			newIdxes[j + 1] = newIdxes[j];
			newIdxes[j] = i;
			sizes[j--] = temp;
        }
    }
	free(sizes);
	return newIdxes;
}

// Пузырьковая сортировка
int* bubble_sort(ULONGLONG *a, int *idxes, int n)
{
	int i, j, *newIdxes;
	ULONGLONG temp, *sizes;
	newIdxes = (int*)malloc(n * sizeof(int));
	sizes = (ULONGLONG*)malloc(n * sizeof(ULONGLONG));
	for (i = 0; i < n; i++)
	{
		newIdxes[i] = i;
		sizes[i] = a[i];
	}
    for (i = 0; i < n; i++) 
        for (j = 1; j < n - i; j++) 
            if (sizes[j - 1] > sizes[j])
            {
                temp = sizes[j];
				sizes[j] = sizes[j - 1];
				sizes[j - 1] = temp;
				swap_int(newIdxes + j, newIdxes + j - 1);
            }
	free(sizes);
	return newIdxes;
}

// Сортировка подсчетом (с произвольным выделением памяти)
void counting_sort(int a[], int n)
{
    int *count;
    int idx = 0, i, j, delta = 0, min = a[0], max = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] < min) 
            min = a[i];
        if (a[i] > max) 
            max = a[i];
    }
    delta = abs(max - min) + 1;
    count = (int*)malloc(delta * sizeof(int));
    for (i = 0; i < delta; i++)
        count[i] = 0;
    for (i = 0; i < n; i++) 
        count[a[i] - min]++;
    for (i = 0; i < delta; i++) 
        for (j = 0; j < count[i]; j++) 
            a[idx++] = i + min;
    free(count);
}

// Быстрая сортировка
void quick_sort(int a[], int n1, int n2)
{
    int m = (n1 + n2) / 2;
    int i = n1, j = n2;
    if (n1 == n2)
        return;
    quick_split(a, &i, &j, a[m]);
    if (i < n2)
        quick_sort(a, i, n2);
    if (j > n1)
        quick_sort(a, n1, j);
}

// Быстрая перестановка
void quick_split(int a[], int* i, int* j, int p)
{
    do {
        while (a[*i] < p) (*i)++;
        while (a[*j] > p) (*j)--;
        if (*i <= *j) {
            if (a[*i] > a[*j]) 
            {
                int tmp = a[*i];
                a[*i] = a[*j];
                a[*j] = tmp;
            }
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

// Сортировка слиянием
void merge_sort(int a[], int l, int r)
{
    int m;
    if (l >= r) 
        return;
    m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    merge_sorted(a, l, m, r);
}

// Слияние отсортированных частей массива (с произвольным выделением памяти)
void merge_sorted(int a[], int l, int m, int r)
{
    int i, j, s = 0, *merged, total_length = r - l + 1;
    merged = (int*)malloc(total_length * sizeof(int)); 
    i = l;
    j = m + 1;
    while ((i <= m) && (j <= r)) {
        if (a[i] <= a[j])
            merged[s++] = a[i++];
        else
            merged[s++] = a[j++];
    }
    while (i <= m)
        merged[s++] = a[i++];
    while (j <= r)
        merged[s++] = a[j++];
    for (i = l; i <= r; i++)
        a[i] = merged[i - l];
    free(merged);
}