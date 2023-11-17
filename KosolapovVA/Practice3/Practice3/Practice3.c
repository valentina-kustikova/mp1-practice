#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
void bot_fill(int *ar, int n);
void user_fill(int *ar, int n, int num);
int botnum(int* ar, int n);
int checkbul(int *ar, int *arr, int n);
int checkcow(int* ar, int* arr, int n);
int main() 
{
    int arr_bot[N], arr_user[N], n_long, user_num, bot_num, cow_count, bul_count, count=0;
    do {
        printf("Input the length of the number from 2 to 5: \n");
        scanf("%d", &n_long);
    } while ((n_long < 2) || (n_long > 5));
    bot_fill(&(arr_bot[0]), n_long);
    bot_num = botnum(&(arr_bot[0]), n_long);
    do {
        printf("Please input your answer length=%d:\n", n_long);
        scanf("%d", &user_num);
        user_fill(&(arr_user[0]), n_long, user_num); 
        bul_count = checkbul(&(arr_bot[0]), &(arr_user[0]), n_long);
        cow_count = checkcow(&(arr_bot[0]), &(arr_user[0]), n_long);
        printf("cow=%d, bul=%d\n", cow_count, bul_count);
        count++;
    } while (user_num != bot_num);
    printf("You won in %d attempts, the hiden number is %d",count, bot_num);
    return 0;

}
void bot_fill(int *ar, int n)
{
    int i = 0, j, count;
    srand((unsigned int)time(0));
    ar[i] = 1 + rand() % 9;
    i = 1;
    for (; i < n; i++)
    {
        do {
            count = 0;
            ar[i] = rand() % 10;
            for (j = 0; j < i; j++)
            {
                if (ar[j] == ar[i])
                    count++;
            }
        } while (count > 0);
    }
}
void user_fill(int *ar, int n, int num)
{
    int i = n-1,j;
    for (; i >=0; i--)
    {
        j = num % 10;
        ar[i] = j;
        num = num / 10;
        
    }
}
int botnum(int *ar, int n)
{
    int i = 0, num;
    num = ar[i];
    for (i = 1; i < n; i++)
    {
        num = num * 10 + ar[i];
    }
    return num;
}
int checkbul(int* ar, int* arr, int n)
{
    int i = 0,bul=0;
    for (; i < n; i++)
    {
        if (ar[i] == arr[i])
        {
            bul++;
        }
    }
    return bul;
}
int checkcow(int* ar, int* arr, int n)
{
    int i = 0,j, cow = 0;
    for (; i < n; i++)
    {
        for (j=0; j < n; j++)
        {
            if ((ar[i] == arr[j]) && (i != j))
            {
                cow++;
            }
        }
    }
    return cow;
}
