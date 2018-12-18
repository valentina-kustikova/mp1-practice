#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS   // разрешение на исп. scanf
#define N 50                      // количество элементов массива
#define BUFFER_SIZE 2048          // размер буфера

void user_input(wchar_t **wa);
int dir_contents(const wchar_t *sDir, wchar_t ***fileNames,
    ULONGLONG **fileSizes);
void output_by_idxes(int *filesIdxes, wchar_t **fileNames,
     ULONGLONG *fileSizes, int filesCount, int is_format);
void output_formatted_size(ULONGLONG size);
int find_by_size(ULONGLONG size, int k, ULONGLONG *sizes, int n);
void swap_int(int *var1, int *var2);
void swap_ULL(ULONGLONG *var1, ULONGLONG *var2);
void copy(int *copy_to, int *copy_from, int n);

int* choosing_sort(ULONGLONG *a, int *idxes, int n);
int* insert_sort(ULONGLONG *a, int *idxes, int n);
int* bubble_sort(ULONGLONG *a, int *idxes, int n);
int* counting_sort(ULONGLONG *a, int *idxes, int n);
int* start_quick_sort(ULONGLONG *sizes, int *idxes, int n1, int n2);
void quick_sort(ULONGLONG *a, int *idxes, int n1, int n2);
int* start_merge_sort(ULONGLONG *sizes, int *idxes, int l, int r);
void merge_sort(ULONGLONG *sizes, int *idxes, int l, int r);
void merge_sorted(ULONGLONG *sizes, int *idxes, int l, int m, int r);

void main() 
{
    int algo, i, filesCount, is_error = 0;
    int *filesIdxes, *newIdxes;
    wchar_t *path;
    wchar_t **fileNames;
    ULONGLONG *fileSizes;
    clock_t start, end;
    float total_time = 0.0f;
    int is_format = 0;
    setlocale(LC_ALL, "Russian");
    
    printf("====================== ФАЙЛОВЫЙ МЕНЕДЖЕР ======================");
    printf("\nВведите путь к папке: ");
    user_input(&path);
    filesCount = dir_contents(path, &fileNames, &fileSizes);
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
    printf("Выберите алгоритм сортировки: ");
    scanf("%d", &algo);
    printf("Отобразить размеры в удобном формате? (0 - нет, 1 - да) ");
    scanf("%d", &is_format);
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
			if (newIdxes == NULL)
				is_error = 1;
            break;
        case 4:
			newIdxes = counting_sort(fileSizes, filesIdxes, filesCount);
            break;
        case 5:
			newIdxes = start_quick_sort(fileSizes, filesIdxes, filesIdxes[0],
				filesIdxes[filesCount - 1]);
            break;
        case 6:
            newIdxes = start_merge_sort(fileSizes, filesIdxes, filesIdxes[0],  
				filesIdxes[filesCount - 1]);
			break;
        default:
            printf("Неверный номер.\n");
            return;
    }
    end = clock();
    total_time = (float)(end - start) / CLOCKS_PER_SEC;
	if (!is_error)
	{
		output_by_idxes(newIdxes, fileNames, fileSizes, filesCount, is_format);
		printf("Время сортировки: %.3f с\n", total_time);
	}
	else
		printf("Похоже, что размер файлов слишком велик для этого метода сортировки");

    for (i = 0; i < filesCount; i++)
        free(fileNames[i]);
    free(fileNames);
    free(fileSizes);
    free(filesIdxes);
    free(newIdxes);
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
int dir_contents(const wchar_t *sDir, wchar_t ***fileNames, 
                 ULONGLONG **fileSizes)
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
            i++;
    } while (FindNextFile(hFind, &fdFile));

    hFind = FindFirstFile(sPath, &fdFile);
    *fileNames = (wchar_t**)malloc(i * sizeof(wchar_t*));
    *fileSizes = (ULONGLONG*)malloc(i * sizeof(ULONGLONG));
    i = 0;
    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;

            (*fileNames)[i] = (wchar_t*)malloc(BUFFER_SIZE * sizeof(wchar_t));
            (*fileSizes)[i] = fileSize;
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf((*fileNames)[i], L"%s", sPath);
            i++;
        }
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind);

    free(sPath);
    return i;
}

// Вывод списка файлов по последовательности индексов
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

// Поиск k-го файла с заданным размером
int find_by_size(ULONGLONG size, int k, ULONGLONG *sizes, int n)
{
	int i, fnd = 0, idx;
	if (k > n)
		return -2;
	for (i = 0; (i < n) && (fnd < k); i++)
	{
		if (sizes[i] == size)
		{
			idx = i;
			fnd++;
		}
	}
	if (i == n)
		return -1;
	return i;
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
    ULONGLONG min;
    newIdxes = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        newIdxes[i] = idxes[i];
    for (i = 0; i < n; i++) 
    {
        min = a[newIdxes[i]];
        minidx = i;
        for (j = i + 1; j < n; j++) 
            if (a[newIdxes[j]] < min)
            {
                min = a[newIdxes[j]];
                minidx = j;
            }
        swap_int(newIdxes + minidx, newIdxes + i);
    }
    return newIdxes;
}

// Сортировка простыми вставками
int* insert_sort(ULONGLONG *a, int *idxes, int n)
{
    int i, j, *newIdxes;
    ULONGLONG temp;
    newIdxes = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        newIdxes[i] = idxes[i];
    for (i = 1; i < n; i++) 
    {
        temp = a[newIdxes[i]];
        j = i - 1;
        while ((j >= 0) && (a[newIdxes[j]]>temp))
        {
            newIdxes[j + 1] = newIdxes[j];
            newIdxes[j] = i;
            j--;
        }
    }
    return newIdxes;
}

// Пузырьковая сортировка
int* bubble_sort(ULONGLONG *a, int *idxes, int n)
{
    int i, j, *newIdxes;
    newIdxes = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        newIdxes[i] = idxes[i];
    for (i = 0; i < n; i++) 
        for (j = 1; j < n - i; j++) 
            if (a[newIdxes[j - 1]] > a[newIdxes[j]])
                swap_int(newIdxes + j, newIdxes + j - 1);
    return newIdxes;
}

// Сортировка подсчетом (с произвольным выделением памяти)
int* counting_sort(ULONGLONG *a, int *idxes, int n)
{
    ULONGLONG *newSizes, idx = 0, i, delta = 0, min = a[0], 
		max = a[0], prev;
	int *newIdxes, *count, j, p = 0;
	newIdxes = (int*)malloc(delta * sizeof(int));
	newSizes = (ULONGLONG*)malloc(delta * sizeof(ULONGLONG));
	for (i = 0; i < n; i++)
	{
		newIdxes[i] = idxes[i];
		newSizes[i] = a[i];
	}
    for (i = 1; i < n; i++)
	{
        if (newSizes[i] < min)
            min = newSizes[i];
        if (newSizes[i] > max)
            max = newSizes[i];
    }
    delta = max - min + 1;
	if ((delta * sizeof(int)) >= (ULONGLONG)2147483648) // 2*1024*1024*1024
		return NULL;
	count = (int*)malloc(delta * sizeof(int));
    for (i = 0; i < delta; i++)
		count[i] = 0;
    for (i = 0; i < (ULONGLONG)n; i++)
		count[newSizes[i] - min]++;
    for (i = 0; i < delta; i++) 
        for (j = 0; j < count[i]; j++)
			newSizes[idx++] = i + min;
	newIdxes[0] = find_by_size(newSizes[0], 1, newSizes, n);
	prev = newSizes[0];
	for (j = 1; j < n; j++)
	{
		if (newSizes[j] == newSizes[j - 1])
			p++;
		else
			p = 0;
		newSizes[j] = find_by_size(newSizes[j], p, newSizes, n);
	}
    free(newSizes);
	free(count);
	return newIdxes;
}

// Запуск быстрой сортировки
int* start_quick_sort(ULONGLONG *sizes, int *idxes, int n1, int n2)
{
	int i, *newIdxes, total_length = n2 - n1 + 1;
	ULONGLONG *newSizes;
	newIdxes = (int*)malloc(total_length * sizeof(int));
	newSizes = (ULONGLONG*)malloc(total_length * sizeof(ULONGLONG));
	for (i = 0; i < total_length; i++)
	{
		newIdxes[i] = idxes[i + n1];
		newSizes[i] = sizes[i + n1];
	}
	quick_sort(newSizes, newIdxes, n1, n2);
	free(newSizes);
	return newIdxes;
}

// Быстрая сортировка
void quick_sort(ULONGLONG *sizes, int *idxes, int n1, int n2)
{
    ULONGLONG comp = sizes[(n1 + n2) / 2];
    int i = n1, j = n2;
	printf("enter qs ");
	do {
		while (sizes[i] < comp)
			i++;
		while (sizes[j] > comp)
			j--;
		if (i <= j) {
			if (sizes[i] > sizes[j])
			{
				swap_int(idxes + i, idxes + j);
				swap_ULL(sizes + i, sizes + j);
			}
			i++;
			j--;
		}
	} while (i <= j);
    if (i < n2)
        quick_sort(sizes, idxes, i, n2);
    if (j > n1)
        quick_sort(sizes, idxes, n1, j);
}

// Запуск сортировки слиянием
int* start_merge_sort(ULONGLONG *sizes, int *idxes, int l, int r)
{
    int i, *newIdxes, total_length = r - l + 1;
    ULONGLONG *newSizes;
    newIdxes = (int*)malloc(total_length * sizeof(int));
    newSizes = (ULONGLONG*)malloc(total_length * sizeof(ULONGLONG));
    for (i = 0; i < total_length; i++)
    {
        newIdxes[i] = idxes[i];
        newSizes[i] = sizes[i];
    }
    merge_sort(newSizes, newIdxes, l, r);
    free(newSizes);
    return newIdxes;
}

// Сортировка слиянием
void merge_sort(ULONGLONG *sizes, int *idxes, int l, int r)
{
	int m;
    if (l >= r) 
        return;
    m = (l + r) / 2;
    merge_sort(sizes, idxes, l, m);
    merge_sort(sizes, idxes, m + 1, r);
    merge_sorted(sizes, idxes, l, m, r);
}

// Слияние отсортированных частей массива (с произвольным выделением памяти)
void merge_sorted(ULONGLONG *sizes, int *idxes, int l, int m, int r)
{
    int i, j, s = 0, *tmpIdxes, total_length = r - l + 1;
    ULONGLONG *merged;
    merged = (ULONGLONG*)malloc(total_length * sizeof(ULONGLONG));
    tmpIdxes = (int*)malloc(total_length * sizeof(int));
	for (i = 0; i < total_length; i++)
		tmpIdxes[i] = idxes[i + l];
    i = l;
    j = m + 1;
    while ((i <= m) && (j <= r)) {
        if (sizes[i] <= sizes[j])
        {
            merged[s] = sizes[i];
			tmpIdxes[s] = idxes[i];
			s++; i++;
        }
        else
        {
            merged[s] = sizes[j];
			tmpIdxes[s] = idxes[j];
			s++; j++;
        }
    }
    while (i <= m)
    {
        merged[s] = sizes[i];
		tmpIdxes[s] = idxes[i];
		s++; i++;
    }
    while (j <= r)
    {
        merged[s] = sizes[j];
		tmpIdxes[s] = idxes[j];
		s++; j++;
    }
    for (i = l; i <= r; i++)
    {
        sizes[i] = merged[i - l];
        idxes[i] = tmpIdxes[i - l];
    }

    free(merged);
    free(tmpIdxes);
}