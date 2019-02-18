#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct {
    wchar_t name[2048];
    ULONGLONG size;
}file;

void inputpath(wchar_t p[2048]) {
    int i = 0;
    printf("Please, enter the path.\n");
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    char a[2048];
    do {
        i = 1;
        fgets(a, sizeof(a), stdin);
        a[strlen(a) - 1] = '\0';
        swprintf(p, 2048, L"%hs", a);
        if ((hFind = FindFirstFile(p, &fdFile)) == INVALID_HANDLE_VALUE)
        {
            wprintf(L"Path not found: [%s]\n", p);
            i = 0;
        }
    } while (i == 0);
}

int amountoffiles(const wchar_t *sDir)
{
    int n = 0;
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t sPath[2048];

    wsprintf(sPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE) {
        wprintf(L"Path not found: [%s]\n", sDir);
    }
    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
            n++;
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    return n;
}

int listoffiles(const wchar_t *sDir, file *f)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t sPath[2048];
    int i = 0;
    printf("\n-------------------------------List of files-------------------------------\n");

    wsprintf(sPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Path not found: [%s]\n", sDir);
        return 1;
    }

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;

            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wprintf(L"File: %s Size: %lld\n", sPath, fileSize);

            wsprintf(f[i].name, L"%s", sPath);
            f[i].size = fileSize;
            i++;
        }
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    return 0;
}

void sortingbychoice(file *a, int n) {
    int i, j, minindex;
    file temp;
    for (i = 0; i < n; i++) {
        temp = a[i];
        minindex = i;
        for (j = i + 1; j < n; j++) {
            if (a[j].size < temp.size) {
                temp = a[j];
                minindex = j;
            }
        }
        a[minindex] = a[i];
        a[i] = temp;
    }
}

void sortinginserts(file *a, int n) {
    int i, j;
    file temp;
    for (i = 1; i < n; i++) {
        j = i - 1;
        temp = a[i];
        while ((j >= 0) && (a[j].size > temp.size)) {
            a[j + 1] = a[j];
            a[j] = temp;
            j--;
        }
    }
}

void bubblesorting(file *a, int n) {
    int i, j;
    file temp;
    for (i = 0; i < n; i++) {
        for (j = 1; j < n - i; j++) {
            if (a[j - 1].size > a[j].size) {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

void sortingbycount(file *a, int n) {
    file *b = (file*)malloc(sizeof(file) * n);
    int i, imax = 0, imin = 0, temp, sum = 0, max, min, lenght;

    for (i = 0; i < n; i++) {
        if (a[i].size > a[imax].size) {
            imax = i;
        }
        if (a[i].size < a[imin].size) {
            imin = i;
        }
    }

    min = a[imin].size;
    max = a[imax].size;
    lenght = max - min + 1;
    int *p = (int*)malloc(sizeof(int) * lenght);

    for (i = 0; i < lenght; i++) {
        p[i] = 0;
    }
    for (i = 0; i < n; i++) {
        p[a[i].size - min]++;//зачем отнимаем min? 
    }
    for (i = 0; i < lenght; i++) {
        temp = p[i];
        p[i] = sum;
        sum += temp;
    }
    for (i = 0; i < n; i++) {
        b[p[a[i].size - min]] = a[i];//
        p[a[i].size - min]++;//
    }
    for (i = 0; i < n; i++) {
        a[i] = b[i];
    }
    free(b);
    free(p);
}


void quicksplit(file *a, int *i, int *j, int p)
{
    file temp;
    do {
        while (a[(*i)].size < p)
            (*i)++;
        while (a[(*j)].size > p)
            (*j)--;
        if ((*i) <= (*j))
        {
            temp = a[(*i)];
            a[(*i)] = a[(*j)];
            a[(*j)] = temp;
            (*i)++;
            (*j)--;
        }
    } while ((*i) < (*j));
}

void quicksorting(file *a, int left, int right)
{
    int mid = (left + right) / 2;
    int i = left, j = right;

    quicksplit(a, &i, &j, a[mid].size);

    if (j > left)
        quicksorting(a, left, j);
    if (i < right)
        quicksorting(a, i, right);
}

void merge(file *a, int l, int m, int r) {
    int i, j, k = 0;
    file *temp = (file*)malloc((r - l + 1) * sizeof(file));
    i = l;
    j = m + 1;
    while ((i <= m) && (j <= r))
    {
        if (a[i].size < a[j].size)
        {
            temp[k++] = a[i++];

        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while (i <= m)
    {
        temp[k++] = a[i++];
    }
    while (j <= r)
    {
        temp[k++] = a[j++];
    }
    for (k = l; k <= r; k++)
    {
        a[k] = temp[k - l];
    }
    free(temp);

}

void mergesorting(file *a, int left, int right) {
    if (left >= right) return;
    int mid;
    mid = (left + right) / 2;
    mergesorting(a, left, mid);
    mergesorting(a, mid + 1, right);
    merge(a, left, mid, right);
}

void inputthenumber(int *number) {
    printf("\nPlease, enter the number of sorting.\n");
    printf("1 - sorting by choice\n");
    printf("2 - sortinginserts\n");
    printf("3 - bubble sorting\n");
    printf("4 - sorting by count\n");
    printf("5 - quick sortig\n");
    printf("6 - merge sorting\n");

    do {
        printf("Your choice: ");
        scanf("%d", &(*number));
        if (*number < 1 || *number > 6) {
            printf("There is no such number of sorting. Try to enter number again.\n");
        }
    } while (*number < 1 || *number > 6);
}

void inputtheway(int *way) {
    printf("\nNow you have to choose the way of sorting.\n");
    printf("1 - ascending sort\n");
    printf("2 - descending sort\n");

    do {
        printf("Your choice: ");
        scanf("%d", &(*way));
        if (*way != 1 && *way != 2) {
            printf("There is no such way of sorting. Try again.\n");
        }
    } while (*way != 1 && *way != 2);
}

void kindofsorting(int number, file* fs, int n, clock_t *start, clock_t *stop) {
    switch (number) {
    case 1: {
        *start = clock();
        sortingbychoice(fs, n);
        *stop = clock();
        break;
    }
    case 2: {
        *start = clock();
        sortinginserts(fs, n);
        *stop = clock();
        break;
    }
    case 3: {
        *start = clock();
        bubblesorting(fs, n);
        *stop = clock();
        break;
    }
    case 4: {
        *start = clock();
        sortingbycount(fs, n);
        *stop = clock();
        break;
    }
    case 5: {
        *start = clock();
        quicksorting(fs, 0, n - 1);
        *stop = clock();
        break;
    }
    case 6: {
        *start = clock();
        mergesorting(fs, 0, n);
        *stop = clock();
        break;
    }
    }
}

void wayofsortintg(int way, file* fs, int n) {
    int i;
    printf("\n----------------------------List of sorted files---------------------------\n");
    switch (way) {
    case 1: {
        for (i = 0; i < n; i++) {
            wprintf(L"File: %s Size: %lld\n", fs[i].name, fs[i].size);
        }
        break;
    }
    case 2: {
        for (i = n - 1; i >= 0; i--) {
            wprintf(L"File: %s Size: %lld\n", fs[i].name, fs[i].size);
        }
        break;
    }
    }
}

void timeofsorting(clock_t start, clock_t stop) {
    clock_t time = stop - start;
    printf("\nTime of sorting: %.5f seconds\n", ((float)time) / CLK_TCK);
}

void main() {
    int n, i = 0, number, way, next = 1, p = 1;
    wchar_t path[2048];
    setlocale(LC_ALL, "Russian");
    inputpath(path);
    n = amountoffiles(path);
    file *fs = (file*)malloc(sizeof(file) * n);
    clock_t start, stop;
    inputthenumber(&number);
    inputtheway(&way);
    listoffiles(path, fs);
    kindofsorting(number, fs, n, &start, &stop);
    wayofsortintg(way, fs, n);
    timeofsorting(start, stop);
    system("pause");
}
