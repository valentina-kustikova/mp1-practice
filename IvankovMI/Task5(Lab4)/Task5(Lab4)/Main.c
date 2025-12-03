#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

#define N 1000       //макс длина ввода
#define R(f) strcmp(inp, f) == 0                //просто для удобства
#define scan {printf("----\b\b\b\b"); scanf_s(format, inp, sizeof(inp));}


//Поддерж. команды: 
// купон
// инфо
// помощь
// позв. персонал
// отмена поз.
// отмена покупки
// финиш
// выход.

void choose(char *inp);
void coupon(char* inp, char* coup);   //+
void info() { ; }
//void help();                        //+
//void callthecashier();              //+
void Galya() { ; }
void Galina() { ; }
void final() { ; }
void barcode(char *inp);

//void file_to_sortedmatrix(FILE* crt, char* dst[][]); { ; }

char helpi[] = "Вводите ниже цифры \"отсканированных штрихкодов\" и специальные команды, а программа \nсформирует чек и расчитает итоговую стоимость и размер скидки в рублях (без копеек). \nЦифры \"штрихкода\" вводите слитно (без пробелов), в десятичной системе счисления, \nкоманды и \"штрихкоды\" разделяйте пробелами и/или переносами строк. \nСписок команд: \n.coupon           — предъявить скидочный купон (затем попросят ввести номер купона) \n.info <штрихкод>  — получить информацию о товаре, не добавляя его в корзину \n(обратите внимание, команду и \"штрихкод\" надо писать раздельно, пример: .info 0123) \n.. / .fin         — завершить \"сканирование товаров\" и перейти к оплате \n.. / .fin (после оплаты) — закончить просмотр чека и завершить покупку \n.callthecashier   — позвать сотрудника \n.Galya            — отменить уже добавленный к покупке товар \n.Galina           — отменить весь процесс покупки \n.quit             — выйти из программы и завершить процесс \n.help             — вывести эту инструкцию ещё раз \n*просто введённый штрихкод добавляет товар в корзину и выводит базовую информацию о нём \n*\"касса\" обслуживает покупателей непрерывно: после завершения одной покупки начнется следующая\n\n";
char format[9];
char* products[9999][3];



//printf("****");
//_getch();
//printf("\b\b\b\b");


int main() {
	
	FILE* list;
	char inp[N + 1];    //format[9];
	int n, coup = 0, error;
	
	size_t szf = sizeof(format);
	snprintf(format, szf, "%%%ds", N);

	setlocale(LC_ALL, "Rus");

	"list ="; error = fopen_s(&list, "list_of_items.txt", "r");

	printf("Добро пожаловать в имитацию кассового аппарата \n\n");
	printf(helpi);
	if (error != 0) {
		printf("Ошибка чтения файла. Проверьте наличие файла.");
		return 0;
	}
	fscanf_s(list, "%d", &n);
	printf("\n------------------ Добро пожаловать в магазин \"Магазин\"! Вводите свои товары ------------------\n\n");

	//printf("%d\n", n);
	scan;
	while (strcmp(inp, ".quit") != 0) {
		
		choose(inp, &coup);
		scan;

	}
	return 0;
}


void choose(char* inp, int* coup) {
	if (R(".help"))
		printf(helpi);
	else if (R(".callthecashier"))
		printf("скоро к вам подойдет сотрудник");
	else if (R(".coupon"))
		coupon(inp, coup);
	else if (R(".info"))
		info();
	else if (R(".Galya"))
		Galya();
	else if (R(".Galina"))
		Galina();
	else if (R("..") && R(".fin"))
		final();
	else
		barcode(inp, inp);
}


void coupon(char* inp,int* coup) {
	printf("Введите номер своего купона: ");
	scan;
	* coup = 1;
}


void barcode(char *inp) {
	;
}