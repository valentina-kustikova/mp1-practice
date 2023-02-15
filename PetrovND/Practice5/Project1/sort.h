#ifndef _SORT_H
#define _SORT_H
void bubbleSort(unsigned long* a, int size, int* index, char** fname);
void swap(unsigned long* x, unsigned long* y);
void quicksort(unsigned long* list, int m, int n, int* index);
void merge(unsigned long* a, unsigned long* tmp, int left, int mid, int right, unsigned long* index, unsigned long* itmp);
void msort(unsigned long* a, unsigned long* tmp, int left, int right, unsigned long* index, unsigned long* itmp);
#endif // !_SORT_H
