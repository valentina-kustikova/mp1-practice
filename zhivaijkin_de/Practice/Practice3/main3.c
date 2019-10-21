#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main()
{
    int a, b, c, d, f, e, x, y, z;
    char g = '.';
    srand((unsigned int)time(0));
    a = 0;
    setlocale(LC_CTYPE, "rus");
    do 
    {
        printf("\nУгадай число! - Введите 1 чтобы отгадывать; 2 - чтобы загадывать.\n");
        scanf("%d", &f);
    }
    while (f < 0 || f > 2);
    if (f == 1)
    {
        b = 1 + rand() % 1000;
        while (1)
        {
            printf("Число загадано (от 1 до 1000), отгадайте!\n");
            do
            {
                scanf("%d", &d);
            }
            while ((d < 1) || (d > 1000));
            a++;
            if (d == b)
            {
                break;
            }
            if (d > b)
            {
                printf("Загаданное число меньше!\n");
            }
            if (d < b)
            {
                printf("Загаданное число больше!\n");
            }
        }
        printf("Победа! \n Всего попыток: %d\n", a);
        return;
    }
    if (f == 2)
    {
        printf("Загадайте число от 1 до 1000\n");
        do
        {
            scanf("%d", &c);
        }
        while ((c < 1)||(c > 1000));
        x = 0;
        y = 1001;
        z = 0;
        a = 0;
        do
        {
            e = rand() * (y-x) / RAND_MAX + x;
            printf("\n Думаю, это: %d \n", e);
            printf("Введите знак >, <, =\n");
            scanf("%*c%c", &g);
            a++;
            switch (g)
            {
            case '>':
                x = e + 1;
                break;
            case '<':
                y = e;
                break;
            case '=':
                z = 1;
                break;
            default:
                printf("Неизвестный знак! Введите еще раз. \n");
                break;
            }
        }
        while (z == 0);
        printf("\n Ура! Я угадал ваше число. Всего попыток: %d \n", a);
    }
}