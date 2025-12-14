#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

typedef struct {
    char* name;
    unsigned long long size;
} FileInfo;

void swap(FileInfo* a, FileInfo* b);
void bubbleSort(FileInfo arr[], int n);
void insertionSort(FileInfo arr[], int n);
void selectionSort(FileInfo arr[], int n);
void quickSort(FileInfo arr[], int low, int high);
int partition(FileInfo arr[], int low, int high);
void mergeSort(FileInfo arr[], int left, int right);
void merge(FileInfo arr[], int left, int mid, int right);
FileInfo* copyFiles(const FileInfo* src, int n);
void freeFiles(FileInfo* files, int n);
char* appendWildcard(const char* input);

int main(void)
{
    char inputPath[1024];
    setlocale(LC_ALL, "RUS");
    printf("Введите путь к папке: ");
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
    }

    int capacity = 10;
    int count = 0;
    FileInfo* originalFiles = (FileInfo*)malloc(capacity * sizeof(FileInfo));
    if (!originalFiles) {
        printf("Ошибка\n");
        free(directory);
        return 1;
    }

    do {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            continue;

        if (count >= capacity) {
            capacity *= 2;
            FileInfo* temp = (FileInfo*)realloc(originalFiles, capacity * sizeof(FileInfo));
            if (!temp) {
                printf("Ошибка\n");
                freeFiles(originalFiles, count);
                free(directory);
                FindClose(hFind);
                return 1;
            }
            originalFiles = temp;
        }

        size_t nameLen = strlen(findData.cFileName);
        originalFiles[count].name = (char*)malloc(nameLen + 1);
        if (!originalFiles[count].name) {
            printf("Ошибка\n");
            freeFiles(originalFiles, count);
            free(directory);
            FindClose(hFind);
            return 1;
        }
        strcpy(originalFiles[count].name, findData.cFileName);

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
        printf("\nМеню сортировки\n");
        printf("Найдено файлов: %d\n", count);
        printf("1. Пузырьковая сортировка (Bubble Sort)\n");
        printf("2. Сортировка вставками (Insertion Sort)\n");
        printf("3. Сортировка выбором (Selection Sort)\n");
        printf("4. Быстрая сортировка (Quick Sort)\n");
        printf("5. Сортировка слиянием (Merge Sort)\n");
        printf("0. Выйти из программы\n");
        printf("Ваш выбор (0-5): ");

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
        if (!workingCopy) {
            printf("Ошибка копирования данных.\n");
            continue;
        }
        LARGE_INTEGER start, end, freq;
        double t_ms;

        QueryPerformanceFrequency(&freq);
        QueryPerformanceCounter(&start);


        switch (choice) {
        case 1:
            bubbleSort(workingCopy, count);
            printf("\nПузырьковая сортировка\n");
            break;
        case 2:
            insertionSort(workingCopy, count);
            printf("\nСортировка вставками\n");
            break;
        case 3:
            selectionSort(workingCopy, count);
            printf("\nСортировка выбором\n");
            break;
        case 4:
            quickSort(workingCopy, 0, count - 1);
            printf("\nБыстрая сортировка\n");
            break;
        case 5:
            mergeSort(workingCopy,0, count-1);
            printf("\nСортировка слиянием\n");
            break;
        default:
            printf("Неверный выбор.\n");
            freeFiles(workingCopy, count);
            continue;
        }
        QueryPerformanceCounter(&end);
        t_ms = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart * 1000.0;

        for (int i = 0; i < count; i++) {
            printf("Файл: %s, Размер: %llu байт\n", workingCopy[i].name, workingCopy[i].size);
        }

        printf("\n Время сортировки: %.3f мс\n", t_ms);

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

void selectionSort(FileInfo arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].size < arr[minIdx].size) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(&arr[i], &arr[minIdx]);
        }
    }
}

int partition(FileInfo arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    unsigned long long pivot = arr[mid].size;
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (arr[i].size < pivot);
        do {
            j--;
        } while (arr[j].size > pivot);
        if (i >= j)
            return j;
        swap(&arr[i], &arr[j]);
    }
}
void quickSort(FileInfo arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

void merge(FileInfo arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    FileInfo* leftArr = (FileInfo*)malloc(n1 * sizeof(FileInfo));
    FileInfo* rightArr = (FileInfo*)malloc(n2 * sizeof(FileInfo));
    if (!leftArr || !rightArr) {
        fprintf(stderr, "Ошибка\n");
        free(leftArr);
        free(rightArr);
        return;
    }

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i].size <= rightArr[j].size) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++; k++;
    }
    free(leftArr);
    free(rightArr);
}

void mergeSort(FileInfo arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
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