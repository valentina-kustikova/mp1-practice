#include <stdio.h>
#include <Windows.h>

#define GOODS_AMOUNT  (sizeof(prod) / sizeof(prod[0]))
struct goods_t
{
	const char* name;
	const char* description;
	double price;
	const char* barcode;
	int discount;
};
struct goods_t prod[] = { 
	{"cabbage", "This is an average head of an average cabbage", 54.99, "1613", 46},
	{"carrot", "A carrot. Just a carrot...", 9.99, "5144", 4},
	{"candies", "Sweet! Some candies!",89.99 ,"3134", 28},
	{"spaghetti", "Spaghetti italiani",79.99 ,"4114", 8},
	{"zucchini", "Zucchini - schiacciare italiane",49.99 ,"6613", 5},
	{"cheese", "CheeSe, not cheeZe",239.99 ,"1117", 21},
	{"tomato", "Tomato is like an apple but better",14.99 ,"1335", 25},
	{"bacon", "Bacon - cool part of a cool pig",149.99 ,"0552", 2},
	{"lettuce", "Lettuce - when cabbage is not an option",29.99 ,"3333", 16},
	{"chicken", "Chicken... KFC...",199.99 ,"2015", 17},
	{"muffin", "Muffin - Delitious small piece of a cake",74.99 ,"4497", 16},
	{"pickles", "Pickles are just forgotten cucumbers in a jar...",319.99 ,"2395", 14},
	{"mushroom", "Mushroom - \"it's me, Mario!\"", 29.99, "0000", 38},
};

int products[GOODS_AMOUNT] = {0};

double cost = 0;
double cost_without_discounts = 0;

void fancy_print(const char* text)
{
	static int c = 0;
	for (int j = 0; j < strlen(text); j++)
	{
		printf("%c", text[j]);
		if (++c % 2)
			Sleep(1);
	}
}
void introduction()
{
	fancy_print("all items will be automatically scanned\n");
	fancy_print("to print your current check enter 'c'\n");
	fancy_print("to sum up and get final cost enter 'f'\n");
	fancy_print("all barcodes:\n");
	for (int i = 0; i < GOODS_AMOUNT; i++) {
		fancy_print(prod[i].name);
		fancy_print(": ");
		fancy_print(prod[i].barcode);
		printf("\n");
	}
	printf("\n");
}
void add_to_check( int index ) 
{
	fancy_print(prod[index].description);
	do
	{
		char confirm[2];

		fancy_print("\nBuy one ([Y]es/No)? ");
		fgets(confirm, sizeof(confirm), stdin);
		fseek(stdin, 0, SEEK_END);

		switch(confirm[0])
		{
		case '\n':
			printf("Yes\n");
		case 'y':
		case 'Y':
			products[index]++;
			fancy_print("Added\n");
			break;
		case 'n':
		case 'N':
			fancy_print("done\n");
			return;
		}
		
	} while (1);
}
void make_check()
{
	cost_without_discounts = 0;
	cost = 0;
	char buffer[80];
	int i;
	printf("\n");
	for (i = 0; i < 61; i++) {
		fancy_print("-");
	};
	snprintf(buffer, sizeof(buffer),
		"\n|   %-20s  |  %8s | %5s |  %9s  |\n",
		"Name", "Price", "Count", "Total");
	fancy_print(buffer);
	for (i = 0; i < 61; i++) {
		fancy_print("-");
	};
	fancy_print("\n");
	for (int i = 0; i < GOODS_AMOUNT; i++)
	{
		
		if (products[i] > 0) {
			snprintf(buffer, sizeof(buffer),
				"|   %-20s  |  %8.2lf |  %4d |  %9.2lf  |\n",
				prod[i].name,
				prod[i].price,
				products[i],
				(double)products[i] * prod[i].price
			);

			fancy_print(buffer);
			cost_without_discounts += (double)products[i] * prod[i].price;
			cost += (double)products[i] * prod[i].price * (1.0 - ((double)(prod[i].discount))/100);
		}
	}
	for (i = 0; i < 61; i++) {
		fancy_print("-");
	}
	fancy_print("\noverall price without discounts: ");
	printf("%.2lf\n\n", cost_without_discounts);
}
void final_cost()
{
	make_check();
	fancy_print("Discount: ");
	printf("%.2lf", cost_without_discounts - cost);
	fancy_print("\nTotal price: ");
	printf("%.2lf", cost);
}
int find_barcode(char* barcode)
{
	for ( int i = 0; i < GOODS_AMOUNT; ++i)
		if (!strcmp(barcode, prod[i].barcode)) 
			return i;
	
	return -1;
}
int move()
{
	char last_scan[5];

	fancy_print("enter your barcode (4 digits)/ print check (c)/ final cost (f): ");

	fgets(last_scan, sizeof(last_scan), stdin);
	fseek(stdin, 0, SEEK_END);
		
	switch (last_scan[0])
	{
	case 'f':
		final_cost();
		return -1;
	case 'c':
		make_check();
		break;
	default:
		{
			int index = find_barcode(last_scan);
			if (index < 0)
				fancy_print("couldn't find this barcode. Please, try again\n");
			else
			{
				add_to_check(index);
			}
		}
	}
	return 0;
}

int main() 
{
	introduction();
	while (!move());
}
