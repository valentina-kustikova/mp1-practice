#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
void main()
{
	int n, ch, r, min = 1, max = 1000, count = 0;
	char z[3];
	printf("Rezhim raboti:\n");
	printf("1-computer zagadivaet chislo\n");
	printf("2-polzovatel zagadivaet chislo\n");
	printf("Vibirite rezhim raboti: ");
	scanf("%d", &r);
	if (r == 1)
	{
		srand((unsigned int)time(0));
		ch = rand() % 1000 + 1;
		while (1)
		{
			do
			{
				printf("Vvedite chislo: \n");
				scanf("%d", &n);
				if ((n <= 0) || (n >= 1000))
					printf("Chislo dolzgno bit v diapazone ot 1 do 1000 \n");
			} while ((n <= 0) || (n >= 1000));
			count++;
			if (n == ch)
			{
				printf("Vi ugadali chislo! \n");
				printf("Chislo popitok: %d \n", count);
				return;
			}
			else if (n > ch)
				printf("Vvedennoe chislo bolshe zagadannogo \n");
			else
				printf("Vvedennoe chislo menshe zagadannogo \n");
		}
	}
	else if (r == 2)
		do
		{
			printf("Vvedite chislo: \n");
			scanf("%d", &n);
			if ((n <= 0) || (n >= 1000))
				printf("Chislo dolzgno bit v diapazone ot 1 do 1000 \n");
		} while ((n <= 0) || (n >= 1000));
		while (z[0] != '=')
		{
			srand((unsigned int)time(0));
			ch = rand() % (max - min + 1) + min;
			printf("Computer: %d \n", ch);
			printf("Vvedite (>),(<),(=) v sootvetstvii s tem bolshe, menshe ili ravno zagadanoe chislo i otgadki computera \n");
			scanf("%9s", &z);
			switch (z[0])
			{
			case '>': min = ch;
				count++;
				break;
			case '<': max = ch;
				count++;
				break;
			case '=':count++;
				printf("Computer ugadal chislo! \n");
				printf("Chislo popitok : %d \n", count);
				break;
			default: printf("Vvedeno nekorrektnoe znacheie");
				break;
			}
		}
}