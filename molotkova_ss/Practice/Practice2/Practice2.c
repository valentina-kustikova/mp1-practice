
﻿#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void main() {
	int i, n, j, cow, bull;
	int m, a, b, c;
	int ch[10], arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	srand((unsigned int)time(0));
	printf("Bulls and cows!\n");
	
	do {
		printf("Ââåäèòå çíà÷åíèå n\n");
		scanf("%d", &n);
	} while ((n <= 0) && (n > 10));
	m = rand() % 100 + 15; 
	for (i = 0; i < m; i++)
	{
		a = 10.0 / RAND_MAX * rand();
		b = 10.0 / RAND_MAX * rand();
		if (a != b) {
			c = arr[a];
			arr[a] = arr[b];
			arr[b] = c;
		}
	}
	if (arr[0] == 0)
	{
		c = arr[0];
		a = 9.0 / RAND_MAX * rand() + 1;
		arr[0] = arr[a];
		arr[a] = c;
	}
	for (i = n; i < 10; i++)
		arr[i] = -1;
	for (i = 0; i < n; i++)
		printf("%d", arr[i]);
	c = 0;
	do {
		cow = 0; bull = 0; c++;
		do {
			m = 0;
			printf("Ââåäèòå ÷èñëî áåç ïîâòîðåíèé\n");
			scanf("%d", &a);
			for (i = (n - 1); i >= 0; i--)
			{
				ch[i] = a % 10;
				a = a / 10;
			}
			for (i = n; i > 0; i--)
			{
				for (j = (i - 1); j > 0; j--)
				{
					if (ch[i] == ch[j])
						m++;
				}
			}
		} while (m != 0);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
			{
				if ((arr[i] == ch[j]) && (i == j))
					bull++;
				if ((arr[i] == ch[j]) && (i != j))
					cow++;
			}
		}
		printf("Áûêè=%d, êîðîâû=%d\n", bull, cow);
	} while (bull != n);
	printf("Âû ïîáåäèëè, êîëè÷åñòâî ïîïûòîê %d\n", c);

}