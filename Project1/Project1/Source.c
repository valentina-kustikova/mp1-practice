#include <stdio.h>
#include <math.h>
int main()
{
  float v1, v2, s, t;
  scanf_s("%f %f %f %f", &v1, &v2, &s, &t);
  printf("%f", fabs(s-t*(v1+v2)));
  return 0;
}
