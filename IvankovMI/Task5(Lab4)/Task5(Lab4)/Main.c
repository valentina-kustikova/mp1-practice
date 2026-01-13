#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
#include <io.h>

//НАСТРОЙКИ:                          --------------------------------------------------------------------------------------|
#define N   1000     //макс длина ввода                                                                                     |
#define NPR 9999     //макс длина таблицы продуктов (не больше 9999 при длине штрихкода = 4)  (при отрицательном значении   |
#define MIDC 1       //минимальный размер скидки (в %)                                         память выделится динамически)|
#define MADC 50      //максимальный размер скидки (в %)                                                                     |
#define BCL 4        //длина штрихкода                                                                                      |
#define PNL 70       //макс длина имени продукта                                                                            |
#define CPL 21       //макс длина купона                                                                                    |
#define ERL 100      //макс длина сообщения об ошибке                                                                       |
#define HK  0        //спрашивать ли про горячие клавиши                                                                    |
#define SOURCE_FILE  list_of_items_ANSI.txt          //имя файла со списком продуктов (только ANSI)                         |
//--------------------------------------------------------------------------------------------------------------------------|


#define DEBUG_RAW 39
#define NOP 1;

#define CONCAT(a, b) a##b
#define TO_STR_(a) #a
#define TO_STR(a) TO_STR_(a)
#define MAKE_FORMAT(a) "%"TO_STR(a)"s"
#define SRC_FILE TO_STR(SOURCE_FILE)
#define BCF MAKE_FORMAT(BCL)
#define BCformat BCF
#define R(f) (strcmp(inp, f) == 0)                //просто для удобства
#define ISCOMMAND (strcmp(inp[0], ".") == 0)
#define ISCOM ISCOMMAND 
#define ISLW is_last_word()
#define scan {printf("--------\b\b\b\b\b\b\b\b"); scanf_s(format, inp, sizeof(char) * N);} //УРААААА!!! РАБОТАЕТ!!!! ВВОД ПОчИНИЛИ!!!
#define scan_t scanf_s(format, inp, sizeof(char) * N)
#define B117 "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"


//Поддерж. команды: 
// купон
// инфо
// помощь
// позв. персонал
// отмена поз.
// отмена покупки
// финиш (завершение покупки)
// выход.
// тест
// показать все товары
// показать текущую корзину

void choose(char* inp, char* inp2, int* coup, char coupon_n[], struct item_in_receipt receipt[], int* l, int n, int i);
void coupon(char* inp, int* coup, char coupon[]);         //+
void info(char* inp, struct product products[], int n);   //+
//void help();                                            //+
//void callthecashier();                                  //+
void Galya() { ; }   // отмена поз.
void Galina() { ; }  // отмена покупки
void final(char* inp, int* coup, char coupon[], struct item_in_receipt basket[], int n, int interactive);
void barcode(char* inp, struct product products[], struct item_in_receipt receipt[], int* l, int n);
void test(char* inp);                                     //+
void show_all_products(struct product products[], int n); //+
void show_basket(struct item_in_receipt basket[], int n); //+


int calc(int price, int discount);
errno_t fill_the_table(FILE* src, struct product dst[], int n);
void set_discounts(struct product dst[], int n);
int is_last_word();
char* point_to_the_first_nonspace(char* str, int n);
struct product* fast_search(struct product products[], int n, char key[]);
struct item_in_receipt* fast_search_in_receipt(struct item_in_receipt receipt[], int n, char key[]);
errno_t make_the_receipt(FILE* stream, struct item_in_receipt receipt[], int n, int coup);
errno_t free_the_basket(struct item_in_receipt basket[], int n);
errno_t free_the_table(struct product table[], int n);

int is_interactive();


struct { char* msg; int data; int data2;  } error_msg;   //указатель на сообщение об ошибке
int error_flag = 0;                                      //флаг, поднимаемый ситуативно вызываемыми функциями в случае ошибки

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
#endif

struct product* make_list_of_products(int n);
struct item_in_receipt { 
	struct product* item; 
	int count; 
	int position; 
} * make_receipt(int n);




int main() {
	//объявляем все локальные в main
	FILE* list;
	char inp[N + 1], error_output[ERL + 1], inp2[N + 1]; //buff[N + 1];    //format[9];
	char coupon_n[CPL + 1];
	int n, coup = 0, l = 0, i = 0, hk = 0;
	errno_t  error, err2;
	struct item_in_receipt* receipt;
	
	size_t szf = sizeof(format);
	snprintf(format, szf, "%%%ds", N);     //формирование строки формата для scanf_s вида "%Ns", где N - максимально разрешенная длина ввода

	setlocale(LC_ALL, "Rus");
	i = is_interactive();

	error = fopen_s(&list, SRC_FILE, "r");

	printf("Добро пожаловать в имитацию кассового аппарата \n\n");
	printf(helpi);
	if (i == 0) {
		printf("**  программа запущена не в интерактивном режиме, горячие клавиши отключены  **\n\n");
	}
	else if (i == -1) {
		printf("**  не удалось определить ржим запуска программы, горячие клавиши отключены  **\n\n");
		i = 0;
	}
	else if (HK) {
		printf("Для включения горячих клавиш введите что-нибудь (иначе просто нажмите Enter):\n  *при включенных горячих клавишах при наборе первого символа не работают специальные клавиши, такие как стрелки и F11\b"B117);
		if (!is_last_word()) {
			scan;
			printf("**  режим горячих клавишь включен  **\n\n");
			hk = 1;
		}
		else
			printf("\n");
	}
	
	if (error != 0) {
		printf("Ошибка чтения файла. Проверьте наличие файла. (код ошибки: %d)\n", error);
		return error;
	}
	error = (errno_t)fscanf_s(list, "%d", &n);
	if (error != 1) {
		printf("Не удалось прочитать колличество продуктов в файле.\n");
		err2 = fclose(list);
		if (err2 != 0) {
			printf("При закрытии файла возникла ошибка. (код ошибки: %d)\n", error);
			return err2;
		}
		return 0;
	}
	printf("Всего товаров в магазине: %d\n", n);
#if ! (NPR > 0)
	products = make_list_of_products(n);
	if (products == NULL) {
		printf("Ошибка выделения памяти при динамическом выделении памяти для таблицы продуктов.\n");
		fclose(list);
		return 0;
	}
#endif
	receipt = make_receipt(n);
	if (receipt == NULL) {
		printf("Ошибка выделения памяти при динамическом выделении памяти для товарного чека.\n");
		err2 = fclose(list);
		if (err2 != 0) {
			printf("При закрытии файла возникла ошибка. (код ошибки: %d)\n", error);
			return err2;
		}
		return 0;
	}

	if (error = fill_the_table(list, products, n)) {
		printf("Ошибка создания таблицы продуктов. Код ошибки: %d\n", error);
		sprintf_s(error_output, sizeof(char) * ERL, "Сообщение об ошибке: %s\n", error_msg.msg);
		printf(error_output, error_msg.data);
		err2 = fclose(list);
		if (err2 != 0) {
			printf("При закрытии файла возникла ошибка. (код ошибки: %d)\n", error);
			return error;
		}
		return error;
	}
	err2 = fclose(list);
	if (err2 != 0) {
		printf("При закрытии файла возникла ошибка. (код ошибки: %d)\n", error);
		return err2;
	}
	set_discounts(products, n);
	printf("\n------------------ Добро пожаловать в магазин \"Магазин\"! Вводите свои товары ------------------\n\n");

	scan;
	while (strcmp(inp, ".quit") != 0) {
		
		choose(inp, inp2, &coup, coupon_n, receipt, &l, n, i);
		if (error_flag) {
			printf("Ошибка обработки команды пользователя.\n");
			sprintf_s(error_output, sizeof(char) * ERL, "Сообщение об ошибке: %s\n", error_msg.msg);
			printf(error_output, error_msg.data);
			return 0;
		}
		printf("\n");
		scan;

	}
	free_the_basket(receipt, l);
	free_the_table(products, n);
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


char* point_to_the_first_nonspace(char* str, int n){
	int i;
	for (i = 0; i < n; i++) {
		if (str[i] == '\n')
			return NULL;
		if (str[i] != ' ')
			return str + i;
	}
	return NULL;
}


struct product* fast_search(struct product products[], int n, char key[]){
	int i;
	for (i = 0; i < n; i++) {
		int ok = 1, k = 0;
		char* search_ptr = products[i].number,* key_ptr = key;
		for (; (*search_ptr != '\0') && (*key_ptr != '\0'); search_ptr++, key_ptr++, k++) {
			if (k > BCL + 1) {       //для безопасности
				error_msg.msg = "Один из штрихкодов не заканчивается нулем (%d по счету при поиске).";
				error_msg.data = i;
				error_flag = 1;
				return NULL;
			}
			if (*search_ptr != *key_ptr) {
				ok = 0;
				break;
			}
		}
		if (ok)
			return products + i;
	}
	return NULL;
}


struct item_in_receipt* fast_search_in_receipt(struct item_in_receipt receipt[], int n, char key[]){
	int i;
	for (i = 0; i < n; i++) {
		int ok = 1, k = 0;
		char* search_ptr = receipt[i].item->number, * key_ptr = key;
		for (; (*search_ptr != '\0') && (*key_ptr != '\0'); search_ptr++, key_ptr++, k++) {
			if (k > BCL + 1) {       //для безопасности
				error_msg.msg = "Один из штрихкодов не заканчивается нулем (%d по счету при поиске).";
				error_msg.data = i;
				error_flag = 1;
				return NULL;
			}
			if (*search_ptr != *key_ptr) {
				ok = 0;
				break;
			}
		}
		if (ok)
			return receipt + i;
	}
	return NULL;
}

errno_t free_the_basket(struct item_in_receipt basket[], int n) {
	free(basket);
	return (errno_t)(0);
}

errno_t free_the_table(struct product table[], int n) {
	int i;
	for (i = 0; i < n; i++)
		free(table[i].name);
	return (errno_t)(0);
}

int is_interactive() {
	return _isatty(_fileno(stdin));
}



struct product* make_list_of_products(int n){
	return (struct product*) malloc(sizeof(struct product) * n);
}
struct item_in_receipt* make_receipt(int n) {
	return (struct item_in_receipt*)malloc(sizeof(struct item_in_receipt) * n);
}



int calc(int price, int discount){
	float fp = (float)price * ((float)discount / 100.0f);
	return price - (int)round(fp);
}


errno_t fill_the_table(FILE* src, struct product dst[], int n){
	//коды ошибок:
	//1 - Не удалось прочитать штрихкод
	//2 - Не удалось прочитать имя продукта
	//3 - Имя продукта пустое
	//4 - Не удалось прочитать цену продукта
	//5 - У продукта отсутствует цена
	//6 - Не удалось выделить память для имени продукта
	//7 - При записи имени продукта что-то пошло не так
	//8 - При записи имени продукта что-то пошло не так (2)
	int i, error, l;
	char buffer[PNL + 1 + 10], buffer_copy[PNL + 1 + 10];   //"+10" - на пробелы вначале строки
	char* start, * end, * price;
	size_t size;
	for (i = 0; i < n; i++) {
		char* t = (char*)(1),* context = NULL;
		int k = 0;
		//if (i == DEBUG_RAW)
		//	NOP;
		error = fscanf_s(src, BCformat, dst[i].number, (unsigned int)(sizeof(char) * (BCL + 1)));
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
		if (dst[i].name == NULL) {
			error_msg.msg = "Не удалось выделить память для имени продукта в %d строке.";
			error_msg.data = i;
			return (errno_t)(6);
		}
		if (k == 1) {
			error = (int)strncpy_s(dst[i].name, size, start, (size_t)(l - 1));
			dst[i].name[l - 1] = '\0';
		}
		else {
			//char* second_word,* context_ = NULL;
			//second_word = (strtok_s(buffer_copy, " \t\n", &context_), strtok_s(NULL, " \t\n", &context_));
			//if (second_word == NULL) {
			//	error_msg.msg = "Что-то пошло не так с заполнением имени продукта в %d строке.";
			//	error_msg.data = i;
			//	return (errno_t)(6);
			//}
			//error = (int)strncat_s(start, (size_t)(PNL + 1) - strlen(start), second_word, (size_t)(PNL)-strlen(start));
			start = point_to_the_first_nonspace(buffer_copy, PNL);
			if (start == NULL) {
				error_msg.msg = "При записи имени продукта в %d строке что-то пошло не так.";
				error_msg.data = i;
				return (errno_t)(7);
			}
			error = (int)strncpy_s(dst[i].name, size, start, (size_t)(l - 1));
			dst[i].name[l - 1] = '\0';
		}
		//strncpy_s(dst[i].name, sizeof(char) * ((size_t)(l)), buffer_copy, (size_t)(l - 1));
		if (error != 0) {
			error_msg.msg = "При записи имени продукта в %d строке что-то другое пошло не так.";
			error_msg.data = i;
			error_msg.data2 = error;
			return (errno_t)(8);
		}
	}
	return (errno_t)(0);
}


void set_discounts(struct product dst[], int n){
	int i;
	srand((unsigned int)time(NULL));
	for (i = 0; i < n; i++) {
		dst[i].discount = MIDC + (rand() % (MADC + 1));
	}
}


void choose(char* inp, char* inp2, int* coup, char coupon_n[], struct item_in_receipt receipt[], int* l, int n, int i) {
	if (R(".help"))
		printf(helpi);
	else if (R(".callthecashier"))
		printf("Скоро к вам подойдет сотрудник\n");
	else if (R(".coupon"))
		coupon(inp, coup, coupon_n);
	else if (R(".info"))
		info(inp, products, n);
	else if (R(".GalyaOtmena"))
		Galya();
	else if (R(".GalinaOtmena"))
		Galina();
	else if (R("..") || R(".fin"))
		final(inp, coup, coupon_n, receipt, *l, i);
	else if (R(".test"))
		test(inp);
	else if (R(".showall"))
		show_all_products(products, n);
	else if (R(".showmy"))
		show_basket(receipt, *l);
	else
		barcode(inp, products, receipt, l, n);
}


void coupon(char* inp, int* coup, char coupon[]) {
	if (is_last_word()) {
		printf("Введите номер своего купона: ");
	}
	scan;
	strncpy_s(coupon, sizeof(char) * CPL + 1, inp, CPL);
	coupon[CPL] = '\0';
	printf("Отлично, теперь на некоторые товары вы получите скидки!\n");
	printf("№ купона: %s\n", inp);
	*coup = 1;
}

void info(char* inp, struct product products[], int n){
	struct product* product_ptr;
	if (is_last_word()) {
		printf("Введите штрихкод продукта: ");
	}
	scan;
	product_ptr = fast_search(products, n, inp);
	if (product_ptr != NULL)
		printf("ШТРИХКОД: %s  НАЗВАНИЕ: %s \nЦЕНА: %3d руб.  СКИДКА: %2d%%  ЦЕНА СО СКИДКОЙ: %3d\n", product_ptr->number, product_ptr->name, product_ptr->price, product_ptr->discount, calc(product_ptr->price, product_ptr->discount));
	else
		printf("Товар с таким штрихкодом не найден.\n");
}


void barcode(char* inp, struct product products[], struct item_in_receipt receipt[], int* l, int n) {
	struct product* product_ptr;
	struct item_in_receipt* pos_in_rec;
	product_ptr = fast_search(products, n, inp);
	if (product_ptr != NULL) {
		pos_in_rec = fast_search_in_receipt(receipt, *l, inp);
		if (pos_in_rec == NULL) {
			//receipt[*l] = struct item_in_receipt { product_ptr, 1, *l};   //поч не работает?
			receipt[*l].item = product_ptr;
			receipt[*l].count = 1;
			receipt[*l].position = *l;
			pos_in_rec = receipt + (*l);
			(*l)++;
		}
		else
			pos_in_rec->count++;
		printf("Товар добавлен в корзину.  (колл-во: %2d)\nШТРИХКОД: %s  НАЗВАНИЕ: %s \nЦЕНА: %3d руб.  СКИДКА: %2d%%  ЦЕНА СО СКИДКОЙ: %3d\n", pos_in_rec->count, product_ptr->number, product_ptr->name, product_ptr->price, product_ptr->discount, calc(product_ptr->price, product_ptr->discount));
	}	
	else
		printf("Товар с таким штрихкодом не найден.\n");
}


void test(char* inp){
	scan;
	printf("ТЕСТ: %s\n", inp);
}


void show_all_products(struct product products[], int n){
	int i;
	printf("Всего товаров в магазине: %d\n", n);
	for (i = 0; i < n; i++) {
		printf("\n№п/п: %4d  ШТРИХКОД: %s  НАЗВАНИЕ: %s \n            ЦЕНА: %3d руб.  СКИДКА: %2d%%  ЦЕНА СО СКИДКОЙ: %3d\n", i + 1, products[i].number, products[i].name, products[i].price, products[i].discount, calc(products[i].price, products[i].discount));
	}
}


void show_basket(struct item_in_receipt basket[], int n){
	int i, c = 0, bare_total = 0, disc_total = 0, total_disc_amount = 0;
	//for (struct item_in_receipt x: basket)          //эх..
	for (i = 0; i < n; i++)
		c += basket[i].count;
	printf("Всего товаров в корзине: %d (%d видов)\n", c, n);
	for (i = 0; i < n; i++) {
		int bare_cost, disc_cost, t, disс_amount;
		t = calc(basket[i].item->price, basket[i].item->discount);
		bare_cost = basket[i].item->price * basket[i].count;
		disc_cost = t * basket[i].count;
		disс_amount = bare_cost - disc_cost;
		printf("\n№п/п:  ШТРИХКОД: %s  НАЗВАНИЕ: %s \n%4d   ЦЕНА: %3d руб.  СКИДКА: %2d%%  ЦЕНА СО СКИДКОЙ: %3d \n       КОЛЛИЧЕСТВО: %2d  СТОИМОСТЬ БЕЗ СКИДКИ: %4d  СО СКИДКОЙ: %4d  (скидка составит: %3d)\n", 
			basket[i].item->number, 
			basket[i].item->name, 
			i + 1, 
			basket[i].item->price, 
			basket[i].item->discount, 
			t, 
			basket[i].count,
			bare_cost,
			disc_cost,
			disс_amount);
		bare_total += bare_cost;
		disc_total += disc_cost;
		total_disc_amount += disс_amount;
	}
	if (n > 0) {
		printf("\nСУММ. СТОИМОСТЬ  БЕЗ СКИДКИ: %d  СО СКИДКОЙ: %d     СКИДКА СОСТАВИТ: %d  (РУБ.)\n", bare_total, disc_total, total_disc_amount);
		printf("* Вы получите скидку только после предъявления скидочного купона. \nВведите \"..\" или \".fin\", чтобы оплатить покупки.\n");
	}
	else
		printf("* Вы ещё не отсканировали ни одного товара\n");
}


void final(char* inp, int* coup, char coupon[], struct item_in_receipt basket[], int n, int interactive) {
	int i, c = 0, bare_total = 0, disc_total = 0, total_disc_amount = 0, total;
	if (! *coup) {
		if (is_last_word()) {
			printf("Введите номер своего купона (если у вас нет купона, просто нажмите Enter): ");
		}
		if (! is_last_word()) {
			scan;
			printf("Отлично, теперь на некоторые товары вы получите скидки!\n\n");
			strncpy_s(coupon, sizeof(char) * CPL + 1, inp, CPL);
			coupon[CPL] = '\0';
			*coup = 1;
		}
		else
			printf("\n");
	}
	for (i = 0; i < n; i++)
		c += basket[i].count;
	printf("Всего товаров в корзине: %d (%d видов)\n", c, n);
	for (i = 0; i < n; i++) {
		int bare_cost, disc_cost, t, disс_amount;
		t = calc(basket[i].item->price, basket[i].item->discount);
		bare_cost = basket[i].item->price * basket[i].count;
		disc_cost = t * basket[i].count;
		disс_amount = bare_cost - disc_cost;
		printf("\n№п/п:  ШТРИХКОД: %s  НАЗВАНИЕ: %s \n%4d   ЦЕНА: %3d руб.  СКИДКА: %2d%%  ЦЕНА СО СКИДКОЙ: %3d \n       КОЛЛИЧЕСТВО: %2d  СТОИМОСТЬ БЕЗ СКИДКИ: %4d  СО СКИДКОЙ: %4d  (скидка составит: %3d)\n",
			basket[i].item->number,
			basket[i].item->name,
			i + 1,
			basket[i].item->price,
			basket[i].item->discount,
			t,
			basket[i].count,
			bare_cost,
			disc_cost,
			disс_amount);
		bare_total += bare_cost;
		disc_total += disc_cost;
		total_disc_amount += disс_amount;
	}
	//printf("\nСУММ. СТОИМОСТЬ  БЕЗ СКИДКИ: %d", bare_total);
	printf("\nСУММ. СТОИМОСТЬ ");
	if (*coup)
		printf(" ");
	printf("БЕЗ СКИДКИ: %d", bare_total);
	if (*coup) {
		printf("     СО СКИДКОЙ: %d     СКИДКА СОСТАВИТ: %d  (РУБ.)\n", disc_total, total_disc_amount);
		printf("№ купона: %s\n", coupon);
		total = disc_total;
	}
	else {
		printf("  (при отсутствии скидочного купона скидка не предоставляется)\n");
		total = bare_total;
	}
	printf("\n\n\nК ОПЛАТЕ %d РУБЛЕЙ\n", total);
	if (interactive) {
		printf("\n(для оплаты приложите банковскую карту к пробелу)\n");
		while (_getch() != ' ')
			;
		printf("QWERTYUVBFG");
	}
}


errno_t make_the_receipt(FILE* stream, struct item_in_receipt receipt[], int n, int coup) {
	int i, c = 0, bare_total = 0, disc_total = 0, total_disc_amount = 0, total;
	char t_buff[85];
	time_t now = time(NULL);
	fprintf(stream, "---------------------------------КАССОВЫЙ ЧЕК/ПРИХОД---------------------------------\n");
	fprintf(stream, "ЦЕНА БЕЗ СКИДКИ  СКИДКА (%)  ЦЕНА СО СКИДКОЙ  КОЛЛИЧЕСТВО  СКИДКА (РУБ.)        ИТОГО\n");
	for (i = 0; i < n; i++) {
		int bare_cost, disc_cost, t, disс_amount;
		c += receipt[i].count;
		t = (coup)? calc(receipt[i].item->price, receipt[i].item->discount) : receipt[i].item->price;
		bare_cost = receipt[i].item->price * receipt[i].count;
		disc_cost = t * receipt[i].count;
		disс_amount = bare_cost - disc_cost;
		fprintf(stream, "%s  %s \n%12d.00  %9d%%  %12d.00  %8dшт.  %10d.00  %8d.00)\n",
			receipt[i].item->number,
			receipt[i].item->name,
			receipt[i].item->price,
			receipt[i].item->discount,
			t,
			receipt[i].count,
			disс_amount, 
			disc_cost);
		bare_total += bare_cost;
		disc_total += disc_cost;
		total_disc_amount += disс_amount;
	}
	fprintf(stream, "(Всего товаров куплено : %d (%d видов))\n", c, n);
	fprintf(stream, "-------------------------------------------------------------------------------------\n");
	fprintf(stream, "ИТОГО БЕЗ СКИДКИ %65d.00\nИТОГО СКИДКА %69d.00\nИТОГО %76d.00\n", bare_total, total_disc_amount, disc_total);
	fprintf(stream, "-------------------------------------------------------------------------------------\n");
	fprintf(stream, "БЕЗНАЛИЧНЫМИ %69d.00\nНАЛИЧНЫМИ %72d.00\n", disc_total, 0);
	fprintf(stream, "-------------------------------------------------------------------------------------\n");
	fprintf(stream, "КАССИР                                                                  Иванков М. И.\n");
	fprintf(stream, "МЕСТО РАСЧЕТОВ                                                                   Lab4\n");
	ctime_s(t_buff, sizeof(char) * 85, &now);
	fprintf(stream, "ДАТА И ВРЕМЯ РАСЧЕТОВ%64s\n", t_buff);
	fprintf(stream, "\n                                 Спасибо за покупки!                                 \n");
	return (errno_t)(0);
}