#include <stdio.h>

#define L 4
int scan(char);

int main()
{
	int i,j, select;
	int check[] = {0,0,0,0};
	char qr[] = {"0000000102009000"};
	char name[] = "milkcakejusebean";
	int cost[] = {50,250,15,30};
	int discount[] = { 10,40,0,15 };
	char qrSelect = -1;
	printf("QRs: ");
	for (i = 0; i < L; i++) { for (j = 0; j < 4; j++) { printf("%c",qr[i*4+j]); }; printf(" "); };
	printf("\n");
	do
	{
		printf("select option (0 - exit, 1 - scan QR, 2 - product info, 3 - add product to check, 4 - create check, 5 - get total cost): ");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1: qrSelect = scan(qr); break;
		}

	} while (select != 0);
	return 0;
}

int scan(char a[])
{
	char qr[4]; int i,j, result = -1;
	printf("Enter QR:");
	scanf_s("%s", &qr);
	for (i = 0; i < 4; i++)
	{
		printf("%d %c\n", i, qr[i]);
	}
	for (i = 0; i < L; i++)
	{
		for (j = 0; j < 4; j++) { if (a[i * 4 + j] != qr[j]) { break; } }
		if (j == 4) { result = i; break; }
	}
	if (result == -1) { printf("uncorect QR\n"); }
	return result;
}