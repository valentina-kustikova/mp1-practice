#include <string.h>
#include <stdlib.h>
#include "shop.h"

void poisk24(Shop* array, int count, Shop** search, int* foundCount) {
    int k = 0;
    *foundCount = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(array[i].special, "grocery") != NULL &&
            (strstr(array[i].reshim, "24/7") != NULL)) {
            (*foundCount)++;
        }
    }
    if (*foundCount == 0) {
        return;
    }
    *search = (Shop*)malloc((*foundCount) * sizeof(Shop));
    for (int j = 0; j < count; j++) {
        if (strstr(array[j].special, "grocery") != NULL &&
            (strstr(array[j].reshim, "24/7") != NULL)) {
            (*search)[k] = array[j];
            k++;
        }
    }
}