#ifndef SHOP_H
#define SHOP_H
#define MAX 256
typedef struct Shop {
    char name[MAX];
    char address[MAX];
    char phones[MAX];
    char special[MAX];
    char forma[MAX];
    char reshim[MAX];
} Shop;

void poisk24(Shop* array, int count, Shop** search, int* foundCount);

#endif
