#include "sort.h"

void swap(unsigned long* x, unsigned long* y) {
    unsigned long temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(unsigned long* list, int m, int n, int* index) {
    unsigned long key, i, j, k;
    if (m < n) {
        k = (m + n) / 2;
        swap(&list[m], &list[k]);
        swap(&index[m], &index[k]);
        key = list[m];
        i = m + 1;
        j = n;
        while (i <= j) {
            while ((i <= n) && (list[i] <= key))
                i++;
            while ((j >= m) && (list[j] > key))
                j--;
            if (i < j) {
                swap(&list[i], &list[j]);
                swap(&index[i], &index[j]);
            }
        }
        swap(&list[m], &list[j]);
        swap(&index[m], &index[j]);

        quicksort(list, m, j - 1, index);
        quicksort(list, j + 1, n, index);
    }
}

void merge(unsigned long* a, unsigned long* tmp, int left, int mid, int right, unsigned long* index, unsigned long* itmp) {
    unsigned long i, left_end, count, tmp_pos;
    left_end = mid - 1;
    tmp_pos = left;
    count = right - left + 1;

    while ((left <= left_end) && (mid <= right)) {
        if (a[left] <= a[mid]) {
            tmp[tmp_pos] = a[left];
            itmp[tmp_pos] = index[left];
            tmp_pos = tmp_pos + 1;
            left = left + 1;
        }
        else {
            tmp[tmp_pos] = a[mid];
            itmp[tmp_pos] = index[mid];
            tmp_pos = tmp_pos + 1;
            mid = mid + 1;
        }
    }

    while (left <= left_end) {
        tmp[tmp_pos] = a[left];
        itmp[tmp_pos] = index[left];
        left = left + 1;
        tmp_pos = tmp_pos + 1;
    }
    while (mid <= right) {
        tmp[tmp_pos] = a[mid];
        itmp[tmp_pos] = index[mid];
        mid = mid + 1;
        tmp_pos = tmp_pos + 1;
    }

    for (i = 0; i <= count; i++) {
        a[right] = tmp[right];
        index[right] = itmp[right];
        right = right - 1;
    }
}

void msort(unsigned long* a, unsigned long* tmp, int left, int right, unsigned long* index, unsigned long* itmp) {
    unsigned long mid;
    if (right > left) {
        mid = (right + left) / 2;
        msort(a, tmp, left, mid, index, itmp);
        msort(a, tmp, mid + 1, right, index, itmp);
        merge(a, tmp, left, mid + 1, right, index, itmp);
    }
}

void bubbleSort(unsigned long* a, int size, int* index, char** fname) {
    int i, j;
    unsigned long tmp;
    int indtmp;
    for (i = 1; i < size; i++) {
        for (j = 1; j < size; j++) {
            if (a[j] > a[j - 1]) {
                tmp = a[j];
                indtmp = index[j];
                a[j] = a[j - 1];
                index[j] = index[j - 1];
                a[j - 1] = tmp;
                index[j - 1] = indtmp;
            }
        }
    }
}