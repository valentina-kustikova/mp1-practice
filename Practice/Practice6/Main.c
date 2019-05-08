#define _CRT_SECURE_NO_WARNINGS
#include "Vector.h"
#include <stdio.h>
#include <locale.h>

void main()
{
    Vector *v1 = NULL, *v2 = NULL, *v = NULL;
    int i, n = 0, p = 0, k = 0, m = 1;
    double sp, len, ang;
    int d1 = 0, d2 = 0;
    char cd1, cd2;
    setlocale(LC_ALL, "Russian");

newtry:
    printf("Введите размерность пространства первого вектора v1:\n");
    do {
        scanf("%d", &d1);
        if (d1 < 1)
            printf("Размерность должна быть больше 0. Попробуйте ввести число ещё раз.\n");
    } while (d1 < 1);
    Create(&d1, &v1);
    Fill(&v1);
    printf("\nВведите размерность пространства второго вектора v2:\n");
    do {
        scanf("%d", &d2);
        if (d2 < 1)
            printf("Размерность должна быть больше 0. Попробуйте ввести число ещё раз.\n");
    } while (d2 < 1);
    Create(&d2, &v2);
    Fill(&v2);

    do {
        m = 0;
        printf("\nДля того чтобы выбрать операцию, которую вы хотите провести над векторами");
        printf("\nвведите соответвсвующий номер операции из указанных ниже:");
        printf("\n1 - Сложение векторов");
        printf("\n2 - Разность векторов");
        printf("\n3 - Скалярное произведение векторов");
        printf("\n4 - Длина вектора");
        printf("\n5 - Угол между двумя веткорами\n");
        do {
            scanf("%d", &n);
            if ((n < 1) || (n > 5))
                printf("Операции с таким номером нет. Попробуйте ввести ещё раз.\n");
        } while ((n < 1) || (n > 5));
        k = Check(v1, v2);
        switch (n) {
        case 1:
        {
            if (k == 0)
                break;
            v = Add(v1, v2);
            Print(v);
            break;
        }
        case 2:
        {
            if (k == 0)
                break;
            v = Difference(v1, v2);
            Print(v);
            break;
        }
        case 3:
        {
            if (k == 0)
                break;
            sp = ScalarProduct(v1, v2);
            printf("\n%.3lf", sp);
            break;
        }
        case 4:
        {
            printf("Выберете вектор, длину которого вы хотите узнать:\n");
            printf("1 - v1\n2 - v2\n");
            do {
                scanf("%d", &p);
                if ((p != 1) && (p != 2))
                    printf("Такого вектора нет. Попробуйте ещё раз.\n");
            } while ((p != 1) && (p != 2));
            if (p == 1)
            {
                len = Lenght(v1);
                printf("%.3lf", len);
            }
            else
            {
                len = Lenght(v2);
                printf("%.3lf", len);
            }
            k = 3;
            break;
        }
        case 5:
        {
            if (k == 0)
                break;
            ang = Аngle(v1, v2);
            printf("\n%.3lf", ang);
            break;
        }
        }
        if (k == 0) {
            printf("Эта операция не может быть выполенена, так как размерности пространств заданных векторов различаются.\n");
            printf("Если хотите ещё раз задать векторы, введите 1, если нет, что любое другое число.\n");
            scanf("%d", &k);
            if (k == 1)
                goto newtry;
        }
        printf("\nЕсли вы хотите совершить ещё какую-нибудь операцию над векторами, введите 1.\n");
        printf("Если вы хотите задать новые векторы, введите 2.\n");
        printf("Если вы хотите закончить работу, введите любое другое число.\n");
        scanf("%d", &m);
        if (m == 2)
            goto newtry;
        else if (m != 1)
            m = 0;

        system("pause");
    } while (m == 1);
}