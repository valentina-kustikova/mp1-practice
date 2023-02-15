#include <stdio.h>
#include <stdlib.h>
void A2()													 //computer is guessing (2 digits)
{

	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, b[2] = { 0 };
	int i = 1, n, k = 0, c, d;
	while ((b[0] == 0) || (b[1] == 0)) {
		k++;
		printf("%d%d", (a[i]), (a[0]));
		printf("?\n");
		scanf("%d%d", &c, &d);
		if ((c == 1) && (d == 0)) {
			b[0] = a[i];
			c = 0;
			d = 0;
		}
		else {
			b[1] = a[i];
			c = 0;
			d = 0;
		}
		i++;
	}
	printf("%d%d %d", b[0], b[1], k);
	return 0;
}
void A3()  													 //3 digits
{
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, b[3] = { 0 };
	int i = 1, n, k = 0, c, d;
	while ((b[0] == 0) || (b[1] == 0) || (b[2] == 0)) {
		k++;
		printf("%d%d%d", (a[i]), (a[0]), (a[0]));
		printf("?\n");
		scanf("%d%d", &c, &d);
		if ((c == 1) && (d == 0)) {
			b[0] = a[i];
			c = 0;
			d = 0;
		}
		else if ((c == 0) && (d == 1)) {
			printf("%d%d%d", (a[0]), (a[i]), (a[0]));
			printf("?\n");
			scanf("%d%d", &c, &d);
			k++;
			if ((c == 1) && (d == 0)) {
				b[1] = a[i];
				c = 0;
				d = 0;
			}
			else {
				b[2] = a[i];
				c = 0;
				d = 0;
			}
		}
		i++;
	}
	printf("%d%d%d %d", b[0], b[1], b[2], k);
	return 0;
}
void A4()													 //4 digits
{
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, b[4] = { 0 };
	int i = 1, n, k = 0, c, d;
	while ((b[0] == 0) || (b[1] == 0) || (b[2] == 0) || (b[3] == 0)) {
		k++;
		printf("%d%d%d%d", (a[i]), (a[i]), (a[0]), (a[0]));
		printf("?\n");
		scanf("%d%d", &c, &d);
		if ((c == 1) && (d == 0)) {
			printf("%d%d%d%d", (a[i]), (a[0]), (a[0]), (a[0]));
			printf("?\n");
			k++;
			scanf("%d%d", &c, &d);
			if ((c == 1) && (d == 0))
			{
				b[0] = a[i];
				c = 0;
				d = 0;
			}
			else
			{
				b[1] = a[i];
				c = 0;
				d = 0;
			}
		}
		if ((c == 0) && (d == 1)) {
			printf("%d%d%d%d", (a[0]), (a[0]), (a[i]), (a[0]));
			printf("?\n");
			k++;
			scanf("%d%d", &c, &d);
			if ((c == 1) && (d == 0))
			{
				b[2] = a[i];
				c = 0;
				d = 0;
			}
			else
			{
				b[3] = a[i];
				c = 0;
				d = 0;
			}
		}
		i++;
	}
	printf("%d%d%d%d %d", b[0], b[1], b[2], b[3], k);
	return 0;
}
void A5()													 //5 digits
{
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, b[5] = { 0 };
	int i = 1, n, k = 0, c, d;
	while ((b[0] == 0) || (b[1] == 0) || (b[2] == 0) || (b[3] == 0) || (b[4] == 0)) {
		k++;
		printf("%d%d%d%d%d", (a[i]), (a[0]), (a[0]), (a[0]), (a[0]));
		printf("?\n");
		scanf("%d%d", &c, &d);
		if ((c == 1) && (d == 0)) {
			b[0] = a[i];
			c = 0;
			d = 0;
		}
		else if ((c == 0) && (d == 1)) {
			printf("%d%d%d%d%d", (a[0]), (a[i]), (a[0]), (a[0]), (a[0]));
			printf("?\n");
			scanf("%d%d", &c, &d);
			k++;
			if ((c == 1) && (d == 0)) {
				b[1] = a[i];
				c = 0;
				d = 0;
			}
			else if ((c == 0) && (d == 1)) {
				printf("%d%d%d%d%d", (a[0]), (a[0]), (a[i]), (a[0]), (a[0]));
				printf("?\n");
				scanf("%d%d", &c, &d);
				k++;
				if ((c == 1) && (d == 0)) {
					b[2] = a[i];
					c = 0;
					d = 0;
				}
				else if ((c == 0) && (d == 1)) {
					printf("%d%d%d%d%d", (a[0]), (a[0]), (a[0]), (a[i]), (a[0]));
					printf("?\n");
					scanf("%d%d", &c, &d);
					k++;
					if ((c == 1) && (d == 0)) {
						b[3] = a[i];
						c = 0;
						d = 0;
					}
					else if ((c == 0) && (d == 1)) {
						b[4] = a[i];
						c = 0;
						d = 0;
					}
				}
			}
		}
		i++;
	}
	printf("%d%d%d%d%d %d", b[0], b[1], b[2], b[3], b[4], k);
	return 0;
}
void B(n)													//human is guessing
{
	{
		int a[5] = { 0 }, b[5] = { 0 }, i = 0, ii = 0, k, l, f = 1, n1, n2, bull = 0, cow = 0, tmp = 0;
		time_t t;
		srand((unsigned)time(&t));
		for (i = 0; i < n; i++) {							//generating a number with unique digits
			do {
				k = (rand() % 9) + 1;
				if ((a[0] != k) && (a[1] != k) && (a[2] != k) && (a[3] != k) && (a[4] != k)) {
					a[i] = k;
				}
			} while (a[i] == 0);
		}
		for (i = 0; i < n; i++) {							//printing that number in case there is a mistake
			printf("%d", a[i]);
		}
		for (i = 0; i < n; i++) {
			f *= 10;
		}
		do {
			printf("\nenter your guess: ");

			do {											//player is guessing
				scanf("%d", &l);
				for (i = n - 1; i >= 0; i--) {
					b[i] = l % 10;
					l /= 10;
				}
				tmp = 0;
				for (i = 0; i < n; i++) {
					for (int kk = i + 1; kk < n; kk++) {
						if ((b[i] == b[kk]) || (b[kk] == 0)){
							tmp = 1;
							break;
						}
					}
				}
				if (tmp == 1) {
					printf("you've entered a wrong number");
				}
			} while (tmp == 1);
			ii++;
			for (n1 = 0; n1 < n; n1++) {					//checking if there are any bulls or cows
				for (n2 = 0; n2 < n; n2++) {
					if ((n1 == n2) && (a[n1] == b[n2])) {
						bull++;
					}
					else if ((n1 != n2) && (a[n1] == b[n2])) {
						cow++;
					}
				}
			}
			printf("bulls: %d", bull);
			printf(", cows: %d\n", cow);
			if (bull == n) {
				printf("Bingo! Total attemts count: %d", ii);
				return 0;
			}
			cow = 0;
			bull = 0;
		} while (1);
	}
}
int main()													//player is choosing a game mode
{
	int n, i;
	printf("chhose a game, 1 or 2: ");
	do {
		scanf("%d", &i);
	} while ((i != 1) && (i != 2));
	printf("enter your number's length (2-5): ");
	do {
		scanf("%d", &n);
	} while ((n < 2) && (n > 5));
	if (i == 1) {
		switch (n)
		{
		case 2:
			A2();
			return 0;
		case 3:
			A3();
			return 0;
		case 4:
			A4();
			return 0;
		case 5:
			A5();
			return 0;
		}
	}
	else { B(n); }
	return 0;
}