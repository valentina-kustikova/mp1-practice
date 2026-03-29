#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct {
    char name[256];
    long long size;
} FileInfo;

#define MAX_DISPLAY_FILES 10

void simple_sort(FileInfo* files, int n, int order);
void choice_sort(FileInfo* files, int n, int order);
void bubble_sort(FileInfo* files, int n, int order);
void insert_sort(FileInfo* files, int n, int order);
void quick_sort(FileInfo* files, int n, int order);
void merge_sort(FileInfo* files, int n, int order);

void recursion_quick(FileInfo* files, int first, int last, int order);
void recursion_merge(FileInfo* files, int l, int r, int order);
void merge(FileInfo* files, int l, int mid, int r, int order);

FileInfo* read_directory(const char* path, int* file_count) {
    DWORD attributes = GetFileAttributesA(path);

    if (attributes == INVALID_FILE_ATTRIBUTES) {
        printf("Ошибка: директория не найдена!\n");
        return NULL;
    }

    if (!(attributes & FILE_ATTRIBUTE_DIRECTORY)) {
        printf("Ошибка: это не директория!\n");
        return NULL;
    }

    char search_path[512];
    sprintf_s(search_path, sizeof(search_path), "%s\\*", path);

    WIN32_FIND_DATAA find_data;
    HANDLE find_handle = FindFirstFileA(search_path, &find_data);

    if (find_handle == INVALID_HANDLE_VALUE) {
        printf("Ошибка при открытии директории!\n");
        return NULL;
    }

    int count = 0;
    do {
        if (strcmp(find_data.cFileName, ".") == 0 ||
            strcmp(find_data.cFileName, "..") == 0) {
            continue;
        }

        if (!(find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            count++;
        }
    } while (FindNextFileA(find_handle, &find_data));

    FindClose(find_handle);

    if (count == 0) {
        printf("В директории нет файлов!\n");
        return NULL;
    }

    printf("Найдено файлов: %d\n", count);

    FileInfo* files = (FileInfo*)malloc(count * sizeof(FileInfo));
    if (files == NULL) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }

    find_handle = FindFirstFileA(search_path, &find_data);
    int index = 0;

    do {
        if (strcmp(find_data.cFileName, ".") == 0 ||
            strcmp(find_data.cFileName, "..") == 0) {
            continue;
        }

        if (!(find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            strcpy_s(files[index].name, sizeof(files[index].name), find_data.cFileName);

            files[index].size = (long long)find_data.nFileSizeLow +
                ((long long)find_data.nFileSizeHigh << 32);

            index++;
        }
    } while (FindNextFileA(find_handle, &find_data) && index < count);

    FindClose(find_handle);

    *file_count = count;
    return files;
}

void print_files(FileInfo* files, int count) {
    printf("\n");
    printf("=============================================\n");
    printf("СОДЕРЖИМОЕ ДИРЕКТОРИИ\n");
    printf("---------------------------------------------\n");
    printf("%-40s %15s\n", "Имя файла", "Размер");
    printf("---------------------------------------------\n");

    int display_count = (count > MAX_DISPLAY_FILES) ? MAX_DISPLAY_FILES : count;

    for (int i = 0; i < display_count; i++) {
        char size_str[20];
        if (files[i].size < 1024) {
            sprintf_s(size_str, sizeof(size_str), "%lld Б", files[i].size);
        }
        else if (files[i].size < 1024 * 1024) {
            sprintf_s(size_str, sizeof(size_str), "%.1f КБ", files[i].size / 1024.0);
        }
        else if (files[i].size < 1024 * 1024 * 1024) {
            sprintf_s(size_str, sizeof(size_str), "%.1f МБ", files[i].size / (1024.0 * 1024.0));
        }
        else {
            sprintf_s(size_str, sizeof(size_str), "%.1f ГБ", files[i].size / (1024.0 * 1024.0 * 1024.0));
        }

        printf("%-40s %15s\n", files[i].name, size_str);
    }

    printf("---------------------------------------------\n");

    if (count > MAX_DISPLAY_FILES) {
        printf("Показано %d из %d файлов\n", MAX_DISPLAY_FILES, count);
    }
    else {
        printf("Всего файлов: %d\n", count);
    }

    printf("=============================================\n");
}

void print_menu() {
    printf("\n");
    printf("=============================================\n");
    printf("ФАЙЛОВЫЙ МЕНЕДЖЕР - ВЫБОР СОРТИРОВКИ\n");
    printf("---------------------------------------------\n");
    printf("1. Простейшая сортировка\n");
    printf("2. Сортировка выбором\n");
    printf("3. Сортировка вставками\n");
    printf("4. Пузырьковая сортировка\n");
    printf("5. Быстрая сортировка\n");
    printf("6. Сортировка слиянием\n");
    printf("7. Выйти\n");
    printf("=============================================\n");
    printf("Выберите метод сортировки (1-7): ");
}

void input_path(char* path, int size) {
    printf("\nВведите путь к директории: ");

    if (fgets(path, size, stdin) == NULL) {
        path[0] = '\0';
        return;
    }

    size_t len = strlen(path);
    if (len > 0 && path[len - 1] == '\n') {
        path[len - 1] = '\0';
    }
}

void print_order_menu() {
    printf("\n");
    printf("---------------------------------------------\n");
    printf("ПОРЯДОК СОРТИРОВКИ:\n");
    printf("1. По возрастанию размера\n");
    printf("2. По убыванию размера\n");
    printf("---------------------------------------------\n");
    printf("Выберите порядок (1-2): ");
}

double get_sorting_time(int sort_type, FileInfo* files, int count, int order) {
    clock_t start, end;

    FileInfo* files_copy = (FileInfo*)malloc(count * sizeof(FileInfo));
    if (files_copy == NULL) {
        printf("Ошибка выделения памяти для копирования!\n");
        return -1.0;
    }

    memcpy(files_copy, files, count * sizeof(FileInfo));

    start = clock();

    switch (sort_type) {
    case 1: simple_sort(files_copy, count, order); break;
    case 2: choice_sort(files_copy, count, order); break;
    case 3: insert_sort(files_copy, count, order); break;
    case 4: bubble_sort(files_copy, count, order); break;
    case 5: quick_sort(files_copy, count, order); break;
    case 6: merge_sort(files_copy, count, order); break;
    }

    end = clock();

    memcpy(files, files_copy, count * sizeof(FileInfo));
    free(files_copy);

    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

void simple_sort(FileInfo* files, int n, int order) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (order == 1) {
                if (files[i].size > files[j].size) {
                    FileInfo temp = files[i];
                    files[i] = files[j];
                    files[j] = temp;
                }
            }
            else {
                if (files[i].size < files[j].size) {
                    FileInfo temp = files[i];
                    files[i] = files[j];
                    files[j] = temp;
                }
            }
        }
    }
}

void choice_sort(FileInfo* files, int n, int order) {
    for (int i = 0; i < n; i++) {
        int selected = i;
        for (int j = i + 1; j < n; j++) {
            if (order == 1) {
                if (files[j].size < files[selected].size) {
                    selected = j;
                }
            }
            else {
                if (files[j].size > files[selected].size) {
                    selected = j;
                }
            }
        }
        if (selected != i) {
            FileInfo temp = files[i];
            files[i] = files[selected];
            files[selected] = temp;
        }
    }
}

void insert_sort(FileInfo* files, int n, int order) {
    for (int i = 1; i < n; i++) {
        FileInfo current = files[i];
        int j = i - 1;

        if (order == 1) {
            while (j >= 0 && files[j].size > current.size) {
                files[j + 1] = files[j];
                j--;
            }
        }
        else {
            while (j >= 0 && files[j].size < current.size) {
                files[j + 1] = files[j];
                j--;
            }
        }
        files[j + 1] = current;
    }
}

void bubble_sort(FileInfo* files, int n, int order) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (order == 1) {
                if (files[j].size > files[j + 1].size) {
                    FileInfo temp = files[j];
                    files[j] = files[j + 1];
                    files[j + 1] = temp;
                }
            }
            else {
                if (files[j].size < files[j + 1].size) {
                    FileInfo temp = files[j];
                    files[j] = files[j + 1];
                    files[j + 1] = temp;
                }
            }
        }
    }
}

void recursion_quick(FileInfo* files, int first, int last, int order) {
    if (first >= last) return;

    int i = first, j = last;
    long long pivot = files[(first + last) / 2].size;

    while (i <= j) {
        if (order == 1) {
            while (files[i].size < pivot) i++;
            while (files[j].size > pivot) j--;
        }
        else {
            while (files[i].size > pivot) i++;
            while (files[j].size < pivot) j--;
        }

        if (i <= j) {
            FileInfo temp = files[i];
            files[i] = files[j];
            files[j] = temp;
            i++;
            j--;
        }
    }

    recursion_quick(files, first, j, order);
    recursion_quick(files, i, last, order);
}

void quick_sort(FileInfo* files, int n, int order) {
    recursion_quick(files, 0, n - 1, order);
}

void merge(FileInfo* files, int l, int mid, int r, int order) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    FileInfo* left = (FileInfo*)malloc(n1 * sizeof(FileInfo));
    FileInfo* right = (FileInfo*)malloc(n2 * sizeof(FileInfo));

    for (int i = 0; i < n1; i++) left[i] = files[l + i];
    for (int j = 0; j < n2; j++) right[j] = files[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (order == 1) {
            if (left[i].size <= right[j].size) {
                files[k] = left[i];
                i++;
            }
            else {
                files[k] = right[j];
                j++;
            }
        }
        else {
            if (left[i].size >= right[j].size) {
                files[k] = left[i];
                i++;
            }
            else {
                files[k] = right[j];
                j++;
            }
        }
        k++;
    }

    while (i < n1) {
        files[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        files[k] = right[j];
        j++;
        k++;
    }

    free(left);
    free(right);
}

void recursion_merge(FileInfo* files, int l, int r, int order) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        recursion_merge(files, l, mid, order);
        recursion_merge(files, mid + 1, r, order);
        merge(files, l, mid, r, order);
    }
}

void merge_sort(FileInfo* files, int n, int order) {
    recursion_merge(files, 0, n - 1, order);
}

int main() {
    char path[261] = { 0 };
    FileInfo* files = NULL;
    int file_count = 0;
    int choice, order;

    setlocale(LC_ALL, "Russian");

    printf("=== ФАЙЛОВЫЙ МЕНЕДЖЕР ===\n");
    printf("Выводит до %d файлов из директории\n", MAX_DISPLAY_FILES);

    while (1) {
        printf("\n");
        printf("=============================================\n");
        printf("ГЛАВНОЕ МЕНЮ\n");
        printf("---------------------------------------------\n");
        printf("1. Выбрать директорию\n");
        printf("2. Выбрать метод сортировки\n");
        printf("3. Выйти\n");
        printf("=============================================\n");
        printf("Выберите действие (1-3): ");

        int main_choice;
        scanf("%d", &main_choice);
        while (getchar() != '\n');

        if (main_choice == 1) {
            input_path(path, sizeof(path));

            if (strlen(path) == 0) {
                printf("Путь не введен!\n");
                continue;
            }

            if (files != NULL) {
                free(files);
                files = NULL;
                file_count = 0;
            }

            files = read_directory(path, &file_count);

            if (files != NULL) {
                printf("Директория успешно загружена!\n");
            }
            print_files(files, file_count);
        }
        else if (main_choice == 2) {
            if (files == NULL) {
                printf("Сначала выберите директорию!\n");
                continue;
            }

            print_order_menu();
            scanf("%d", &order);
            while (getchar() != '\n');

            if (order != 1 && order != 2) {
                printf("Неверный выбор порядка!\n");
                continue;
            }

            print_menu();
            scanf("%d", &choice);
            while (getchar() != '\n');

            if (choice < 1 || choice > 7) {
                printf("Неверный выбор сортировки!\n");
                continue;
            }

            if (choice == 7) {
                continue;
            }

            const char* sort_names[] = {
                "", "Простейшая", "Выбором", "Вставками",
                "Пузырьковая", "Быстрая", "Слиянием"
            };

            printf("\nСортировка: %s, Порядок: %s\n",
                sort_names[choice],
                (order == 1) ? "по возрастанию" : "по убыванию");

            double time = get_sorting_time(choice, files, file_count, order);

            printf("Время сортировки: %.3f мс\n", time);

            print_files(files, file_count);
        }
        else if (main_choice == 3) {
            printf("Выход из программы...\n");
            if (files != NULL) {
                free(files);
            }
            system("pause");
            return 0;
        }
        else {
            printf("Неверный выбор!\n");
        }
    }
    return 0;
}