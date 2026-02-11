#ifndef __SESORTS_H
#define __SESORTS_H

void swap(int* a, int* ai, int* b, int* bi);
void BubbleSort(int n, int* sz, int* num);
void ClassicSort(int n, int* sz, int* num);
void ChoiceSort(int n, int* sz, int* num);
void InsertSort(int n, int* sz, int* num);
void Merge(int l, int c, int r, int* sz, int* num, int* temp, int* tempnum);
void MergeSort(int l, int r, int* sz, int* num, int* temp, int* tempnum);
int parse(int* sz, int* num, int l, int r);
void QuickSort(int l, int r, int* sz, int* num);
char fsort(char method[], int k, int* sz, int* num);

#endif
