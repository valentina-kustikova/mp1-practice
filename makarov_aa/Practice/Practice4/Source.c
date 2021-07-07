#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define D 5
#define namelength 4
#define codelength 4
void mode1(int* kolvo, char* code)
{
    char scode[codelength];
    int i = 0, check = 0, j;
    printf("Введите штрих-код для сканирования\n");
    scanf("%s", &scode);
    while ((check < codelength) && (i < D))
    {
        j = check = 0;
        while (j < codelength)
        {
            if (scode[j] == code[i * codelength + j])
                check++;
            j++;
        }
        i++;
    }
    if (check == 4) kolvo[i - 1]++;
    else printf("Товара с данным штрихкодом не существует");
}
void mode2(int* kolvo, char* code, char* name, int* cena, int* skidka)
{
    char scode[codelength];
    int i = 0, check = 0, j;
    printf("Введите штрих-код отсканированного товара\n");
    scanf("%s", &scode);
    while ((check < 4) && (i < D))
    {
        j = check = 0;
        while (j < codelength)
        {
            if (scode[j] == code[i* codelength + j])
                check++;
            j++;
        }
        i++;
    }
    if (check == 4)
        if (kolvo[i - 1] == 0)
            printf("Данный товар не отсканирован\n");
        else
        {
            printf("%s    ", scode);
            for (j = 0; j < namelength; j++)
                printf("%c", name[(i - 1) * namelength + j]);
            printf("    %d", cena[i - 1]);
            printf("    %d\n", skidka[i - 1]);
        }
    else printf("Товара с данным штрихкодом не существует");
}
void mod3(int* kolvo, int* fullst, int* summa, int* cena, int* skidka, char* name)
{
    int check = 0, i, j;
    for (i = 0; i < 5; i++)
        if (kolvo[i] != 0)
        {
            *fullst += cena[i] * kolvo[i];
            *summa += cena[i] * kolvo[i] * skidka[i] / 100;
            for (j = 0; j < namelength; j++)
                printf("%c", name[i * namelength + j]);
            printf("    %d", cena[i]);
            printf("    %d", kolvo[i]);
            printf("    %d", cena[i] * kolvo[i]);
            printf("    %d\n", cena[i] * kolvo[i] * skidka[i] / 100);
            check++;
        }
    if (!check) printf("Нет ни одного отсканированного товара\n");
}
void mod4(int* fullst, int* summa)
{
    int i, fullskidka;
    for (i = 0; i < D; i++)
    {
    }
    fullskidka = *fullst - *summa;
    printf("Общая стоимость - %d\n", *fullst);
    printf("Общая скидка - %d\n", fullskidka);
    printf("К оплате - %d\n", *summa);
}
void main()
{
    char name[D][namelength] = { "milk", "eggs", "corn", "fish", "meat" };
    int cena[D] = { 70, 50, 100, 200, 300 };
    int skidka[D] = { 50, 66, 90, 80, 60 };
    char code[D][codelength] = { "0001", "0002", "0003", "0004", "0005" };
    int kolvo[D] = { 0 };
    int summa = 0, fullst = 0, mode;
    setlocale(LC_ALL, "Russian");
    printf("1 - сканирование товара\n");
    printf("2 - вывести описание отсканированного товара\n");
    printf("3 - сформировать чек на покупку\n");
    printf("4 - рассчитать итоговую стоимость покупки\n");
    do
    {
        do
        {
            printf("Введите режим работы программы\n");
            scanf("%d", &mode);
        } while (mode > 4 || mode < 1);
        switch (mode)
        {
            case 1:
            {
                mode1(&kolvo, &code);
                break;
            }
            case 2:
            {
                mode2(&kolvo, &code, &name, &cena, &skidka);
                break;
            }
            case 3:
            {
                mod3(&kolvo, &fullst, &summa, &cena, &skidka, name);
                break;
            }
            case 4:
            {
                mod4(&fullst, &summa);
                break;
            }
        }
    } while (mode != 4);
}
