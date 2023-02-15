#ifndef _SORTS_H
#define _SORTS_H

typedef struct {
    char* name;
    int l;
} file_t;

#define LENGTH 50

void merge(file_t* a, int left, int mid, int right);
void mergeSort(file_t* a, int left, int right);
void BubbleSort(file_t* a, int len);
void QuickSort(file_t* a, int low, int high);

#endif
