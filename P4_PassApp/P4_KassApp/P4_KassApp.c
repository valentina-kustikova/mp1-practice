#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ALL_PRODUCTS 10
#define ENTER 10
#define MAX 100

///////////////////////////////////////////////////////////

char* PRODUCTS[ALL_PRODUCTS] = {
		"Steel sword + scabbard",
		"Steel sword",
		"Oak bow",
		"40 х Arrows",
		"Rod of Fire",
		"Rod of Water",
		"Magic stick",
		"Simple Potion",
		"Weak poison",
		"Carving knife"
};
char* PRODUCTS_BARCODES[ALL_PRODUCTS] = {
		"0104",
		"4583",
		"0555",
		"1332",
		"7432",
		"9981",
		"3992",
		"6661",
		"4132",
		"0091"
};
int PRICE[ALL_PRODUCTS] = {
		8490,
		6990,
		5190,
		1590,
		22990,
		19990,
		11890,
		390,
		340,
		1990
};

////////////////////////////////////////////////////////

int SALES[ALL_PRODUCTS], SCANNED_PRODUCTS[MAX], k = 0, IMPORT_CASH, FINAL_PRICE = 0, ODD_MONEY = 0;
//Массив для скидок, массив для индексов сканированных товаров, счетчик колва скан. товаров, сколько покупатель вносит денег, финальная сумма, сдача
int FUNC_SCAN_BARCODES(); //Для сканирования штрихкоа и поиска продукта 
int FUNC_INFO(int num); //Для вывода информации о товаре
void FUNC_CHECK(void); //Для создания чека


////////////////////////////////////////


void main() {
	srand(time(NULL)); 



	for (int i = 0; i < ALL_PRODUCTS; i++) {		//Для создания рандомных скидок
		SALES[i] = 0;
		int j = 1 + rand() % 2;
		if (j == 1)
			SALES[i] = 1 + rand() % 49;
	}



	int c;
	do {
		printf("\n\n");
		int qq = FUNC_SCAN_BARCODES();			//qq для учета индексов товаров
		while (qq == -1) {
			printf("XXX THE PRODUCT WAS NOT FOUND! XXX\n");
			qq = FUNC_SCAN_BARCODES();
		}

		SCANNED_PRODUCTS[k] = qq;
		FINAL_PRICE += FUNC_INFO(qq);
		printf("Next barcode? enter/other");
		c = getchar();
		k++; //Колво товаров
	} while ((c == ENTER) && (k < MAX));



	printf("\n\n>>> Total sum: %d rub\n", FINAL_PRICE);
	getchar();
	do {
		printf(">>> Deposit money (rub): ");
		scanf_s("%d", &IMPORT_CASH);
		ODD_MONEY = IMPORT_CASH - FINAL_PRICE;
	} while (IMPORT_CASH < FINAL_PRICE);



	FUNC_CHECK();


	system("pause");
} 


///////////////////////////////////////


int FUNC_SCAN_BARCODES() {
	char barcode[5];
	int outcome = -1;
	printf("Enter barcode >>> ");
	char* a = gets(barcode);
	
	for (int i = 0; i < ALL_PRODUCTS; i++) {
		int b = strcmp(a, PRODUCTS_BARCODES[i]);
		if (b == 0) {
			outcome = i;
			break;
		}
	}
	return outcome;
}

int FUNC_INFO(int num) {
	int pricePlusSale = PRICE[num] - (PRICE[num] * SALES[num]) / 100;

	printf("\n-------------------------------\n");
	printf("%s\t price: %d rub (sale: -%d%%)", PRODUCTS[num],  pricePlusSale,  SALES[num]);
	printf("\n-------------------------------\n");
	
	return pricePlusSale;
}


void FUNC_CHECK() {
	int g = 0, t = 0;
	printf("\n\n\n\n\n\n\n*************************************************\n");
	printf("**********MAGIC PYATEROCHKA**********************");
	printf("\n*************************************************\n");
	printf("\t\t<<< POVTORNIU CHEK >>>");
	for (int x = 0; x < k; x++) {
		
		for (int z = 0; z <= x; z++) {
			if (SCANNED_PRODUCTS[z] == SCANNED_PRODUCTS[x])
				g++;
		}
		
		for (int z = x; z < k; z++) {
			if (SCANNED_PRODUCTS[z] == SCANNED_PRODUCTS[x]) 
				t++;
			
		} 
		int b = SCANNED_PRODUCTS[x];
		int pricePlusSale = PRICE[b] - (PRICE[b] * SALES[b]) / 100;
		if (t == 1) printf("\n%d\t%s\t\t%d, %d (sale: %d%%)", g, PRODUCTS[b], pricePlusSale, g * pricePlusSale, SALES[b]);


		g = 0; t = 0;
		}

	
	printf("\n\nFINAL PRICE: %d", FINAL_PRICE);
	printf("\nENTERED SUM: %d", IMPORT_CASH);
	printf("\nCHANGE: %d", ODD_MONEY);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~*******\n");
	printf("08.04.09 10:43 CHEK:00009");
	printf("\nOP: 1 manager");
	printf("\nFIO: Fatehov Cumil Gayarovich");
	printf("\n\nSIGN: ____________");
	printf("\n\tINN 123456789012");
	printf("\n\tChPM 12345678");
	printf("\n\n*************************************************\n");
	printf("*************THANKS FOR PRESENT******************");
	printf("\n************************************************* \n");
}