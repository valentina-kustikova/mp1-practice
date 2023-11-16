#include <stdio.h>
#define N 5
int main()
{
    int n, number1, number2, number3, number4, number5;
    int computer[N], people[N], cow, bull;
    do {
        printf("Input line:\n");
        scanf("%d", &n);
    } while ((n != 2) && (n != 3) && (n != 4) && (n != 5));

    srand((unsigned int)time(0));
    computer[0] = 1 + rand() % 9;
    int i, g;
    for (i = 1; i < n; i++)
    {
        for (g = 0; g < i; g++)
        {
            do {
                srand((unsigned int)time(0));
                computer[i] = rand() % 10;
            } while (computer[i] == computer[g]); //заполныем массив рандомом + убираем повторы 
        }
    }

    printf("%d %d %d %d %d\n", computer[0], computer[1], computer[2], computer[3], computer[4]);

    do {
        cow = 0, bull = 0;
        printf("input your answer:");
        fill(&(people[0]), N);
        for (i = 0; i < n; i++)
        {
            for (g = 0; g < i; g++)
            {
                if (computer[i] == people[g])
                    cow++;
                if (computer[i] == people[i])
                    bull++;
            }
        }
        printf("count cows:  ");
        printf("%d\n", cow);
        printf("count bulls: ");
        printf("%d\n", bull);
    } while (bull != n);
    printf(" you win! ");
}

int fill(int *people, int n)
{
    int i = 0;
    for (; i < n; i++)
        scanf("%d", &(people[i]));
}