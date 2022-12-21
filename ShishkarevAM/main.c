/*
 * Разработать прототип файлового менеджера,
 * с функцией показа файлов,
 * упорядоченных по размеру
 *
 * Входные данные:
 * Путь до файла
 * Метод сортировка
 *
 * Выходные данные:
 * Отсортированный список имен файлов (с указанием размера)
 * Время сортировки
 *
 * Программа должна предоставлять пользователю возможность изменить
 * метод сортировки и повторно сформировать выходние данные
 * Программа должна реализовывать диалог с пользователем посредством
 * интерфейса:
 * Возможность ввода пути до заданного каталога
 * Возможность выбора метода сортировки
 * Возможность просмотра списка отсортированных файлов с временем выполнения
 *
 * Сортировки:
 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include "omp.h"
char path[200];


void InsertSort(struct _finddata_t* arr, long size);
void merge(struct _finddata_t* arr, long size);
void mergeSort(struct _finddata_t* arr, long size);
void QuickSort(struct _finddata_t* arr, long size);
long increment(long inc[], long size);
char GetPath();
int GetMode();
void GetSorted(struct _finddata_t* arr, long size);
void GetResorted(struct _finddata_t* arr, long size);
enum ModeSort
{
    Insert = 1, Merge = 2, Quick = 3, ChangeDir = 4, ExProg = 5
};

void main(void)
{
    setlocale(LC_ALL, "Rus");
    struct _finddata_t c_file;
    struct _finddata_t* directory;
    struct _finddata_t* time_arr;
    intptr_t hFile;
    double start, stop;
    char  mode;
    int next;
    system("title File sorter");
    printf("Welcome to the program for sorting files in many ways!\n");
    while (1)
    {
        printf("Input format : c:/TestFolder/\n");
        long count = 0;
        long size = 0;
        char ch;
        while (1)
        {
            printf("Enter the path to the folder:\n");
            fgets(path, 200, stdin);
            path[strlen(path) - 1] = '\0';
            strcat_s(path,200, "*.*");
            if ((hFile = _findfirst(path, &c_file)) == -1L)
            {
                printf("Enter the path to the folder: There are no files in the folder or the path is incorrect\n");
                system("pause");
            }
            else
            {
                do
                {
                    if (c_file.size > 0)
                        size++;
                } while (_findnext(hFile, &c_file) == 0);

                directory = calloc(size, sizeof(struct _finddata_t));
                hFile = _findfirst(path, &c_file);
                do
                {
                    if (c_file.size > 0)
                        directory[count++] = c_file;
                } while (_findnext(hFile, &c_file) == 0);
                _findclose(hFile);
                break;
            }
        }
        time_arr = calloc(size, sizeof(struct _finddata_t));
        for (long i = 0; i < size; i++)
            time_arr[i] = directory[i];
        system("cls");
        GetSorted(directory, size);
        system("pause");
        newsort:
        mode = GetMode();
        system("cls");
        start = omp_get_wtime();
        switch (mode) {
            case Insert:
                InsertSort(time_arr, size);
                break;
            case Merge:
                mergeSort(time_arr,0, size-1);
                break;
            case Quick:
                QuickSort(time_arr, size);
                break;
            case ChangeDir:
                printf("You decide to change the directory.\n");
                break;
            case ExProg:
                free(directory);
                free(time_arr);
                printf("Thanks for choosing the program! Have a good day!\n");
                system("pause");
                exit(0);
            default:
                goto newsort;
        }
        stop = omp_get_wtime();
        if (mode != ChangeDir) {
            system("cls");
            printf("Do you want to sort the array in ascending or descending order?\n");
            printf("1. Sort ascending\n");
            printf("2. Sort in descending order\n");
            next = getch();
            switch (next)
            {
                case '1':
                    system("cls");
                    GetSorted(time_arr,size);
                    break;
                case '2':
                    system("cls");
                    GetResorted(time_arr,size);
                    break;
                default:
                    system("cls");
                    printf("Invalid option selected, back to sort selection.\n");
                    goto newsort;
                    break;
            }
            printf("Sort time: %.4lf ms\n", (stop - start)*1000);
            system("pause");
            system("cls");
            printf("Select next action\n\n");
            printf("1. Change sorting method\n");
            printf("2. Change directory\n");
            printf("3. Exit program\n");
            next = getch();
            switch (next)
            {
                case '1':
                    system("cls");
                    goto newsort;
                    break;
                case '2':
                    system("cls");
                    printf("You have decided to change directory.\n");
                    system("pause");
                    system("cls");
                    break;
                case '3':
                    free(directory);
                    free(time_arr);
                    system("cls");
                    printf("Thank you for choosing the program! Have a great day!\n");
                    system("pause");
                    exit(0);
                default:
                    system("cls");
                    printf("Invalid option selected, back to sort selection.\n");
                    goto newsort;
                    break;
            }
        }
        free(time_arr);
    }
}
void GetSorted(struct _finddata_t* arr, long size) {
    printf("File name\t\t File size\n\n");
    for (int i = 0; i < size; i++) {
        printf("%-25.10s   %-5lld\n", arr[i].name, arr[i].size);
    }
}
void GetResorted(struct _finddata_t* arr, long size) {
    printf("File name\t\t File size\n\n");
    for (int i = size-1; i > -1; i--) {
        printf("%-25.10s   %-5lld\n", arr[i].name, arr[i].size);
    }
}
char GetPath() {
    char path[100],dop="\\*.*";
    int c = 100;
    printf("Enter the path to the folder ");
    fgets(path,c,stdin);
    strcat(path, dop);
    return path;
}

int GetMode() {
    int mode;
    char answ;
    system("cls");
    printf("Select the desired function\n");
    printf("1. Sort \"Inserts\"\n");
    printf("2. Sort by \"Merge\"\n");
    printf("3. Sort \"Hoare\"\n");
    printf("4. Change directory\n");
    printf("5. Program exit\n");
    mode = getch();
    answ = mode - '0';
    return answ;
}
void InsertSort(struct _finddata_t* arr, long size)
{
    int newElement, location;
    for (int i = 1; i < size; i++)
    {
        newElement = arr[i].size;
        location = i - 1;
        while (location >= 0 && arr[location].size > newElement)
        {
            arr[location + 1] = arr[location];
            location = location - 1;
        }
        arr[location + 1].size = newElement;
    }
}
void merge(struct _finddata_t* a, long lb, long split, long ub)
{
    long pos1 = lb;
    long pos2 = split + 1;
    long pos3 = 0;
    struct _finddata_t* temp = malloc(sizeof(struct _finddata_t) * (ub - lb + 1));
    while (pos1 <= split && pos2 <= ub)
    {
        if (a[pos1].size < a[pos2].size)
            temp[pos3++] = a[pos1++];
        else
            temp[pos3++] = a[pos2++];
    }
    while (pos2 <= ub)
        temp[pos3++] = a[pos2++];
    while (pos1 <= split)
        temp[pos3++] = a[pos1++];
    for (pos3 = 0; pos3 < ub - lb + 1; pos3++)
        a[lb + pos3] = temp[pos3];

    free(temp);
}
void mergeSort(struct _finddata_t* a[], long lb, long ub)
{
    long split;

    if (lb < ub)
    {
        split = (lb + ub) / 2;
        mergeSort(a, lb, split);
        mergeSort(a, split + 1, ub);
        merge(a, lb, split, ub);
    }
}
void QuickSort(struct _finddata_t* arr, long size)
{
    long i = 0, j = size-1;
    struct _finddata_t* temp, p;
    p = arr[size >> 1];
    do {
        while (arr[i].size < p.size) i++;
        while (arr[j].size > p.size) j--;
        if (i <= j) {
            temp = arr[i].size;
            arr[i] = arr[j];
            arr[j].size = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) QuickSort(arr, j);
    if (size > i) QuickSort(arr + i, size - i);
}

