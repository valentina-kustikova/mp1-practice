#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void main()
{
    setlocale(LC_ALL, "Russian");
    int a[10] = { 0 }; // массив позиций цифр в числе
    int b[10] = { 0 }; // массив для проверки неповторяемости 
    int n; //длина числа
    int g; //рандомируемая цифра
    int i;//счетчик
    int check1, check2;//переменные для проверки на длину и неповторяемость
    int cows, beefs;//быки и коровы
    long long int k, p, p1;//загаданное и вводимое
    printf("Введите длину загадываемого числа \n");
    do 
    {
        scanf("%d", &n);
    }
    while ((n <= 0) || (n > 10)); // ввод длины числа
    i = 1;
    k = 0;
    srand((unsigned int)time(0));
    g = rand() * 8 / RAND_MAX + 1;//отдельная генерация для первой цифры
    k += g;
    a[g] += i;
    while (i < n) //генерация остальных цифр с занесением позиций в массив
    { 
        g = rand() * 9 / RAND_MAX;
        if (a[g] == 0) 
        {
            k *= 10;
            k += g;
            a[g] += i + 1;
            i++;
        }
    }
    printf("%lld Отгадайте число (цифры в ответе не должны повторяться)\n", k);
    do 
    {
        do //проверка вводимого числа
        {
            scanf("%lld", &p);
            p1 = p;
            for (i = 0; i < 10; i++)
                b[i] = 0;
            check1 = 0;
            while (p1 != 0) //проверка на длину
            { 
                b[p1 % 10]++;
                p1 /= 10;
                check1++;
            }
            check2 = 0;
            for (i = 0; i < 10; i++) //проверка на неповторяемость
                if (b[i] > 1)
                    check2++;
        } 
        while ((check1 != n) || (check2 != 0));
        i = n;
        cows = 0;
        beefs = 0;
        while (p != 0) //проверка на количество коров и быков
        {
            if (a[p % 10] > 0)
                cows++;
            if (a[p % 10] == i)
                beefs++;
            i--;
            p /= 10;
        }
        printf("%d коров, %d быков\n", cows, beefs);//вывод ответа
    } 
    while ((cows != n) || (beefs != n));// повторять, пока игрок не отгадает
    printf("Поздравляем, вы выиграли!");
}