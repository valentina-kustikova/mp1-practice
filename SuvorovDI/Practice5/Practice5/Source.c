#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <profileapi.h>
#include <malloc.h>

#define MAX_PATH_LEN 100

void getFiles(char* path, struct file* files);
int getCountOfFiles(char* path);
int* getlensFileNames(char* path, int count_files);
void quick_sort(struct file* files, int size);
void merge(struct file* files, int l, int mid, int r);
void mergeSort(struct file* files, int l, int r);
void bubble_sort(struct file* files, int len);
void print_gap();
void print_files(struct file* files, int len);
struct file* cpy_arr(struct file* files, int len, int* lensNames);
char* getPath();
void sortFiles(struct file* files, int len, int* lensNames);

struct file {
    char* name;
    int size;
};

int main() {
    struct file* files;
    char path[MAX_PATH_LEN];
    int count_files;
    int* lensNames;
    int i;

    strcpy(path, getPath());

    count_files = getCountOfFiles(path); // counting the number of files
    lensNames = getlensFileNames(path, count_files); // counting the length of file names

    files = (struct file*)malloc(count_files * sizeof(struct file));
    for (i = 0; i < count_files; i++) {
        files[i].name = (char*)malloc((lensNames[i] + 1) * sizeof(char));
    }

    getFiles(path, files);

    sortFiles(files, count_files, lensNames);

    
    // free memory
    for (i = 0; i < count_files; i++) {
        free(files[i].name);
    }
    
    free(files);
    
    

    return 0;
}

void sortFiles(struct file* files, int count_files, int* lensNames) {
    struct file* copy;
    char sort_selection[100] = "";
    char sortEnough[100] = "";
    int i;
    int enough = 1;
    long long time1;
    long long time2;
    

    printf("\nOk, I got all the files, how do you want to sort them?\n");

    while (enough) {
        printf("Enter '1' - if you want to use a bubble_sort, '2' -- merge_sort, '3' -- quick_sort:\n");
        do {
            gets(sort_selection);

            if ((strcmp(sort_selection, "1") != 0) && (strcmp(sort_selection, "2") != 0) && (strcmp(sort_selection, "3") != 0)) {
                printf("incorrest data, please enter '1' - if you want to use a bubble_sort, '2' -- merge_sort, '3' -- quick_sort:\n");
            }
        } while ((strcmp(sort_selection, "1") != 0) && (strcmp(sort_selection, "2") != 0) && (strcmp(sort_selection, "3") != 0));

        copy = cpy_arr(files, count_files, lensNames);
        if (strcmp(sort_selection, "1") == 0) {
            printf("\nList of files as they are located in the directory\n");
            print_files(copy, count_files);
            print_gap();
            QueryPerformanceCounter(&time1);
            bubble_sort(copy, count_files);
            QueryPerformanceCounter(&time2);
            printf("\nThis is sorted list of your files in this directory (sorted by bubble_sort)\n");
            print_files(copy, count_files);
        }
        else if (strcmp(sort_selection, "2") == 0) {
            printf("\nList of files as they are located in the directory\n");
            print_files(copy, count_files);
            print_gap();
            QueryPerformanceCounter(&time1);
            mergeSort(copy, 0, count_files - 1);
            QueryPerformanceCounter(&time2);
            printf("\nThis is sorted list of your files in this directory (sorted by merge_sort)\n");
            print_files(copy, count_files);
        }
        else {
            printf("\nList of files as they are located in the directory\n");
            print_files(copy, count_files);
            print_gap();
            QueryPerformanceCounter(&time1);
            quick_sort(copy, count_files);
            QueryPerformanceCounter(&time2);
            printf("\nThis is sorted list of your files in this directory (sorted by quick_sort)\n");
            print_files(copy, count_files); 
        }
        printf("it took exactly %lld milliseconds to sort\n\n", time2 - time1);
        printf("If you want to sort again this directory -- enter 'again', else - enter 'enough'\n");
        
        do {
            gets(sortEnough);

            if ((strcmp(sortEnough, "again") != 0) && (strcmp(sortEnough, "enough") != 0)) {
                printf("incorrest data, please enter only 'again' or 'enough'\n");
            }
        } while ((strcmp(sortEnough, "again") != 0) && (strcmp(sortEnough, "enough") != 0));

        if (strcmp(sortEnough, "enough") == 0) {
            enough = 0;
        }

        // free memory
        for (i = 0; i < count_files; i++) {
            free(copy[i].name);
        }
        free(copy);
    }  
}

char* getPath() {
    char path[MAX_PATH_LEN];
    int getPathSuccess = 0;
    while (!getPathSuccess) {
        printf("enter the path to directory which files you want to look at:\n");
        gets(path);

        strcat(path, "//*");

        if (checkPath(path)) {
            getPathSuccess = 1;
        }
        else {
            printf("Path is incorrect\n Try again, don't give up!!!\n");
        }
    }
    return path;
}


int checkPath(char* path) {
    WIN32_FIND_DATAA files_data;
    HANDLE h_file = FindFirstFileA(path, &files_data);

    FindNextFileA(h_file, &files_data);
    if (h_file == INVALID_HANDLE_VALUE) {
        return 0;
    }
    return 1;
}

struct file* cpy_arr(struct file* files, int len, int* lensNames) {
    int i;
    struct file* copy_files;
    copy_files = (struct file*)malloc(len * sizeof(struct file));
    for (i = 0; i < len; i++) {
        copy_files[i].name = (char*)malloc((lensNames[i] + 1) * sizeof(char));
    }
    for (i = 0; i < len; i++) {
        strcpy(copy_files[i].name, files[i].name);
        copy_files[i].size = files[i].size;
    }

    return copy_files;
}

int getCountOfFiles(char* path) {
    int count = 0;
    WIN32_FIND_DATAA files_data;
    HANDLE h_file = FindFirstFileA(path, &files_data);

    FindNextFileA(h_file, &files_data);
    
    while (FindNextFileA(h_file, &files_data) != NULL) {
        if (files_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            continue;
        }
        count++;
    }
    FindClose(h_file);
    
    return count;
}

int* getlensFileNames(char* path, int count_files) {
    int* lens = (int*)malloc(count_files * sizeof(int));
    WIN32_FIND_DATAA files_data;
    HANDLE h_file = FindFirstFileA(path, &files_data);

    FindNextFileA(h_file, &files_data);
    
    int i = 0;
    while (FindNextFileA(h_file, &files_data) != NULL) {
        if (files_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            continue;
        }
        lens[i] = strlen(files_data.cFileName);
        i++;
    }
    FindClose(h_file);
    
    return lens;
}

void getFiles(char* path, struct file* files) {
    WIN32_FIND_DATAA files_data;
    HANDLE h_file = FindFirstFileA(path, &files_data);

    FindNextFileA(h_file, &files_data);
    
    int i = 0;
    printf("Here what I found:\n");
    while (FindNextFileA(h_file, &files_data) != NULL) {
        if (files_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            continue;
        }
        printf("%s       ", files_data.cFileName);
        strcpy(files[i].name, files_data.cFileName);
        printf("%d\n", files_data.nFileSizeLow);
        files[i].size = files_data.nFileSizeLow;

        i++;
    }
    FindClose(h_file);
    
}

void print_files(struct file* files, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%s   %d\n", files[i].name, files[i].size);
    }
}

void print_gap() {
    printf("\n-----------------------------------\n");
}

void bubble_sort(struct file* files, int len) {
    int i, j;
    struct file tmp;
    tmp.name = "";
    tmp.size = 0;

    for (i = 0; i < len; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            tmp.name = "111";
            tmp.size = -1;
            if (files[j + 1].size < files[j].size) {
                tmp = files[j];
                files[j] = files[j + 1];
                files[j + 1] = tmp;
            }
        }
    }

}

void mergeSort(struct file* files, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;

        mergeSort(files, l, mid);
        mergeSort(files, mid + 1, r);

        merge(files, l, mid, r);
    }
}

void merge(struct file* files, int l, int mid, int r) {
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    struct file* L;
    struct file* R;
    L = (struct file*)malloc(n1 * sizeof(struct file));
    R = (struct file*)malloc(n2 * sizeof(struct file));

    //Copy to temperary arrays
    for (i = 0; i < n1; i++)
        L[i] = files[l + i];
    for (j = 0; j < n2; j++)
        R[j] = files[mid + 1 + j];

    // Merge the temperary arrays
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

    // copy ending of L, if it's exists
    while (i < n1) {
        files[k] = L[i];
        i++;
        k++;
    }

    // copy ending of R, if it's exists
    while (j < n2) {
        files[k] = R[j];
        j++;
        k++;
    }

    free(R);
    free(L);

}

void quick_sort(struct file* files, int size) {
    // start & end of array
    int i = 0;
    int j = size - 1;
    struct file tmp;
    tmp.name = "111";
    tmp.size = -1;

    //middle
    int mid = files[size / 2].size;

    // greater -- to right, less -- to left
    do {
        while (files[i].size < mid) {
            i++;
        }

        while (files[j].size > mid) {
            j--;
        }

        if (i <= j) {
            tmp = files[i];
            files[i] = files[j];
            files[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //if there are something to sort
    if (j > 0) {
        // left part
        quick_sort(files, j + 1);
    }
    if (i < size) {
        // right part
        quick_sort(&files[i], size - i);
    }
}