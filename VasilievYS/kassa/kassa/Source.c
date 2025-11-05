#include <stdio.h>
#include<string.h>
#include <locale.h>
struct good {
  char code;
  char name;
  float price;
  int sale;
};
int main()
{
  int i = 0, n=4;
  struct good bd[4];
  setlocale(LC_ALL, "Russian");
  bd[0].code = "1010"; bd[0].name = "Вода 0.5"; bd[0].price = 35; bd[0].sale = 10;
  bd[1].code = "1210"; bd[1].name = "Шоколад"; bd[1].price = 85; bd[1].sale = 15;
  bd[2].code = "1213"; bd[2].name = "Фарш куриный"; bd[2].price = 200; bd[2].sale = 5;
  bd[3].code = "1310"; bd[3].name = "Мука 2кг"; bd[3].price = 99; bd[3].sale = 20;
 // for (i = 0; i < n; i++)
 // {
   printf("%s", bd[0].code);
  //}
   return 0;
}