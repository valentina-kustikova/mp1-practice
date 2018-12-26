#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#define MAX_LEN 256
#define MAX_AMOUNT 1024

void Merge(ULONGLONG *size_copy, int l, int m, int r);

void Print(wchar_t **name, ULONGLONG *size, int *index, int n, int order, double time)
{
    int i;
    if (n == 0)
        printf("В папке нет элементов\n");
    else
    {
     if (order == 0)
          for (i = 0; i < n; i++)
               wprintf(L"Файл: %s Размер: %lli\n",
                  name[index[i]], size[index[i]]);
        else
           for (i = n - 1; i > -1; i--)
               wprintf(L"Файл: %s Размер: %lli\n",
                  name[index[i]], size[index[i]]);
       printf("Время сортировки %lf секунд(ы)\n", time);
    }
}
void ChooseSort(ULONGLONG *size_copy, int n)
{
    int i, j, ind;
    ULONGLONG min;
    for (i = 0; i < n - 1; i++)
    {
        min = size_copy[i];
        ind = i;
        for (j = i + 1; j < n; j++)
        {
            if (size_copy[j] < min)
            {
                min = size_copy[j];
                ind = j;
            }
        }
        size_copy[ind] = size_copy[i];
        size_copy[i] = min;
    }
}
void InsertSort(ULONGLONG *size_copy, int n)
{
    int i, j;
    ULONGLONG tmp;
    for (i = 1; i < n; i++)
    {
        tmp = size_copy[i];
        j = i - 1;
        while (j >= 0 && size_copy[j] > tmp)
        {
            size_copy[j + 1] = size_copy[j];
            size_copy[j] = tmp;
        }
    }
}
void BubbleSort(ULONGLONG *size_copy, int n)
{
    int i, j;
    ULONGLONG tmp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 1; j < n - i; j++)
            if (size_copy[j - 1] > size_copy[j])
            {
                tmp = size_copy[j - 1];
                size_copy[j - 1] = size_copy[j];
                size_copy[j] = tmp;
            }
    }
}
void CountingSort(ULONGLONG *size_copy, int n)
{
    int *count, i, j, ind = 0;
    ULONGLONG min = size_copy[0], max = size_copy[0];
    for (i = 0; i < n; i++)
    {
        if (size_copy[i] < min)
            min = size_copy[i];
        if (size_copy[i] > max)
            max = size_copy[i];
    }
    count = (void*)malloc((max - min + 1) * sizeof(int));
    memset(count, 0, (max - min + 1) * sizeof(int));
    for (i = 0; i < n; i++)
        count[size_copy[i] - min]++;
    for (i = 0; i < (max - min + 1); i++)
        for (j = 0; j < count[i]; j++)
            size_copy[ind++] = i + min;
    free(count);
}
void QuickSort(ULONGLONG *size_copy, int n1, int n2)
{
    ULONGLONG m = size_copy[(n1 + n2) / 2];
    int i = n1, j = n2;
    do
    {
        while (size_copy[i] < m)
            i++;
        while (size_copy[j] > m)
            j--;
        if (i <= j)
        {
            ULONGLONG tmp = size_copy[i];
            size_copy[i++] = size_copy[j];
            size_copy[j--] = tmp;
        }
    } while (i <= j);
    if (i < n2)
        QuickSort(size_copy, i, n2);
    if (j > n1)
        QuickSort(size_copy, n1, j);
}
void MergeSort(ULONGLONG *size_copy, int l, int r)
{
    int m = (l + r) / 2;
    if (l >= r)
        return;
    MergeSort(size_copy, l, m);
    MergeSort(size_copy, m + 1, r);
    Merge(size_copy, l, m, r);
}
void Merge(ULONGLONG *size_copy, int l, int m, int r)
{
    int i = l, j = m + 1, s = l,  k = l;
    ULONGLONG *c;
    c = (ULONGLONG*)malloc(MAX_AMOUNT * sizeof(ULONGLONG));
    while (i < m + 1 && j < r + 1)
        c[s++] = size_copy[i] < size_copy[j] ? size_copy[i++] : size_copy[j++];
    while (i < m + 1)
        c[s++] = size_copy[i++];
    while (j < r + 1)
        c[s++] = size_copy[j++];
    while (k < r + 1)
        size_copy[k] = c[k++];
    free(c);
}
int ListDirectoryContents(wchar_t *sDir, wchar_t **name,
  ULONGLONG *size, int mode, int *amount)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t *sPath;
    sPath = (wchar_t*)malloc(MAX_LEN * sizeof(wchar_t));
    wsprintf(sPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFileW(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Путь не найден: [%s]\n", sDir);
        return 1;
    }
    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp
          (fdFile.cFileName, L"..") != 0)
        {
            size[*amount] = fdFile.nFileSizeHigh;
            size[*amount] <<= sizeof(fdFile.nFileSizeHigh) * 8;
            size[*amount] |= fdFile.nFileSizeLow;
            wsprintf(name[*amount], L"%s\\%s", sDir, fdFile.cFileName);
            (*amount)++;
        }
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    free(sPath);
    return 0;
}
void main()
{
    setlocale(LC_ALL, "Rus");

    while (1)
    {
        int mode, order, i, amount = 0, *index, ind = 0;
        wchar_t *wdir, **name;
        clock_t time;
        double t;
        ULONGLONG *size, *size_copy, *size_t;
        wdir = (wchar_t*)malloc(MAX_LEN);
        size = (ULONGLONG*)malloc(MAX_AMOUNT * sizeof(ULONGLONG));
        size_t = (ULONGLONG*)malloc(MAX_AMOUNT * sizeof(ULONGLONG));
        size_copy = (ULONGLONG*)malloc(MAX_AMOUNT * sizeof(ULONGLONG));
        name = (wchar_t**)malloc(sizeof(wchar_t*) * MAX_AMOUNT);
        index = (int*)malloc(MAX_AMOUNT * sizeof(int));
        for (i = 0; i < MAX_AMOUNT; i++)
            index[i] = i;
        for (i = 0; i < MAX_AMOUNT; i++)
            name[i] = (wchar_t*)malloc(sizeof(wchar_t) * MAX_LEN);
        printf("Выберите режим:\n0 – выбором, 1 – вставкой, "
          "2 – пузырьком, 3 – подсчётом,\n4 – быстрая, "
          "5 – слиянием,\n6 для выхода\n");
        do
        {
            scanf("%d", &mode);
        } while (mode < 0 || mode > 6);
        if (mode == 6)
            return;
        printf("0 – по возрастанию, 1 – по убыванию\n");
        do
        {
            scanf("%d", &order);
        } while (order < 0 || order > 1);
        printf("Введите адрес\n");
        getchar();
        fgetws(wdir, MAX_LEN, stdin);
        wdir[wcslen(wdir) - 1] = '\0';
        if (ListDirectoryContents(wdir, name, size, mode, &amount))
            continue;
        for (i = 0; i < amount; i++)
            size_copy[i] = size[i];
        for (i = 0; i < amount; i++)
            size_t[i] = size[i];
        switch (mode)
        {
            case 0:
                time = clock();
                ChooseSort(size_copy, amount + 1);
                break;
            case 1:
                time = clock();
                InsertSort(size_copy, amount + 1);
                break;
            case 2:
                time = clock();
                BubbleSort(size_copy, amount);
                break;
            case 3:
                time = clock();
                CountingSort(size_copy, amount);
                break;
            case 4:
                time = clock();
                QuickSort(size_copy, 0, amount - 1);
                break;
            case 5:
                time = clock();
                MergeSort(size_copy, 0, amount - 1);
        }
        time = clock() - time;
        for (ind = 0; ind < amount; ind++)
        {
            for (i = 0; i < amount; i++)
                if (size_t[i] == size_copy[ind])
                {
                    size_t[i] = -1;
                    break;
                }
            index[ind] = i;
        }
        t = ((double)time) / CLOCKS_PER_SEC;
        Print(name, size, index, amount, order, t);
        for (i = 0; i < MAX_AMOUNT; i++)
            free(name[i]);
        free(name);
        free(size);
        free(size_t);
        free(size_copy);
        free(index);
        free(wdir);
    }
}
