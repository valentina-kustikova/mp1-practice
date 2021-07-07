#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void main() 
{
    int mode;//режим работы
    int n;//загаданное число
    int p = 0;//число для попытки ввода
    int t = 0;//проверка
    int k = 0;//количество попыток
    int a = 0, b = 1001; //интервал
    char c;//ответ пользователя
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(0));
    printf("Выберите режим работы\n1 - отгадывает пользователь");
	printf("\n2 - отгадывает компьютер\n");
    do 
    {
        scanf("%d", &mode);
    }
    while ((mode != 1) && (mode != 2));
    if (mode == 1) 
    {
        n = rand() * 999 / RAND_MAX  + 1;
        while (p != n) 
        {
            printf("Угадайте число\n");
            scanf("%d", &p);
            if (p < n)
                printf("Заданное число больше\n");
            if (p > n)
                printf("Заданное число меньше\n");
            k++;
        }
        printf("Угадали\nКоличество попыток %d", k);
    }
    else 
    {
        printf("Введите число\n");
        do 
        {
            scanf("%d", &n);
        }
        while ((n < 1) || (n > 1000));
        do 
        {
            p = (a + b) / 2;
            printf("%d\n", p);
            do 
            {
                scanf("%*c", &c);
            }
            while ((c != '>') && (c != '<') && (c != '='));
            k++;
            if (c == '>')
                a = p;
            if (c == '<')
                b = p;
        }
        while (c != '=');
        printf("Компьютер угадал за %d попыток", k);
    }
}