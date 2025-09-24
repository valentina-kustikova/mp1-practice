
#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
  float cx1, cy1, r1, cx2, cy2, r2;
  setlocale(LC_ALL, "Russian");
  scanf_s("%f %f %f %f", &cx1, &cy1, &cx2, &cy2);
  scanf_s("%f %f", &r1, &r2);
  if (r1 <= 0 || r2 <= 0)
  {
    printf("Не существует");
    return 1;
  }
  if (cx1 == cx2 && cy1 == cy2 )
  {
    if (r1 == r2)
    {
      printf("Совпадают");
    }
    else
    {
      printf("Одна окружность внутри другой");
    }
  }
  else if(((cx2 + r2 < cx1 + r1)&&(cy2 + r2 < cy1 + r1))||((cx1 + r1 < cx2 + r2)&&(cy1 + r1 < cy2 + r2)))
  {
    printf("Одна окружность внутри другой");
  }
 return 0;
}

