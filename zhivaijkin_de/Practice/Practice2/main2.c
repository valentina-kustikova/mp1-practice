#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

void main()
{
    int n, corv, buk, i, j, h;
    int a[10] = {0}, b[10] = {0};
    long long int f;
    int c1, d;
    srand((unsigned int)time(0));
    setlocale(LC_CTYPE, "rus");
    //Приветсвие
    printf("\nБЫКИ И КОРОВЫ\n");
    printf("\nКоровы - это цифры, которые угаданы, но не угадана позиция.\n");
    printf("\nБыки - это цифры, которые угаданы вплоть до правильной позиции\n");
    //Ввод длины числа
    for (;;)
    {
        printf("\nВведите длину числа\n");
        scanf("%d", &n);
        if ((n > 0)&&(n < 11)) break;
    }
    //Генерация числа с неповторяющимися цифрами
    h = 0;
    for (;;)
    {
        a[0] = rand() % 10;
        if(a[0] > 0) break;
    }
    for (i = 1; i < n; i++)
    {
        a[i] = rand() % 10;
        for(;;)
        {
        for (j = 0; j < i; j++)
        {
            if (a[j] == a[i])
            {
                a[i] = rand() % 10;
                h++;
            }
        }
        if (h == 0) break;
        h = 0;
        }
    }
    //Процесс игры
    printf("\n Число загадано, отгадайте его! (Цифры в числе не повторяются!)\n");
    do
    {
        corv = 0;
        buk = 0;
        scanf("%d", &c1);
        f = n - 1;
        while (f != -1)
        {
            d = c1 % 10;
            b[f] = d;
            c1 /= 10;
            f = f - 1;
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if ((b[i] == a[j]) && (i == j))
                {
                    buk++;
                }
                if ((b[i] == a[j]) && (i != j))
                {
                    corv++;
                }
            }
    }
        if (buk != n)
        {
            printf("\nКоров = %d, Быков = %d. Пробуйте снова!\n", corv, buk);
        }
    }
    while (buk != n);
    printf("Победа!\n");
}