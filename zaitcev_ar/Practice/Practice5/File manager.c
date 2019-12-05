#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#define BUFFER 1000
#define N 1500

void Input(wchar_t **path)
{
    char *str;

    *path = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
    str = (char*)malloc(BUFFER * sizeof(char));
    printf("\n  Please, enter the path:  ");
    fgets(str, BUFFER, stdin); 
    str[strlen(str) - 1] = '\0';
    swprintf(*path, BUFFER, L"%hs", str);
}

int ListDirectoryContetns(const wchar_t *sDir, wchar_t ***fNames, ULONGLONG **fSizes)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    int i = 0;
    wchar_t *sPath;
    sPath = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));

    wsprintf(sPath, L"%s\\*.*", sDir);

    // Check of existence of the directory
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
        return -1; 

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
            i++;
    } while (FindNextFile(hFind, &fdFile));

    hFind = FindFirstFile(sPath, &fdFile);
    *fNames = (wchar_t**)malloc(i * sizeof(wchar_t*));
    *fSizes = (ULONGLONG*)malloc(i * sizeof(ULONGLONG));
    i = 0;

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fSize = fdFile.nFileSizeHigh;
            fSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fSize |= fdFile.nFileSizeLow;

            (*fNames)[i] = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
            (*fSizes)[i] = fSize;
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf((*fNames)[i], L"%s", sPath);
            i++;
        }
    } while (FindNextFile(hFind, &fdFile));
    return i;
    FindClose(hFind);
    free(sPath);
}

void Output(int *ind, int count_files, wchar_t **fNames, ULONGLONG *size)
{
    int i;
    WIN32_FIND_DATA fdFile;
    for (i = 0; i < count_files; i++)
    {
        wprintf(L"  %s\t  %.0llf kb \n", fNames[ind[i]], ceil((float)(*(size + ind[i]) / 1024.0)));
    }
    printf("\n");
}

void Choose_Sort(int count_files, ULONGLONG *size, int *ind)
{
    int i = 0, j = 0, k = 0, t = 0;
    long min;

    for (i = 0; i < count_files - 1; i++)
    {
        k = i;
        for (j = i + 1; j < count_files; j++)
        {
            if (size[ind[k]] > size[ind[j]])
            {
                k = j;
            }
        }
        t = ind[k];
        ind[k] = ind[i];
        ind[i] = t;
    }
}

void Insert_Sort(ULONGLONG *size, int count_files, int *ind)
{
    int k, i, j;
    for (i = 1; i < count_files; i++)
    {
        k = ind[i];
        j = i - 1;
        while((j >= 0) && (size[ind[j]] > size[k]))
        {
            ind[j + 1] = ind[j];
            ind[j] = k;
            j--;
        }
    }
}

void Bubble_Sort(ULONGLONG *size, int count_files, int *ind)
{
    int i, j, k;
    for (i = 0; i < count_files; i++)
    {
        for (j = 1; j < count_files - i; j++)
        {
            if (size[ind[j]] < size[ind[j - 1]])
            {
                k = ind[j];
                ind[j] = ind[j - 1];
                ind[j - 1] = k;
            }
        }
    }

}

int Count_Sort(ULONGLONG *size, int count_files, int *ind)
{
    int *count = (int*)malloc(N * sizeof(int));
    int i, j, id = 0, idel = 0;
    int del = 0, min, max, pos = 0;

    min = size[0];
    max = size[0];

    for (i = 0; i < count_files; i++)
    {
        if ((size[i]) < min)
        {
            min = size[i];
        }
        if ((size[i]) > max)
        {
            max = size[i];
        }
    }
    del = max - min + 1;
    idel = (int)del;
    for (i = 0; i < count_files; i++)
    {
    if (size[i] > N)
        return -1;
    }

    for (i = 0; i < idel; i++)
    {
        if (count[i]>0)
        {
            pos = 0;
            for (j = 0; j < count[i]; j++)
            {
                while (size[pos] != i)
                {
                    pos++;
                }
                ind[id] = pos;
                pos++;
                id++;
            }
        }
    }

    free(count);
}

void Quick_Split(int *ind, ULONGLONG *size, int *i, int *j, ULONGLONG p)
{
    int tmp;
    do {
        while (size[ind[(*i)]] < p)
        {
            (*i)++;
        }
        while (size[ind[(*j)]] > p)
        {
            (*j)--;
        }
        if ((*i) <= (*j))
        {
            tmp = ind[(*i)];
            ind[(*i)] = ind[(*j)];
            ind[(*j)] = tmp;
            (*i)++;
            (*j)--;
        }
    } while ((*i) < (*j));
}

void Quick_Sort(ULONGLONG *size, int *ind, int n1, int n2)
{
    int mid = (n1 + n2) / 2;
    int i = n1, j = n2;
    Quick_Split(ind, size, &i, &j, size[ind[mid]]);
    if (j > n1)
    {
        Quick_Sort(size, ind, n1, j);
    }
    if (i < n2)
    {
        Quick_Sort(size, ind, i, n2);
    }
}

void Merge(ULONGLONG *size, int lb, int mid, int ub, int *ind)
{
    int i, j = mid + 1;
    int pos, tmp;
    for (i = lb; ((i < ub) && (j <= ub)); i++)
    {
        if (size[ind[i]] > size[ind[j]])
        {
            tmp = ind[j];
            for (pos = j; pos > i; pos--)
            {
                ind[pos] = ind[pos - 1];
            }
            ind[i] = tmp;
            j++;
        }
    }
}

void Merge_Sort(ULONGLONG *size, int lb, int ub, int *ind)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        Merge_Sort(size, lb, mid, ind);
        Merge_Sort(size, mid + 1, ub, ind);
        Merge(size, lb, mid, ub, ind);
    }
}

void main()
{
    int baz = 0;
    wchar_t *path;
    wchar_t **fNames;
    ULONGLONG *fSizes;
    int count_files = 0;
    int method, i = 0;
    int *ind = NULL;
    clock_t begin, end;
    double time_spent = 0;
    setlocale(LC_ALL, "Russian");

    fNames = (wchar_t**)malloc(MAX_PATH * sizeof(wchar_t*));
    fSizes = (ULONGLONG*)malloc(MAX_PATH * sizeof(ULONGLONG));

    printf("  oooooooooooooooooooooooooooooooooooooo\n");
    printf("  O\t      -FILE MANAGER-           O\n");
    printf("  oooooooooooooooooooooooooooooooooooooo\n");

    // Enter of path with the keyboard
    do
    {
        Input(&path);
        count_files = ListDirectoryContetns(path, &fNames, &fSizes);

        if (count_files == -1)
        {
            printf("  Path not found");
            continue;
        }
        if (count_files == 0)
        {
            printf("  Folder is empty");
            continue;
        }

        printf("  Files found:  %d\n\n", count_files);

        ind = (int*)malloc(count_files * sizeof(int));
        i = 0;
        while (i != count_files)
        {
            ind[i] = i;
            i++;
        }

        printf("\n Choose method of sort:\n");
        printf(" 1) Choose Sort\n 2) Insert Sort\n 3) Bubble Sort\n 4) Count Sort\n 5) Quick Sort\n 6) Merge Sort\n\n");
        do{
            printf(" Method: ");
            scanf("%d", &method);
            printf("\n");
        }while ((method != 1) && (method != 2) && (method != 3) && (method != 4) && (method != 5) && (method != 6));

        begin = clock();
        switch (method)
        {
        case(1):
        {
            Choose_Sort(count_files, fSizes, ind);
            Output(ind, count_files, fNames, fSizes);
            break;
        }
        case(2):
        {
            Insert_Sort(fSizes, count_files, ind);
            Output(ind, count_files, fNames, fSizes);
            break;
        }
        case(3):
        {
            Bubble_Sort(fSizes, count_files, ind);
            Output(ind, count_files, fNames, fSizes);
            break;
        }
        case(4):
        {
            baz = Count_Sort(fSizes, count_files, ind);
            if (baz == -1)
            {
                printf("  File sizes are too large for this sort, please choose another sort\n");
                break;
            }
            Output(ind, count_files, fNames, fSizes);
            break;
        }
        case(5):
        {
            Quick_Sort(fSizes, ind, 0, count_files - 1);
            Output(ind, count_files, fNames, fSizes);
            break;
        }
        case(6):
        {
            Merge_Sort(fSizes, 0, count_files - 1, ind);
            Output(ind, count_files, fNames, fSizes);
            break;
        }
        }
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("  Sorting time: %.3f cek\n\n", time_spent);

        getchar();
        free(ind);
        for (i = 0; i < count_files; i++)
            free(fNames[i]);
        free(fNames);
        free(fSizes);
    } while (1);
}