#include <stdio.h>
#include <stdlib.h>
int bigger(max, k) //random number between k and max
{
	time_t t;
	int n;
	srand((unsigned)time(&t));
	n = (rand() % (max - k)) + k;
	return n;
}
int smaller(min, k) //random number between min and k
{
	time_t t;
	int n;
	srand((unsigned)time(&t));
	n = (rand() % (k - min)) + min;
	return n;
}
void A() //first game
{
	time_t t;
	int a, n, i = 0;
	srand((unsigned)time(&t));
	n = rand() % 1000;
	printf("debug: %d\n", n); //checking the machine generated number (just in case)
	printf("enter your first guess: ");
	do {
		i++;
		scanf("%d", &a);
		if ((a == n) && (a > 0) && (a < 1000))
		{
			printf("That's it! Attemts count: %d", i);
			return 0;
		}
		else if ((a < n) && (a > 0) && (a < 1000))
		{
			printf("bigger... ");
		}
		else if ((a > n) && (a > 0) && (a < 1000))
		{
			printf("smaller... ");
		}
	} while (1); //this loop makes program not to break if strng is intodused instead of int
}
void B() //second game with randomly generated guesses
{
	time_t t;
	char ch;
	int n = 0, a, i = 0, k = 0, min = 0, max = 1000;
	srand((unsigned)time(&t));
	printf("enter one natural number to 1000 from 0: ");
	do {
		scanf("%d", &a);
	} while ((a > 1000) || (a < 0));
	n = rand() % 1000;
	do {
		i++;
		printf("is it %d", n);
		printf("? ");
		do {
			scanf("%c", &ch);
		} while ((ch != 'y') && (ch != 'b') && (ch != 's'));
		if (ch == 'y') {
			printf("Woohoo! It's %d", n);
			printf("! Total attemts count: %d", i);
			return 0;
		}
		else if (ch == 'b') {
			min = n + 1;
			n = bigger(max, n);
		}
		else {
			max = n - 1;
			n = smaller(min, n);
		}
	} while (1);
}
void B1() //second game with an optimized algorithm (up to 10 moves (log2(1000)))
{
	time_t t;
	char ch;
	int n = 0, a, i = 0, k = 0, min = 1, max = 1000;
	srand((unsigned)time(&t));
	printf("enter one natural number to 1000 from 0: ");
	do {
		scanf("%d", &a);
	} while ((a > 1000) || (a < 0));
	do {
		i++;
		n = (min + max) / 2;
		if (n == k) {
			n -= 1;
		}
		printf("is it %d", n);
		printf("? ");
		do {
			scanf("%c", &ch);
		} while ((ch != 'y') && (ch != 'b') && (ch != 's'));
		if (ch == 'b') {
			min = n;
		}
		else if (ch == 's') {
			max = n;
		}
		else {
			printf("gotcha! Total attemts count: %d", i);
			return 0;
		}
	} while (1);
}
int main() //choosing a game
{
	char a, b;
	printf("choose game, A or B: ");
	do {
		scanf("%c", &a);
	} while ((a != 'A') && (a != 'B'));
	if (a == 'B')
	{
		printf("choose your regime: 1 is for random, 2 is for optimized ");
		do {
			scanf("%c", &b);
		} while ((b != '1') && (b != '2'));
		if (b == '1')
		{
			B();
		}
		else
		{
			B1();
		}
	}
	else
	{
		A();
	}
	return 0;
}