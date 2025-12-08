#include <stdio.h>
#include <sys/time.h>
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
Методы сортировок:\n\
1. Прострейшая сортировка\n\
2. Сортировка выбором минимального\n\
3. Сортировка вставками\n\
4. Сортировка пузырьком\n\
5. Быстрая сортировка\n\
6. Сортировка слиянием\n\n"

struct File {
    wchar_t name[256];
    long long size;
};

void selectMethodSorting(int* selectedMethod);
void sortingCatalog(int* selectedMethod);

int main() {
    int selectedMethod = 3;
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

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
            sortingCatalog(&selectedMethod);
        }
        else if (operation == 2) {
            selectMethodSorting(&selectedMethod);
        }
        else {
            break;
        }
    }
    return 0;
}

char* getNameSort(int selectedMethod);

void selectMethodSorting(int* selectedMethod) {
    int method;
    system("cls");
    printf(CATALOG_SORTER_FRAME);
    printf(SORTING_METHODS);

    printf("Сейчас выбрана: %s\n", getNameSort(*selectedMethod));
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
        case 2: return "Сортировка выбором минимального";
        case 3: return "Сортировка вставками";
        case 4: return "Сортировка пузырьком";
        case 5: return "Быстрая сортировка";
        case 6: return "Сортировка слиянием";
    }
}

void executionSelectedSorting(int* selectedMethod, struct File* files, int n);

void sortingCatalog(int* selectedMethod) {
    wchar_t path[MAX_PATH];
    wchar_t searchPath[MAX_PATH];
    WIN32_FIND_DATAW findData;
    HANDLE hFind;
    struct File* files = NULL;
    int count = 0;
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
        wprintf(L"%s", path);
    }

    
    swprintf_s(searchPath, MAX_PATH, L"%s\\*", path);

    hFind = FindFirstFileW(searchPath, &findData);
    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Не удалось найти файлы в каталоге!\n\n");
        system("pause");
        return;
    }

    do {
        if (strcmp(findData.cFileName, ".") == 0 ||
            strcmp(findData.cFileName, "..") == 0 ||
            (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            continue;
        }

        struct File* temp = realloc(files, (count + 1) * sizeof(struct File));
        if (temp == NULL) {
            free(files);
            FindClose(hFind);
            printf("Произошла непредвиденная ошибка!\n\n");
            system("pause");
            return;
        }
        files = temp;

        wcscpy_s(files[count].name, 256, findData.cFileName);
        files[count].size = findData.nFileSizeLow;

        count++;
    } while (FindNextFile(hFind, &findData));
    FindClose(hFind);

    while (1) {
        int operation;
        system("cls");
        printf(CATALOG_SORTER_FRAME);
		printf("Найдено %d файлов:\n\n", count);
        wprintf(L"Сортировка каталога \"%s\"", path);
        printf("методом \"%s\"\n", getNameSort(*selectedMethod));
		executionSelectedSorting(selectedMethod, files, count);

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

    free(files);
    system("pause");
}

void swap(struct File* a, struct File* b);
void sortEasy(struct File* files, int n);
void sortSelectMin(struct File* files, int n);
void sortPastes(struct File* files, int n);
void sortBubble(struct File* files, int n);
void quickSort(struct File* files, int first, int last);
void mergeSort(struct File* files, int l, int r);

void executionSelectedSorting(int* selectedMethod, struct File* files, int n) {
	struct timeval start, end;
	long seconds, microseconds;
	gettimeofday(&start, NULL);
	switch (*selectedMethod) {
		case 1: 
			sortEasy(files, n);
			break;
		case 2: 
			sortSelectMin(files, n);
			break;
		case 3: 
			sortPastes(files, n);
			break;
		case 4: 
			sortBubble(files, n);
			break;
		case 5: 
			quickSort(files, 0, n - 1);
			break;
		case 6: 
			mergeSort(files, 0, n - 1);
			break;
	}
	gettimeofday(&end, NULL);
	seconds = end.tv_sec - start.tv_sec;

	
	printf("Сортировка заняла %.3f мс\n\n");
}

void swap(struct File* a, struct File* b) {
	struct File* temp = a;
	a = b;
	b = temp;
}

void sortEasy(struct File* files, int n) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (files[i].size > files[j].size)
				swap(&files[i], &files[j]);
}

void sortSelectMin(struct File* files, int n) {

}

void sortPastes(struct File* files, int n) {

}

void sortBubble(struct File* files, int n) {

}

void quickSort(struct File* files, int first, int last) {

}

void mergeSort(struct File* files, int l, int r) {

}
