#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "shop.h"



void search24hGroceries(Shop* array, int count, Shop** search, int* foundCount) {
    int k = 0;
    *foundCount = 0;

    for (int i = 0; i < count; i++) {
        int isGrocery = 0;
        int is24h = 1;

        if (strstr(array[i].specialization, "grocery") != NULL) {
            isGrocery = 1;
        }

        for (int d = 0; d < 7; d++) {
            if (array[i].schedule[d].mode != ALLDAY) {
                is24h = 0;
                break;
            }
        }

        if (isGrocery && is24h) {
            (*foundCount)++;
        }
    }

    if (*foundCount == 0) {
        *search = NULL;
        return;
    }

    *search = (Shop*)malloc((*foundCount) * sizeof(Shop));
    if (*search == NULL) {
        printf("err\n");
        *foundCount = 0;
        return;
    }

    for (int j = 0; j < count; j++) {
        int isGrocery = 0;
        int is24h = 1;

        if (strstr(array[j].specialization, "grocery") != NULL) {
            isGrocery = 1;
        }

        for (int d = 0; d < 7; d++) {
            if (array[j].schedule[d].mode != ALLDAY) {
                is24h = 0;
                break;
            }
        }

        if (isGrocery && is24h) {
            (*search)[k++] = array[j];
        }
    }
}