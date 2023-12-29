#include <stdio.h>
#include <time.h>
#include "dirent.h"

typedef struct File {
    char* name;
    long int size;
} File;

DIR* d;
struct dirent* ent;

int stat(const char* path_to_file, struct stat* buf);

char* path_to_file(const char* a1, const char* a2) {

    size_t a1_length = strlen(a1), a2_length = strlen(a2),
    a3_length = a1_length + 1 + a2_length + 1;

    char* a3 = malloc(a3_length * sizeof(char));
    if (a3 == NULL) {
        printf("The error of memory\n");
        return NULL;
    }
    strcpy(a3, a1);
    strcat(a3, "/");
    strcat(a3, a2);
    return a3;
}

char* convertation(const char* a1) {
    size_t a1_length = strlen(a1), a3_length = a1_length + 1;
    char* a3 = (char*)malloc(a3_length * sizeof(char));
    strcpy(a3, a1);
    
    return a3;
}

int files_number(char path[100]) {
    int n = 0;
    d = opendir(path);
    if (d) { 
        while ((ent = readdir(d)) != NULL) { 
            if (ent->d_type != DT_REG) { 
                continue;
            } 
            n++; 
        }
        closedir(d); 
    } 
    return n; 
}

int size_cmp(const void* a, const void* b) {
    File* c = (File*)a;
    File* d = (File*)b;
    return (c->size - d->size);
}

void selectionSort(File* files, int count) {
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < count; j++) {
            if (files[j].size < files[minIndex].size) {
                minIndex = j;
            }
        }
        File temp = files[minIndex];
        files[minIndex] = files[i];
        files[i] = temp;
    }
}

void insertionSort(File* files, int count) {
    for (int i = 1; i < count; i++) {
        File key = files[i];
        int j = i - 1;
        while (j >= 0 && files[j].size > key.size) {
            files[j + 1] = files[j];
            j--;
        }
        files[j + 1] = key;
    }
}

void merge(File* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    File* L = (File*)malloc(n1 * sizeof(File));
    File* R = (File*)malloc(n2 * sizeof(File));


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i].size <= R[j].size) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(File* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void showFiles(File* files, int N) {
    for (int i = 0; i < N; i++) {
        printf("File name: %s, Size: %ld bytes\n", files[i].name, files[i].size);
    }
}

void main() {
    int i = 0, number, choice = 0;
    char path[100];
    clock_t t_start; 
    clock_t t_finish; 
    double time_f;
    struct stat fileStat;
    struct File* files_old;
    struct File* files;

    printf("Input way: ");
    scanf("%s", path);
    number = files_number(path); 
    files_old = (File*)malloc(number * sizeof(File));
    d = opendir(path);
    if (d) {
        while ((ent = readdir(d)) != NULL) { 
            char* Pathfile;
            if (ent->d_type != DT_REG) {
                continue;
            }
            Pathfile = path_to_file(path, ent->d_name); 
            stat(Pathfile, &(fileStat)); 
            free(Pathfile);
            
            File new = { convertation(ent->d_name), fileStat.st_size }; 

            files_old[i].name = (char*)malloc((strlen(new.name) + 1) * sizeof(char)); 
            memcpy(files_old[i].name, new.name, strlen(new.name) + 1);
            files_old[i].size = new.size;
            i++;
        }
        closedir(d);
    }

    files = (File*)malloc(number * sizeof(File));
    do {
        for (i = 0; i < number; i++) {
            files[i].name = (char*)malloc((strlen(files_old[i].name) + 1) * sizeof(char));
            memcpy(files[i].name, files_old[i].name, strlen(files_old[i].name) + 1);
            files[i].size = files_old[i].size;
        }
        printf("Input choice: 1 - Print files\n");
        printf("Input choice for sorting methods: 2 - selection sort, 3 - insertion sort, 4 - merge sort\n");
        printf("Print 5 to finish program\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            showFiles(files_old, number);
            break;
        case 2:
            t_start = clock();
            selectionSort(files, number); 
            t_finish = clock();
            showFiles(files, number);
            time_f = (double)((t_finish - t_start)) / CLOCKS_PER_SEC; 

            printf("Time: %.5lf\n", time_f);
            break;
        case 3:
            t_start = clock();
            insertionSort(files, number); 
            t_finish = clock();
            showFiles(files, number);  
            time_f = (double)((t_finish - t_start)) / CLOCKS_PER_SEC;
            printf("Time: %.5lf\n", time_f);
            break;
        case 4:
            t_start = clock();
            mergeSort(files, 0, number - 1);  
            t_finish = clock();
            showFiles(files, number); 
            time_f = (double)((t_finish - t_start)) / CLOCKS_PER_SEC;
            printf("Time: %.5lf\n", time_f);
            break;
        case 5:
            break;
        default:
            printf("Wrong choice\n");
        }
        for (i = 0; i < number; i++)
        {
            free(files[i].name);
        }

    } while (choice != 5);

    free(files);
    for (i = 0; i < number; i++)
    {
        free(files_old[i].name);
    }
    free(files_old);
}
    

    
    
    
    

    
