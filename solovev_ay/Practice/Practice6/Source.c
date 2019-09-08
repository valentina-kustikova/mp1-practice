#include "Header.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include<locale.h>
#define _CRT_SECURE_NO_WARNINGS
void main()
{
	int kolvo, kolvo2;
	VECTOR rofl;
	VECTOR kurdyk;
	VECTOR sum, sub;
	setlocale(LC_ALL, "Russian");
	printf("enter size vector1:");
	scanf("%d", &kolvo);
	kurdyk = input(kolvo);
	printf("enter size vector2:");
	scanf("%d", &kolvo2);
	rofl = input(kolvo2);
	printf("length 1 and 2\n");
	length(rofl);
	printf("\n");
	length(kurdyk);
	printf("\n");
	corner(rofl, kurdyk);
	printf("\n");
	printf("skalyar");
	float skl = skalyar(rofl, kurdyk);
	sum = Sum(kurdyk, rofl);
	sub = roflan(kurdyk, rofl);
	printf("\n");
	printf("vector summa");
	Output(sum);
	printf("\n");
	printf("vector raznosti");
	Output(sub);
	Delete(rofl);
	Delete(sum);
	Delete(kurdyk);
	Delete(sub);
	system("pause");
};
