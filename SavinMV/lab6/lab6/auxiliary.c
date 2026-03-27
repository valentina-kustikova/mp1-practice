#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liblary.h"
#include "auxiliary.h"

int numberBooks(const char* filename) {   
    char buff[2048];
    int count = 0;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("oshibka");
        return 1;
    }
    while (fgets(buff, sizeof(buff), file)){
        count++;
    }
    fclose(file);
    return count;
    
}

void readFile(int count,Book* arr, const char* filename) {
    char buff[2048];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("oshibka");
        return 1;
    }
    for (int i = 0; i < count; i++) {
        fgets(buff, sizeof(buff), file);
        buff[strcspn(buff, "\n")] = 0;
        strcpy(arr[i].avtor, strtok(buff, ";"));
        strcpy(arr[i].name, strtok(NULL, ";"));
        strcpy(arr[i].izdanie, strtok(NULL, ";"));
        arr[i].year = atoi(strtok(NULL, ";"));
    }
    fclose(file);
}

void printResults(Book* itogpoiska, int k) {
    if (k == 0) {
        printf("ne naydeno\n");
    }
    else {
        for (int i = 0; i < k; i++) {
            printf("%s; %s; %s; %d\n", itogpoiska[i].avtor, itogpoiska[i].name, itogpoiska[i].izdanie, itogpoiska[i].year);
        }
    }
}