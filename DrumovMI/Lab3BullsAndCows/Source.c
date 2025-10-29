#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define LINE 512

struct bullsandcows {
    int bulls, int cows;
};

bool no_repetitions(int a[], int n) {
    int i, j;
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (a[i] == a[j])
                return false;
    return true;
}

struct bullsandcows count(int a[], int b[], int n) {
    int i, j;
    int bulls = 0, cows = 0;
    struct bullsandcows;
    for (i = 0; i < n; i++)
        if (a[i] == b[i]) bulls++;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] == b[j]) cows++;
    bullsandcows = {
        .bulls = bulls,
        .cows = cows
    };
    return bullsandcows;
}

int main() {
    char a[5], b[5];
    int n, i;
    int guesses = 0;
    bool guessed;

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
        do {
            printf("Загадайте %d-значное число с различными цифрами: ", n);
            for (i = 0; i < n; i++)
                scanf("%c ", &b[i]);
            scanf("%*s");
        } while (!no_repetitions(b, n));

        struct bullsandcows result = count(a, b, n);
        if (result.bulls == n)
            guessed = true;
        printf("Кол-во коров: %d. Кол-во быков: %d.\n", result.cows, result.bulls);
    } while (!guessed);
    printf("Вы угадали! Кол-во затраченных попыток: %d.", guesses);

    system("chcp 866");
    return 0;
}
