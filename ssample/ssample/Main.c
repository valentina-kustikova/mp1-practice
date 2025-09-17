# include <stdio.h>
int main() {
  float V1, V2, S, T;
  scanf_s("%f%f%f%f", &V1, &V2, &S, &T);
  printf("s=%f", S+(V1+V2)*T);
  return 0;
}