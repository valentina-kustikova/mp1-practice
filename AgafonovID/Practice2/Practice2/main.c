#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main() {
    setlocale(LC_ALL, "Rus");
    int game, number, n, attempts = 0;
    int number2, n2, attempts2 = 0, a = 1, b = 1000;
    char p;
    int true = 0;

    printf("Выберите режим (1 - отгадываете число, 2 - загадываете): \n");
    scanf("%d", &game);
    while (game < 1 || game > 2) {
        printf("Неверный ввод, попробуй еще раз: \n");
        scanf("%d", &game);
    }
    if (game == 1) {
        srand((unsigned int)time(NULL));
        srand((unsigned int)time(0));
        number = 1 + rand() % 1000;
        printf("Загадано число от 1 до 1000\n");
        printf("Попробуй отгадать это число: \n");
        scanf("%d", &n);
        while (n < 0) {
            printf("Неверный ввод, попробуй еще раз: \n");
            scanf("%d", &n);
        }
        while (true != 1) {
            if (n > number) {
                printf("Загаданное число меньше, попытайся еще раз: \n");
                scanf("%d", &n);
                attempts++;
            }

            if (n < number) {
                printf("Загаданное число больше, попытайся еще раз: \n");
                scanf("%d", &n);
                attempts++;
            }

            if (n == number) {
                true = 1;
                attempts++;
                printf("Вы отгадали число!\n");
                printf("Число ваших попыток: %d\n", attempts);
            }
        }
    }
    else if (game == 2) {
        printf("Я попытаюсь угадать число, а ты подсказывай знаками >, < или =. Загадай число от 1 до 1000: \n");
        scanf("%d", &number2);
        while (number2 < 0) {
            printf("Неверный ввод, попробуй еще раз: \n");
            scanf("%d", &number2);
        }
        while (true != 1) {
            n2 = (a + b) / 2;
            printf("Это число %d?: \n", n2);
            scanf("%*c%c", &p);
            if (p == '<') {
                b = n2 - 1;
                attempts2++;
            }

            if (p == '>') {
                a = n2 + 1;
                attempts2++;
            }
            if (p == '=') {
                true = 1;
                attempts2++;
                printf("Я угадал. Число попыток: %d", attempts2);
            }
        }
    }
    return 0;
}