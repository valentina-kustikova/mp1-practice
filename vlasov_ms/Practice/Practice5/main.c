#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define N 10     // количество элементов массива

void gen(int a[], int n, int min, int max);
void output(int a[], int n);

void choosing_sort(int a[], int n);
void insert_sort(int a[], int n);
void bubble_sort(int a[], int n);
void counting_sort(int a[], int n);
void quick_sort(int a[], int n1, int n2);
void quick_split(int a[], int* i, int* j, int p);
void merge_sort(int a[], int l, int r);
void merge_sorted(int a[], int l, int m, int r);

int dir_contents(const wchar_t *sDir);

wchar_t* user_input() {
	wchar_t *string;
    char symbol;
    int i = 0;
    string = (wchar_t*)malloc(0 * sizeof(wchar_t));
    do
    {
        symbol = getchar();
        printf("%c", symbol);
        string = (wchar_t*)realloc(string, 1 * sizeof(wchar_t));
        //string[i] = symbol >> (sizeof(wchar_t) - sizeof(char)) * 8;
		string[i] = (wchar_t)symbol;
        //*(string + i) = *(string + i) >> 8;
        i++;
    } while (symbol != '\n');
    return string;
}

/*unsigned short* user_input() {
	unsigned short *wstring;
	char cstring[2048] = { 0 };
	int i = 0, length;
	for (i = 0; cstring[i] != "."; i++) {
		scanf("%c", &(cstring[i]));
	}
	length = strlen(cstring);
	wstring = (unsigned short*)malloc(length * sizeof(unsigned short));
	for (i = 0; i < length; i++) {
		wstring[i] = (unsigned short)cstring[i];
	}
	return wstring;
}*/

void main() 
{
    int a[N], algo, min, max, i;
    unsigned short *path;
    setlocale(LC_ALL, "Russian");

    // Debug - START
    path = user_input();
    dir_contents((wchar_t*)path);
    return;
    // Debug - END

    gen(a, N, 502, 692);
    printf("Исходный массив:        ");
    output(a, N);
    printf("Алгоритм сортировки:       ");
    scanf("%d", &algo);
    switch (algo) 
    {
        case 1:
            choosing_sort(a, N);
            break;
        case 2:
            insert_sort(a, N);
            break;
        case 3:
            bubble_sort(a, N);
            break;
        case 4:
            counting_sort(a, N);
            break;
        case 5:
            quick_sort(a, 0, N - 1);
            break;
        case 6:
            merge_sort(a, 0, N - 1);
            break;
        default:
            printf("Неверный номер.\n");
            return;
    }
    printf("Отсортированный массив: ");
    output(a, N);
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
void output(int a[], int n) 
{
    int i;
    for (i = 0; i < n - 1; i++) 
        printf("%4d", a[i]);
    printf("%4d\n", a[n - 1]);
}


// Сортировка выбором
void choosing_sort(int a[], int n)
{
    int i, j, min, minidx;
    for (i = 0; i < n; i++) 
    {
        min = a[i];
        minidx = i;
        for (j = i + 1; j < n; j++) 
            if (a[j] < min) 
            {
                min = a[j];
                minidx = j;
            }
        a[minidx] = a[i];
        a[i] = min;
    }
}

// Сортировка простыми вставками
void insert_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++) 
    {
        temp = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j]>temp)) 
        {
            a[j + 1] = a[j];
            a[j--] = temp;
        }
    }
}

// Пузырьковая сортировка
void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++) 
        for (j = 1; j < n - i; j++) 
            if (a[j - 1]>a[j]) 
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
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
    //printf("min=%d, max=%d, delta=%d\n", min, max, delta); // debug info
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
    int i = n1, j = n2 + 1;
    if (n1 == n2)
        return;
    quick_split(a, &i, &j, a[m]);
    quick_sort(a, n1, i);
    quick_sort(a, j, n2);
}

// Быстрая перестановка
void quick_split(int a[], int* i, int* j, int p)
{
    do {
        while (a[*i] < p) (*i)++;
        while (a[*j] > p) (*j)--;
        if (*i <= *j) {
            int tmp = a[*i];
            a[*i] = a[*j];
            a[*j] = tmp;
        }
        output(a, N);
    } while (*i < *j);
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
        if (a[i] < a[j])
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

// Печать списка файлов и размеров из директории
int dir_contents(const wchar_t *sDir)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t sPath[2048];

    wsprintf(sPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Path not found: [%s]\n", sDir);
        return 1;
    }
	wprintf(L"Path: [%s]\n", sDir);
    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;

            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wprintf(L"File: %s Size: %d\n", sPath, fileSize);
        }
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    return 0;
}