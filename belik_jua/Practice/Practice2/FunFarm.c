#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int i, n, bull = 0, cow = 0, a, j, m;
	int num[10], inp[10], sam[10] = { 0,1,2,3,4,5,6,7,8,9 };
	srand((unsigned int)time(0));
	
	do {
		printf("0 > n > 10, n = ");
		scanf("%d", &n);
	} while ((n <= 0) || (n > 10));

    i = n - 1;
    m = 9.0 / RAND_MAX * rand() + 1;
    num[0] = m;
    sam[m] = -1;
	while (i > 0)
	{
		m = 10.0 / RAND_MAX * rand();
		if (sam[m] != -1) 
		{
			num[i] = sam[m];
			sam[m] = -1;
			i--;
		} 
	}
 
	do {
		bull = 0;
		cow = 0;
		do {
			m = 0;
			printf("number (no repetitions) = ");
			scanf("%d", &a);
            for (i = (n - 1); i >= 0; i--)
			{
				inp[i] = a % 10;
				a = a / 10;
			}
            for (i = (n - 1); i >= 0; i--)
			{
				for (j = (i - 1); j >= 0; j--)
				{
					if (inp[i] == inp[j]) m++;
				}
			}
		} while (m != 0);
        for (i = (n - 1); i >= 0; i--)
		{
            for (j = (n - 1); j >= 0; j--)
			{
				if ((num[i] == inp[j]) && (i == j)) bull++;
				if ((num[i] == inp[j]) && (j != i)) cow++;
			}
		}
		printf("cow = %d and bull = %d \n", cow, bull);
	} while (bull != n);
	printf("you win");
}