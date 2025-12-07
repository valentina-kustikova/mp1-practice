#include <stdio.h>

#define DIRECTORY_COUNT 2
#define MAX_PATH_LEN 100
#define MAX_FILE_NAME_LEN 30
#define DIR_1_ELS 4
#define DIR_2_ELS 6

#define CHOICE_SORTING_METHOD_TEXT "\
Choose a sorting method:\n\
1. Simple sort\n\
2. Choose sort\n\
3. Insert sort\n\
4. Bubble sort\n\
5. Merge sort (not finished)\n\
6. Quick sort (not finished)\n\n\
Input number of your choice: "

#define CHOICE_SORT_BY_TEXT "\
Sort by:\n\
1. Increasing\n\
2. Descending\n\n\
Input number of your choice: "

//directories
char directories[DIRECTORY_COUNT][MAX_FILE_NAME_LEN] = {
    "dir_1",
    "dir_2",
};

char dir_1[DIR_1_ELS][MAX_FILE_NAME_LEN] = {
    "coding.c",
    "readme.txt",
    "solution.sln",
    "backup.txt",
};

char dir_2[DIR_2_ELS][MAX_FILE_NAME_LEN] = {
    "photo1.jpeg",
    "photo2.jpeg",
    "picture.png",
    "something.webp",
    "cat.gif",
    "video.mp4",
};

int dir_1_sizes[DIR_1_ELS] = { 15, 5, 27, 9 };

int dir_2_sizes[DIR_2_ELS] = { 4, 7, 12, 2, 9, 78 };

//sortings
void simple_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                int buff = arr[i];
                arr[i] = arr[j];
                arr[j] = buff;
            }
        }
    }
}

void choose_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        int min = arr[i], ind = i;
        for (j = i + 1; j < n; j++) {
            if (min > arr[j]) {
                min = arr[j];
                ind = j;
            }
        }
        arr[ind] = arr[i];
        arr[i] = min;
    }
}

void insert_sort(int arr[], int n) {
    int i;
    for (i = 1; i < n; i++) {
        int j = i + 1, tmp = arr[i];
        while (j >= 0 && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[j + 1] < arr[j]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

//functions
int check_the_dir(char path[]) {
    for (int i = 0; i < DIRECTORY_COUNT; i++) {
        if (strcmp(path, directories[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void dir_printing(int *dir_exists) {

}


//main code
int main() {
    int c, dir_exists = -1, sorting_method = 0, sort_by = 0;
    char path[MAX_PATH_LEN];
    printf("WELCOME TO FILE EXPLORER!\n\n");

    do {
        printf("Input a path to a catalog you want to get list of files from: ");
        scanf_s("%s", path, (unsigned)sizeof(path));
        while ((c = getchar()) != '\n' && c != EOF);
        dir_exists = check_the_dir(path);
        if (dir_exists == -1) {
            printf("The directory doesn't exist.\n\n");
        }
    } while (dir_exists == -1);

    do {
        printf(CHOICE_SORTING_METHOD_TEXT);
        scanf_s("%d", &sorting_method);
        if (sorting_method < 1 || sorting_method > 6) {
            printf("Wrong input! Try again.\n");
        }
    } while (sorting_method < 1 || sorting_method > 6);
    
    do {
        printf(CHOICE_SORT_BY_TEXT);
        scanf_s("%d", &sort_by);
        if (sort_by < 1 || sort_by > 2) {
            printf("Wrong input! Try again.\n");
        }
    } while (sort_by < 1 || sort_by > 2);


}
