#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 5

int main() {
    setlocale(LC_ALL, "Rus");
    srand((unsigned int)time(0));

    int length, i, j, digit, temp, bulls, cows, n, gameover = 0;
    int number[N], num[N];
    printf("Игра быки-коровы\n");
    printf("Выбери число какой длины мне загадать(от 2 до 5)\n");
    scanf("%d", &length);
    while (length < 2 || length > 5) {
        printf("Неверный ввод, попробуй еще раз: \n");
        scanf("%d", &length);
    }
    for (i = 0; i < length; i++) {
        digit = 1 + rand() % 9;
        number[i] = digit;
        for (j = 0; j < i; j++) {
            temp = number[i];
            if (number[j] == temp) {
                i--;
                break;
            }
        }
    }
    printf("Попробуй угадать число: \n");
    while (gameover != 1) {
        cows = 0;
        bulls = 0;
        scanf("%d", &n);
        for (i = length - 1; i >= 0; i--) {
            num[i] = n % 10;
            n /= 10;
        }
        for (i = 0; i < length; i++) {
            for (j = 0; j < length; j++) {
                if (number[i] == num[j]) {
                    if (i == j) {
                        bulls++;
                    }
                    else {
                        cows++;
                    }
                }
            }
        }
        printf("Количество быков = %d, коров = %d\n", bulls, cows);
        if (bulls == length) {
            gameover = 1;
            printf("Ты угадал!");
        }
    }
    return 0;
}
