#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
int main()
{
  int n, check = 0, temp, i, a[5], j, b[5] = { 0 }, num=0, ans=0, bull=0, cow=0;
  setlocale(LC_ALL, "Russian");
  srand((unsigned int)time(0));
  printf("Длина числа(от 2 до 5): ");
  scanf_s("%d", &n);
  for (i = 0; i < n; i++)
  {
    a[i] = rand() % 9 + 1;
    
  }
  while (check != 1)
  {
      check = 1;
      for (i = 0; i < n; i++)
      {
          for (j = 0; j < n; j++)
          {
              if (a[i] == a[j] && i!=j)
              {
                  a[i] = rand() % 9 + 1; 
              }
          }
      }
      for (i = 0; i < n; i++)
      {
          for (j = 0; j < n; j++)
          {
              if (a[i] == a[j] && i!=j)
              {
                  check = 0;
              }
          }
      }
  }
  for (i = 0; i < n; i++)
  {
      num += a[i] * pow(10, n - 1 - i);
  }
  while (num != ans)
  {
    printf("Ваше число длинной из %d cимволов: ", n);
    scanf_s("%d", &ans);
    if (ans == num)
      printf("Верно");
    else
    {
      for (i = 0; i < n; i++)
      {
        temp = ans % 10;
        b[n - 1 - i] = temp;
        ans /= 10;
      }
      for (i = 0; i < n; i++)
      {
        if (b[i] == a[i])
        {
          bull++;
          continue;
        }
        else
        {
          for (j = 0; j < n; j++)
          {
              if (b[i] == a[j] && i != j)
              {
                  cow++;
                  continue;
              }
          }
        }
      }
      printf("Быков: %d\n", bull);
      printf("Коров: %d\n", cow);
      cow = 0;
      bull = 0;
    }
  }
  return 0;
}