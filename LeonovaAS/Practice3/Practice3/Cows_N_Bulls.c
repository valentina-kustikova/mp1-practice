#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int n, i, j, num[6];
    printf("Input n: \n");
    scanf("%d", &n);
    srand((unsigned int)time(0));
    for (i = 0; i < n; i++)
    {
        num[i] = rand() % 10;    
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                while (num[i] == num[j])
                {
                    num[i] = rand() % 10;
                }
            }
        }

    }
    for (i = 0; i < n; i++)
    {
        printf("%d", num[i]);
    }
}