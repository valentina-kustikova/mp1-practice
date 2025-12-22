#include <stdio.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>

#define DEBUG

#define CATALOG_SORTER_FRAME "\
|-------------------------------------|\n\
|          Файловый менеджер          |\n\
|-------------------------------------|\n\n"

#define MAIN_OPERATIONS "\
Выберите операцию:\n\
1. Отсортировать каталог\n\
2. Выбрать метод сортировки\n\
0. Выход\n\n"

#define SORTING_METHODS "\
Методы сортировки:\n\
1. Простейшая сортировка\n\
2. Сортировка выбором максимального\n\
3. Сортировка вставками\n\
4. Сортировка пузырьком\n\
5. Быстрая сортировка\n\
6. Сортировка слиянием\n\n"

struct File {
    wchar_t name[256];
    long long size;
};


void openMenu(int* selectedMethod);

int main() {
    int selectedMethod = 3;
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    openMenu(&selectedMethod);
    return 0;
}

void selectMethodSorting(int* selectedMethod);
void sortingCatalog(int* selectedMethod);

void openMenu(int* selectedMethod) {
    while (1) {
        int operation;
        system("cls");
        printf(CATALOG_SORTER_FRAME);
        printf(MAIN_OPERATIONS);

        printf("Введите операцию: ");
        scanf_s("%d", &operation);
        while (operation < 0 || operation > 2) {
            printf("Некорректная операция. Введите операцию: ");
            scanf_s("%d", &operation);
        }

        if (operation == 1) {
            sortingCatalog(selectedMethod);
        }
        else if (operation == 2) {
            selectMethodSorting(selectedMethod);
        }
        else {
            break;
        }
    }
}

char* getNameSort(int selectedMethod);

void selectMethodSorting(int* selectedMethod) {
    int method;
    system("cls");
    printf(CATALOG_SORTER_FRAME);
    printf(SORTING_METHODS);

    printf("Сейчас выбран: %s\n", getNameSort(*selectedMethod));
    printf("Введите номер метода сортировки: ");
    scanf_s("%d", &method);
    while (method < 1 || method > 6) {
        printf("Некорректный номер. Введите номер метода сортировки: ");
        scanf_s("%d", &method);
    }
    *selectedMethod = method;
    printf("%s выбрана!\n\n", getNameSort(*selectedMethod));
    system("pause");
}

char* getNameSort(int selectedMethod) {
    switch (selectedMethod) {
    case 1: return "Простейшая сортировка";
    case 2: return "Сортировка выбором максимального";
    case 3: return "Сортировка вставками";
    case 4: return "Сортировка пузырьком";
    case 5: return "Быстрая сортировка";
    case 6: return "Сортировка слиянием";
    }
}

struct File* searchFiles(wchar_t* path, int* count);
void sortingCatalogRealization(int* selectedMethod, struct File* files, wchar_t* path, int count);

void sortingCatalog(int* selectedMethod) {
    wchar_t path[MAX_PATH];
    struct File* files = NULL;
    int count = 0;

    files = searchFiles(path, &count);

    if (files == NULL || count == 0) {
        printf("Не удалось найти файлы в каталоге!\n\n");
        system("pause");
        return;
    }

    sortingCatalogRealization(selectedMethod, files, path, count);

    free(files);
    system("pause");
}

struct File* searchFiles(wchar_t* path, int* count) {
    wchar_t searchPath[MAX_PATH];
    WIN32_FIND_DATAW findData;
    HANDLE hFind;
    struct File* files = NULL;

    system("cls");
    printf(CATALOG_SORTER_FRAME);

    while (getchar() != '\n');

    while (1) {
        printf("Введите путь к каталогу: ");
        fgetws(path, MAX_PATH, stdin);
        path[wcslen(path) - 1] = L'\0';


        DWORD attrs = GetFileAttributesW(path);
        if (attrs != INVALID_FILE_ATTRIBUTES && (attrs & FILE_ATTRIBUTE_DIRECTORY)) {
            break;
        }
        printf("Ошибка: путь некорректный или папка не существует\n");
    }


    swprintf_s(searchPath, MAX_PATH, L"%s\\*", path);

    hFind = FindFirstFileW(searchPath, &findData);
    do {
        if (wcscmp(findData.cFileName, L".") == 0 ||
            wcscmp(findData.cFileName, L"..") == 0 ||
            (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ||
            findData.dwFileAttributes & (FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM)) {
            continue;
        }

        struct File* temp = realloc(files, ((*count) + 1) * sizeof(struct File));
        if (temp == NULL) {
            free(files);
            FindClose(hFind);
            printf("Произошла непредвиденная ошибка!\n\n");
            system("pause");
            return;
        }
        files = temp;

        wcscpy_s(files[*count].name, 256, findData.cFileName);
        files[*count].size = ((long long)findData.nFileSizeHigh << 32) | findData.nFileSizeLow;

        (*count)++;
    } while (FindNextFileW(hFind, &findData));
    FindClose(hFind);
    return files;
}

void executionSelectedSorting(int* selectedMethod, struct File* files, int n);

void sortingCatalogRealization(int* selectedMethod, struct File* files, wchar_t* path, int count) {
    struct File* originalFiles = malloc(count * sizeof(struct File));
    memcpy(originalFiles, files, count * sizeof(struct File));

    while (1) {
        int operation, i;
        system("cls");
        printf(CATALOG_SORTER_FRAME);
        printf("Найдено %d файлов:\n\n", count);
        wprintf(L"Сортировка каталога \"%s\" ", path);
        printf("методом \"%s\"\n", getNameSort(*selectedMethod));
        memcpy(files, originalFiles, count * sizeof(struct File));
        executionSelectedSorting(selectedMethod, files, count);
        if (count < 10) for (i = 0; i < count; i++) {
            wprintf(L"%d. %ls - %lld байт\n", i + 1, files[i].name, files[i].size);
        }

        printf("\nХотите отсортировать другим методом (1 - да, 2 - нет): ");
        scanf_s("%d", &operation);
        while (operation < 1 || operation > 2) {
            printf("Неверный ответ. Хотите отсортировать другим методом (1 - да, 2 - нет): ");
            scanf_s("%d", &operation);
        }
        if (operation == 1) {
            selectMethodSorting(selectedMethod);
        }
        else {
            break;
        }
    }

    free(originalFiles);
}

void swap(struct File* a, struct File* b);
void sortEasy(struct File* files, int n);
void sortSelectMax(struct File* files, int n);
void sortPastes(struct File* files, int n);
void sortBubble(struct File* files, int n);
void quickSort(struct File* files, int first, int last);
void mergeSort(struct File* files, int l, int r, struct File* tmp);

void executionSelectedSorting(int* selectedMethod, struct File* files, int n) {
    struct timespec start, end;
    long seconds, nanoseconds;
    float elapsed_ms;
    struct File* tmp = *selectedMethod == 6 ? malloc(n * sizeof(struct File)) : NULL;

    switch (*selectedMethod) {
    case 1:
        timespec_get(&start, TIME_UTC);
        sortEasy(files, n);
        break;
    case 2:
        timespec_get(&start, TIME_UTC);
        sortSelectMax(files, n);
        break;
    case 3:
        timespec_get(&start, TIME_UTC);
        sortPastes(files, n);
        break;
    case 4:
        timespec_get(&start, TIME_UTC);
        sortBubble(files, n);
        break;
    case 5:
        timespec_get(&start, TIME_UTC);
        quickSort(files, 0, n - 1);
        break;
    case 6:
        timespec_get(&start, TIME_UTC);
        mergeSort(files, 0, n - 1, tmp);
        break;
    }
    timespec_get(&end, TIME_UTC);

    seconds = end.tv_sec - start.tv_sec;
    nanoseconds = end.tv_nsec - start.tv_nsec;
    elapsed_ms = seconds * 1000.0 + nanoseconds / 1000000.0;

    printf("Сортировка заняла %.2f мс\n\n", elapsed_ms);
    if (tmp != NULL) free(tmp);
}

void swap(struct File* a, struct File* b) {
    struct File temp = *a;
    *a = *b;
    *b = temp;
}

void sortEasy(struct File* files, int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (files[i].size < files[j].size)
                swap(&files[i], &files[j]);
}

void sortSelectMax(struct File* files, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        long long max = files[i].size, idx = i;
        for (j = i + 1; j < n; j++) {
            if (max < files[j].size) {
                max = files[j].size;
                idx = j;
            }
        }
        swap(&files[i], &files[idx]);
    }
}

void sortPastes(struct File* files, int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        struct File tmp = files[i];
        int j = i - 1;
        while (j >= 0 && files[j].size < tmp.size) {
            files[j + 1] = files[j];
            j--;
        }
        files[j + 1] = tmp;
    }
}

void sortBubble(struct File* files, int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (files[j + 1].size > files[j].size)
                swap(&files[j + 1], &files[j]);
}

void quickSort(struct File* files, int first, int last) {
    int f = first, l = last;
    long long mid = files[f + (l - f) / 2].size;
    while (f < l) {
        while (files[f].size > mid) f++;
        while (files[l].size < mid) l--;
        if (f <= l) {
            swap(&files[f], &files[l]);
            f++;
            l--;
        }
    }
    if (first < l) quickSort(files, first, l);
    if (f < last) quickSort(files, f, last);
}

void merge(struct File* files, int l, int m, int r, struct File* tmp);

void mergeSort(struct File* files, int l, int r, struct File* tmp) {
    int m;
    if (l >= r) return;

    m = l + (r - l) / 2;
    mergeSort(files, l, m, tmp);
    mergeSort(files, m + 1, r, tmp);
    merge(files, l, m, r, tmp);
}

void merge(struct File* files, int l, int m, int r, struct File* tmp) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (files[i].size >= files[j].size) {
            tmp[k] = files[i];
            i++;
            k++;
        }
        else {
            tmp[k] = files[j];
            j++;
            k++;
        }
    }
    if (i > m) {
        while (j <= r) {
            tmp[k] = files[j];
            j++;
            k++;
        }
    }
    if (j > r) {
        while (i <= m) {
            tmp[k] = files[i];
            i++;
            k++;
        }
    }
    for (i = l; i <= r; i++) {
        files[i] = tmp[i];
    }
}