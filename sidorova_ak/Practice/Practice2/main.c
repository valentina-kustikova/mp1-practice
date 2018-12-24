#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    long long tmp, pc, pl;
    int i, a, b, f, n, k, bulls, cows;
    int player[10];
    srand((unsigned int)time(0));

    printf("\n               \"Bulls and cows\"\n");
    printf("\nCows - the amount of digits in the intended number that do not stand in their place.");
    printf("\nBulls - the amount of digits in the intended number that stand in their place.\n");

    do                                                                     // Контроль ввода количества цифр числа
    {                                                                  
        printf("\nEnter a natural number up to 10 inclusive: ");
        scanf("%d", &n);
    } while ((n <= 0) || (n >= 11));

    pc = 0;
    f = 0;

    for (i = 1; i <= n; i++)                                               // Создание рандомного числа компьютером 
    {                                                                      // без повторяющихся цифр
        a = rand() % 10;
        tmp = pc;

        while (tmp > 0)                                                    // Сама проверка на повторы с флажком
        {
            b = tmp % 10;
            tmp /= 10;
            if (b == a) f = 1;
        }

        if ((a == 0) && (i == 1)) f = 1;                                   // Флажок на тот случай, если первая цифра окажется нулем
        if (f != 1) pc = pc * 10 + a;                                      // Создание числа, если флажок "опущен"
        else i--;

        f = 0;
    }

    printf("\nWell, I have conceived a number. Try to guess :)\n");

    do                                                                      // Пошел цикл на обработку вводного числа 
    {                                                                       // и его сравнения с задуманным
        do 
        {                                                                   
            f = i = k = 0;

            printf("\nEnter a natural number of non-repeating %d digits: ", n);
            scanf("%lld", &pl);

            while (pl > 0)                                                     // Каждую цифру в каждый элемент массива
            {
                player[i] = pl % 10;
                pl /= 10;
                i++;
            }

            if (i == n)                                                        // Отсев, если количество цифр в числе пользователя
            {                                                                  // не совпадает с количеством цифр числа компьютера (Проверка)
                for (k = 0; k < n - 1; k++)                                    // Цикл в цикле - проверка на повторы цифр
                {
                    for (i = k + 1; i < n; i++)
                    {
                        if (player[k] == player[i])
                        {
                            f = 1;
                            break;
                        }

                    }
                }
            }
            else f = 1;
        } while (f != 0);

        i = k = cows = bulls = 0;

        for (i = 0; i <= n - 1; i++)                                           // Проверка на кол-во коров и быков
        {
            tmp = pc;

            while (tmp > 0)                                                    // "Рубим" задуманное число
            {
                if (((tmp % 10) == player[i]) && (i == k)) bulls++;
                if (((tmp % 10) == player[i]) && (i != k)) cows++;

                k++;
                tmp /= 10;
            }

            k = 0;
        }

        printf("Cows = %d\n", cows);
        printf("Bulls = %d\n", bulls);

    } while (bulls != n);

    printf("\nCongratulations! You win!\n");
}