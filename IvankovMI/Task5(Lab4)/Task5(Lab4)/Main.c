#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

//НАСТРОЙКИ:                          --------------------------------------------------------------------------------------|
#define N   1000     //макс длина ввода                                                                                     |
#define NPR 9999     //макс длина таблицы продуктов (не больше 9999 при длине штрихкода = 4)  (при отрицательном значении   |
#define BCL 4        //длина штрихкода                                                         память выделится динамически)|
#define PNL 30       //макс длина имени продукта                                                                            |
#define ERL 100      //макс длина сообщения об ошибке                                                                       |
#define SOURCE_FILE  list_of_items_ANSI.txt          //имя файла со списком продуктов (только ANSI)                         |
//--------------------------------------------------------------------------------------------------------------------------|


#define CONCAT(a, b) a##b
#define TO_STR_(a) #a
#define TO_STR(a) TO_STR_(a)
#define _MAKE_FORMAT(a) "%"#a"s"
#define MAKE_FORMAT(a) "%"TO_STR(a)"s"
#define SRC_FILE TO_STR(SOURCE_FILE)
#define _BCF__ CONCAT(%,BCL)
#define _BCF_ CONCAT(BCF__,s)
#define _BCF TO_STR(BCF_)
#define __BCF "%"#BCL"s"
#define BCF MAKE_FORMAT(BCL)
#define BCformat BCF
#define R(f) (strcmp(inp, f) == 0)                //просто для удобства
#define R2(f) (strcmp(inp2, f) == 0)              //сравнение второго инпута
#define ISCOMMAND (strcmp(inp[0], ".") == 0)
#define ISCOM ISCOMMAND 
#define ISLW is_last_word()
#define scan {printf("--------\b\b\b\b\b\b\b\b"); scanf_s(format, inp, sizeof(char) * N);} //УРААААА!!! РАБОТАЕТ!!!! ВВОД ПОчИНИЛИ!!!
#define scan_t scanf_s(format, inp, sizeof(char) * N)
#define old_scan_with_error {printf("-----\b\b\b\b\b"); scanf_s(format, inp, sizeof(inp));}  //вот она, где собака была зарыта: "sizeof(inp)" возвращает размер УКАЗАТЕЛЯ, как раз, видимо, равный 8 байтам, а вот "sizeof(char) * N" возвращает размер байтового массива длиной N
//деклассированные элементы:    (возможно, никогда не используются)
#define scan_old {printf("----\b\b\b\b"); scanf_s(format, inp, sizeof(inp), inp2, sizeof(inp2));}
#define FGscan {char buff[N + 1]; printf("----\b\b\b\b"); fgets(buff, N, stdin); sscanf_s(buff, format, inp, sizeof(inp), inp2, sizeof(inp2));}
#define scan_(fl) input(format, b, inp, inp2, fl)
#define NEWscan ic = scan_(ic)


//Поддерж. команды: 
// купон
// инфо
// помощь
// позв. персонал
// отмена поз.
// отмена покупки
// финиш (завершение покупки)
// выход.

void choose(char* inp, char* inp2, int* coup, int ic);   //+
void coupon(char* inp, int* coup);   //+
void info() { ; }
//void help();                        //+
//void callthecashier();              //+
void Galya() { ; }   // отмена поз.
void Galina() { ; }  // отмена покупки
void final() { ; }
void barcode(char* inp);
void test(char* inp);

void file_to_sortedmatrix(FILE* crt, char* dst[][4], int n);                //старый вариант для старого массива
errno_t fill_the_table(FILE* src, struct product dst[], int n);
int input(char format[], char buff[], char inp[], char inp2[], int flag);   //стереть ?????
int is_last_word();

struct { char* msg; int data; int data2;  } error_msg;   //указатель на сообщение об ошибке
char helpi[] = "Вводите ниже цифры \"отсканированных штрихкодов\" и специальные команды, а программа \nсформирует чек и расчитает итоговую стоимость и размер скидки в рублях (без копеек). \nЦифры \"штрихкода\" вводите слитно (без пробелов), в десятичной системе счисления, \nкоманды и \"штрихкоды\" разделяйте пробелами и/или переносами строк. \nСписок команд: \n.coupon           — предъявить скидочный купон (затем попросят ввести номер купона) \n.info <штрихкод>  — получить информацию о товаре, не добавляя его в корзину \n(обратите внимание, команду и \"штрихкод\" надо писать раздельно, пример: .info 0123) \n.. / .fin         — завершить \"сканирование товаров\" и перейти к оплате \n.. / .fin (после оплаты) — закончить просмотр чека и завершить покупку \n.callthecashier   — позвать сотрудника \n.Galya            — отменить уже добавленный к покупке товар \n.Galina           — отменить весь процесс покупки \n.quit             — выйти из программы и завершить процесс \n.help             — вывести эту инструкцию ещё раз \n*просто введённый штрихкод добавляет товар в корзину и выводит базовую информацию о нём \n*\"касса\" обслуживает покупателей непрерывно: после завершения одной покупки начнется следующая\n\n";
char format[14];                         //строка формата для scanf_s вида "%Ns", где N - максимально разрешенная длина ввода

#if NPR > 0
struct product {
	char number[BCL + 1];
	char* name;
	int price;
	int discount;
} products[NPR];
#else
struct product {
	char number[BCL + 1];
	char* name;
	int price;
	int discount;
} * products; 
struct product * make_list_of_products(int n);
#endif




//старый вариант четырехмерного массива указателей на строки, не совсем понятно как предполагавшийся работать, будет заменен на массив структур
//char* products[NPR][4];                  //двумерный массив указателей на строки, представляющий таблицу товаров

//char* b;                 //уже не помню, для чего

//printf("****");
//_getch();
//printf("\b\b\b\b");

int main0() {
	int n, e;
	char s[20];
	e = scanf_s("%d %5s", &n, s, sizeof(s));
	printf("%d, %s\n", n, s);
	printf("%d", e);
	return 0;
}

int main() {
	
	FILE* list;
	char inp[N + 1], error_output[ERL + 1], inp2[N + 1]; //buff[N + 1];    //format[9];
	int n, coup = 0, ic = 0;
	errno_t  error;
	
	//b = buff;
	
	size_t szf = sizeof(format);
	snprintf(format, szf, "%%%ds", N);     //формирование строки формата для scanf_s вида "%Ns", где N - максимально разрешенная длина ввода

	setlocale(LC_ALL, "Rus");

	//"list ="; error = fopen_s(&list, "list_of_items.txt", "r, ccs=UTF-8");
	error = fopen_s(&list, SRC_FILE, "r");

	printf("Добро пожаловать в имитацию кассового аппарата \n\n");
	printf(helpi);
	if (error != 0) {
		printf("Ошибка чтения файла. Проверьте наличие файла. (код ошибки: %d)\n", error);
		return error;
	}
	error = (errno_t)fscanf_s(list, "%d", &n);
	if (error != 1) {
		printf("Не удалось прочитать колличество продуктов в файле.\n");
		return 0;
	}
	printf("%d\n", n);
#if ! (NPR > 0)
	products = make_list_of_products(n);
	if (products == NULL) {
		printf("Ошибка выделения памяти при динамическом выделении памяти для таблицы продуктов.\n");
		return 0;
	}
#endif
	//file_to_sortedmatrix(list, products, n);
	if (error = fill_the_table(list, products, n)) {
		printf("Ошибка создания таблицы продуктов. Код ошибки: %d\n", error);
		sprintf_s(error_output, sizeof(char) * ERL, "Сообщение об ошибке: %s\n", error_msg.msg);
		printf(error_output, error_msg.data);
		return error;
	}
	printf("\n------------------ Добро пожаловать в магазин \"Магазин\"! Вводите свои товары ------------------\n\n");

	//printf("%d\n", n);
	//scanf_s(888, format, inp, inp2, sizeof(inp), sizeof(inp2));
	scan;
	while (strcmp(inp, ".quit") != 0) {
		
		choose(inp, inp2, &coup, ic);
		scan;

	}
	fclose(list);
	return 0;
}


int is_last_word() {            //странная, конечно, реализация. но зато простая, как топор
	char c = fgetc(stdin);
	while (c == ' ') {
		c = fgetc(stdin); 
	}
	if (c == '\n' || c == EOF) {
		return 1;
	}
	else {
		ungetc(c, stdin);
		return 0;
	}
}


#if ! (NPR > 0)
struct product* make_list_of_products(int n){
	return (struct product*) malloc(sizeof(struct product) * n);
}
#endif


void file_to_sortedmatrix(FILE* crt, char* dst[][4], int n) { 
	;
}

errno_t fill_the_table(FILE* src, struct product dst[], int n){
	//коды ошибок:
	//1 - Не удалось прочитать штрихкод
	//2 - Не удалось прочитать имя продукта
	//3 - Имя продукта пустое
	//4 - Не удалось прочитать цену продукта
	//5 - У продукта отсутствует цена
	//6 - Что-то пошло не так с заполнением имени продукта
	//7 - Что-то пошло не так с заполнением имени продукта (2)
	int i, error, l, k = 0;
	//float price_buff;
	char buffer[PNL + 1 + 10], buffer_copy[PNL + 1 + 10];   //"+10" - на пробелы вначале строки
	char* start, * end, * price;
	size_t size;
	for (i = 0; i < n; i++) {
		char* t = (char*)(1),* context = NULL;
		error = fscanf_s(src, BCformat, dst[i].number, sizeof(char) * (BCL + 1));
		if (error == 0 || error == EOF) {
			error_msg.msg = (error == 0) ? "Не удалось прочитать штрихкод в %d строке." : "Достигнут конец файла в %d строке.";
			error_msg.data = i;
			return (errno_t)(1);
		}
		error = (int) fgets(buffer, sizeof(char) * (PNL + 1), src);
		if (error == 0) {
			error_msg.msg = "Не удалось прочитать имя продукта в %d строке.";
			error_msg.data = i;
			return (errno_t)(2);
		}
		strncpy_s(buffer_copy, sizeof(char) * ((size_t)(PNL + 1)), buffer, (size_t)PNL);
		start = strtok_s(buffer, " \t\n", &context);
		if (start == NULL) {
			error_msg.msg = "Имя продукта в %d строке пустое.";
			error_msg.data = i;
			return (errno_t)(3);
		}
		end = start;
		k++;
		price = strtok_s(NULL, " \t\n", &context);
		if (price == NULL) {
			error_msg.msg = "У продукта в %d строке отсутствует цена.";
			error_msg.data = i;
			return (errno_t)(5);
		}
		while (t) {
			t = strtok_s(NULL, " \t\n", &context);
			if (t) {
				k++;
				end = price;
				price = t;
			}
		}
		error = sscanf_s(price, "%d", &(dst[i].price));
		if (error == 0) {
			error_msg.msg = "Не удалось прочитать цену продукта в %d строке.";
			error_msg.data = i;
			return (errno_t)(4);
		}
		l = (end - start) + strlen(end) + 1;
		size = sizeof(char) * l;
		dst[i].name = (char*)malloc(size);
		if (k == 1) {
			error = (int)strncpy_s(dst[i].name, sizeof(char) * ((size_t)(l)), start, (size_t)(l - 1));
		}
		else {
			char* second_word,* context_ = NULL;
			second_word = (strtok_s(buffer_copy, " \t\n", &context_), strtok_s(NULL, " \t\n", &context_));
			if (second_word == NULL) {
				error_msg.msg = "Что-то пошло не так с заполнением имени продукта в %d строке.";
				error_msg.data = i;
				return (errno_t)(6);
			}
			error = (int)strncat_s(start, (size_t)(PNL + 1) - strlen(start), second_word, (size_t)(PNL)-strlen(start));
		}
		//strncpy_s(dst[i].name, sizeof(char) * ((size_t)(l)), buffer_copy, (size_t)(l - 1));
		if (error != 0) {
			error_msg.msg = "Что-то ещё пошло не так с заполнением имени продукта в %d строке.";
			error_msg.data = i;
			error_msg.data2 = error;
			return (errno_t)(7);
		}
	}
	return (errno_t)(0);
}


//стереть ?????
int input(char format[], char buff[], char inp[], char inp2[], int flag) {
	char c;
	if (flag == 0)
		fgets(buff, N + 1, stdin);
	sscanf_s(buff, format, inp, sizeof(inp));
	if (fgetc(buff) == '\n')
		return 0;
	else
		return 1;
}


void choose(char* inp, char* inp2, int* coup, int ic) {
	if (R(".help"))
		printf(helpi);
	else if (R(".callthecashier"))
		printf("Скоро к вам подойдет сотрудник\n");
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
	else if (R(".test"))
		test(inp);
	else
		barcode(inp);
}


void coupon(char* inp, int* coup) {
	//char coupon[21];     //если нужна будет действительно проверка купона
	if (is_last_word()) {
		printf("Введите номер своего купона: ");
	}
	scan;
	//strcpy(coupon, inp);
	printf("Отлично, теперь на некоторые товары вы получите скидки!\n");
	printf("№ купона: %s\n", inp);
	*coup = 1;
}


void barcode(char* inp) {
	printf("ТЕСТ: Штрихкод %s принят\n", inp);
}


void test(char* inp){
	scan;
	printf("ТЕСТ: %s\n", inp);
}
