#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 1000

char file_names[MAX_FILES][256];
long file_sizes[MAX_FILES];
int file_count = 0;

void show_files() {
    if (file_count == 0) {
        printf("No files\n");
        return;
    }

    printf("\n%-30s %s\n", "File Name", "Size");
    printf("----------------------------------------\n");

    for (int i = 0; i < file_count; i++) {
        printf("%-30s %ld\n", file_names[i], file_sizes[i]);
    }
}

void print_menu() {
    printf("\n1. Sort files\n");
    printf("2. Show files\n");
    printf("3. Change directory\n");
    printf("4. Exit\n");
    printf("Choice: ");
}

int get_choice() {
    int choice;
    if (scanf_s("%d", &choice) != 1) {
        choice = 0;
    }
    while (getchar() != '\n');
    return choice;
}

int check_dir(char* path) {
    unsigned long attr = GetFileAttributesA(path);
    return (attr != INVALID_FILE_ATTRIBUTES &&
        (attr & FILE_ATTRIBUTE_DIRECTORY));
}

void get_path(char* path) {
    printf("Directory path: ");
    fgets(path, 256, stdin);

    int i = 0;
    while (path[i] != '\n' && path[i] != '\0') {
        i++;
    }
    path[i] = '\0';
}

void get_files(char* path) {
    WIN32_FIND_DATAA file_data;
    char search_path[300];

    // Используем sprintf_s вместо sprintf
    sprintf_s(search_path, sizeof(search_path), "%s\\*", path);

    HANDLE handle = FindFirstFileA(search_path, &file_data);
    if (handle == INVALID_HANDLE_VALUE) {
        printf("Error reading directory\n");
        return;
    }

    file_count = 0;

    do {
        if (strcmp(file_data.cFileName, ".") == 0) continue;
        if (strcmp(file_data.cFileName, "..") == 0) continue;

        if (!(file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            // Используем strcpy_s вместо strcpy
            strcpy_s(file_names[file_count], 256, file_data.cFileName);
            file_sizes[file_count] = file_data.nFileSizeLow;
            file_count++;

            if (file_count >= MAX_FILES) break;
        }
    } while (FindNextFileA(handle, &file_data));

    FindClose(handle);
    printf("Found %d files\n", file_count);
}

void bubble_sort(int ascending) {
    for (int i = 0; i < file_count - 1; i++) {
        for (int j = 0; j < file_count - i - 1; j++) {
            int need_swap = 0;

            if (ascending == 1) {
                if (file_sizes[j] > file_sizes[j + 1]) {
                    need_swap = 1;
                }
            }
            else {
                if (file_sizes[j] < file_sizes[j + 1]) {
                    need_swap = 1;
                }
            }

            if (need_swap) {
                long temp_size = file_sizes[j];
                file_sizes[j] = file_sizes[j + 1];
                file_sizes[j + 1] = temp_size;

                char temp_name[256];
                strcpy_s(temp_name, 256, file_names[j]);
                strcpy_s(file_names[j], 256, file_names[j + 1]);
                strcpy_s(file_names[j + 1], 256, temp_name);
            }
        }
    }
}

void quick_sort(int left, int right, int ascending) {
    if (left >= right) return;

    long pivot = file_sizes[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        if (ascending == 1) {
            while (file_sizes[i] < pivot) i++;
            while (file_sizes[j] > pivot) j--;
        }
        else {
            while (file_sizes[i] > pivot) i++;
            while (file_sizes[j] < pivot) j--;
        }

        if (i <= j) {
            long temp_size = file_sizes[i];
            file_sizes[i] = file_sizes[j];
            file_sizes[j] = temp_size;

            char temp_name[256];
            strcpy_s(temp_name, 256, file_names[i]);
            strcpy_s(file_names[i], 256, file_names[j]);
            strcpy_s(file_names[j], 256, temp_name);

            i++;
            j--;
        }
    }

    if (left < j) quick_sort(left, j, ascending);
    if (i < right) quick_sort(i, right, ascending);
}

int get_sort_choice() {
    int choice;

    printf("\nChoose sorting method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Quick Sort\n");
    printf("Enter choice: ");

    if (scanf_s("%d", &choice) != 1) {
        choice = 1;
    }
    while (getchar() != '\n');

    return choice;
}

int get_order_choice() {
    int order;

    printf("\nSorting order:\n");
    printf("1. Ascending (smallest first)\n");
    printf("2. Descending (largest first)\n");
    printf("Enter choice: ");

    if (scanf_s("%d", &order) != 1) {
        order = 1;
    }
    while (getchar() != '\n');

    return order;
}

double get_time() {
    static LARGE_INTEGER frequency;
    static int frequency_initialized = 0;

    if (!frequency_initialized) {
        QueryPerformanceFrequency(&frequency);
        frequency_initialized = 1;
    }

    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);

    return (double)counter.QuadPart / frequency.QuadPart;
}

int main() {
    char path[256];
    int choice;
    double start, end;

    printf("=== File Manager ===\n");
    get_path(path);

    if (!check_dir(path)) {
        printf("Invalid directory!\n");
        return 1;
    }

    get_files(path);

    while (1) {
        print_menu();
        choice = get_choice();

        if (choice == 1) {
            if (file_count == 0) {
                printf("No files to sort!\n");
                continue;
            }

            int sort_type = get_sort_choice();
            int order = get_order_choice();

            start = get_time();

            if (sort_type == 1) {
                bubble_sort(order == 1);
                printf("Sorted with Bubble Sort\n");
            }
            else {
                quick_sort(0, file_count - 1, order == 1);
                printf("Sorted with Quick Sort\n");
            }

            end = get_time();
            double time_taken = end - start;
            if (time_taken < 0.001) {
                printf("\nSorting time: %.6f milliseconds\n", time_taken * 1000);
            }
            else {
                printf("\nSorting time: %.6f seconds\n", time_taken);
            }

        }
        else if (choice == 2) {
            show_files();

        }
        else if (choice == 3) {
            get_path(path);
            if (!check_dir(path)) {
                printf("Invalid directory!\n");
                continue;
            }
            get_files(path);

        }
        else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}