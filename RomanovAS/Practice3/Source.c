#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
int main()
{
	int b[N], c[5] = { 0 }, a[5] = { 0 }, i, n = 0, cow = 0, bull = 0, p = 0, s, j, k = 0, d = 1, x = 0, o;
	printf("Vvedite skolki znachnim budet ygadivaemoe chislo (ot 2 do 5)");
	do
	{
		scanf("%d", &n);
	} while ((n < 2) || (n > 5));
	srand(time(NULL));
	while (k < n)
	{
		i = rand() % 10;
		if (b[i] != 1)
		{
			x += i * d;
			b[i] = 1;
			k++;
			d *= 10;
		}
	} 
	for (i = 0; i < n; i++)
	{
		a[i] = x % 10;
		x /= 10;
	}
	do
	{
		p++;
		cow = 0;
		bull = 0;
		printf("\nVvedite vashu popitku");
		scanf("%d", &j);
		for (i = 0; i < n; i++)
		{
			c[i] = j % 10;
			j /= 10;
		}
		for (i = 0; i < n; i++)
		{
			for (o = 0; o < n; o++)
			{
				if ((c[i] == a[o]) && (i != o))
				{
					cow++;
				}
				if ((c[i] == a[o]) && (i == o))
				{
					bull++;
				}
			}
		}
		if (bull == n)
		{
			printf("Vi otgadali, kolichestvo popitok - %d", p);
			s = 1;
		}
		else
		{
			printf("Kolichestvo bikov - %d  ", bull);
			printf("Kolichestvo korov - %d  ", cow);
			s = 0;
		}
	} while (s != 1);
	return 0;
}