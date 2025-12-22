#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

#define MAX_FILES 100

#define CHOICE_SORTING_METHOD_TEXT "\
Choose a sorting method:\n\
1. Simple sort\n\
2. Choose sort\n\
3. Bubble sort\n\n\
Input number of your choice: "

#define CHOICE_SORT_BY_TEXT "\
Sort by:\n\
1. Increasing\n\
2. Descending\n\n\
Input number of your choice: "

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

//functions prototypes
void dir_query(char path[]);
void choose_sorting(int sorting_method, int sort_by);

//main code
int main() {
    int dir_exists = -1, sorting_method = 0, sort_by = 0;
    char path[MAX_PATH], search_path[MAX_PATH];
    time_t start_time, end_time;
    double total_time;

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
        if (sorting_method < 1 || sorting_method > 3) {
            printf("Wrong input! Try again.\n");
        }
    } while (sorting_method < 1 || sorting_method > 3);

    do {
        printf(CHOICE_SORT_BY_TEXT);
        scanf_s("%d", &sort_by);
        if (sort_by < 1 || sort_by > 2) {
            printf("Wrong input! Try again.\n");
        }
    } while (sort_by < 1 || sort_by > 2);

    start_time = clock();
    choose_sorting(sorting_method, sort_by);
    end_time = clock();

    total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("%s\n", path);
    printf("--------------------------\n");

    for (int i = 0; i < file_count; i++) {
        printf("%-40s %d bytes\n", files[i].name, files[i].size);
    }

    printf("\nSorting total time: %lf\n\n", total_time);
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
    }
}
