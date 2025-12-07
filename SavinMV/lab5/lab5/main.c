#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

typedef struct {
    char* name;
    unsigned long long size;
} FileInfo;

void swap(FileInfo* a, FileInfo* b);
void bubbleSort(FileInfo arr[], int n);
void insertionSort(FileInfo arr[], int n);
void quickSort(FileInfo arr[], int low, int high);
int partition(FileInfo arr[], int low, int high);
FileInfo* copyFiles(const FileInfo* src, int n);
void freeFiles(FileInfo* files, int n);
char* appendWildcard(const char* input);

int main(void)
{
    char inputPath[1024];
    setlocale(LC_ALL, "RUS");
    printf("Введите путь к папке (например, C:\\test или .): ");
    if (!fgets(inputPath, sizeof(inputPath), stdin)) {
        printf("Ошибка ввода пути.\n");
        return 1;
    }

    size_t len = strlen(inputPath);
    if (len > 0 && inputPath[len - 1] == '\n') {
        inputPath[len - 1] = '\0';
    }

    char* directory = appendWildcard(inputPath);


    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFileA(directory, &findData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Не удалось открыть директорию: %s\n", inputPath);
        DWORD err = GetLastError();
        if (err == ERROR_FILE_NOT_FOUND || err == ERROR_PATH_NOT_FOUND) {
            printf("Папка не найдена или не содержит файлов.\n");
        }
        else {
            printf("Код ошибки Windows: %lu\n", err);
        }
        free(directory);
        return 1;
    }

    int capacity = 10;
    int count = 0;
    FileInfo* originalFiles = (FileInfo*)malloc(capacity * sizeof(FileInfo));


    do {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            continue;

        if (count >= capacity) {
            capacity *= 2;
            FileInfo* temp = (FileInfo*)realloc(originalFiles, capacity * sizeof(FileInfo));
            originalFiles = temp;
        }

        size_t nameLen = strlen(findData.cFileName);
        originalFiles[count].name = (char*)malloc(nameLen + 1);
        strcpy_s(originalFiles[count].name, nameLen + 1, findData.cFileName);

        originalFiles[count].size = ((unsigned long long)findData.nFileSizeHigh << 32) | findData.nFileSizeLow;
        count++;
    } while (FindNextFileA(hFind, &findData));

    FindClose(hFind);
    free(directory);

    if (count == 0) {
        printf("В указанной папке не найдено файлов.\n");
        freeFiles(originalFiles, 0);
        return 0;
    }

    int choice;
    while (1) {
        printf("\n=== Меню сортировки ===\n");
        printf("Найдено файлов: %d\n", count);
        printf("1. Пузырьковая сортировка (Bubble Sort)\n");
        printf("2. Сортировка вставками (Insertion Sort)\n");
        printf("3. Быстрая сортировка (Quick Sort)\n");
        printf("0. Выйти из программы\n");
        printf("Ваш выбор (0-3): ");

        if (scanf_s("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Некорректный ввод. Попробуйте снова.\n");
            continue;
        }

        if (choice == 0) {
            printf("Выход из программы.\n");
            break;
        }

        FileInfo* workingCopy = copyFiles(originalFiles, count);

        clock_t start, end;
        double cpu_time_used;

        start = clock();

        switch (choice) {
        case 1:
            bubbleSort(workingCopy, count);
            printf("\n--- Пузырьковая сортировка ---\n");
            break;
        case 2:
            insertionSort(workingCopy, count);
            printf("\n--- Сортировка вставками ---\n");
            break;
        case 3:
            quickSort(workingCopy, 0, count - 1);
            printf("\n--- Быстрая сортировка ---\n");
            break;
        default:
            printf("Неверный выбор.\n");
            freeFiles(workingCopy, count);
            continue;
        }

        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;

        for (int i = 0; i < count; i++) {
            printf("Файл: %s, Размер: %llu байт\n", workingCopy[i].name, workingCopy[i].size);
        }

        printf("\n Время сортировки: %.3f мс\n", cpu_time_used);

        freeFiles(workingCopy, count);
    }

    freeFiles(originalFiles, count);
    return 0;
}
void swap(FileInfo* a, FileInfo* b) {
    FileInfo temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(FileInfo arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].size > arr[j + 1].size) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void insertionSort(FileInfo arr[], int n) {
    for (int i = 1; i < n; i++) {
        FileInfo key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].size > key.size) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void quickSort(FileInfo arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int partition(FileInfo arr[], int low, int high) {
    unsigned long long pivot = arr[high].size;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].size <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
FileInfo* copyFiles(const FileInfo* src, int n) {
    FileInfo* copy = (FileInfo*)malloc(n * sizeof(FileInfo));
    if (!copy) return NULL;

    for (int i = 0; i < n; i++) {
        size_t len = strlen(src[i].name);
        copy[i].name = (char*)malloc(len + 1);
        if (!copy[i].name) {
            for (int j = 0; j < i; j++) {
                free(copy[j].name);
            }
            free(copy);
            return NULL;
        }
        strcpy_s(copy[i].name, len + 1, src[i].name);
        copy[i].size = src[i].size;
    }
    return copy;
}
void freeFiles(FileInfo* files, int n) {
    if (!files) return;
    for (int i = 0; i < n; i++) {
        free(files[i].name);
    }
    free(files);
}
char* appendWildcard(const char* input) {
    size_t len = strlen(input);
    char* result = NULL;

    if (len > 0 && (input[len - 1] == '\\' || input[len - 1] == '/')) {
        result = (char*)malloc(len + 2);
        if (result) {
            strcpy_s(result, len + 2, input);
            strcat_s(result, len + 2, "*");
        }
    }
    else {
        result = (char*)malloc(len + 3);
        if (result) {
            strcpy_s(result, len + 3, input);
            strcat_s(result, len + 3, "\\*");
        }
    }
    return result;
}