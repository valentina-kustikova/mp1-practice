#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include"Sorts.h"

char names[LENGTH][LENGTH];
CHAR path[MAX_PATH];

long long int count = 0;

void findfiles(CHAR* path);

file_t* cpy_arr(file_t* files, int len, int* lensNames) {
    int i;
    file_t* copy_files;
    copy_files = (file_t*)malloc(len * sizeof(file_t));
    for (i = 0; i < len; i++) {
        copy_files[i].name = (char*)malloc((lensNames[i] + 1) * sizeof(char));
    }
    for (i = 0; i < len; i++) {
        strcpy(copy_files[i].name, files[i].name);
        copy_files[i].l = files[i].l;
    }

    return copy_files;
}

void StartTimer()
{
    LARGE_INTEGER A;
    QueryPerformanceCounter(&A);
    count = A.QuadPart;

}
void StopTimer()
{
    LARGE_INTEGER A;
    QueryPerformanceCounter(&A);
    printf("and spent %.2lf ms\n", (double)(A.QuadPart - count) / 1000);
}
void print_files(file_t* files, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%s %d\n", files[i].name, files[i].l);
    }
}


void findfiles(CHAR* path, file_t* filess)
{
    int i = 0;
    WIN32_FIND_DATAA files;
    HANDLE lastfile;
    lastfile = FindFirstFileA(path, &files);
    FindNextFileA(lastfile, &files);
    if (lastfile != INVALID_HANDLE_VALUE) {
        while (FindNextFileA(lastfile, &files)) {
            strcpy(filess[i].name, files.cFileName);
            filess[i].l = files.nFileSizeLow;
            i++;
        }
    }
    FindClose(lastfile);
}

int l_files(CHAR* path)
{
    int c = 0;
    WIN32_FIND_DATAA files;
    HANDLE lastfile;
    lastfile = FindFirstFileA(path, &files);
    FindNextFileA(lastfile, &files);
    if (lastfile != INVALID_HANDLE_VALUE) {
        while (FindNextFileA(lastfile, &files)) {
            c++;
        }
    }
    FindClose(lastfile);

    return c;
}

int* l_names_files(CHAR* path, int count_files)
{
    int i = 0;
    int* lens_names = (int*)malloc(count_files * sizeof(int));
    WIN32_FIND_DATAA files;
    HANDLE lastfile;
    lastfile = FindFirstFileA(path, &files);
    FindNextFileA(lastfile, &files);
    if (lastfile != INVALID_HANDLE_VALUE) {
        while (FindNextFileA(lastfile, &files)) {
            lens_names[i] = strlen(files.cFileName);
            i++;
        }
    }
    FindClose(lastfile);

    return lens_names;
}

int main()
{
    int n, i, count_files;
    int* lensNames;
    file_t* files;
    printf("Enter directory:");
    scanf("%s", &path);
    count_files = l_files(path);
    lensNames = l_names_files(path, count_files);

    files = (file_t*)malloc(count_files * sizeof(file_t));
    for (i = 0; i < count_files; i++) {
        files[i].name = (char*)malloc((lensNames[i] + 1) * sizeof(char));
    }

    printf("%d\n", count_files);
    findfiles(path, files);
    do {
        file_t* copy;
        printf("choose a sort\n");
        scanf("%d", &n);
        copy = cpy_arr(files, count_files, lensNames);
        StartTimer();
        if (n == 1) {
            mergeSort(copy, 0, i - 1);
            printf("MergeSort did this:\n");
        }
        else if (n == 2) {
            BubbleSort(copy, i);
            printf("BubbleSort did this:\n");
        }
        else if (n == 3) {
            QuickSort(copy, 0, i - 1);
            printf("QuickSort did this:\n");
        }
        else if (n == 0) {
            return 0;
        }
        print_files(copy, count_files);
        StopTimer();

    } while (1);

    for (i = 0; i < count_files; i++) {
        free(files[i].name);
    }
    free(files);
}
