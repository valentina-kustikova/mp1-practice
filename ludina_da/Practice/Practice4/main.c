#include <stdio.h>
#include <locale.h>
#define N 10

int code(int sht[])
{
    int i, c;
    setlocale(LC_ALL, "Rus");
    printf("Введите штрих-код от 1230 до 1239: \n");
    do
    {
        scanf("%d", &c);
    } while (c < 1230 || c > 1239);
    for (i = 0; i < N; i++)
    {
        sht[i] = c;
        return i;
    }
}
void inf_tovar(char tovar[][8], int c[], int p[], float s[], int b)
{
    int i;
    setlocale(LC_ALL, "Rus");
    printf("Информация о товаре: \n");
    for (i = 0; i < 8; i++)
        printf("%c", tovar[b][i]);
    printf(" \n");
    printf("Код: %d \n", c[b]);
    printf("Цена: %d \n", p[b]);
    printf("Скидка: %0.0f \n", s[b]);
}
void check(char tovar[][8], int p[], float s[], int colvo[], float price)
{
    int i, j;
    printf("-----------------------Касса №1-------------------------\n");
    printf("--------------------------------------------------------\n");
    for (i = 0; i < N; i++)
    {
        if (colvo[i] != 0)
        {
            printf("Наименование: ");
            for (j = 0; j < 8; j++)
            {
                printf("%c", tovar[i][j]);
            }
            printf(" \n");
            printf("Стоимость 1 шт.: %d руб. \n", p[i]);
            printf("Количесво: %d \n", colvo[i]);
            printf("Скидка: %0.0f \n", s[i]);
            printf("Цена со скидкой: %.2f  \n", (p[i] + (p[i] * s[i]) / 100.0) * colvo[i]);
        }
    }
    printf("--------------------------------------------------------\n");
    printf("К оплате: %.2f \n", price);
}
float sum(int p[], float s[], int b)
{
    int i;
    float sum = 0.0;
    for (i = 0; i < N; i++)
    {
        sum = (p[b] * s[b]) / 100.0 + p[b];
    }
    return sum;
}
void main()
{
    int c[N] = { 1230, 1231, 1232, 1233, 1234, 1235, 1236, 1237, 1238, 1239 };
    char tovar[N][8] = {"Яблоко" , "Апельсин" , "Мандарин" , "Банан" , "Груша" , "Лимон" , "Виноград" , "Персик" , "Слива" , "Нектарин"};
    int p[N] = { 50, 70, 86, 48, 123, 79, 150, 170, 90, 120 };
    float s[N] = { 5, 10, 30, 40, 15, 2, 18, 25, 35, 3 };
    int number;
    int b;
    float price = 0;
    int shtrih[100] = { 0 };
    setlocale(LC_ALL, "Rus");
    while(1)
    {
        printf("Нажмите цифру 1, если вы хотите отсканировать товар \n");
        printf("Нажмите цифру 2, если вы хотите распечатать чек \n");
        scanf("%d", &number);
        switch (number)
        {
        case 1:
        {
            b = code(c);
            shtrih[b] = shtrih[b] + 1;
            inf_tovar(tovar, c, p, s, b);
            price += sum(p, s, b);
            break;
        }
        case 2:
        {
            check(tovar, p, s, shtrih, price);
            break;
        }
        }
    } 
}