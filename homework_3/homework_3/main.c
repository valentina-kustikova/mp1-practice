#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, a, temp, dig1, dig2, k, len, coe1 = 10, coe2 = 10, i, copy_a, bull, cow, pos_n, pos_a;
    printf("choose the length of the number\n");
    do {
        scanf_s("%d", &len);
    } while ((len < 2) || (len > 5));
    for (i = 1; i < len - 1; i++) {
        coe1 *= 10;
        coe2 *= 10;
    }
    coe1 *= 10;
    //generation number
    srand((unsigned int)time(0));
    a = rand() % (coe1 - coe2) + coe2;
    copy_a = a;
    //printf("%d\n", a);
    while (copy_a > 0) {
        k = 1;
        dig1 = copy_a % 10;
        temp = copy_a / 10;
        while (temp > 0) {
            dig2 = temp % 10;

            if (dig1 == dig2) {
                k = 0;
            }
            temp /= 10;
        }
        copy_a /= 10;
        if (k == 0) {
            a = rand() % (coe1 - coe2) + coe2;
            copy_a = a;
            //printf("%d\n", a);
        }
    }

    //guessing
    k = 0;
    bull = 0;
    while (bull < len) {
        printf("try to guess the number\n");
        scanf_s("%d", &n);
        k++;
        pos_n = len;
        cow = 0;
        bull = 0;
        while (n > 0) {
            copy_a = a;
            pos_a = len;
            while (copy_a > 0) {
                dig1 = n % 10;
                dig2 = copy_a % 10;
                if ((dig1 == dig2) && (pos_a == pos_n)) {
                    bull++;
                }
                if ((dig1 == dig2) && (pos_a != pos_n)) {
                    cow++;
                }
                copy_a /= 10;
                pos_a--;

            }
            n /= 10;
            pos_n--;
        }
        printf("cow = %d, bull = %d\n", cow, bull);
    }
    printf("right, k = %d\n", k);
    return 0;

}