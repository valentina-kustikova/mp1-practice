#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define N 1000
#define MAX_LEN 2048

int ListDirectoryContents(const wchar_t *sDir, ULONGLONG* size, wchar_t** file_name, wchar_t** temp)
{
    int i = 0;
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t sPath[MAX_LEN];

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
            file_name[i] = (wchar_t*)malloc(sizeof(wchar_t*) * MAX_LEN);
            temp[i] = (wchar_t*)malloc(sizeof(wchar_t*) * MAX_LEN);
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;
            size[i] = fileSize;
            wsprintf(file_name[i], L"%s\\%s", sDir, fdFile.cFileName);
            wprintf(L"File: %s Size: %d\n", file_name[i] , fileSize);
            i++;
        }
    } while (FindNextFile(hFind, &fdFile) && i < 1000);
    FindClose(hFind);
    return 1;
}

int CountofFiles(const wchar_t *sDir)
{
    int i = 0;
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t sPath[2048];

    wsprintf(sPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Path not found: [%s]\n", sDir);
        return -1;
    }

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            i++;
        }
    } while (FindNextFile(hFind, &fdFile) && i < 1000);
    FindClose(hFind);
    return i;
}

void choose(ULONGLONG* a, wchar_t** file_name, int n)
{
    int i = 0, j, min, minindx;
    wchar_t** tmp;
    for (; i < n - 1; i++)
    {
        min = a[i];
        minindx = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < min)
            {
                min = a[j];
                minindx = j;
            }
        a[minindx] = a[i];
        a[i] = min;
        tmp = file_name[minindx];
        file_name[minindx] = file_name[i];
        file_name[i] = tmp;
    }
}

void insert(ULONGLONG* a, wchar_t** f, int n)
{
    int i, j;
    ULONGLONG tmp;
    wchar_t* temp;
    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > tmp))
        {
            a[j + 1] = a[j];
            a[j] = tmp;
            temp = f[j + 1];
            f[j + 1] = f[j];
            f[j] = temp;
            j--;
        }
    }
}

void bubble(ULONGLONG* a, wchar_t** f, int n)
{
    int i = 0, j;
    ULONGLONG tmp;
    wchar_t* temp;
    for (; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                temp = f[j];
                f[j] = f[j + 1];
                f[j + 1] = temp;
            }

}

void quicksplit(ULONGLONG* a, wchar_t** f, int* i, int* j, int p)
{
    do {
        while (a[*i] < p) (*i)++;
        while (a[*j] > p) (*j)--;
        if (*i <= *j)
        {
            ULONGLONG tmp = a[*i];
            wchar_t* temp = f[*i];
            a[*i] = a[*j];
            a[*j] = tmp;
            f[*i] = f[*j];
            f[*j] = temp;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void quicksort(ULONGLONG* a, wchar_t** f, int n1, int n2)
{
    if (n1 < n2)
    {
        int pidx = (n1 + n2) / 2;
        int i = n1, j = n2;
        quicksplit(a, f, &i, &j, a[pidx]);
        quicksort(a, f, n1, j);
        quicksort(a, f, i, n2);
    }
}

void merge(ULONGLONG* a, ULONGLONG* buffer, wchar_t** f, wchar_t** temp, int l, int m, int r)
{
    int i, j, k;
    i = l; j = m + 1; k = l;
    while (k <= r)
    {
        while (i <= m && j <= r)
            if (a[i] < a[j]) 
            {
                buffer[k] = a[i];
                temp[k] = f[i];
                k++; i++;
            }

            else
                if (a[j] < a[i] && j <= r)
                {
                    buffer[k] = a[j];
                    temp[k] = f[j];
                    k++; j++;
                }
                else
                    if (a[i] == a[j])
                    {
                        buffer[k] = a[i];
                        temp[k] = f[i];
                        k++; i++;
                        buffer[k] = a[j];
                        temp[k] = f[j];
                        k++; j++;
                    }
        while (i <= m)
        {
            buffer[k] = a[i];
            temp[k] = f[i];
            k++; i++;
        }
        while (j <= r)
        {
            buffer[k] = a[j];
            temp[k] = f[j];
            k++; j++;
        }
        for (i = l; i <= r; i++) 
        {
            a[i] = buffer[i];
            f[i] = temp[i];
        }

    }
}

void mergesort(ULONGLONG* a, ULONGLONG* buffer, wchar_t** f, wchar_t** temp, int l, int r)
{
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    mergesort(a, buffer, f, temp, l, m);
    mergesort(a, buffer, f, temp, m + 1, r);
    merge(a, buffer, f, temp, l, m, r);
}

void main()
{ 
    setlocale(LC_ALL, "Russian");
	clock_t begin, end, time;
    int n, i, sort_num, check;
    ULONGLONG* tmp = NULL;
    ULONGLONG* size = NULL;
    wchar_t* file_name[N] = { NULL };
    wchar_t* temp[N] = { NULL };
    char* a = (char*)malloc(sizeof(char) * MAX_LEN);
    wchar_t* ca = (wchar_t*)malloc(sizeof(wchar_t) * MAX_LEN);
	do {
		printf("Введите путь\n");
		fgets(a, MAX_LEN, stdin);
		a[strlen(a) - 1] = '\0';
		swprintf(ca, MAX_LEN, L"%hs", a);
		n = CountofFiles(ca);
	} while (n == -1);
    size = (ULONGLONG*)malloc(sizeof(ULONGLONG*) * n);
    tmp = (ULONGLONG*)malloc(sizeof(ULONGLONG*) * n);
    ListDirectoryContents(ca, size, file_name, temp);
    for (i = 0; i < n; i++)
    {
        tmp[i] = size[i];
        temp[i] = file_name[i];
    }
    printf("Выберите метод сортировки:\n1: Выбором\n2: Вставками\n3: Пузырьком\n4: Быстрая\n5: Слиянием\n0: Выход\n");
    scanf("%d", &sort_num);
    while (sort_num != 0) {

        switch (sort_num)
        {
        case 1:
			begin = clock();
            choose(size, file_name, n);
			end = clock();
			time = (double)(end - begin) / CLOCKS_PER_SEC;
            for (i = 0; i < n; i++)
                wprintf(L"File: %s Size: %d\n", file_name[i], size[i]);
			printf("Сортировка выбором, время сортировки %lf", time);
            break;
        case 2:
			begin = clock();
            insert(size, file_name, n);
			end = clock();
			time = (double)(end - begin) / CLOCKS_PER_SEC;
            for (i = 0; i < n; i++)
                wprintf(L"File: %s Size: %d\n", file_name[i], size[i]);
			printf("Сортировка вставками, время сортировки %lf", time);
            break;
        case 3:
			begin = clock();
            bubble(size, file_name, n);
			end = clock();
			time = (double)(end - begin) / CLOCKS_PER_SEC;
            for (i = 0; i < n; i++)
                wprintf(L"File: %s Size: %d\n", file_name[i], size[i]);
			printf("Сортировка пузырьком, время сортировки %lf", time);
            break;
        case 4:
			begin = clock();
            quicksort(size, file_name, 0, n);
			end = clock();
			time = (double)(end - begin) / CLOCKS_PER_SEC;
            for (i = 0; i < n; i++)
                wprintf(L"File: %s Size: %d\n", file_name[i], size[i]);
			printf("Быстрая сортировка, время сортировки %lf", time);
            break;
        case 5:
			begin = clock();
            mergesort(size, tmp, file_name, temp, 0, n);
			end = clock();
			time = (double)(end - begin) / CLOCKS_PER_SEC;
            for (i = 0; i < n; i++)
                wprintf(L"File: %s Size: %d\n", file_name[i], size[i]);
			printf("Сортировка слиянием, время сортировки %lf", time);
            break;
        }
		printf("Выберите метод сортировки:\n1: Выбором\n2: Вставками\n3: Пузырьком\n4: Быстрая\n5: Слиянием\n0: Выход\nНеобходимо ввести цифру\n");
        scanf("%d", &sort_num);
    }


    
}