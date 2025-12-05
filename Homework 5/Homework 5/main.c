#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_FILES 200

void display_list(char** file_list, int* file_sizes, int num_files);
void sort_by_selection(char** file_list, int* file_sizes, int num_files, int is_desc);
void sort_by_insertion(char** file_list, int* file_sizes, int num_files, int is_desc);
void sort_by_bubble(char** file_list, int* file_sizes, int num_files, int is_desc);
void recursive_merge_sort(char** file_list, int* file_sizes, int num_files, int is_desc, int left, int right);
void merge_arrays(char** file_list, int* file_sizes, int is_desc, int left, int mid, int right);

int main() {
    char dir_path[256];
    WIN32_FIND_DATAA file_info;
    HANDLE search_handle;
    char** file_names = NULL;
    int* file_sizes = NULL;
    int file_count = 0;
    int sort_type, is_desc;

    printf("Enter directory path: ");
    scanf_s("%s", dir_path, (unsigned)_countof(dir_path));
    strcat_s(dir_path, sizeof(dir_path), "\\*.*");

    file_names = (char**)malloc(MAX_FILES * sizeof(char*));
    file_sizes = (int*)malloc(MAX_FILES * sizeof(int));

    search_handle = FindFirstFileA(dir_path, &file_info);
    if (search_handle == INVALID_HANDLE_VALUE) {
        printf("Failed to open directory.\n");
        free(file_names);
        free(file_sizes);
        return 1;
    }

    do {
        if (strcmp(file_info.cFileName, ".") == 0 || strcmp(file_info.cFileName, "..") == 0)
            continue;

        if (file_count >= MAX_FILES) {
            printf("Too many files! Limit is %d.\n", MAX_FILES);
            break;
        }

        file_names[file_count] = (char*)malloc(strlen(file_info.cFileName) + 1);
        strcpy_s(file_names[file_count], strlen(file_info.cFileName) + 1, file_info.cFileName);
        file_sizes[file_count] = (int)file_info.nFileSizeLow;
        file_count++;
    } while (FindNextFileA(search_handle, &file_info));

    FindClose(search_handle);

    // Ввод типа сортировки с проверкой
    while (1) {
        printf("\nChoose sorting method:\n");
        printf("1 - Selection sort\n");
        printf("2 - Insertion sort\n");
        printf("3 - Bubble sort\n");
        printf("4 - Merge sort\n");
        if (scanf_s("%d", &sort_type) != 1) {
            // Очистка буфера при неверном формате
            while (getchar() != '\n');
            printf("Invalid input! Please enter a number.\n");
            continue;
        }
        if (sort_type >= 1 && sort_type <= 4) {
            break;
        }
        printf("Invalid choice! Choose 1, 2, 3, or 4.\n");
    }

    // Ввод порядка с проверкой
    while (1) {
        printf("Order: ascending (0) or descending (1)? ");
        if (scanf_s("%d", &is_desc) != 1) {
            while (getchar() != '\n');
            printf("Invalid input! Please enter 0 or 1.\n");
            continue;
        }
        if (is_desc == 0 || is_desc == 1) {
            break;
        }
        printf("Invalid input! Enter 0 for ascending or 1 for descending.\n");
    }

    // Выполнение выбранной сортировки
    switch (sort_type) {
    case 1:
        sort_by_selection(file_names, file_sizes, file_count, is_desc);
        break;
    case 2:
        sort_by_insertion(file_names, file_sizes, file_count, is_desc);
        break;
    case 3:
        sort_by_bubble(file_names, file_sizes, file_count, is_desc);
        break;
    case 4:
        recursive_merge_sort(file_names, file_sizes, file_count, is_desc, 0, file_count - 1);
        break;
    }

    // Вывод результата
    display_list(file_names, file_sizes, file_count);

    // Освобождение памяти
    for (int i = 0; i < file_count; i++) {
        free(file_names[i]);
    }
    free(file_names);
    free(file_sizes);

    return 0;
}

void display_list(char** file_list, int* file_sizes, int num_files) {
    for (int i = 0; i < num_files; i++) {
        printf("%s - %d bytes\n", file_list[i], file_sizes[i]);
    }
}

void sort_by_selection(char** file_list, int* file_sizes, int num_files, int is_desc) {
    for (int i = 0; i < num_files - 1; i++) {
        int target_idx = i;
        for (int j = i + 1; j < num_files; j++) {
            if (is_desc ? (file_sizes[j] > file_sizes[target_idx]) : (file_sizes[j] < file_sizes[target_idx])) {
                target_idx = j;
            }
        }
        if (target_idx != i) {
            int tmp_size = file_sizes[i];
            file_sizes[i] = file_sizes[target_idx];
            file_sizes[target_idx] = tmp_size;

            char* tmp_name = file_list[i];
            file_list[i] = file_list[target_idx];
            file_list[target_idx] = tmp_name;
        }
    }
}

void sort_by_insertion(char** file_list, int* file_sizes, int num_files, int is_desc) {
    for (int i = 1; i < num_files; i++) {
        int current_size = file_sizes[i];
        char* current_name = file_list[i];
        int j = i - 1;

        while (j >= 0 && (is_desc ? (file_sizes[j] < current_size) : (file_sizes[j] > current_size))) {
            file_sizes[j + 1] = file_sizes[j];
            file_list[j + 1] = file_list[j];
            j--;
        }

        file_sizes[j + 1] = current_size;
        file_list[j + 1] = current_name;
    }
}

void sort_by_bubble(char** file_list, int* file_sizes, int num_files, int is_desc) {
    for (int i = 0; i < num_files - 1; i++) {
        for (int j = 0; j < num_files - i - 1; j++) {
            if (is_desc ? (file_sizes[j] < file_sizes[j + 1]) : (file_sizes[j] > file_sizes[j + 1])) {
                int tmp_size = file_sizes[j];
                file_sizes[j] = file_sizes[j + 1];
                file_sizes[j + 1] = tmp_size;

                char* tmp_name = file_list[j];
                file_list[j] = file_list[j + 1];
                file_list[j + 1] = tmp_name;
            }
        }
    }
}

void recursive_merge_sort(char** file_list, int* file_sizes, int num_files, int is_desc, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    recursive_merge_sort(file_list, file_sizes, num_files, is_desc, left, mid);
    recursive_merge_sort(file_list, file_sizes, num_files, is_desc, mid + 1, right);
    merge_arrays(file_list, file_sizes, is_desc, left, mid, right);
}

void merge_arrays(char** file_list, int* file_sizes, int is_desc, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* left_sizes = (int*)malloc(n1 * sizeof(int));
    int* right_sizes = (int*)malloc(n2 * sizeof(int));
    char** left_names = (char**)malloc(n1 * sizeof(char*));
    char** right_names = (char**)malloc(n2 * sizeof(char*));

    for (int i = 0; i < n1; i++) {
        left_sizes[i] = file_sizes[left + i];
        left_names[i] = file_list[left + i];
    }
    for (int j = 0; j < n2; j++) {
        right_sizes[j] = file_sizes[mid + 1 + j];
        right_names[j] = file_list[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        int condition;
        if (is_desc == 0) {
            condition = (left_sizes[i] <= right_sizes[j]);
        }
        else {
            condition = (left_sizes[i] >= right_sizes[j]);
        }

        if (condition) {
            file_sizes[k] = left_sizes[i];
            file_list[k] = left_names[i];
            i++;
        }
        else {
            file_sizes[k] = right_sizes[j];
            file_list[k] = right_names[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        file_sizes[k] = left_sizes[i];
        file_list[k] = left_names[i];
        i++; k++;
    }
    while (j < n2) {
        file_sizes[k] = right_sizes[j];
        file_list[k] = right_names[j];
        j++; k++;
    }

    free(left_sizes);
    free(right_sizes);
    free(left_names);
    free(right_names);
}