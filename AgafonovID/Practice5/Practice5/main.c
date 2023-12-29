#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_LEN 255

typedef struct {
    char names[MAX_LEN];
    int size;
}fileinfo;

typedef struct {
    char names[MAX_LEN];
    int size;
}fileinfo_cpy;

int count_files(char* path) {
    int k = 0;
    char search_path[MAX_LEN];
    sprintf(search_path, "%s\\*.*", path);
    WIN32_FIND_DATAA Files;
    HANDLE file = FindFirstFileA(search_path, &Files);
    if (file != INVALID_HANDLE_VALUE) {
        do {
            if (!(Files.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                k++;
            }
        } while (FindNextFileA(file, &Files) != 0);
        FindClose(file);
    }
    return k;
}


void find_files(char* path, fileinfo* files, int k) {
    int i = 0;
    char search_path[MAX_LEN];
    snprintf(search_path, MAX_LEN, "%s\\*.*", path);
    WIN32_FIND_DATAA FileData;
    HANDLE file = FindFirstFileA(search_path, &FileData);
    if (file == INVALID_HANDLE_VALUE) {
        printf("Не удалось найти файл\n");
    }
    else {
        while (FindNextFileA(file, &FileData) != 0) {
            if (!(FileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                strcpy((files)[i].names, FileData.cFileName);
                (files)[i].size = FileData.nFileSizeLow;
                i++;
            }
        }
        printf("Количество найденных файлов: %d\n", i);
    }
    FindClose(file);
}

void bubble_sorting(fileinfo files[], int k) {
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (files[j].size > files[j + 1].size) {
                fileinfo temp = files[j];
                files[j] = files[j + 1];
                files[j + 1] = temp;
            }
        }
    }
}

void insert_sorting(fileinfo files[], int k) {
    for (int i = 1; i < k; i++) {
        fileinfo min = files[i];
        int j = i - 1;
        while (j >= 0 && files[j].size > min.size) {
            files[j + 1] = files[j];
            j--;
        }
        files[j + 1] = min;
    }
}

void merge(fileinfo files[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    fileinfo* L = (fileinfo*)malloc(n1 * sizeof(fileinfo));
    fileinfo* R = (fileinfo*)malloc(n2 * sizeof(fileinfo));
    if (L == NULL || R == NULL) {
        printf("Ошибка выделения памяти\n");
        return;
    }

    for (i = 0; i < n1; i++)
        L[i] = files[l + i];
    for (j = 0; j < n2; j++)
        R[j] = files[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i].size <= R[j].size) {
            files[k] = L[i];
            i++;
        }
        else {
            files[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        files[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        files[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void merge_sort(fileinfo files[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(files, l, m);
        merge_sort(files, m + 1, r);
        merge(files, l, m, r);
    }
}

void sorted_files(fileinfo files[], int k) {
    for (int i = 0; i < k; i++) {
        printf("Имя файла %s, размер %d байт\n", files[i].names, files[i].size);
    }
}
void cpy(fileinfo files[],fileinfo_cpy files2[], int k) {
    for (int i = 0; i < k; i++) {
        strcpy(files2[i].names, files[i].names);
        (files2)[i].size = files[i].size;
    }
}
void cpy_back(fileinfo files[], fileinfo_cpy files2[], int k) {
    for (int i = 0; i < k; i++) {
        strcpy(files[i].names, files2[i].names);
        (files)[i].size = files2[i].size;
    }
}

int main() {
    char path[MAX_LEN];
    int len, k, method, true = 0;
    clock_t start, finish;
    double duration;
    len = strlen(path);
    k = count_files(path);
    fileinfo* files = (fileinfo*)malloc(k * sizeof(fileinfo));
    fileinfo_cpy* files2 = (fileinfo_cpy*)malloc(k * sizeof(fileinfo_cpy));

    setlocale(LC_ALL, "Rus");

    printf("Файловый менеджер\n");
    printf("Введите путь: \n");
    fgets(path, MAX_LEN, stdin);
    
    if (len > 0 && path[len - 1] == '\n') {
        path[len - 1] = '\0';
    }
    
    if (files == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }
    find_files(path, files, k);
    cpy(files, files2, k);
    
    while (true != 1) {
        printf("Какой метод сортировки использовать?(1 - пузырьком, 2 - вставками, 3 - слиянием, 4 - выйти):\n");
        scanf("%d", &method);
        switch (method) {
        case 1:
            start = clock();
            bubble_sorting(files, k);
            sorted_files(files, k);
            finish = clock();
            duration = ((double)(finish - start)) / CLOCKS_PER_SEC;
            printf("Время выполнения %.3lfс\n", duration);
            break;
        case 2:
            start = clock();
            insert_sorting(files, k);
            sorted_files(files, k);
            finish = clock();
            duration = ((double)(finish - start)) / CLOCKS_PER_SEC;
            printf("Время выполнения %.3lfс\n", duration);
            break;
        case 3:
            start = clock();
            merge_sort(files, 0, k - 1);
            sorted_files(files, k);
            finish = clock();
            duration = ((double)(finish - start)) / CLOCKS_PER_SEC;
            printf("Время выполнения %.3lfс\n", duration);
            break;
        case 4:
            true = 1;
            break;
        default:
            printf("Неверный ввод\n");
            break;
        }
        cpy_back(files, files2, k);
        
    }
    free(files);
    free(files2);
    return 0;
}