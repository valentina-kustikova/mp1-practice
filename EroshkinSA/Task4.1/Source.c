#include <stdio.h>
#define F 4
#define N 256

char names[10000][256] = {""};
int true_costs[10000] = { 0 }, costs[10000] = { 0 }, count[10000] = { 0 };

void form() {
	int id = 0;
	printf("-----\n");
	for (; id < 10000; id++) {
		if (!names[id][0]) continue;
		printf("%s (x%d): %d --> %d (%d)\n", names[id], count[id], costs[id], true_costs[id], id);
	}
	printf("-----\n");
}

void calculate() {
	int id = 0, summ = 0;
	for (; id < 10000; id++) {
		if (!names[id][0]) continue;
		summ += true_costs[id];
	}
	printf("\nTotal sum: %d\n", summ);
}

void scan(char code[], int name[], int cost, int sale) {
// Считываю очередной лог
	int i = 0, id = 0, true_cost, l = 0;
	char c;
	for (i = 0; i < F; i++) {
		scanf_s("%c", &(code[i]), 1);
		id *= 10;
		id += code[i] - '0';
	}
	scanf_s("%*c");
	do {
		scanf_s("%c", &c);
		if (c != ' ') name[l++] = c;
	} while (c != ' ');
	scanf_s("%d %d", &cost, &sale);
	true_cost = cost - (cost * sale) / 100;
// Добавляю новый лог в чек
	for (i = 0; i < l; i++) {
		names[id][i] = name[i];
	}
	true_costs[id] += true_cost; costs[id] += cost;
	count[id]++;
// Вывожу новый лог
	printf("NEW LOG  ");
	for (i = 0; i < l; i++) printf("%c", name[i]);
	printf(": %d -> %d\n", cost, true_cost);
}


int main() {
	char code[F], name[N];
	int cost = 0, sale = 0, n;
	scanf_s("%d", &n); scanf_s("%*c");
	while (n--) {
		scan(code, name, cost, sale);
		scanf_s("%*c");
	}
	form();
	calculate();
	return 0;
}