#include <stdio.h>
#include <string.h>

#define L 4

void scan(char qr[]);
void info(int qrSelect, char name[], int cost[], int discount[]);
void addToCheck(int qrSelect, int check[]);
void createCheck(int check[], char name[], int cost[], float discount[]);
void totalCost(int check[], int cost[], float discount[]);

int main()
{
	int i,j, select;
	int check[L] = {0,0,0,0};
	char qr[L][4] = { "0000","0001","0200","9000" };
	char name[L][4] = { "milk","cake","juse","bean" };
	int cost[L] = {50,250,15,30};
	float discount[L] = { 0.10f,0.40f,0.0f,0.15f };
	char qrSelect[4] = "9999";
	printf("QRs: ");
	for (i = 0; i < L; i++) { for (j = 0; j < 4; j++) { printf("%c",qr[i][j]); }; printf(" "); };
	printf("\n");
	do
	{
		printf("select option (0 - exit, 1 - scan QR, 2 - product info, 3 - add product to check, 4 - create check, 5 - get total cost): ");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1: scan(qrSelect); for (j = 0; j < 4; j++) { printf("%c", qrSelect[j]); }; break;
		/*case 2: info(qrSelect, name, cost, discount); break;
		case 3: addToCheck(qrSelect, check); break;
		case 4: createCheck(check, name, cost, discount); break;
		case 5: totalCost(check, cost, discount); select = 0; break;*/
		default:break;
		}

	} while (select != 0);
	return 0;
}

void scan(char qr[])
{
	getchar();
	printf("Enter QR:");
	gets(qr);
}
void info(int qrSelect, char name[],int cost[], float discount[])
{
	int i;
	if (qrSelect == -1) { printf("uncorect QR\n"); }
	else
	{
		printf("product name: ");
		for (i = 0; i < 4; i++)
		{
			printf("%c", name[4* qrSelect + i]);
		}
		printf("\nproduct cost: %d\n",cost[qrSelect]);
		printf("product discount: %2.1f\n", discount[qrSelect]*100);
	}
}
void addToCheck(int qrSelect, int check[])
{
	if (qrSelect == -1) { printf("uncorect QR\n"); }
	else { check[qrSelect]++; printf("product added\n");}
}
void createCheck(int check[], char name[], int cost[], float discount[])
{
	int i,j;
	printf("\tname\t|\tcost\t|\tquantity\t|\ttotal cost\t\n");
	printf("--------------------------------------------------------------------------------\n");
	for (i = 0; i < L; i++)
	{
		if (check[i] > 0)
		{
			printf("\t");
			for (j = 0; j < 4; j++)
			{
				printf("%c", name[4 * i + j]);
			}
			printf("\t|\t%.2f\t|\t%8d\t|\t%.2f\t\n", cost[i] * (1 - discount[i]), check[i], cost[i] * (1 - discount[i]) * check[i]);
		}
	}
}
void totalCost(int check[], int cost[], float discount[])
{
	int i; float s = 0.0f;
	for (i = 0; i < L; i++)
	{
		s += cost[i] * (1 - discount[i]) * check[i];
	}
	printf("Total Cost: %.2f",s);
}