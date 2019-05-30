#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	char m;
	int mode, num, i = 0, inp;
	int a = 1, b = 1001;
	srand((unsigned int)time(0));
	do
	{
		printf("Choose mode 1 or 2 \n");
		scanf("%d", &mode);
	} while ((mode > 2) || (mode < 1));

	if (mode == 1)
	{
		num = 1000.0 / RAND_MAX * rand() + 1;
		do
		{
			do {
				printf("inp = ");
				scanf("%d", &inp);
			} while ((inp < 1) || (inp > 1000));
			if (num > inp) printf(" > \n");
			if (num < inp) printf(" < \n");
			i++;
		} while (inp != num);
		printf("You guessed from %d attempts", i);
	}
	if (mode == 2)
	{
		do {
			printf("num = ");
			scanf("%d", &num);
		} while ((num < 1) || (num>1000));
		do {
			i++;
			inp = ((double)(b - a)) / RAND_MAX * rand() + a;
			printf("%d ", inp);
			scanf("%s", &m);
			switch (m)
			{
			case '>': a = inp + 1;
				break;
			case '<': b = inp;
			}
			if (m == '=') inp = 0;
		} while (inp != 0);
		printf("The program guessed from %d attempts", i);
	}
}