#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

void main() {
    int Number[10] = { 0 };
    int UserNumber[10] = { 0 };
    int width = 0, i = 0, j = 0, m = 0, rnd, a, User_Number, bull = 0, cow = 0;
    double q = 0;
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(0));
    while (width < 1 || width > 9) {
        printf("Введите разрядность числа\n");
        scanf("%d", &width);
        if (width < 1 || width > 9)
            printf("Разрядность должна быть от 1 до 9\n");
    }
    //Генерация числа
    for (i = 1; i <= width; i++) {
        m = 0;
        while (m == 0) {
            if (i > 1)
                rnd = rand() % 10;
            else
                rnd = 1 + rand() % 9;
            if (Number[rnd] == 0) {
                m = 1;
                Number[rnd] = i;
            }
        }
    }

    //Ввод числа юзером, проверка, подсчет быков-коров
    while (bull != width) {
        bull = 0;
        cow = 0;
        do
        {
            m = 0;
            for (i = 0; i < 10; i++)
                UserNumber[i] = 0;
            printf("Введите %d-разрядное число\n", width);
            scanf("%d", &User_Number);
            a = User_Number;
            q = a / pow(10, width - 1);
            if ((q >= 10) || (q <= 1)) {
                printf("Вы ввели число неверной длины\n");
            }

            //Заполнение массива и проверка на повторяющиеся цифры
            else {
                for (i = 1; i <= width; i++) {
                    if (UserNumber[a % 10] != 0)
                        m = 1;
                    UserNumber[a % 10] = i;
                    a /= 10;
                }
            }
            if (m == 1) printf("Число не должно содержать повторяющихся цифр\n");
        } while ((q >= 10) || (q <= 1) || (m == 1));

        //Подсчет быков и коров
        for (i = 0; i < 10; i++) {
            if ((Number[i] == UserNumber[i]) && (Number[i] != 0)) bull++;
            if ((Number[i] != 0) && (UserNumber[i] != 0) && (Number[i] != UserNumber[i])) cow++;
        }
        printf("Коровы: %d\nБыки: %d\n", cow, bull);
    }
    printf("Вы отгадали число %d\n", User_Number);
}