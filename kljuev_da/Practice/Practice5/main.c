﻿#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#define MAX_LEN 256
#define MAX_AMOUNT 256
#define N 5
#define Range 100

void QuickSplit(int *a, int *i, int *j, int p);
void Merge(int *a, int l, int m, int r);

void Input(int *a, int n, int mode)
{
    int i, j, f;
    printf("Введите массив\n");
    if (mode != 3)
        for (i = 0; i < n; i++)
            scanf("%d", &(a[i]));
    else
        for (i = 0; i < n;)
        {
            scanf("%d", &(a[i]));
            f = 0;
            for (j = 0; j < i; j++)
                if (a[j] - a[i] > Range - 1 || a[i] - a[j] > Range - 1)
                    f = 1;
            if (f == 1)
                continue;
            i++;
        }
}
void Print(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
}
void ChooseSort(int *a, int n)
{
    int i, j, min, ind;
    for (i = 0; i < n - 1; i++)
    {
        min = a[i];
        ind = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                ind = j;
            }
        }
        a[ind] = a[i];
        a[i] = min;
    }
}
void InsertSort(int *a, int n)
{
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > tmp)
        {
            a[j + 1] = a[j];
            a[j--] = tmp;
        }
    }
}
void BubbleSort(int *a, int n)
{
    int i, j, tmp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 1; j < n - i; j++)
            if (a[j - 1] > a[j])
            {
                tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
    }
}
void CountingSort(int *a, int n)
{
    int *count, i, j, min = a[0], ind = 0;
    count = (void*)malloc(Range * sizeof(int));
    memset(count, 0, Range * sizeof(int));
    for (i = 0; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    for (i = 0; i < n; i++)
        count[a[i] - min]++;
    for (i = 0; i < Range; i++)
        for (j = 0; j < count[i]; j++)
            a[ind++] = i + min;
    free(count);
}
void QuickSort(int *a, int n1, int n2)
{
    int m = (n1 + n2) / 2;
    int i = n1, j = n2;
    QuickSplit(a, &i, &j, a[m]);
    if (i > n1)
        QuickSort(a, n1, i - 1);
    if (j < n2)
        QuickSort(a, j + 1, n2);
}
void MergeSort(int *a, int l, int r)
{
    int m = (l + r) / 2;
    if (l >= r)
        return;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, m, r);
}
void QuickSplit(int *a, int *i, int *j, int p)
{
    do
    {
        while (a[*i] < p)
            (*i)++;
        while (a[*j] > p)
            (*j)--;
        if (*i <= *j)
        {
            int tmp = a[*i];
            a[*i] = a[*j];
            a[*j] = tmp;
        }
    } while (*i < *j);
}
void Merge(int *a, int l, int m, int r)
{
    int i = l, j = m + 1, s = l, *c, k = l;
    c = (int*)malloc(N * sizeof(int));
    while (i < m + 1 && j < r + 1)
        c[s++] = a[i] < a[j] ? a[i++] : a[j++];
    while (i < m + 1)
        c[s++] = a[i++];
    while (j < r + 1)
        c[s++] = a[j++];
    while (k < r + 1)
        a[k] = c[k++];
    free(c);
}
int ListDirectoryContents(const wchar_t *sDir, int mode)
{
    //typedef struct file_ { wchar_t name[MAX_LEN]; ULONGLONG size } file;
    int num = 0, i, *index;
    wchar_t** name;
    ULONGLONG* size;
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t* sPath;
    //index = (int*)malloc(sizeof(int) * MAX_AMOUNT);
    index = (int*)malloc(MAX_AMOUNT * sizeof(int));
    name = (wchar_t*)malloc(sizeof(wchar_t) * MAX_AMOUNT);
   // size = (int*)malloc(sizeof(int) * MAX_AMOUNT);
    size = (ULONGLONG*)malloc(MAX_AMOUNT * sizeof(ULONGLONG));
    for (i = 0; i < MAX_AMOUNT; i++)
        index[i] = i;
    for (i = 0; i < MAX_AMOUNT; i++)
        name[i] = (wchar_t*)malloc(sizeof(wchar_t) * MAX_LEN);
    sPath = (wchar_t*)malloc(2048 * sizeof(wchar_t));
    wsprintf(sPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFileW(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Path not found: [%s]\n", sDir);
        return 1;
    }
    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp
          (fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wprintf(L"File: %s\nSize: %d\n", sPath, (wchar_t)fileSize);
            num++;
        }
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind);
   // for (i = 0; i < MAX_AMOUNT; i++)
     //   free(name[i]);
    //free(name);
    free(size);
   // free(index);
    free(sPath + 1);
    return 0;
}
void main()
{
    char* ta = (char*)malloc(MAX_LEN);
    wchar_t* ca = (wchar_t*)malloc(MAX_LEN);
    setlocale(LC_ALL, "Rus");
    while (1)
    {
        int mode = -1;
        printf("Выберите режим:\n0 – выбором, 1 – вставкой, "
            "2 – пузырьком, 3 – подсчётом,\n4 – быстрая, "
            "5 – слиянием,\n6 для выхода\n");
        do
        {
            scanf("%d", &mode);
        } while (mode < 0 || mode > 6);
        if (mode == 6)
            return;
        printf("Введите адрес\n");
        getchar();
        fgets(ta, MAX_LEN, stdin);
        ta[strlen(ta) - 1] = '\0';
        swprintf(ca, MAX_LEN, L"%hs", ta);
        ListDirectoryContents(ca, mode);
    }
    free(ta);
    free(ca);
}

/*void main()
{
    int mode, *a;
    setlocale(LC_ALL, "Rus");
    a = (int*)malloc(N * sizeof(int));
    
    printf("Выберите режим:\n0 – выбором, 1 – вставкой, "
      "2 – пузырьком, 3 – подсчётом,\n4 – быстрая, "
      "5 – слиянием,\n6 для выхода\n");
    do
    {
        scanf("%d", &mode);
    } while (mode < 0 || mode > 6);
    Input(a, N, mode);
    printf("\nСортировка по возрастанию\n\n");
    switch (mode)
    {
    case 0:
        ChooseSort(a, N);
        break;
    case 1:
        InsertSort(a, N);
        break;
    case 2:
        BubbleSort(a, N);
        break;
    case 3:
        CountingSort(a, N);
        break;
    case 4:
        QuickSort(a, 0, N - 1);
        break;
    case 5:
        MergeSort(a, 0, N - 1);
    }
    Print(a, N);
    free(a);
}
*/
