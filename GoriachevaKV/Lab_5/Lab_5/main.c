#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#define MAX_FILES 100

#define CHOICE_SORTING_METHOD_TEXT "\
Choose a sorting method:\n\
1. Simple sort\n\
2. Choose sort\n\
3. Bubble sort\n\
4. Insert sort\n\
5. Merge sort\n\
6. Quick sort\n\n\
Input number of your choice: "

#define CHOICE_SORT_BY_TEXT "\
Sort by:\n\
1. Increasing\n\
2. Descending\n\n\
Input number of your choice: "

//dirs for check
//D:\test\test_dir_1
//D:\test\test_dir_2

typedef struct {
    char name[MAX_PATH];
    long size;
} FileInfo;

FileInfo files[MAX_FILES];

int file_count = 0;

//sortings prototypes
void simple_sort(int sort_by);
void choose_sort(int sort_by);
void bubble_sort(int sort_by);
void insert_sort(int sort_by);
void mergeSort(FileInfo files[], int left, int right, int sort_by);
void merge(FileInfo files[], int left, int mid, int right, int sort_by);
void quick_sort(FileInfo files[], int l, int r, int sort_by);

//functions prototypes
void dir_query(char path[]);
void choose_sorting(int sorting_method, int sort_by);
void print_output(char path[], FileInfo files[], double total_time);


//main code
int main() {
    int sorting_method = 0, sort_by = 0;
    char path[MAX_PATH], search_path[MAX_PATH];
    double total_time;
    LARGE_INTEGER start_time, end_time, frequency;
    QueryPerformanceFrequency(&frequency);

    printf("WELCOME TO FILE EXPLORER!\n\n");

    dir_query(path);

    snprintf(search_path, sizeof(search_path), "%s\\*", path);
    WIN32_FIND_DATAA file_data;
    HANDLE hFind = FindFirstFileA(search_path, &file_data);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Error reading directory\n");
        return;
    }

    do {
        if (!(file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            strcpy_s(files[file_count].name, sizeof(files[file_count].name), file_data.cFileName);
            files[file_count].size = (long)file_data.nFileSizeLow + ((long)file_data.nFileSizeHigh << 32);
            file_count++;
        }
    } while (FindNextFileA(hFind, &file_data) && file_count < MAX_FILES);

    FindClose(hFind);

    do {
        printf(CHOICE_SORTING_METHOD_TEXT);
        scanf_s("%d", &sorting_method);
        if (sorting_method < 1 || sorting_method > 6) {
            printf("Wrong input! Try again.\n");
        }
    } while (sorting_method < 1 || sorting_method > 6);

    do {
        printf(CHOICE_SORT_BY_TEXT);
        scanf_s("%d", &sort_by);
        if (sort_by < 1 || sort_by > 2) {
            printf("Wrong input! Try again.\n");
        }
    } while (sort_by < 1 || sort_by > 2);

    QueryPerformanceCounter(&start_time);
    choose_sorting(sorting_method, sort_by);
    QueryPerformanceCounter(&end_time);

    total_time = (double)(end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart;

    print_output(path, files, total_time);
    return 0;
}


//sortings
void simple_sort(int sort_by) {
    int i, j;
    switch (sort_by) {
    case 1:
        for (i = 0; i < file_count; i++) {
            for (j = i + 1; j < file_count; j++) {
                if (files[i].size > files[j].size) {
                    FileInfo buff = files[i];
                    files[i] = files[j];
                    files[j] = buff;
                }
            }
        }
        break;
    case 2:
        for (i = 0; i < file_count; i++) {
            for (j = i + 1; j < file_count; j++) {
                if (files[i].size < files[j].size) {
                    FileInfo buff = files[i];
                    files[i] = files[j];
                    files[j] = buff;
                }
            }
        }
        break;
    }
}

void choose_sort(int sort_by) {
    int i, j;
    switch (sort_by) {
    case 1:
        for (i = 0; i < file_count; i++) {
            int min = files[i].size, ind = i;
            FileInfo min_str = files[i];
            for (j = i + 1; j < file_count; j++) {
                if (min > files[j].size) {
                    min = files[j].size;
                    min_str = files[j];
                    ind = j;
                }
            }
            files[ind] = files[i];
            files[i] = min_str;
            files[i].size = min;
        }
        break;
    case 2:
        for (i = 0; i < file_count; i++) {
            int max = files[i].size, ind = i;
            FileInfo max_str = files[i];
            for (j = i + 1; j < file_count; j++) {
                if (max < files[j].size) {
                    max = files[j].size;
                    max_str = files[j];
                    ind = j;
                }
            }
            files[ind] = files[i];
            files[i] = max_str;
            files[i].size = max;
        }
        break;
    }
}

void bubble_sort(int sort_by) {
    int i, j;
    switch (sort_by) {
    case 1:
        for (i = 0; i < file_count; i++) {
            for (j = 0; j < file_count; j++) {
                if (files[j + 1].size < files[j].size) {
                    FileInfo tmp = files[j];
                    files[j] = files[j + 1];
                    files[j + 1] = tmp;
                }
            }
        }
        break;
    case 2:
        for (i = 0; i < file_count; i++) {
            for (j = 0; j < file_count; j++) {
                if (files[j + 1].size > files[j].size) {
                    FileInfo tmp = files[j];
                    files[j] = files[j + 1];
                    files[j + 1] = tmp;
                }
            }
        }
    }
}

void insert_sort(int sort_by) {
    int i;
    switch (sort_by) {
    case 1:
        for (i = 0; i < file_count; i++) {
            int j = i - 1;
            FileInfo tmp = files[i];
            while (j >= 0 && files[j].size > tmp.size) {
                files[j + 1] = files[j];
                j--;
            }
            files[j + 1] = tmp;
        }
        break;
    case 2:
        for (i = 0; i < file_count; i++) {
            int j = i - 1;
            FileInfo tmp = files[i];
            while (j >= 0 && files[j].size < tmp.size) {
                files[j + 1] = files[j];
                j--;
            }
            files[j + 1] = tmp;
        }
        break;
    }
}

//merge_sort
void mergeSort(FileInfo files[], int left, int right, int sort_by) {
    switch (sort_by) {
    case 1:
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(files, left, mid, sort_by);
            mergeSort(files, mid + 1, right, sort_by);
            merge(files, left, mid, right, sort_by);
        }
        break;
    case 2:
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(files, left, mid, sort_by);
            mergeSort(files, mid + 1, right, sort_by);
            merge(files, left, mid, right, sort_by);
        }
        break;
    }
}

void merge(FileInfo files[], int left, int mid, int right, int sort_by) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    FileInfo* leftArr = (FileInfo*)malloc(n1 * sizeof(FileInfo));
    FileInfo* rightArr = (FileInfo*)malloc(n2 * sizeof(FileInfo));
    for (i = 0; i < n1; i++)
        leftArr[i] = files[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = files[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    switch (sort_by) {
    case 1:
        while (i < n1 && j < n2) {
            if (leftArr[i].size <= rightArr[j].size) {
                files[k] = leftArr[i];
                i++;
            }
            else {
                files[k] = rightArr[j];
                j++;
            }
            k++;
        }
        break;
    case 2:
        while (i < n1 && j < n2) {
            if (leftArr[i].size >= rightArr[j].size) {
                files[k] = leftArr[i];
                i++;
            }
            else {
                files[k] = rightArr[j];
                j++;
            }
            k++;
        }
        break;
    }

    while (i < n1) {
        files[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        files[k] = rightArr[j];
        j++;
        k++;
    }
    free(leftArr);
    free(rightArr);
}

void quick_sort(FileInfo files[], int l, int r, int sort_by) {
    int i = l, j = r;
    FileInfo x = files[(l + r) / 2];
    switch (sort_by) {
    case 1:
        do {
            while (files[i].size < x.size) i++;
            while (files[j].size > x.size) j--;

            if (i <= j) {
                if (files[i].size > files[j].size) {
                    FileInfo tmp = files[i];
                    files[i] = files[j];
                    files[j] = tmp;
                }
                i++;
                j--;
            }
        } while (i <= j);

        if (i < r) {
            quick_sort(files, i, r, sort_by);
        }
        if (l < j) {
            quick_sort(files, l, j, sort_by);
        }
        break;
    case 2:
        do {
            while (files[i].size > x.size) i++;
            while (files[j].size < x.size) j--;

            if (i <= j) {
                if (files[i].size < files[j].size) {
                    FileInfo tmp = files[i];
                    files[i] = files[j];
                    files[j] = tmp;
                }
                i++;
                j--;
            }
        } while (i <= j);

        if (i < r) {
            quick_sort(files, i, r, sort_by);
        }
        if (l < j) {
            quick_sort(files, l, j, sort_by);
        }
        break;
    }
}


//functions
void dir_query(char path[]) {
    int path_obtained = 1;
    do {
        printf("Input a path to a directory you want to get list of files from: ");
        
        if ((fgets(path, MAX_PATH, stdin)) == NULL) {
            path_obtained = 0;
            printf("Wrong input! Try again.\n\n");
            continue;
        }
        path[strcspn(path, "\n")] = '\0'; //remove \n

        if (strlen(path) == 0) {
            path_obtained = 0;
            printf("The path is empty. Try again.\n\n");
        }
    } while (path_obtained == 0);
}


void choose_sorting(int sorting_method, int sort_by) {
    switch (sorting_method) {
    case 1:
        simple_sort(sort_by);
        break;
    case 2:
        choose_sort(sort_by);
        break;
    case 3:
        bubble_sort(sort_by);
        break;
    case 4:
        insert_sort(sort_by);
        break;
    case 5:
        mergeSort(files, 0, file_count - 1, sort_by);
        break;
    case 6:
        quick_sort(files, 0, file_count - 1, sort_by);
        break;
    }
}

void print_output(char path[], FileInfo files[], double total_time) {
    printf("%s\n", path);
    printf("--------------------------\n");
    for (int i = 0; i < file_count; i++) {
        printf("%-60s %d bytes\n", files[i].name, files[i].size);
    }
    printf("\nSorting total time: %.5lf\n\n", total_time);
}
