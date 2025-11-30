#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 1000
#define PATH_LENGTH 150

typedef struct {
    char name[MAX_PATH];
    long size;
} FileInfo;

FileInfo files[MAX_FILES];
int file_count = 0;

// Функция для установки русской кодировки
void setRussianEncoding() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
}

int check_correct_path(char* path) {
    DWORD attributes = GetFileAttributesA(path);
    if (attributes == INVALID_FILE_ATTRIBUTES) {
        printf("\nERROR: Path not found!\n");
        return 0;
    }
    if (!(attributes & FILE_ATTRIBUTE_DIRECTORY)) {
        printf("\nERROR: This is not a directory!\n");
        return 0;
    }
    return 1;
}

void input_dir_path(char* path) {
    while (1) {
        printf("\nEnter directory path: ");
        if (fgets(path, PATH_LENGTH, stdin) == NULL) {
            printf("Input error!\n");
            continue;
        }
        path[strcspn(path, "\n")] = 0;

        if (strlen(path) == 0) {
            printf("Path cannot be empty!\n");
            continue;
        }

        if (check_correct_path(path)) {
            printf("Directory found successfully.\n");
            break;
        }
        printf("Please try again.\n");
    }
}

void get_files_list(char* path) {
    WIN32_FIND_DATAA file_data;
    char search_path[PATH_LENGTH];
    sprintf_s(search_path, sizeof(search_path), "%s\\*", path);

    HANDLE hFind = FindFirstFileA(search_path, &file_data);
    file_count = 0;

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

    if (file_count == 0) {
        printf("No files found in directory.\n");
    }
    else {
        printf("Found %d files.\n", file_count);
    }
}

void bubble_sort(int ascending) {
    for (int i = 0; i < file_count - 1; i++) {
        for (int j = 0; j < file_count - i - 1; j++) {
            int condition = ascending ?
                (files[j].size > files[j + 1].size) :
                (files[j].size < files[j + 1].size);

            if (condition) {
                FileInfo temp = files[j];
                files[j] = files[j + 1];
                files[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int ascending) {
    for (int i = 0; i < file_count - 1; i++) {
        int extreme = i;
        for (int j = i + 1; j < file_count; j++) {
            if (ascending ?
                (files[j].size < files[extreme].size) :
                (files[j].size > files[extreme].size)) {
                extreme = j;
            }
        }
        FileInfo temp = files[i];
        files[i] = files[extreme];
        files[extreme] = temp;
    }
}

void show_files() {
    if (file_count == 0) {
        printf("No files to display.\n");
        return;
    }

    printf("\n%-50s %s\n", "File Name", "Size (bytes)");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < file_count; i++) {
        printf("%-50s %ld\n", files[i].name, files[i].size);
    }
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int get_int_input(const char* prompt, int min, int max) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf_s("%d", &value) != 1) {
            printf("Invalid input! Please enter a number between %d and %d.\n", min, max);
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        if (value >= min && value <= max) {
            return value;
        }
        printf("Please enter a number between %d and %d.\n", min, max);
    }
}

// Функция для точного измерения времени
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
    char path[PATH_LENGTH];
    int choice, sort_method, order;
    double start, end;

    // Устанавливаем русскую кодировку
    setRussianEncoding();

    printf("=== File Manager ===\n");
    input_dir_path(path);
    get_files_list(path);

    do {
        printf("\n=== Main Menu ===\n");
        printf("1. Sort files\n");
        printf("2. Change directory\n");
        printf("3. Exit\n");

        choice = get_int_input("Enter your choice (1-3): ", 1, 3);

        if (choice == 1) {
            if (file_count == 0) {
                printf("No files to sort!\n");
                continue;
            }

            printf("\nChoose sorting method:\n");
            printf("1. Bubble Sort\n");
            printf("2. Selection Sort\n");
            sort_method = get_int_input("Enter choice (1-2): ", 1, 2);

            printf("\nSorting order:\n");
            printf("1. Ascending (smallest first)\n");
            printf("2. Descending (largest first)\n");
            order = get_int_input("Enter choice (1-2): ", 1, 2);

            // Создаем копию для сортировки
            FileInfo files_to_sort[MAX_FILES];
            memcpy(files_to_sort, files, sizeof(FileInfo) * file_count);

            start = get_time();

            if (sort_method == 1) {
                bubble_sort(order == 1);
                printf("\nUsing Bubble Sort - ");
            }
            else {
                selection_sort(order == 1);
                printf("\nUsing Selection Sort - ");
            }

            end = get_time();

            printf("%s order\n", (order == 1) ? "Ascending" : "Descending");
            show_files();

            double time_taken = end - start;
            if (time_taken < 0.001) {
                printf("\nSorting time: %.6f milliseconds\n", time_taken * 1000);
            }
            else {
                printf("\nSorting time: %.6f seconds\n", time_taken);
            }

            // Восстанавливаем исходный массив
            memcpy(files, files_to_sort, sizeof(FileInfo) * file_count);

        }
        else if (choice == 2) {
            input_dir_path(path);
            get_files_list(path);
        }
        else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        }

    } while (1);

    return 0;
}