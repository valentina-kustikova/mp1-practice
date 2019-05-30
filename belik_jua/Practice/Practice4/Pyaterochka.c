#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define L 5

void Command()
{
    printf("\n1 - scan item \n");
    printf("2 - display description \n");
    printf("3 - add item to check \n");
    printf("4 - form a check \n");
    printf("5 - calculate the total \n");
}

void Gen(int a[], int n, double m)
{
    int i;
    srand((unsigned int)time(0));
    for (i = 1; i < n; i++)
        a[i] = m / RAND_MAX * rand() + 1;
}

int Scan(int goo[], int num)
{
    int temp;
    do
    {
        printf("Enter barcode \n");
        scanf("%d", &temp);
    } while ((temp < 0) || (temp > N));
    goo[num] = temp;
    do
    {
        printf("Enter the quantity of goods \n");
        scanf("%d", &temp);
    } while ((temp < 0) || (temp > 1000));
    return temp;
}

void Desciption(char prod[][L], int pr[], int dis[], int num)
{
    int i;
    printf("id ");
    if (num < 1000)
        printf("0");
    if (num < 100)
        printf("0");
    if (num < 10)
        printf("0");
    printf("%d ", num);
        for (i = 0; i < L; i++)
            printf("%c", prod[num][i]); 
    printf(" price %d dis %d \n", pr[num], dis[num]);
}

void AddToCheck(int quan[], int num, int q)
{
    quan[num] += q;
}

void Form(int quan[], char prod[][L], int pr[], int dis[])
{
    int i, tov;
    int check = 0, total = 0;
    for (i = 1; i < N; i++)
    {
        if (quan[i] > 0)
        {
            Desciption(prod, pr, dis, i);
            tov = quan[i] * pr[i] * (100 - dis[i]) / 100;
            printf("quan %d total %d \n", quan[i], tov);
            check += (pr[i] * quan[i]);
            total += (pr[i] * quan[i] * (100 - dis[i]) / 100);
        }
    }
    if (check > 0)
    {
        i = (check - total) * 100 / check;
        printf("without discount %d discount %d total %d \n", check, i, total);
    }
    else
        printf("No products added");
}

void main()
{
    int num = 0, i, q;
    int quan[N] = {0}, pr[N], dis[N], goo[N];
    char prod[N][L] = { "     ", "Milk ", "Bread", "Egg  ", "Flour", "Apple", "Meat ", "Fish " };
    Gen(pr, N, 1000.0); 
    Gen(dis, N, 50.0);
    q = Scan(goo, num);
    do
    {
        Command();
        scanf("%d", &i);
        printf("\n");
        switch (i) {
        case 1: 
            q = Scan(goo, num);
            break;
        case 2:
            Desciption(prod, pr, dis, goo[num]);
            break;
        case 3: 
            AddToCheck(quan, goo[num], q);
            num++;
            break;
        case 4:
            Form(quan, prod, pr, dis);
            break;
        case 5:
            Form(quan, prod, pr, dis);
            break;
        }
    } while (i != 5);
}