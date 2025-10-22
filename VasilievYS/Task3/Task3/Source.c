#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
int main()
{
  int n, temp, i, a[5], j, b[5] = { 0 }, num=0, ans=0, bull=0, cow=0;
  setlocale(LC_ALL, "Russian");
  srand((unsigned int)time(0));
  printf("Длина числа: ");
  scanf_s("%d", &n);
  for (i = 0; i < n; i++)
  {
    a[i] = rand() % 9 + 1;
    num += a[i] * pow(10, n -1 - i);
  }
  printf("%d", num);
  while (num != ans)
  {
    printf("Ваше число длинной из %d cимволов: ", n);
    scanf("%d", ans);
    if (ans == num)
      printf("Верно");
    else
    {
      for (i = 0; i < n; i++)
      {
        temp = ans % 10;
        b[n - 1 - i] = temp;
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
          for (j = 0, j < n, j++)
          {

          }
        }
      }
    }
  }
  return 0;


}