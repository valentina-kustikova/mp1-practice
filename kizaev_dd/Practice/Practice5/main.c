#define _CRT_SECURE_NO_WARNINGS
#define UNICODE
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct 
{
    wchar_t name [2048];
    ULONGLONG size;
} files;

void getpath (wchar_t d[2048])
{
    char inp [2048];
    fgets (inp, sizeof(inp), stdin);
    inp[strlen(inp) - 1] = '\0';
    swprintf (d, 2048, L"%hs", inp);
}

void swapfiles (files *p, int i, int j)
{
    files tmp = p[i];
    p[i] = p[j];
    p[j] = tmp;
}

void outstraight (files *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        wprintf(L"%s ", p[i].name);
        printf ("(%d bytes)\n", p[i].size);
    }
    printf ("\n");
}

void outinverted (files *p, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        wprintf (L"%s ", p[i].name);
        printf ("(%d bytes)\n", p[i].size);
    }
    printf ("\n");
}

int CountFiles (const wchar_t *sDir) 
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL; 
    wchar_t sPath[2048]; 
    wsprintf(sPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE) 
    {    
        wprintf(L"Path not found: [%s]\n\n", sDir); 
        return -1; 
    }

    int nfiles = 0;
    do
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
            nfiles++;
    while(FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    return nfiles;
} 

void GetContent(const wchar_t *sDir, files *p) 
{ 
    WIN32_FIND_DATA fdFile;       
    HANDLE hFind = NULL;
    wchar_t sPath[2048]; 
    wsprintf(sPath, L"%s\\*.*", sDir); 
    if ((hFind = FindFirstFile(sPath, &fdFile)) != INVALID_HANDLE_VALUE) 
    { 
        int n = 0;
        do
        { 
            if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
            {
                                                                 
                ULONGLONG fileSize = fdFile.nFileSizeHigh;
                fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
                fileSize |= fdFile.nFileSizeLow;
                wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
                wsprintf(p[n].name, L"%s", sPath);
                p[n].size = fileSize;
                n++;
            }
        }
        while (FindNextFile(hFind, &fdFile));
        FindClose(hFind);
    }
}
// SORTINGS

void selection_sort (files *p, int n)
{
    int i, j, minidx;

    for (i = 0; i < n-1; i++)
    {
        minidx = i;
        for (j = i + 1; j < n; j++)
            if (p[j].size < p[minidx].size)
                minidx = j;

        if (minidx != i)
            swapfiles (p, i, minidx);
    }
}

void insertion_sort (files *p, int n)
{
    int i , j;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        files tmp = p[i];
        while ((p[j].size > tmp.size)  && (j >= 0))
        {
            p[j + 1] = p[j];
            p[j] = tmp;
            j--;
        }
    }
}

void bubble_sort (files *p, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 1; j < n - i; j++)
            if (p[j - 1].size > p[j].size)
                swapfiles (p, j, j-1);
}

void counting_sort (files *p, int n)
{
    int i, imax = 0, imin = 0;
    for (i = 1; i < n; i++)
    {
        if (p[i].size > p[imax].size)
            imax = i;
        if (p[i].size < p[imin].size)
            imin = i;
    }
    ULONGLONG min = p[imin].size;
    ULONGLONG max = p[imax].size;
    ULONGLONG range = max - min + 1;

    int *count = (int*) malloc (sizeof (int) * range);
    files *s = (files*)malloc(sizeof(files) * n);

    for (i = 0; i < range; i++)
        count[i] = 0;
    
    for (i = 0; i < n; i++)
        count[p[i].size - min]++;

    int sumprev = 0;

    for (i = 0; i < range; i++)
    {
        int current = count[i];
        count[i] = sumprev;
        sumprev += current;
    }

    for (i = 0; i < n; i++)
    {
        s[count[p[i].size - min]] = p[i];
        count[p[i].size - min]++;
    }  
    free (count);

    for (i = 0; i < n; i++)
        p[i] = s[i];
    free (s);
}

void quick_split (files *p, int *i, int *j, int m)
{
    do
    {
        while (p[*i].size < p[m].size)
            (*i)++;
        while (p[*j].size > p[m].size)
            (*j)--;
        if ((*i) <= (*j))
        {
            swapfiles (p, (*i), (*j));
            (*i)++;
            (*j)--;
        }
    }
    while ((*i) <= (*j));
}

void quick_sort (files *p, int left, int right)
{
    int m = (left + right) / 2;
    int i = left, j = right;

    quick_split (p, &i, &j, m);

    if (j > left)
        quick_sort(p, left, j);
    if (i < right)
        quick_sort(p, i, right);
}

void merge(files *p, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1, n2 = r - m; 
   
    files *L = (files*) malloc (sizeof (files)*n1);
    files *R = (files*) malloc (sizeof (files)*n2); 
  
    for (i = 0; i < n1; i++)
        L[i] = p[l + i];
    for (j = 0; j < n2; j++) 
        R[j] = p[m + 1+ j]; 
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i].size <= R[j].size) 
        { 
            p[k] = L[i]; 
            i++; 
        } 
        else
        { 
            p[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1)
    { 
        p[k] = L[i]; 
        i++; 
        k++; 
    }
    while (j < n2)
    { 
        p[k] = R[j]; 
        j++; 
        k++; 
    } 
    free (L);
    free (R);
} 

void merge_sort (files *p, int l, int r)
{
    if (l >= r) return;
    int m = (l+r) / 2;
    merge_sort (p, l, m);
    merge_sort (p, m+1, r);
    merge (p, l, m, r);
}

void main()
{
    printf ("### SIMPLE FILE MANAGER ###\n\n");
    wchar_t d[2048];
    int n, method = -1, flag = 0;
    
    do
    {    
        if (flag == 1)
        {
            getpath (d);
            flag--;
        }
        else
        {
            method = -1;
            do
            {
                printf ("Enter folder: \n");
                getpath (d);
                n = CountFiles (d);
            }
            while (n == -1);
			files *sorted = (files*)malloc(sizeof(files) * n);
           
            GetContent(d, sorted);
        
            wprintf (L"\nDirectory: %s \n\n", d);
            printf ("Files: \n");
            outstraight (sorted, n);

            while (method != 7)
            {    
                clock_t t1, t2;
    
                printf ("actions possible: \n");
                printf ("1 - bubble sort \n");
                printf ("2 - selection sort \n");
                printf ("3 - insertion sort \n");
                printf ("4 - counting sort \n");
                printf ("5 - quick sort \n");
                printf ("6 - merge sort \n");
                printf ("7 - change folder \n");
                printf ("0 - quit \n");
                printf ("\n");

                do
                    scanf ("%d", &method);
                while ((method > 7) || (method <0));
        
                printf ("\n");
            
                switch (method)
                {
                    case 0:
                        return;
                    break;

                    case 1:
                        t1 = clock();
                        bubble_sort (sorted, n);
                        t2 = clock();
                    break;

                    case 2:
                        t1 = clock();
                        selection_sort (sorted, n);
                        t2 = clock();
                    break;

                    case 3:
                        t1 = clock();
                        insertion_sort (sorted, n);
                        t2 = clock();
                    break;

                    case 4:
                        t1 = clock();
                        counting_sort (sorted, n);
                        t2 = clock();
                    break;

                    case 5:
                        t1 = clock();
                        quick_sort (sorted, 0, n);
                        t2 = clock();
                    break;

                    case 6:
                        t1 = clock();
                        merge_sort(sorted, 0, n);
                        t2 = clock();
                    break;

                    case 7:
                        flag = 1;
                    break;
                }

                if (method != 7)
                {
                    double t = (double) (t2-t1) / CLOCKS_PER_SEC;
                    int mode = -1;
            
                    printf ("choose sorting order \n");
                    printf ("1 - descending order \n");
                    printf ("2 - ascending order \n");
                    printf ("\n");
    
                    while ((mode > 2) || (mode < 1))
                        scanf ("%d", &mode);

                    printf ("\n");
                    if (mode == 1) 
                        outinverted (sorted, n);
                    if (mode == 2)
                        outstraight (sorted, n);

                    printf ("Time: %lf sec \n\n", t);
                }    
            }
            free (sorted);
        }
    }
    while (method != 0);
}