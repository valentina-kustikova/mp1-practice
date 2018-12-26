#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

void main()
{
	int n, chislo;
	int d[10];
	srand(time(NULL));
    chislo = rand();
	setlocale(LC_ALL, "Rus");
	printf("¬ведите длину загадываемого числа: ");
	scanf("%d", &n);
}