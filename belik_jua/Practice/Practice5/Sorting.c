#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#define K 20000
#define MAX_LEN 10000

int ListDirectoryContents(const wchar_t *sDir, ULONGLONG *size, wchar_t ***name) 
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t sPath[2048]; 
    int j, i = 0; 

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
    } while (FindNextFile(hFind, &fdFile)); wsprintf(sPath, L"%s\\*.*", sDir);
    hFind = NULL;
    hFind = FindFirstFile(sPath, &fdFile);
    *size = (ULONGLONG*)malloc(sizeof(ULONGLONG) * i);
    *name = (wchar_t**)malloc(sizeof(wchar_t*) * i); 
    i = 0;
    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;

            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);

            j = 0;
            *(size + i) = fileSize / 1024; 

            while (sPath[j] != '\0') j++; 
            (*name)[i] = (wchar_t*)malloc(sizeof(wchar_t) * j); 
            wsprintf((*name)[i], L"%s", sPath);
            i++;
        }
    } while (FindNextFile(hFind, &fdFile)); 
    FindClose(hFind);
    return i;
}

void Command()
{
    printf("\n1 - ChooseSort \n");
    printf("2 - InsertionSort \n");
    printf("3 - BubbleSort \n");
    printf("4 - CountingSort \n");
    printf("5 - QuickSort \n");
    printf("6 - MergeSort \n");
    printf("7 - New path to the folder\n");
    printf("8 - Exit\n");
}

void Print(int *a, ULONGLONG *size, wchar_t **name, int n, float time) 
{
    int i;     
    for (i = 0; i < n; i++)
    {
        wprintf(L"File: %s size: %lld \n", name[a[i]], *(size + a[i]));
    }
    printf("Sorting time: %.10f s\n", time);
    printf("\n");
}

void ChooseSort(int *a, ULONGLONG *size, int n)
{
    int i, j, tmp, ind;
    for (i = 0; i < n - 1; i++)
    {
        ind = i;
        for (j = i + 1; j < n; j++)
        {
            if (size[a[ind]] > size[a[j]])
                ind = j; 
        }
        tmp = a[ind];
        a[ind] = a[i];
        a[i] = tmp;
    }
}

void InsertionSort(int *a, ULONGLONG *size, int n)
{
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        j = i - 1;
        while ((j >= 0) && (size[a[j]] > size[tmp]))
        {
            a[j + 1] = a[j];
            a[j] = tmp;
            j--;
        }
    }
}

void BubbleSort(int *a, ULONGLONG *size, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n - i; j++)
        {
            if (size[a[j]] < size[a[j - 1]])
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

int CountingSort(int *a, ULONGLONG *size, int n)
{
    int *b = (int*)malloc(K * sizeof(int));
    int i, j, idx = 0;
    int h = 0;
    for (i = 0; i < K; i++)
        b[i] = 0;
    for (i = 0; i < n; i++)
    {
        if (size[a[i]] > K)
        {
            printf("CountingSort cannot be performed, please, choose another sort\n");
            return 1;
        }
            b[size[a[i]]]++;
    }
    for (i = 0; i < K; i++)
    {
        if (b[i]>0)
        {
            h = 0;
            for (j = 0; j < b[i]; j++)
            {
                while (size[h] != i)
                    h++;
                a[idx++] = h++;
            }
        }
    }
    free(b);
    return 0;
}

void Quicksplit(int *a, ULONGLONG *size, int *i, int *j, ULONGLONG p)
{
    int tmp;
    do {
        while (size[a[(*i)]] < p)
            (*i)++; 
        while (size[a[(*j)]] > p)
            (*j)--; 
        if ((*i) <= (*j))
        {
            tmp = a[(*i)];
            a[(*i)] = a[(*j)];
            a[(*j)] = tmp;
            (*i)++;
            (*j)--;
        } 
    } while ((*i) < (*j));
}

void QuickSort(int *a, ULONGLONG *size, int n1, int n2)
{
    int m = (n1 + n2) / 2;
    int i = n1, j = n2;
    Quicksplit(a, size, &i, &j, size[a[m]]);
    if (j > n1)
        QuickSort(a, size, n1, j);
    if (i < n2)
        QuickSort(a, size, i, n2); 
}

void Merge(int *a, ULONGLONG *size, int l, int m, int r) 
{
    int i, j = m + 1, h, tmp;
    for (i = l; ((i < r) && (j <= r)); i++)
    {
        if (size[a[i]] > size[a[j]])
        {
            tmp = a[j];
            for (h = j; h > i; h--)
                a[h] = a[h - 1];
            a[i] = tmp;
            j++;
        }
    }
    
}

void MergeSort(int *a, ULONGLONG *size, int l, int r)
{
    int m;
    if (l >= r) return;
    m = (l + r) / 2;
    MergeSort(a, size, l, m);
    MergeSort(a, size, m + 1, r);
    Merge(a, size, l, m, r);
}

void main()
{
    int i = 0; 
    int count = 0;
    clock_t start, end;
    float allTime = 0.0f;
    int* ind; 
    int N = -1;
    ULONGLONG* size = (ULONGLONG*)malloc(sizeof(ULONGLONG) * MAX_LEN); ;
    wchar_t** name;
    char* a = (char*)malloc(MAX_LEN);
    wchar_t* sDir = (wchar_t*)malloc(MAX_LEN);

    do
    {
        if (N == 0)
            printf("Folder is Empty\n");
        printf("Enter the path to the folder\n");
        fgets(a, MAX_LEN, stdin);
        a[strlen(a) - 1] = '\0';
        swprintf(sDir, MAX_LEN, L"%hs", a); 
        N = ListDirectoryContents(sDir, size, &name);
    } while ((N == 0) || (N == -1));
       
    do
    { 
        count = 0;
        Command();
        ind = (int*)malloc(N * sizeof(int));
        for (i = 0; i < N; i++)
            ind[i] = i;  
        scanf("%d", &i);
        printf("\n");
        start = clock();
        switch (i) {
        case 1:
            ChooseSort(ind, size, N);
            break;
        case 2:
            InsertionSort(ind, size, N);
            break;
        case 3:
            BubbleSort(ind, size, N);
            break;
        case 4:
            count = CountingSort(ind, size, N);
            break;
        case 5:
            QuickSort(ind, size, 0, (N - 1));
            break;
        case 6:
            MergeSort(ind, size, 0, (N - 1));
            break;
        case 7:
            N = -1; 
            count = 1;
            scanf("%*c");
            do
            {
                if (N == 0)
                    printf("Folder is Empty\n");
                printf("Enter the path to the folder\n"); 
                fgets(a, MAX_LEN, stdin); 
                a[strlen(a) - 1] = '\0';
                swprintf(sDir, MAX_LEN, L"%hs", a); 
                N = ListDirectoryContents(sDir, size, &name);
            } while ((N == 0) || (N == -1));
            break;
        case 8:
            count = 1;
            break;
        }
        end = clock();
        allTime = (float)(end - start) / CLOCKS_PER_SEC;
        if (count == 0)
            Print(ind, size, name, N, allTime);
        free(ind);
    } while (i != 8); 

    for (i = 0; i < N; i++)
        free(name[i]);
    free(name);
    free(size);
    free(a);
    free(sDir);
}