#include <stdio.h>
#include <string.h>
#include <memory.h>
#define N 10
#define _CRT_SECURE_NO_WARNINGS

char names[N][16] = { "Water", "Chocolate", "Milk", "Bread", "Fries", "Soup", "Tea", "Coffee", "Cookies", "Sugar" };
char barcodes[N][6] = { "0001","0002", "0003", "0004", "0005", "0006", "0007", "0008", "0009", "0010", };
int sales[N] = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 };
int coasts[N] = { 20, 50, 50, 35, 40, 90, 90, 300, 150, 50 };
int cart[N] = { 0 };


int index(char user_code[5]) {
	for (int i = 0; i < 10; i++) {
		if (strcmp(&(barcodes[i]), user_code) == 0) {
			return i;
		}
	}
}

void product_information(char user_code[5]) {
	int i = index(user_code);
	printf("You choose %s\n ", names[i]);
	printf("The price per unit with a discount is: %d \n", coasts[i] - (coasts[i] * sales[i] / 100));
}



int amount_summ() {

	int s = 0;
	for (int i = 0; i < N; i++) {
		s += cart[i] * (coasts[i] - (coasts[i] * sales[i] / 100));
	}

	return s;
}

void list() {
	char p = ' ';
	printf("Hi, goods in stock:\n\n");
	printf("product %11c price(rub) %5c discount(%%) %5c barcode\n", p, p, p);
	printf("--------------------------------------------------------------\n");
	printf("Water %14c 20 %13c 5 %15c 0001\n", p, p, p);
	printf("Chocolate %10c 50 %13c 10 %14c 0002\n", p, p, p);
	printf("Milk %15c 50 %13c 15 %14c 0003\n", p, p, p);
	printf("Bread %14c 35 %13c 20 %14c 0004\n", p, p, p);
	printf("Fries %14c 40 %13c 25 %14c 0005\n", p, p, p);
	printf("Soup %15c 90 %13c 30 %14c 0006\n", p, p, p);
	printf("Tea %16c 90 %13c 35 %14c 0007\n", p, p, p);
	printf("Coffee %13c 300 %12c 40 %14c 0008\n", p, p, p);
	printf("Cookies %12c 150 %12c 45 %14c 0009\n", p, p, p);
	printf("Sugar %14c 50 %13c 50 %14c 0010\n", p, p, p);
	printf("--------------------------------------------------------------\n\n");
}

void removed() {

	printf("Choose a barcode of this product: \n");
	for (int i = 0; i < N; i++) {
		if (cart[i] != 0) {
			printf("Name: %s Barcode: %s Count: %d \n", names[i], barcodes[i], cart[i]);
		}
	}
	char tmp[5];
	scanf("%s", &tmp);
	int i = index(tmp);
	if (cart[i] == 0) {
		printf("You cant remove this product. Try again \n ");

	}
	else
	{
		int cnt;
		printf("Input a number 0 <= number <= %d \n", cart[i]);
		scanf("%d", &cnt);
		if (cnt > cart || cnt < 0) {
			printf("Try again. You inputed a wrong count \n");
		}
		else {
			cart[i] -= cnt;
			printf("Done!");
		}
	}
}

void basket() {
	int c1 = 0, sl = 0, f = 0;;
	for (int i = 0; i < N; i++) {
		if (cart[i] != 0) {
			f++;
			printf("Name: %s Barcode: %s, Unit_price: %d  Discount %d  Count: %d Total_cost: %d \n", names[i], barcodes[i],coasts[i], (coasts[i] * sales[i] / 100), cart[i], cart[i] * (coasts[i] - (coasts[i] * sales[i] / 100)));
			sl += coasts[i] - coasts[i] * sales[i]/100;
		}
	}
	if (f == 0) printf("Cart is empty \n");
	else printf("Total cost of goods: %d      Total discount of goods: %d\n ", amount_summ(), sl);
}



void pay() {
	int as = amount_summ();

	int tmp = 0;
	while (10 > 9) {
		printf("Write %d for to pay for the goods \n", as);
		scanf("%d", &tmp);
		if (tmp == as) {
			printf("Thank you \n");
			break;
		}
		else if (tmp < as) {
			as = as - tmp;
			printf("You have to pay another \n");
		}
		else if (tmp > as) {
			printf(" This is your change %d \n", tmp - as);
			break;
		}
	}

}

void gen_of_receipt() {

	printf("Cashier: Mircosoft Visual Studio\n ");
	basket();
	printf("To be paid: %d \n ", amount_summ());
	pay();

}




int scanning_funtion() {
	int flag = 1, count;


	while (flag != 0) {
		printf("You always can input 'stop' if u wanna kill it ");


		//Scanning barcode
		char user_code[10];
		printf("Scan your barcode: \n");
		scanf("%s", user_code);

		//exit 
		if (strcmp(user_code, "stop") == 0) {
			flag = 0;
			return 0;
		}

		//check input barcode
		int product_index = check_user_code(user_code);
		while (product_index == -1) {
			
			printf("Pls, scan a right barcode: ");
			scanf("%s", &user_code);
			product_index = check_user_code(user_code);
		}

		product_information(user_code);
		printf("Input a count you wanna to buy. Input 0 if u dont want to buy it. \n ");
		scanf("%d", &count);

		if (count != 0) {
			cart[product_index] += count;
			printf("Done! %d products '%s' have been added to the cart \n", count, names[product_index]);
			continue;

		}

	}

	int s = amount_summ();
	if (s == 0) {
		int id = random_digit();
		printf("You did not choose any product :( Maybe u wanna %s with %d percent a discount \n", names[id], sales[id]);
	}
	else printf("You added to the cart products for %d \n", s);

	return 0;
}





int main() {
	int c = 0, user;

	list();

	while (c == 0) {

		printf("\n Also u can: \n Input 1 for add a products to cart \n Input 2 for know more about product. \n Input 3 for total cost \n Input 4 for generate a receipt \n Input 5 for remove last product from a cart \n Input 6 for print shopping cart \n ");
		scanf("%d", &user);


		//Box office
		if (user == 1) scanning_funtion();
		else if (user == 2) list();
		else if (user == 3) {
			printf("In your basket of products for %d rubles \n", amount_summ());
		}

		else if (user == 4) {
			gen_of_receipt();
			c = 1;
			break;
		}

		else if (user == 5) removed();

		else if (user == 6) basket();

		else printf("Choose a operation and write a digit from 1 to 6 pls. \n");



	}
	printf("Have a nice day!");
	return 0;
}




int check_user_code(char* user_code) {
	int product_index = -1, f=0;
	for (int i = 0; i < N; i++) {
		if (strcmp(barcodes[i], user_code) == 0) {
			product_index = i;
			break;
		}
	}

	return product_index;
}


int random_digit() {
	int n;

	srand((unsigned int)time(NULL));
	n = rand() % (10);

	return n;
}