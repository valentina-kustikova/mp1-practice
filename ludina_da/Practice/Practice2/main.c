#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 10
void main()
{
    int n, x, x1, c = 0, m = 9, t = 1;
    int i, j, k = 1, c1 = 0, b1 = 0;
    int a[N] = { 0 }, b[N], d[N] = { 0 };
    int check1, check2;
    setlocale(LC_ALL, "Rus");
    srand((unsigned int)time(0));
    printf("Игра 'Быки и коровы'\n");
    printf("Коровы - количесво цифр, угаданных без совподения с их позицией в загаданном числе\n");
    printf("Быки - количесво цифр, угаданных вплоть до позиции в загаданном числе\n");
    do
    {
        printf("Выберете длинну загаданного число:");
        scanf("%d", &n);
    } while (n < 1 || n > 10);
    for (i = 0; i < n; i++)
    {
        a[i] = (m - c) / RAND_MAX * rand() + c;
        if (a[0] = 0)
            a[0] = (m - 1) / RAND_MAX * rand() + 1;
        b[0] = a[0];
        for (i = 1; i < n; i++)
        {
            int f = 0;
            for (j = 0; j < i; j++)
            {
                if (a[i] == a[j])
                {
                    f = 1;
                    a[i] = (m - c) / RAND_MAX * rand() + c;
                    break;
                }
            }
            if (f == 0)
            {
                b[k] = a[i];
                k++;
            }
        }
    }
    do
    {
        printf("Попробуйте отгадать (цифры в числе не должны повторяться): \n");
        do
        {
            scanf("%d", &x);
            x1 = x;
            for (i = 0; i < n; i++)
                d[i] = 0;
            check1 = 0;
            while (x1 != 0) //проверка на длину
            {
                d[x1 % 10]++;
                x1 /= 10;
                check1++;
            }
            check2 = 0;
            for (i = 0; i < 10; i++) //проверка на неповторяемость
                if (d[i] > 1)
                    check2++;
        } while ((check1 != n) || (check2 != 0));
        for (t = 0; t < n; t++)
        {
            d[n - t] = x % 10;
            x /= 10;
        }
        for (k = 0; k < n; k++)
        {
            for (t = 0; t < n; t++)
            {
                if ((d[t] == b[k]) && (t == k))
                {
                    b1++;
                }
                else if ((d[t] == b[k]) && (t != k))
                {
                    c1++;
                }
            }
        }
        printf("Количесво коров: %d \n", c1);
        printf("Количесво быков: %d \n", b1);
    } while ((c1 != n) || (b1 != n));
    printf("Вы угадали \n");
}