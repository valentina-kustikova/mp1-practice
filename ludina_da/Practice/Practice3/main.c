#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
void main()
{
    int n, r, k, a, x = 1, y = 1000;
    int i = 0;
    char c;
    setlocale(LC_ALL, "Rus");
    printf("Выберите режим 1 или 2: ");
    scanf("%d", &n);
    srand((unsigned int)time(0));
    if (n == 1)
    {
        r = rand() * (y - x) / RAND_MAX + x;
        printf("Компьютер загадывает случайное число от 1 до 1000, попробуйте отгадать:\n");
        while (1)
        {
            i++;
            printf("Введите число: ");
            scanf("%d", &k);
            if (k < r)
            {
                printf("Загаданое число больше\n");
            }
            else if (k > r)
            {
                printf("Загаданное число меньше\n");
            }
            else
            {
                printf("Вы угадали\n");
                break;
            }
        }
        printf("Количество попыток: %d \n", i);
    }
    else if (n == 2)
    {
        printf("Загадайте число от 1 до 1000, введите его: ");
        scanf("%d", &a);
        k = rand() * (y - x) / RAND_MAX + x;;
        printf("Компьютер пробует угадать: %d \n", k);
        while (1)
        {
            i++;
            printf("Загаданное вами число является <,> или =: \n");
            scanf("%*c%c", &c);
            if (c == '<')
            {
                y = k;
                k = rand() * (y - x) / RAND_MAX + x;
                printf("%d \n", k);
            }
            else if (c == '>')
            {
                x = k;
                k = rand() * (y - x) / RAND_MAX + x;
                printf("%d \n", k);
            }
            else if (c == '=')
            {
                printf("Компьютер угадал\n");
                break;
            }

        }
        printf("Количество попыток: %d \n", i);
    }
}