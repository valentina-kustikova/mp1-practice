#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 10
char* barcodes[N] = { "1212", "0101" , "2323" , "2424" , "5454" , "5858" , "8989" , "9090" , "9898" , "2727" };
char* names[N] = { "Tea", "Milk", "Bread", "Eggs", "Apples", "Chocolate", "Cookies", "Beer", "Sugar", "Salt" };
int price[N] = { 150, 100, 105, 100, 120, 240, 179, 149, 350, 120 };
float discout[N] = { 0.15, 0.20, 0.0, 0.25, 0.10, 0.35, 0.39, 0.0, 0.0, 0.0 };

void scan(int* arr)
{
	int i,f;
	float cost;
	char a[5];
	
	printf("Good day!\n Enter the barcodes of your products\n If you have entered all your products, then write 0\n");
	do {
		printf("Enter the barcode\n");
		gets(a);
		f = 0;
		for (i = 0; i < N; i++)
		{
			if (strcmp(barcodes[i], a) == 0)
			{
				arr[i]++;
				cost = price[i] - discout[i] * price[i];
				printf("| %s | Price is %d rubles  | Discout is %.0f%% | Total cost is %.2f rubles\n\n", names[i], price[i], discout[i]*100,cost);//Вывод информации о товаре
				f = 1;
			}
		}
		if ((f == 0) && (strcmp(a, "0")!=0))
		{
			printf("There is no such barcode, check the correctness of the input\n\n");
		}
		
	} while (strcmp(a,"0"));
}



void receipt_print (int *arr)
{
	int i, sum = 0;
	
	float r_price,sum_discout=0,total_sum=0;
	for (i = 0; i < N; i++)
	{
		if (arr[i] > 0)
		{
			sum = price[i]*arr[i] + sum;
			r_price = (price[i] - price[i] * discout[i])*arr[i];
			total_sum = total_sum + r_price;
			sum_discout=sum_discout+ (price[i] * discout[i])*arr[i];
			printf("|%10s\t|\tCOST=%d\t|\tCOUNT=%d\t|\tTOTAL COST=%.2f\t|\n", names[i], price[i], arr[i],  r_price);
		}
	}
	printf("\n\tThe cost of all goods=%d rubles\n", sum);
	printf("\tTotal discount=%.2f rubles\n", sum_discout);
	printf("\tTotal cost of all goods=%.2f rubles\n", total_sum);
}


int main()
{
	int i;
	int count[N] = { 0 };
	scan(count);
	printf("YOUR RECEIPT\n\n");
	receipt_print(count);
	return 0;
}