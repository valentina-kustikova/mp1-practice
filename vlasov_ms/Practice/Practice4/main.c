#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define ITEMS_IN_DB 5      // количество товаров в базе
#define NAME_SYM_MAX 12    // макс. количество символов в наименовании
#define PT_SIGN 37         // код символа процента

int codes[ITEMS_IN_DB] = { 1, 1234, 4385, 7998, 6914 };
char names[ITEMS_IN_DB][NAME_SYM_MAX] = { 
	"Хлеб черный ", 
	"Молоко 1л   ", 
	"Колбаса     ", 
	"Чай черный  ", 
	"Бананы 1кг  " 
};
int price[ITEMS_IN_DB]    = { 5, 10, 50, 30, 50 };
int sales[ITEMS_IN_DB]    = { 0 };
int recp[ITEMS_IN_DB];     // иды товаров
int recp_num[ITEMS_IN_DB]; // кол-во товаров
int recs = 0;                // кол-во добавленных в чек
int last_id = 0;             // последний отсканированный

int find_by_code(int code)
{
	int i;
	for (i = 0; i < ITEMS_IN_DB; i++) {
		if (codes[i] == code) break;
	}
	if (i >= ITEMS_IN_DB) {
		return -1;
	}
	else {
		return i;
	}
}

void prettyprint_code(int code) {
	if (code < 10) {
		printf("000%d", code);
	}
	else if (code < 100) {
		printf("00%d", code);
	}
	else if (code < 1000) {
		printf("0%d", code);
	}
	else {
		printf("%d", code);
	}
}

void print_info(int id)
{
	int i;
	prettyprint_code(codes[id]);
	printf(" => ");
	for (i = 0; i < NAME_SYM_MAX; i++) {
		printf("%c", names[id][i]);
	}
	printf("\nЦена %d (со скидкой %d%c: %.2f)", price[id], sales[id], 
		PT_SIGN, price[id] * (1 - (float)(sales[id] / 100.00)));
}

void scan()
{
	int code, id;
	printf("Введите код товара: ");
	scanf("%d", &code);
	if (code == 0) {
		printf("Отмена сканирования");
		return;
	}
	else {
		id = find_by_code(code);
		last_id = id;
		if (id == -1) {
			printf("Товар не найден\n");
		}
		else {
			print_info(id);
		}
	}
}

void add(int id)
{
	if (id == -1) {
		printf("Неверный код.");
	}
	else {
		int i, found;
		for (i = 0; i < recs; i++)
			if (recp[i] == id) break;
		found = i >= recs ? -1 : i;
		if (found == -1) {
			recp[recs] = id;
			recp_num[recs] = 1;
			recs++;
		}
		else {
			recp_num[found]++;
		}
		printf("Товар ");
		prettyprint_code(codes[id]);
		printf(" добавлен.");
	}
}

float sum_item(int pos) {
	int id = recp[pos];
	float summa = 0.0f;
	summa += price[id] * (1 - (float)(sales[id] / 100.00)) * recp_num[pos];
	return summa;
}

void compose()
{
	if (recs == 0) {
		printf("Чек пустой.\n");
	}
	else {
		int i;
		printf("======== РЕЖИМ ПЕЧАТИ ТЕКСТА ========\n");
		printf("Код  | Наименование | Скидка | Цена со скидкой | Кол-во | Стоимость\n");
		for (i = 0; i < recs; i++) {
			int j, id = recp[i];
			prettyprint_code(codes[id]);
			printf(" | ");
			for (j = 0; j < NAME_SYM_MAX; j++) {
				printf("%c", names[id][j]);
			}
			printf(" | %5d%c | %15.2f | %6d | %4.2f", sales[id], PT_SIGN, 
				price[id] * (1 - (float)(sales[id] / 100.00)), 
				recp_num[i], sum_item(i));
			printf("\n");
		}
		printf("======== КОНЕЦ ПЕЧАТИ ТЕКСТА ========\n");
	}
}

float sum()
{
	float S = 0.0f;
	int i;
	for (i = 0; i < recs; i++) {
		S += (float)sum_item(i);
	}
	return S;
}

void show_menu()
{
	printf("\nМЕНЮ ");
	printf("| 1 сканировать товар и отобразить инфо ");
	printf("| 2 добавить товар в чек ");
	printf("| 3 показать чек ");
	printf("| 4 подвести итог ");
	printf("\nУкажите любую другую цифру, чтобы отобразить это меню.");
	printf("\nНажмите Ctrl+C, чтобы выйти из программы.\n");
}

void main()
{
	int i, menu;
    setlocale(LC_ALL, "Russian");

	srand((unsigned)time(0));
	for (i = 0; i < ITEMS_IN_DB; i++) {
		sales[i] = rand() % 50 + 1;
	}

	printf("==================================");
	printf(" ЭЛЕКТРОННАЯ КАССА 1С:ПРЕДПРИЯТИЕ 2.0 ");
	printf("==================================");
	show_menu();
	do {
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			printf("[Сканирование товара] ");
			scan();
			break;
		case 2:
			printf("[Добав. товара в чек] ");
			add(last_id);
			break;
		case 3:
			//printf("[Печать чека] ");
			compose();
			break;
		case 4:
			printf("[Подвести итог] Итого к оплате: %.2fР", sum());
			break;
		default:
			show_menu();
		}
		printf("\nВведите цифру (Ctrl+C, чтобы выйти): ");
	} while (1);
}