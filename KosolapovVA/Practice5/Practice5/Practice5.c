#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <fileapi.h>
#include <string.h>
#include <time.h>

#define MAX_LEN_PATH 1023
#define G 5

char* size[G] = {"Byte", "Kb", "Mb", "Gb", "Tb"};
typedef struct
{
    char* name;
    long size;
} f_arr;

void take_path(char* pt, int* f);
void path_adapting(char* path);
int count_files(char* path);
f_arr* take_f_path(char* path, int cfp);
int take_metod();
int* take_ind_arr(int cfp);
void bubble_sort(f_arr* Arr, int* ind, int cfp);
void insert_sort(f_arr* Arr, int* ind, int cfp);
void quick_sort(f_arr* Arr, int* ind, int left, int right);
void swap(int* x, int* y);
void pr_files(int* ind, f_arr* Copy_Arr, int cfp);

int main()
{
    system("chcp 1251");
    
    do
    {
        f_arr* files_arr;
        char path[MAX_LEN_PATH];
        int flag = -1, count_f_p, i = 0;
        clock_t t_start, t_finish;
        double time;
        take_path(&path, &flag);
        path_adapting(&path);
        if (flag == 0)
        {
            printf("End");
            break;
        }
        count_f_p = count_files(&path);
        if (count_f_p == -1)
        {
            printf("The directory does not exist. Try again\n");
            continue;
        }
        if (count_f_p == 0)
        {
            printf("The directory is empty\n");
            continue;
        }
        files_arr = take_f_path(&path, count_f_p);
        do {
            int metod = take_metod();
            if (metod == 0)
            {
                break;
            }
            int* ind_arr;
            ind_arr = take_ind_arr(count_f_p);
            switch (metod)
            {
            case 1:
                t_start = clock();
                bubble_sort(files_arr, ind_arr, count_f_p);
                t_finish = clock();
                time = (double)((t_finish - t_start)) / CLOCKS_PER_SEC;
                pr_files(ind_arr, files_arr, count_f_p);
                printf("Sorting time: %.6g seconds\n", time);
                break;
            case 2:
                t_start = clock();
                insert_sort(files_arr, ind_arr, count_f_p);
                t_finish = clock();
                time = (double)((t_finish - t_start)) / CLOCKS_PER_SEC;
                pr_files(ind_arr, files_arr, count_f_p);
                printf("Sorting time: %.6g seconds\n", time);
                break;
            case 3:
                t_start = clock();
                quick_sort(files_arr, ind_arr, 0, count_f_p-1);
                t_finish = clock();
                time = (double)((t_finish - t_start)) / CLOCKS_PER_SEC;
                pr_files(ind_arr, files_arr, count_f_p);
                printf("Sorting time: %.6g seconds\n", time);
                break;
            }
            free(ind_arr);
        } while (1);
        for (i = 0; i < count_f_p; i++)
        {
            free(files_arr[i].name);
        }
        free(files_arr);
    } while (1);
    return 0;
}

void take_path(char* pt, int* f)
{
    printf("1) Enter the path to the directory:\n");
    printf("2) Enter 0 if you want to finish:  \n");
    scanf("%s", pt);
    if (pt[0] == '0')
    {
        *f = 0;
    }
}
void path_adapting(char* path)
{
    int ln = strlen(path);
    if (path[ln - 1] != '*') {
        path[ln] = '\\';
        path[ln + 1] = '*';
        path[ln + 2] = '\0';
    }
}
int count_files(char* path)
{
    WIN32_FIND_DATAA fdata;
    HANDLE hFind = FindFirstFileA(path, &fdata);
    int count = -1;
    while (FindNextFileA(hFind, &fdata) != NULL)
    {
        if ((strcmp(fdata.cFileName, "..") == 0))
        {
            count = 0;
        }
        if ((strcmp(fdata.cFileName, ".") != 0) && (strcmp(fdata.cFileName, "..") != 0))
        {
            count++;
        }
    }
    FindClose(hFind);
    return count;
}
f_arr* take_f_path(char* path, int cfp)
{
    int i = 0;
    f_arr* Arr;
    WIN32_FIND_DATAA fdata;
    HANDLE hFind = FindFirstFileA(path, &fdata);
    Arr = (f_arr*)malloc(cfp * sizeof(f_arr));
    while (FindNextFileA(hFind, &fdata) != NULL)
    {
        if ((strcmp(fdata.cFileName, ".") != 0) && (strcmp(fdata.cFileName, "..") != 0))
        {
            char* filename = fdata.cFileName;
            long filesize = fdata.nFileSizeLow;
            Arr[i].name = _strdup(fdata.cFileName);
            Arr[i].size = filesize;
            i++;
        }
    }
    FindClose(hFind);
    return Arr;
}
int take_metod()
{
    int m;
    printf("Select the sorting method: 1)bubble, 2)inserts, 3)quick\n");
    printf("Enter 0 if you want to change the directory:  \n");
    scanf("%d", &m);
    while (m < 0 || m >3)
    {
        printf("Error, try again");
        scanf("%d", &m);
    }
    return m;
}
int* take_ind_arr(int cfp)
{
    int i = 0;
    int* a;
    a = (int*)malloc(cfp * sizeof(int));
    for (; i < cfp; i++)
    {
        a[i] = i;
    }
    return a;
}
void bubble_sort(f_arr* Arr, int* ind, int cfp)
{
    int i, j, k;
    for (i = 0; i < cfp; i++)
    {
        for (j = (cfp - 1); j > i; j--)
        {
            if (Arr[ind[j]].size < Arr[ind[j - 1]].size)
            {
                k = ind[j];
                ind[j] = ind[j - 1];
                ind[j - 1] = k;
            }
        }
    }
}
void insert_sort(f_arr* Arr, int* ind, int cfp)
{
    int i, j, k;
    for (i = 1; i < cfp; i++)
    {
        k = ind[i];
        j = i;
        while ((j > 0) && (Arr[k].size < Arr[ind[j-1]].size))
        {
            ind[j] = ind[j-1];
            j--;
        }
        ind[j] = k;
    }
}
void quick_sort(f_arr* Arr, int* ind, int left, int right)
{
    int pivot, left_h = left, right_h = right;
    pivot =ind[left];
    while (left < right)
    {
        while ((Arr[ind[right]].size >= Arr[pivot].size) && (left < right))
        {
            right--;
        }
        if (left != right)
        {
            ind[left] = ind[right];
            left++;
        }
        while ((Arr[ind[left]].size <= Arr[pivot].size) && (left < right))
        {
            left++;
        }
        if (left != right)
        {
            ind[right] = ind[left];
            right--;
        }
    }
    ind[left] = pivot;
    pivot = left;
    left = left_h;
    right = right_h;
    if (left < pivot)
    {
        quick_sort(Arr, ind, left, pivot - 1);
    }
    if (right > pivot)
    {
        quick_sort(Arr, ind, pivot+1, right);
    }
}
void swap(int* x, int* y)
{
    int tmp = 0;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
void pr_files(int* ind, f_arr* Copy_Arr, int cfp)
{
    int i = 0,s, temp;
    double tmp;
    for (; i < cfp; i++)
    {
        s = 0;
        temp = Copy_Arr[ind[i]].size;
        tmp = (double)temp;
        printf("|%s       |", Copy_Arr[ind[i]].name);
        while (tmp/1024>=1)
        {
            tmp = tmp / 1024;
            s++;
        }
        printf("%.3f %s \n", tmp, size[s]);
    }
}
