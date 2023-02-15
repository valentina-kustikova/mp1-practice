#include <stdio.h>
#include <stdlib.h>
#include "Sorts.h"
void ChooseSort(int* arr, int len, int* nums)
{
    for (int st = 0; st < len - 1; st++) {
        int MinPos = st, buf, buf0;
        for (int j = st + 1; j < len; j++) {
            if (arr[j] < arr[MinPos]) {
                MinPos = j;
            }
        }
        buf = arr[MinPos];
        buf0 = nums[MinPos];
        arr[MinPos] = arr[st];
        nums[MinPos] = nums[st];
        arr[st] = buf;
        nums[st] = buf0;
    }
}

void merge(int* arr, int beg, int mid, int end, int i, int* nums)
{
    int i0 = 0, i1 = 0, i2 = beg;
    int* b = (int*)malloc(sizeof(int) * i);
    int* c = (int*)malloc(sizeof(int) * i);
    while ((i0 < (mid - beg + 1)) && (i1 < (end - mid))) {
        if (arr[beg + i0] <= arr[mid + i1 + 1]) {
            b[i2] = arr[beg + i0];
            c[i2] = nums[beg + i0];
            i0++;
        }
        else {
            b[i2] = arr[mid + i1 + 1];
            c[i2] = nums[mid + i1 + 1];
            i1++;
        }
        i2++;
    }
    while (i0 < (mid - beg + 1)) {
        b[i2] = arr[beg + i0];
        c[i2] = nums[beg + i0];
        i0++;
        i2++;
    }
    while (i1 < (end - mid)) {
        b[i2] = arr[mid + i1 + 1];
        c[i2] = nums[mid + i1 + 1];
        i1++;
        i2++;
    }
    for (int j = beg; j < i2; j++) {
        arr[j] = b[j];
        nums[j] = c[j];
    }
    free(b);
    free(c);
}
void mergeSort(int* arr, int beg, int end, int i, int* nums)
{
    if (beg < end) {
        int mid;
        mid = (beg + end) / 2;
        mergeSort(arr, beg, mid, i, nums);
        mergeSort(arr, mid + 1, end, i, nums);
        merge(arr, beg, mid, end, i, nums);
    }
}

void QuickSort(int* arr, int beg, int end, int* nums) {
    int tmp, tmp0, piv, j = end, g = beg;

    piv = arr[(beg + end) / 2];
    do {
        while (arr[g] < piv) {
            g++;
        }
        while (arr[j] > piv) {
            j--;
        }
        if (g <= j) {
            if (arr[g] > arr[j]) {
                tmp = arr[g];
                arr[g] = arr[j];
                arr[j] = tmp;
                tmp0 = nums[g];
                nums[g] = nums[j];
                nums[j] = tmp0;
            }
            g++;
            if (j > 0) {
                j--;
            }
        }
    } while (g <= j);

    if (g < end) {
        QuickSort(arr, g, end, nums);
    }
    if (j > beg) {
        QuickSort(arr, beg, j, nums);
    }
}