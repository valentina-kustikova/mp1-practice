#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void main()
{
int a, b;
srand((unsigned int)time(0));
a=(int)(1000.0 / RAND_MAX * rand());
printf("%d", a);
printf("угадайте число");
do {scanf("%d", &b);}
while b!=a;
}

