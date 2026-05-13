#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "shop.h"


void poisk24(ShopLib* shops, ShopLib* result) {
    int k = 0;
    result->count = 0;

    for (int i = 0; i < shops->count; i++) {
        int isGrocery = 0;
        int is24h = 1;

        if (strstr(shops->arr[i].specialization, "grocery") != NULL) {
            isGrocery = 1;
        }

        for (int d = 0; d < 7; d++) {
            if (shops->arr[i].schedule[d].mode != ALLDAY) {
                is24h = 0;
                break;
            }
        }

        if (isGrocery && is24h) {
            result->count++;
        }
    }

    if (result->count == 0) {
        result->arr = NULL;
        return;
    }

    result->arr = (Shop*)malloc(result->count * sizeof(Shop));
    if (result->arr == NULL) {
        printf("err\n");
        result->count = 0;
        return;
    }

    for (int j = 0; j < shops->count; j++) {
        int isGrocery = 0;
        int is24h = 1;

        if (strstr(shops->arr[j].specialization, "grocery") != NULL) {
            isGrocery = 1;
        }

        for (int d = 0; d < 7; d++) {
            if (shops->arr[j].schedule[d].mode != ALLDAY) {
                is24h = 0;
                break;
            }
        }

        if (isGrocery && is24h) {
            result->arr[k++] = shops->arr[j];
        }
    }
}