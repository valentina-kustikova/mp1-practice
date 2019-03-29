#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000

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
    for (i = 0; i < n; i++)
        a[i] = m / RAND_MAX * rand() + 1;
}

int Scan(int *num, char **id)
{
    char tov[4];
    int tmp, i;
    do
    {
        printf("Enter barcode \n");
        scanf("%s", &tov);
        i = 0;
        while (strncmp(tov, id[i], 4) != 0)
        {
            i++;
        }
        tmp = i;
    } 
    while ((tmp < 0) || (tmp > N)); 
    *num = tmp; 
    do
    {
        printf("Enter the quantity of goods \n");
        scanf("%d", &tmp); 
    } 
    while ((tmp < 0) || (tmp > 1000));
    return tmp;
}

void Desciption(char **prod, int pr[], int dis[], int num, char **id)
{
    int i;
    printf("id ");
    for (i = 0; i < 4; i++)
        printf("%c", id[num][i]);
    printf(" %s price %d dis %d \n", prod[num], pr[num], dis[num]);
}

void AddToCheck(int quan[], int num, int q)
{
    quan[num] += q;
    printf("Item added to check\n");
}

void Form(int quan[], char **prod, int pr[], int dis[], char **id)
{
    int i, tov;
    int check = 0, total = 0;
    for (i = 0; i < N; i++)
    {
        if (quan[i] > 0)
        {
            Desciption(prod, pr, dis, i, id);
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
        printf("Check empty\n");
}

void main()
{
    int num = 0, i, q;
    int quan[N] = {0}, pr[N], dis[N];
    char** prod = (char**)malloc(sizeof(char*) * N);
    char** id = (char**)malloc(sizeof(char*) * N);
    for (i = 0; i < N; i++)
    {
        switch (i % 10) {
        case 0:
            prod[i] = (char*)malloc(sizeof(char) * 4); 
            prod[i] = "Pack";
            break;
        case 1:
            prod[i] = (char*)malloc(sizeof(char) * 4);
            prod[i] = "Milk";
            break;
        case 2:
            prod[i] = (char*)malloc(sizeof(char) * 5);
            prod[i] = "Bread";
            break;
        case 3:
            prod[i] = (char*)malloc(sizeof(char) * 3);
            prod[i] = "Egg";
            break;
        case 4:
            prod[i] = (char*)malloc(sizeof(char) * 5);
            prod[i] = "Flour";
            break;
        case 5:
            prod[i] = (char*)malloc(sizeof(char) * 5);
            prod[i] = "Apple";
            break;
        case 6:
            prod[i] = (char*)malloc(sizeof(char) * 4);
            prod[i] = "Meat";
            break;
        case 7:
            prod[i] = (char*)malloc(sizeof(char) * 4);
            prod[i] = "Fish";
            break;
        case 8:
            prod[i] = (char*)malloc(sizeof(char) * 4);
            prod[i] = "Nuts";
            break;
        case 9:
            prod[i] = (char*)malloc(sizeof(char) * 9);
            prod[i] = "Chocolate";
            break;
        }
        id[i] = (char*)malloc(sizeof(char) * 4);
        id[i][3] = i % 10 + '0';
        id[i][2] = (i / 10) % 10 + '0';
        id[i][1] = (i / 100) % 10 + '0';
        id[i][0] = (i / 1000) + '0';
    }
    Gen(pr, N, 1000.0); 
    Gen(dis, N, 50.0);
    q = Scan(&num, id); 
    do
    {
        Command();
        scanf("%d", &i);
        printf("\n");
        switch (i) {
        case 1: 
            q = Scan(&num, id);
            break;
        case 2:
            Desciption(prod, pr, dis, num, id);
            break;
        case 3: 
            AddToCheck(quan, num, q);
            num++;
            break;
        case 4:
            Form(quan, prod, pr, dis, id);
            break;
        case 5:
            Form(quan, prod, pr, dis, id);
            break;
        default:
            printf("Invalid command\n");
        }
    } 
    while (i != 5);
    for (i = 0; i < N; i++)
        free(prod[i]);
    free(prod);
    for (i = 0; i < N; i++)
        free(id[i]);
    free(id);
}
