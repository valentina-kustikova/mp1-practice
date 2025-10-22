#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define LINE 512

int main() {
    char a[5], b[5];
    int n, i;
    srand((unsigned int) time(0));
    setlocale(LC_ALL, "ru");
    setlocale(LC_NUMERIC, "C");
    system("chcp 1251");

    do {
        printf("Длина числа (от 2 до 5): ");
        scanf("%d", &n);
    } while (n < 2 || n > 5);

    a[0] = '1' + rand() % 9;
    for (i = 1; i < n; i++) {
        bool correct = true;
        do {
            int j;
            a[i] = rand() % 10;
            for (j = 0; j < i; j++) {
                if (a[j] == a[i]) {
                    correct = false;
                    break;
                }
            }
        } while (!correct);
    }

    do {
        printf("Загадайте %d-значное число с различными цифрами: ", n);
        for (i = 0; i < n; i++)
            scanf("%c ", &b[i]);
        scanf("%*s");
    } while ();

    system("chcp 866");
    return 0;
}