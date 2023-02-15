#include <stdlib.h>
#include <time.h>
#include <stdio.h>
int main() 
{
	int game_variant;
	srand((unsigned int)time(NULL));
	do 
	{
		printf("game variant=");
		scanf_s("%d", &game_variant);
	} while ((game_variant < 1) || (game_variant > 2));
	if (game_variant == 1)
	{
		int r_number=rand()%1001, p_number, i=0;
		do
		{
			printf("enter a number\n");
			scanf_s("%d", &p_number);
			i++;
			if ((p_number > 1000) || (p_number < 0))
			{
				printf("input error\n");
			}
			else if (p_number > r_number)
			{
				printf("random number less\n");
			}
			else if (p_number < r_number)
			{
				printf("random number is greater\n");
			}
			else
			{
				printf("random number guessed\n");
			}
			
		} while (r_number != p_number);
		printf("number of attempts=%d\n", i);
	}
	else
	{
		int r_numb, i = 0, k=0, upper_limit=1001, lower_limit=0, answer;
		while (k != 1)
		{
			r_numb = rand() % (upper_limit - lower_limit + 1) + lower_limit;
			printf("hidden number = %d?\n", r_numb);
			scanf_s("%d", &answer);         //0 - hidden number lower     1 - higher      2 - guessed 
			i++;
			if (answer == 0)
			{
				upper_limit = r_numb;
			}
			else if (answer == 1)
			{
				lower_limit = r_numb;
			}
			else if (answer == 2)
			{
				printf("number of attempts =%d", i);
				k++;
			}
			else
			{
				printf("input error");
			}
		}
	}
	return 0;
}