#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define MAX_PATH 1024

typedef struct {
    char name[MAX_PATH];
    UINT64 size;
} File;

int openfile(File files[], int maxFiles) {
    wchar_t directoryPath[MAX_PATH];
    printf("Enter the path to the directory: ");
    wscanf_s(L"%s", directoryPath, MAX_PATH);

    if (!SetCurrentDirectory(directoryPath)) {
        printf("  Directory not found\n Error code : % d\n", GetLastError());
        return 0;
    }

    WIN32_FIND_DATA findData;
    HANDLE findHandle = FindFirstFile(L"*.*", &findData);
    if (findHandle == INVALID_HANDLE_VALUE) {
        printf("Failed to find first file. Error code: %d\n", GetLastError());
        return 0;
    }
    int file_count = 0;
    do {
        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            strcpy_s(files[file_count].name, sizeof(files[file_count].name), (const char*)findData.cFileName);
            files[file_count].size = findData.nFileSizeLow;
            file_count++;
        }
    } while (FindNextFile(findHandle, &findData) != 0 && file_count < maxFiles);
    FindClose(findHandle);

    return file_count;
}

void print(File files[], int file_count) {
    for (int i = 0; i < file_count; i++) {
        printf("Name: %s  Size: %llu\n", files[i].name, files[i].size);
    }
}

void selection(File files[], int file_count) {
    int minind, n;
    clock_t start, end;
    start = clock();
    for (int i = 0; i < file_count; i++) {
        minind = i;
        for (int j = (i + 1); j < file_count; j++) {
            if (files[j].size < files[minind].size ) {
                minind = j;
            }
        }
        if (minind != i) {
            File sup = files[minind];
            files[minind] = files[i];
            files[i] = sup;
        }
    }
    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time: %f sec\n", cpu_time_used);
    print(files, file_count);
}

void insert(File files[], int file_count)
{
    clock_t start, end;
    start = clock();
    for (int i = 1; i < file_count; i++) {
        File min = files[i];
        int j = i - 1;
        while ((j >= 0) && (files[j].size > min.size)) {
            files[j + 1] = files[j];
            j--;
        }
        files[j + 1] = min;
    }
    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time: %f sec\n", cpu_time_used);
    print(files, file_count);
}

void merge(File files[], int left, int mid, int right, File temp[]) {
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (files[i].size <= files[j].size) {
            temp[k++] = files[i++];
        }
        else {
            temp[k++] = files[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = files[i++];
    }
    while (j <= right) {
        temp[k++] = files[j++];
    }
    for (i = left, k = 0; i <= right; i++, k++) {
        files[i] = temp[k];
    }
}

void mergeSortRecursive(File files[], int left, int right, File temp[]) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortRecursive(files, left, mid, temp);
    mergeSortRecursive(files, mid + 1, right, temp);
    merge(files, left, mid, right, temp);
}

void mergeSort(File files[], int file_count) {
    clock_t start, end;
    start = clock();
    File* temp = (File*)malloc(file_count * sizeof(File));
    mergeSortRecursive(files, 0, file_count - 1, temp);
    free(temp);
    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time: %f sec\n", cpu_time_used);
    print(files, file_count);
}


int main() {
    File files[100];
    File files_new[100];
    int rep;
    int file_count = 0;
    do {
        if (file_count == 0) {
            file_count = openfile(files, 100);
            print(files,file_count);
            if (file_count == 0) {
                printf("No files found for sorting\n");
                return 1;
            }
        }
        for (int i = 0; i < file_count; i++) {
            files_new[i] = files[i];
        }
        int method;
        printf("Methods of sort:\n 1 - selection sort\n 2 - insertion sort\n 3 - merge sort\n");
        printf("Input method: ");
        scanf_s("%d", &method);
        if (method == 1) { selection(files, file_count); }
        else if (method == 2) { insert(files, file_count); }
        else if (method == 3) { mergeSort(files, file_count); }
        else { printf("Invalid sorting method\n"); }
        printf("Repeat?(1-yes,0-no)\n");
        scanf_s("%d", &rep);
        for (int j = 0; j < file_count; j++)
        {
            files[j] = files_new[j];
        }
        print(files, file_count);
    } while (rep == 1);
    return 0;
}
