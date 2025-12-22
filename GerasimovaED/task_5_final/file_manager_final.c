#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>
#include <locale.h>

#define MAX_FILES 100

//C:\Users\geniy\OneDrive\Desktop\codelifehacks
//C:\Users\geniy\OneDrive\Desktop\photo

char types_of_sort[6][MAX_FILES] = { "Simple", "Choise", "Insert", "Bubble", "Merge", "Quick"};
char types_of_order[2][MAX_FILES] = { "From small to big", "From big to small" };

typedef struct {
	char file_name[1000];
	long long int file_size;
}file_info;

file_info files_in_directory[MAX_FILES];
int file_cnt = 0;

void simple_sort(file_info files_in_directory[], int file_cnt);
void choise_sort(file_info files_in_directory[], int file_cnt);
void insert_sort(file_info files_in_directory[], int file_cnt);
void bubble_sort(file_info files_in_directory[], int file_cnt);
void merge_sort(file_info files_in_directory[], int file_size);
void quick_sort(file_info files_in_directory[], int l, int r);
void directory_reader(char path[]);

int main() {
    int dir_exists = -1, sort_choise = 0, order_choise = 0, i, l = 0, r = file_cnt-1;
    char path[MAX_PATH], search_path[MAX_PATH];
    LARGE_INTEGER start_time, end_time, frequency;
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
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start_time);
        simple_sort(files_in_directory, file_cnt);
        QueryPerformanceCounter(&end_time);
        break;
    case 2:
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start_time);
        choise_sort(files_in_directory, file_cnt);
        QueryPerformanceCounter(&end_time);
        break;
    case 3: 
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start_time);
        insert_sort(files_in_directory, file_cnt);
        QueryPerformanceCounter(&end_time);
        break;
    case 4:
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start_time);
        bubble_sort(files_in_directory, file_cnt);
        QueryPerformanceCounter(&end_time);
        break;
    case 5: 
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start_time);
        merge_sort(files_in_directory, file_cnt);
        QueryPerformanceCounter(&end_time);
        break;
    case 6: 
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start_time);
        quick_sort(files_in_directory, l, r);
        QueryPerformanceCounter(&end_time);
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

    time_diff = (double)(end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart;
    printf("Time: %.10f\n", time_diff);

	return 0;
}

void directory_reader(char path[]) {
    char tmp_path[MAX_PATH];
    int access = 0;
    do {
        printf("Input path to the directory:\n");
        if (fgets(tmp_path, sizeof(tmp_path), stdin) == NULL) {
            printf("Wrong Input. Try again.\n");
            continue;
        }
        size_t len = strnlen_s(tmp_path, sizeof(tmp_path));
        while (len > 0 && isspace((unsigned char)tmp_path[len - 1])) {
            len--;
        }
        size_t start_of_path = 0;
        while (start_of_path < len && isspace((unsigned char)tmp_path[start_of_path])) {
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
        if (memcpy_s(path, MAX_PATH, tmp_path + start_of_path, len) != 0) {
            path[0] = '\0';
            printf("Wrong Input. Try again.\n");
            continue;
        }
        path[len] = '\0';
        access = 1;
    } while (!access);
}

void simple_sort(file_info files_in_directory[], int file_cnt) {
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
}

void choise_sort(file_info files_in_directory[], int file_cnt) {
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
}

void insert_sort(file_info files_in_directorya[], int file_cnt) {
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
}

void bubble_sort(file_info files_in_directory[], int file_cnt) {
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
}

void merge_sort(file_info files_in_directory[], int file_cnt) {
    file_info* tmp = (file_info*)malloc(file_cnt * sizeof(file_info));
    if (tmp == NULL) return;
    for (int curr_size = 1; curr_size < file_cnt; curr_size *= 2) {
        for (int left_start = 0; left_start < file_cnt - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, file_cnt - 1);
            int right_end = min(left_start + 2 * curr_size - 1, file_cnt- 1);
            int i = left_start;
            int j = mid + 1;
            int k = left_start;
            for (int m = left_start; m <= right_end; m++) {
                tmp[m] = files_in_directory[m];
            }
            while (i <= mid && j <= right_end) {
                if (tmp[i].file_size <= tmp[j].file_size) {
                    files_in_directory[k] = tmp[i];
                    i++;
                }
                else {
                    files_in_directory[k] = tmp[j];
                    j++;
                }
                k++;
            }
            while (i <= mid) {
                files_in_directory[k] = tmp[i];
                i++;
                k++;
            }
        }
    }
    free(tmp);
}

void quick_sort(file_info files_in_directory[], int l, int r) {
    int i = l, j = r;
    file_info x = files_in_directory[(l + r) / 2];

    do {
        while (files_in_directory[i].file_size < x.file_size) i++;
        while (files_in_directory[j].file_size > x.file_size) j--;

        if (i <= j) {
            if (files_in_directory[i].file_size > files_in_directory[j].file_size) {
                file_info tmp = files_in_directory[i];
                files_in_directory[i] = files_in_directory[j];
                files_in_directory[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < r)
        quick_sort(files_in_directory, i, r);
    if (l < j)
        quick_sort(files_in_directory, l, j);
}