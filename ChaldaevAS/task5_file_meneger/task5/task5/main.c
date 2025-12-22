#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 5000
#define MAX_DISPLAYED 5000

char file_names[MAX_FILES][256];
long file_sizes[MAX_FILES];
int file_count = 0;

void show_files() {
    if (file_count == 0) {
        printf("No files\n");
        return;
    }

    printf("\n%-10s %-70s %s\n", "Number", "File Name", "Size");
    printf("----------------------------------------\n");

    for (int i = 0; i < min(file_count, MAX_DISPLAYED); i++) {
        printf("%-10d %-70s %ld\n", i + 1, file_names[i], file_sizes[i]);
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
            strcpy_s(file_names[file_count], 256, file_data.cFileName);
            file_sizes[file_count] = file_data.nFileSizeLow;
            file_count++;

            if (file_count >= MAX_FILES) break;
        }
    } while (FindNextFileA(handle, &file_data));

    FindClose(handle);
    printf("Found %d files\n", file_count);
}

void selection_sort(char names[][256], long sizes[], int count, int ascending) {
    for (int i = 0; i < count - 1; i++) {
        int extreme_index = i;

        for (int j = i + 1; j < count; j++) {
            if (ascending == 1) {
                if (sizes[j] < sizes[extreme_index]) {
                    extreme_index = j;
                }
            }
            else {
                if (sizes[j] > sizes[extreme_index]) {
                    extreme_index = j;
                }
            }
        }

        if (extreme_index != i) {
            long temp_size = sizes[i];
            sizes[i] = sizes[extreme_index];
            sizes[extreme_index] = temp_size;

            char temp_name[256];
            strcpy_s(temp_name, 256, names[i]);
            strcpy_s(names[i], 256, names[extreme_index]);
            strcpy_s(names[extreme_index], 256, temp_name);
        }
    }
}

void insertion_sort(char names[][256], long sizes[], int count, int ascending) {
    for (int i = 1; i < count; i++) {
        long key_size = sizes[i];
        char key_name[256];
        strcpy_s(key_name, 256, names[i]);

        int j = i - 1;

        if (ascending == 1) {
            while (j >= 0 && sizes[j] > key_size) {
                sizes[j + 1] = sizes[j];
                strcpy_s(names[j + 1], 256, names[j]);
                j--;
            }
        }
        else {
            while (j >= 0 && sizes[j] < key_size) {
                sizes[j + 1] = sizes[j];
                strcpy_s(names[j + 1], 256, names[j]);
                j--;
            }
        }

        sizes[j + 1] = key_size;
        strcpy_s(names[j + 1], 256, key_name);
    }
}

void bubble_sort(char names[][256], long sizes[], int count, int ascending) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int need_swap = 0;

            if (ascending == 1) {
                if (sizes[j] > sizes[j + 1]) {
                    need_swap = 1;
                }
            }
            else {
                if (sizes[j] < sizes[j + 1]) {
                    need_swap = 1;
                }
            }

            if (need_swap) {
                long temp_size = sizes[j];
                sizes[j] = sizes[j + 1];
                sizes[j + 1] = temp_size;

                char temp_name[256];
                strcpy_s(temp_name, 256, names[j]);
                strcpy_s(names[j], 256, names[j + 1]);
                strcpy_s(names[j + 1], 256, temp_name);
            }
        }
    }
}

void quick_sort(char names[][256], long sizes[], int left, int right, int ascending) {
    if (left >= right) return;

    long pivot = sizes[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        if (ascending == 1) {
            while (sizes[i] < pivot) i++;
            while (sizes[j] > pivot) j--;
        }
        else {
            while (sizes[i] > pivot) i++;
            while (sizes[j] < pivot) j--;
        }

        if (i <= j) {
            long temp_size = sizes[i];
            sizes[i] = sizes[j];
            sizes[j] = temp_size;

            char temp_name[256];
            strcpy_s(temp_name, 256, names[i]);
            strcpy_s(names[i], 256, names[j]);
            strcpy_s(names[j], 256, temp_name);

            i++;
            j--;
        }
    }

    if (left < j) quick_sort(names, sizes, left, j, ascending);
    if (i < right) quick_sort(names, sizes, i, right, ascending);
}

int get_sort_choice() {
    int choice;

    printf("\nChoose sorting method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Quick Sort\n");
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


            switch (sort_type) {
            case 1:
                start = get_time();
                bubble_sort(file_names, file_sizes, file_count, order == 1);
                end = get_time();
                printf("Sorted with Bubble Sort\n");
                break;
            case 2:
                start = get_time();
                selection_sort(file_names, file_sizes, file_count, order == 1);
                end = get_time();
                printf("Sorted with Selection Sort\n");
                break;
            case 3:
                start = get_time();
                insertion_sort(file_names, file_sizes, file_count, order == 1);
                end = get_time();
                printf("Sorted with Insertion Sort\n");
                break;
            case 4:
                start = get_time();
                quick_sort(file_names, file_sizes, 0, file_count - 1, order == 1);
                end = get_time();
                printf("Sorted with Quick Sort\n");
                break;
            default:
                start = get_time();
                bubble_sort(file_names, file_sizes, file_count, order == 1);
                end = get_time();
                printf("Sorted with Bubble Sort (default)\n");
                break;
            }



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