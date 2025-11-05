#include <stdio.h>
#define F 4
#define N 256


struct things {
	char code[F], name[N];
	float cost, sale;
	int count;
};

struct thing emp = { "", "", 0.0f, 0.0f, 0 };
struct thing things[30] = { emp };


void form(int costs[], int sales[], int count[]) {
	int id = 0;
	printf("-----\n");
	for (; id < 10000; id++) {
		if (!count[id]) continue;
		printf("%s - %d - %d - %d\n", names[id], costs[id], count[id], count[id] * (costs[id] * (100 - sales[id]) / 100));
	}
	printf("-----\n");
}

void calculate(int count[], int costs[], int sales[]) {
	int id = 0;
	int summ = 0;
	for (; id < 10000; id++) {
		if (!count[id]) continue;
		summ += count[id] * (costs[id] * (100 - sales[id]) / 100);
	}
	printf("\nОбщая сумма: %d\n", summ);
}

int scan(int count[], int costs[], int sales[], int* last_cost, int* last_sale) {
// Считываю очередной лог
	char code[F];
	int i = 0, id = 0, true_cost;
	char c;
	for (i = 0; i < F; i++) {
		scanf_s("%c", &(code[i]), 1);
		id *= 10;
		id += code[i] - '0';
	}
	if (!names[id][0]) {
		printf("Неверный код\n");
		return -1;
	}
// Сохраняю последний лог
	*last_cost = costs[id]; *last_sale = sales[id];
	return id;
}

void last(int id, int len, int* last_cost, int* last_sale) {
	int i = 0;
	printf("ПОСЛЕДНИЙ ОТСКАНИРОВАННЫЙ ТОВАР  ");
	for (i = 0; i < len; i++) printf("%c", names[id][i]);
	printf(": %d -> %d\n", *last_cost, *last_cost * (100 - *last_sale) / 100);
}

void base() {
	int i;
	for (i = 0; i < 30; i++) {
		struct thing t = things[i];
		scanf("%s %s %f %f", t.code, t.name, &t.cost, &t.sale);

	}
}


int main() {
	system("chcp 1251");

	freopen("database.txt", "r", stdin);
	int id = -1, type;

	int length[10000] = { 0 };
	int true_costs[10000] = { 0 }, costs[10000] = { 0 }, count[10000] = { 0 }, sales[10000] = { 0 };
	printf("Доступные действия:\n0 - Завершение работы\n1 <****> - Считать штрих-код\n2 - Вывести последний отсканированный товар\n3 - Добавить товар в чек\n4 - Сформировать и вывести чек\n5 - Узнать общую стоимость товаров в чеке\n");
	int last_cost, last_sale;
	printf("Коды доступные для сканирования: ");
	base(length, costs, sales);
	printf("\n");
	freopen("CON", "r", stdin);
	while (scanf_s("%d%*c", &type)) {
		switch (type) {
		case 0:
			return 0;
		case 1:
			id = scan(count, costs, sales, &last_cost, &last_sale);
			scanf_s("%*c");
			break;
		case 2:
			if (id == -1) {
				printf("Пусто\n");
				break;
			}
			last(id, length[id], &last_cost, &last_sale);
			break;
		case 3:
			if (id == -1) printf("Пусто\n");
			else {
				count[id]++;
				printf("Добавлено в чек!\n");
			}
			break;
		case 4:
			form(costs, sales, count);
			break;
		case 5:
			calculate(count, costs, sales);
			break;
		default:
			printf("Неверное действие!\n");
		}
	}
	return 0;
}