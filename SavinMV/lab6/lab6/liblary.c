#include <string.h>
#include <stdlib.h>
#include "liblary.h"
void poisk(Book* arr, int count, const char* avtor, Book** itogpoiska, int *kolvonaydenknig) {
    int k = 0, i, j;
    *kolvonaydenknig = 0;
    for (i = 0; i < count; i++) {
        if (strstr(arr[i].avtor, avtor) != NULL) {
            (*kolvonaydenknig)++;
        }
    }
    if (*kolvonaydenknig == 0) {
        return;
    }
    *itogpoiska = (Book*)malloc((*kolvonaydenknig) * sizeof(Book));
    for (j = 0; j < count; j++) {
        if (strstr(arr[j].avtor, avtor) != NULL) {
            (*itogpoiska)[k] = arr[j];
            k++;
        }
    }
}