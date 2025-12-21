#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>
#include <time.h>
#include <locale.h>

#define MAX_FILES 100

//C:\Users\geniy\OneDrive\Desktop\codelifehacks

char types_of_sort[6][MAX_FILES] = { "Simple", "Choise", "Insert", "Bubble", "Merge", "Quick"};
char types_of_order[2][MAX_FILES] = { "From small to big", "From big to small" };

typedef struct {
	char file_name[1000];
	long long int file_size;
}file_info;

file_info files_in_directory[MAX_FILES];
int file_cnt = 0;

void simple_sort(file_info files_in_directory[], int file_cnt, clock_t* start_time, clock_t* end_time);
void choise_sort(file_info files_in_directory[], int file_cnt, clock_t* start_time, clock_t* end_time);
void insert_sort(file_info files_in_directory[], int file_cnt, clock_t* start_time, clock_t* end_time);
void bubble_sort(file_info files_in_directory[], int file_cnt, clock_t* start_time, clock_t* end_time);

void merge_sort(file_info files_in_directory[], int l, int r);
void merge(file_info files_in_directory[], int l, int m, int r);

void quick_sort(file_info files_in_directory[], int l, int r);
int partition(file_info files_in_directory[], int l, int r);

void directory_reader(char path[]);

int main() {
    int dir_exists = -1, sort_choise = 0, order_choise = 0, i, l = 0, r = file_cnt-1;
    char path[MAX_PATH], search_path[MAX_PATH];
    clock_t start_time, end_time;
    double time_diff;

    setlocale(LC_ALL, "rus");

    directory_reader(path);

    snprintf(search_path, sizeof(search_path), "%s\\*", path);
    WIN32_FIND_DATAA file_data;
    HANDLE hFind = FindFirstFileA(search_path, &file_data);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Directory does not exist.\n");
        return;
    }

    do {
        if (!(file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            strcpy_s(files_in_directory[file_cnt].file_name, sizeof(files_in_directory[file_cnt].file_name), file_data.cFileName);
            files_in_directory[file_cnt].file_size = (long long)file_data.nFileSizeLow + ((long long)file_data.nFileSizeHigh << 32);
            file_cnt++;
        }
    } while (FindNextFileA(hFind, &file_data) && file_cnt < MAX_FILES);

    FindClose(hFind);

    system("cls");
    printf("Directory: %s\n\n", path);

    printf("Choose sort type:\n\n1. Simple\n2. Choise\n3. Insert\n4. Bubble\n5. Merge\n6. Quick\n\n");
    while (sort_choise < 1 || sort_choise > 6) {
        scanf_s("%d", &sort_choise);
        if (sort_choise < 1 || sort_choise > 6) {
            printf("Wrong input. Try again.\n");
        }
    }

    system("cls");
    printf("Directory: %s\n", path);
    printf("Sort type: %s\n\n", types_of_sort[sort_choise-1]);

    printf("Choose sort order:\n\n1. From small to big\n2. From big to small\n\n");
    while (order_choise < 1 || order_choise > 2) {
        scanf_s("%d", &order_choise);
        if (order_choise < 1 || order_choise > 2) {
            printf("Wrong input. Try again.\n");
        }
    }

    system("cls");
    printf("Directory: %s\n", path);
    printf("Sort type: %s\n", types_of_sort[sort_choise - 1]);
    printf("Order: %s\n\n", types_of_order[order_choise - 1]);

    switch (sort_choise) {
    case 1: 
        simple_sort(files_in_directory, file_cnt, &start_time, &end_time);
        break;
    case 2:
        choise_sort(files_in_directory, file_cnt, &start_time, &end_time);
        break;
    case 3: 
        insert_sort(files_in_directory, file_cnt, &start_time, &end_time);
        break;
    case 4:
        bubble_sort(files_in_directory, file_cnt, &start_time, &end_time);
        break;
    case 5: 
        start_time = clock();
        merge_sort(files_in_directory, l, r);
        end_time = clock();
        break;
    case 6: 
        start_time = clock();
        quick_sort(files_in_directory, l, r);
        end_time = clock();
        break;
    default:
        printf("Error.\n");
        break;
    }

    switch(order_choise){
    case 1:
        for (i = 0; i < file_cnt; i++) {
            printf("%s | %lld B\n\n", files_in_directory[i].file_name, files_in_directory[i].file_size);
        }
        break;
    case 2:
        for (i = file_cnt-1; i >= 0; i--) {
            printf("%s | %lld B\n\n", files_in_directory[i].file_name, files_in_directory[i].file_size);
        }
        break;
    default:
        printf("Error.\n\n");
        break;
    }

    time_diff = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time: %f\n", time_diff);

	return 0;
}

void directory_reader(char path[]) {
    char temp_path[MAX_PATH];
    int access = 0;
    do {
        printf("Input path to the directory:\n");
        if (fgets(temp_path, sizeof(temp_path), stdin) == NULL) {
            printf("Wrong Input. Try again.\n");
            continue;
        }
        size_t len = strnlen_s(temp_path, sizeof(temp_path));
        while (len > 0 && isspace((unsigned char)temp_path[len - 1])) {
            len--;
        }
        size_t start_of_path = 0;
        while (start_of_path < len && isspace((unsigned char)temp_path[start_of_path])) {
            start_of_path++;
        }
        len -= start_of_path;
        if (len == 0) {
            printf("Wrong Input. Try again.\n");
            continue;
        }
        if (len >= MAX_PATH) {
            printf("Wrong Input. Try again.\n");
            continue;
        }
        if (memcpy_s(path, MAX_PATH, temp_path + start_of_path, len) != 0) {
            path[0] = '\0';
            printf("Wrong Input. Try again.\n");
            continue;
        }
        path[len] = '\0';
        access = 1;
    } while (!access);
}

void simple_sort(file_info files_in_directory[], int file_cnt, clock_t* start_time, clock_t* end_time) {
    *start_time = clock();
    int i, j;
    for (i = 0; i < file_cnt; i++) {
        for (j = i + 1; j < file_cnt; j++) {
            if (files_in_directory[i].file_size > files_in_directory[j].file_size) {
                file_info tmp = files_in_directory[i];
                files_in_directory[i] = files_in_directory[j];
                files_in_directory[j] = tmp;
            }
        }
    }
    *end_time = clock();
}

void choise_sort(file_info files_in_directory[], int file_cnt, clock_t* start_time, clock_t* end_time) {
    *start_time = clock();
    int i, j;
    for (i = 0; i < file_cnt; i++) {
        file_info min = files_in_directory[i];
        int ind = i;
        for (j = i + 1; j < file_cnt; j++) {
            if (min.file_size > files_in_directory[j].file_size) {
                min = files_in_directory[j];
                ind = j;
            }
        }
        files_in_directory[ind] = files_in_directory[i];
        files_in_directory[i] = min;
    }
    *end_time = clock();
}

void insert_sort(file_info files_in_directorya[], int file_cnt, clock_t* start_time, clock_t* end_time) {
    *start_time = clock();
    int i;
    for (i = 1; i < file_cnt; i++) {
        int j = i - 1;
        file_info tmp = files_in_directory[i];
        while (j >= 0 && files_in_directory[j].file_size > tmp.file_size) {
            files_in_directory[j + 1] = files_in_directory[j];
            j--;
        }
        files_in_directory[j + 1] = tmp;
    }
    *end_time = clock();
}

void bubble_sort(file_info files_in_directory[], int file_cnt, clock_t* start_time, clock_t* end_time) {
    *start_time = clock();
    int i, j;
    for (i = 0; i < file_cnt; i++) {
        for (j = 0; j < file_cnt - i - 1; j++) {
            if (files_in_directory[j + 1].file_size < files_in_directory[j].file_size) {
                file_info tmp = files_in_directory[j];
                files_in_directory[j] = files_in_directory[j + 1];
                files_in_directory[j + 1] = tmp;
            }
        }
    }
    *end_time = clock();
}

void merge_sort(file_info files_in_directory[], int l, int r) {
    int m;
    if (l + 1 >= r) return;
    m = l + (r - l) / 2;
    merge_sort(files_in_directory, l, m);
    merge_sort(files_in_directory, m + 1, r);
    merge(files_in_directory, l, m, r);
}

void merge(file_info files_in_directory[], int l, int m, int r) {
    file_info* b = (file_info*)malloc(MAX_FILES * sizeof(file_info));
    int it1 = 0, it2 = 0, i;
    while (it1 <= m && it2 < r) {
        if (files_in_directory[l + it1].file_size < files_in_directory[m + it2 + 1].file_size) {
            b[it1 + it2] = files_in_directory[l + it1];
            it1++;
        }
        else {
            b[it1 + it2] = files_in_directory[m + it2 + 1];
            it2++;
        }
    }
    while (it1 <= m - l) {
        b[it1 + it2] = files_in_directory[it1 + l];
        it1++;
    }
    while (it2 < r - m) {
        file_info* b = (file_info*)malloc(MAX_FILES * sizeof(file_info));
        it2++;
    }
    for (i = 0; i < it1 + it2; i++) {
        files_in_directory[l + i] = b[i];
    }
    free(b);
}

void quick_sort(file_info files_in_directory[], int l, int r) {
    if (l < r) {
        int pi = partition(files_in_directory, l, r);
        quick_sort(files_in_directory, l, pi - 1);
        quick_sort(files_in_directory, pi + 1, r);
    }
}

int partition(file_info files_in_directory[], int l, int r) {
    file_info p = files_in_directory[l];
    int i = l;
    int j = r;
    while (i < j) {
        while (files_in_directory[i].file_size <= p.file_size && i <= r - 1) {
            i++;
        }
        while (files_in_directory[j].file_size > p.file_size && j >= l + 1) {
            j--;
        }
        if (i < j) {
            file_info tmp = files_in_directory[i];
            files_in_directory[i] = files_in_directory[j];
            files_in_directory[j] = tmp;
        }
    }
    file_info tmp = files_in_directory[l];
    files_in_directory[l] = files_in_directory[j];
    files_in_directory[j] = tmp;
    return j;
}