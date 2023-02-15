#include"Sorts.h"

void merge(file_t* a, int left, int mid, int right)
{
    int i0 = 0, i1 = 0, i2 = left;
    file_t b[LENGTH];
    while ((i0 < (mid - left + 1)) && (i1 < (right - mid))) {
        if (a[left + i0].l <= a[mid + i1 + 1].l) {
            b[i2] = a[left + i0];
            i0++;
        }
        else {
            b[i2] = a[mid + i1 + 1];
            i1++;
        }
        i2++;
    }
    while (i0 < (mid - left + 1)) {
        b[i2] = a[left + i0];
        i0++;
        i2++;
    }
    while (i1 < (right - mid)) {
        b[i2] = a[mid + i1 + 1];
        i1++;
        i2++;
    }
    for (int j = left; j < i2; j++) {
        a[j] = b[j];
    }
}

void mergeSort(file_t* a, int left, int right)
{
    if (left < right) {
        int mid;
        mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}
void BubbleSort(file_t* a, int len)
{
    file_t tmp;
    tmp.name = ' ';
    tmp.l = -1;
    for (int g = 0; g < len; g++) {
        for (int j = 0; j < len - g - 1; j++) {
            if (a[j + 1].l < a[j].l)
            {
                tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}
void QuickSort(file_t* a, int low, int high) {
    int pivot, j = high, g = low;
    file_t tmp;

    pivot = a[(low + (high - low) / 2)].l;
    do {
        while (a[g].l < pivot) {
            g++;
        }
        while (a[j].l > pivot) {
            j--;
        }
        if (g <= j) {
            if (a[g].l > a[j].l) {
                tmp = a[g];
                a[g] = a[j];
                a[j] = tmp;
            }
            g++;
            if (j > 0) {
                j--;
            }
        }
    } while (g <= j);

    if (g < high) {
        QuickSort(a, g, high);
    }
    if (j > low) {
        QuickSort(a, low, j);
    }
}