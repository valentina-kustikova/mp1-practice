#include <stdio.h>
#include <stdlib.h>

int main()
{
	srand(time());
	int i,j,bulls = 0,cows = 0,userNumber,L;
	printf("enter number (1-9):");
	scanf_s("%d", &L);
	int num[9];
	int userNum[9];
	for (i = L - 1; i >= 0; i--)
	{
		do {
			userNumber = rand() % 9 + 1;
			for (j = L - 1; j > i; j--) { if (num[j] == userNumber) { break; }};
		} while (j != i);
		num[i] = userNumber;
	}
	printf("----Bulls and Cows----\n\n");
	while (bulls < L)
	{
#ifdef DEBUG
		for (i = L - 1; i >= 0; i--) {
			printf("%d", num[i]);
		}
		printf("\n");
#endif
		printf("enter an %d-digit number: ", L);
		scanf_s("%d", &userNumber);
		for (i = 0; i < L; i++) { userNum[i] = userNumber % 10; userNumber /= 10;}
		for (i = 0; i < L; i++)
		{
			for (j = i+1; j < L; j++) { if (userNum[j] == userNum[i]) { break; } };
			if (j != L) { break; }
		}
		if (i == L) {
			for (i = 0; i < L; i++)
			{
				userNumber *= 10;
				userNumber += userNum[i];
			}
			i = 0; bulls = 0; cows = 0;
			while (userNumber > 0 && i < L)
			{
				if (userNumber % 10 == num[i]) { bulls++; };
				for (j = 0; j < L; j++) { if (userNumber % 10 == num[j]) { cows++; } };
				i++;
				userNumber /= 10;
			}
			printf("Bulls = %d, Cows = %d\n\n", bulls, cows - bulls);
		}
		else { printf("Uncorect enter!\n"); }
	}
	printf("You win!");
	return 0;
}