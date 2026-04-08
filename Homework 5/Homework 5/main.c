#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

typedef struct {
    char* fname;
    unsigned long long fsize;
} Item;

Item* scanDirectory(const char* pattern, int* total);
void naiveSort(Item arr[], int n);
void swap(Item* x, Item* y);
void bubbleSort(Item arr[], int n);
void insertSort(Item arr[], int n);
void selectSort(Item arr[], int n);
void quickSort(Item arr[], int lo, int hi);
int split(Item arr[], int lo, int hi);
void mergeSort(Item arr[], int l, int r);
void merge(Item arr[], int l, int m, int r);
Item* duplicateItems(const Item* src, int n);
void releaseItems(Item* list, int n);
char* makeSearchPattern(const char* base);

int main(void)
{
    char pathBuf[1024];
    setlocale(LC_ALL, "RUS");
    printf("Укажите путь к каталогу: ");
    if (!fgets(pathBuf, sizeof(pathBuf), stdin)) {
        printf("Не удалось прочитать путь.\n");
        return 1;
    }

    size_t plen = strlen(pathBuf);
    if (plen > 0 && pathBuf[plen - 1] == '\n') {
        pathBuf[plen - 1] = '\0';
    }

    char* searchMask = makeSearchPattern(pathBuf);
    if (!searchMask) {
        printf("Ошибка формирования маски поиска.\n");
        return 1;
    }

    int fileCount = 0;
    Item* originalList = scanDirectory(searchMask, &fileCount);
    free(searchMask);

    if (!originalList) {
        printf("Не удалось прочитать содержимое папки.\n");
        return 1;
    }

    if (fileCount == 0) {
        printf("В папке не найдено файлов.\n");
        releaseItems(originalList, 0);
        return 0;
    }

    int userChoice;
    while (1) {
        printf("\n--- Меню сортировки ---\n");
        printf("Обнаружено файлов: %d\n", fileCount);
        printf("1. Пузырьковая сортировка\n");
        printf("2. Сортировка вставками\n");
        printf("3. Сортировка выбором\n");
        printf("4. Быстрая сортировка\n");
        printf("5. Сортировка слиянием\n");
        printf("6. Простейшая сортировка\n");
        printf("0. Выйти\n");
        printf("Ваш выбор (0–6): ");

        if (scanf_s("%d", &userChoice) != 1) {
            while (getchar() != '\n');
            printf("Ошибка: введите число от 0 до 6.\n");
            continue;
        }

        if (userChoice == 0) {
            printf("Завершение работы.\n");
            break;
        }

        if (userChoice < 0 || userChoice > 6) {
            printf("Ошибка: введите число от 0 до 6.\n");
            continue;
        }

        Item* tempCopy = duplicateItems(originalList, fileCount);

        LARGE_INTEGER t1, t2, freq;
        double execTimeMs;

        QueryPerformanceFrequency(&freq);
        QueryPerformanceCounter(&t1);

        switch (userChoice) {
        case 1: bubbleSort(tempCopy, fileCount); break;
        case 2: insertSort(tempCopy, fileCount); break;
        case 3: selectSort(tempCopy, fileCount); break;
        case 4: quickSort(tempCopy, 0, fileCount - 1); break;
        case 5: mergeSort(tempCopy, 0, fileCount - 1); break;
        case 6: naiveSort(tempCopy, fileCount); break;
        }

        QueryPerformanceCounter(&t2);
        execTimeMs = (double)(t2.QuadPart - t1.QuadPart) / freq.QuadPart * 1000.0;


        if (fileCount <= 10) {
            printf("\n--- Отсортированный список ---\n");
            for (int i = 0; i < fileCount; i++) {
                printf("Файл: %s, Размер: %llu байт\n", tempCopy[i].fname, tempCopy[i].fsize);
            }
        }
        else {
            printf("\n(Список скрыт: найдено более 10 файлов)\n");
        }

        printf("Время сортировки: %.3f мс\n", execTimeMs);
        releaseItems(tempCopy, fileCount);
    }

    releaseItems(originalList, fileCount);
    return 0;
}

void swap(Item* a, Item* b) {
    Item tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(Item arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].fsize > arr[j + 1].fsize)
                swap(&arr[j], &arr[j + 1]);
}

void insertSort(Item arr[], int n) {
    for (int i = 1; i < n; i++) {
        Item key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].fsize > key.fsize) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectSort(Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j].fsize < arr[minIdx].fsize)
                minIdx = j;
        if (minIdx != i)
            swap(&arr[i], &arr[minIdx]);
    }
}

int split(Item arr[], int lo, int hi) {
    unsigned long long pivot = arr[lo].fsize;
    int i = lo - 1, j = hi + 1;
    while (1) {
        do { i++; } while (arr[i].fsize < pivot);
        do { j--; } while (arr[j].fsize > pivot);
        if (i >= j) return j;
        swap(&arr[i], &arr[j]);
    }
}

void quickSort(Item arr[], int lo, int hi) {
    if (lo < hi) {
        int p = split(arr, lo, hi);
        quickSort(arr, lo, p);
        quickSort(arr, p + 1, hi);
    }
}

void merge(Item arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    Item* L = malloc(n1 * sizeof(Item)), * R = malloc(n2 * sizeof(Item));
    if (!L || !R) {
        free(L); free(R);
        return;
    }

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        if (L[i].fsize <= R[j].fsize)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L); free(R);
}

void mergeSort(Item arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void naiveSort(Item arr[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i].fsize < arr[j].fsize)
                swap(&arr[i], &arr[j]);
}

Item* duplicateItems(const Item* src, int n) {
    Item* copy = malloc(n * sizeof(Item));
    if (!copy) return NULL;
    for (int i = 0; i < n; i++) {
        size_t len = strlen(src[i].fname);
        copy[i].fname = malloc(len + 1);
        if (!copy[i].fname) {
            for (int j = 0; j < i; j++) free(copy[j].fname);
            free(copy);
            return NULL;
        }
        strcpy_s(copy[i].fname, len + 1, src[i].fname);
        copy[i].fsize = src[i].fsize;
    }
    return copy;
}

void releaseItems(Item* list, int n) {
    if (!list) return;
    for (int i = 0; i < n; i++) free(list[i].fname);
    free(list);
}

char* makeSearchPattern(const char* base) {
    if (!base) return NULL;
    size_t len = strlen(base);
    char* res = malloc(len + 3);
    if (!res) return NULL;
    strcpy_s(res, len + 3, base);
    if (len > 0 && (base[len - 1] == '\\' || base[len - 1] == '/'))
        strcat_s(res, len + 3, "*");
    else
        strcat_s(res, len + 3, "\\*");
    return res;
}

Item* scanDirectory(const char* pattern, int* outCount) {
    WIN32_FIND_DATA fd;
    HANDLE hf = FindFirstFileA(pattern, &fd);
    if (hf == INVALID_HANDLE_VALUE) {
        *outCount = 0;
        return NULL;
    }

    int cap = 10, count = 0;
    Item* items = malloc(cap * sizeof(Item));
    if (!items) {
        FindClose(hf);
        *outCount = 0;
        return NULL;
    }

    do {
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) continue;

        if (count >= cap) {
            cap *= 2;
            Item* tmp = realloc(items, cap * sizeof(Item));
            if (!tmp) {
                for (int i = 0; i < count; i++) free(items[i].fname);
                free(items);
                FindClose(hf);
                *outCount = 0;
                return NULL;
            }
            items = tmp;
        }

        size_t nlen = strlen(fd.cFileName);
        items[count].fname = malloc(nlen + 1);
        if (!items[count].fname) {
            for (int i = 0; i < count; i++) free(items[i].fname);
            free(items);
            FindClose(hf);
            *outCount = 0;
            return NULL;
        }
        strcpy_s(items[count].fname, nlen + 1, fd.cFileName);
        items[count].fsize = ((unsigned long long)fd.nFileSizeHigh << 32) | fd.nFileSizeLow;
        count++;
    } while (FindNextFileA(hf, &fd));

    FindClose(hf);
    *outCount = count;
    return items;
}

