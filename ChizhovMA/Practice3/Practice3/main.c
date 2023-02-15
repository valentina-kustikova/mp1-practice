#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int n;
int Check(int* arr);

int main()
{
	int i, x, j, cow=0, bull=0, k;
	int a[5];
	int b[5];
	
	do {
		printf("Enter the length of the number (2-5) ");
		scanf("%d", &n);
	} while ((n < 0) || (n > 5));
	
	srand((unsigned int)time(NULL));
	do {
		for (i = 0; i < n; i++)
			a[i] = rand() % 10;

	} while (Check(a)==0 || a[0]==0);

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	
	do {
		printf("\nEnter a number of non-repeating digits with a length of %d\n", n);
		scanf("%d", &x);
		while(x > 0)
		{
			k = n;
			for (i = n - 1; i >= 0; i--)
			{
				b[i] = x % 10;
				x = x / 10;
				k--;
			}
		}
	} while (Check(b)==0 || k!=0 || b[0]==0);
	
	while (true)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (a[i] == b[j])
				{
					if (i == j)
						bull++;
					else
						cow++;
				}
			}
		}
		
		
		if (bull == n)
		{
			printf("You guessed the number!");
			break;
		}
		else
			printf("%d cow(s) and %d bull(s) were found\n", cow, bull);

		do {
			printf("\nEnter a number of non-repeating digits with a length of %d\n", n);
			scanf("%d", &x);



			while (x > 0)
			{
				k = n;
				for (i = n - 1; i >= 0; i--)
				{
					b[i] = x % 10;
					x = x / 10;
					k--;
				}
			}

		} while (Check(b) == 0 || k != 0 || b[0] == 0);
		cow = 0;
		bull = 0;
	}

	return 0;
}


int Check(int* arr)
{
	int Un_index = 0, Cur_index;

	for (Cur_index = 0; Cur_index < n; Cur_index++)
	{
		if ((Cur_index != Un_index) && (arr[Cur_index] == arr[Un_index]))
			return 0;
		if (Cur_index == n-1 && Un_index != n-1)
		{
			Un_index++;
			Cur_index = 0;
		}
			
	}

	return 1;
}
