#include <stdio.h>
#define F 4
#define N 256

char names[10000][256] = {""};
int last_cost, last_true_cost;

void form(int costs[], int true_costs[], int count[]) {
	int id = 0;
	printf("-----\n");
	for (; id < 10000; id++) {
		if (!names[id][0]) continue;
		printf("%s (x%d): %d --> %d (%d)\n", names[id], count[id], costs[id], true_costs[id], id);
	}
	printf("-----\n");
}

void calculate(int true_costs[]) {
	int id = 0, summ = 0;
	for (; id < 10000; id++) {
		if (!names[id][0]) continue;
		summ += true_costs[id];
	}
	printf("\nTotal sum: %d\n", summ);
}

int scan(int length[], int true_costs[], int costs[], int count[]) {
// —читываю очередной лог
	char code[F], name[N];
	int cost, sale;
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
	length[id] = l;
	scanf_s("%d %d", &cost, &sale);
	true_cost = cost - (cost * sale) / 100;
// ƒобавл€ю новый лог в чек
	for (i = 0; i < l; i++) {
		names[id][i] = name[i];
	}
	true_costs[id] += true_cost; costs[id] += cost;
	count[id]++;
// —охран€ю последний лог
	last_cost = cost; last_true_cost = true_cost;
	return id;
}

void last(int id, int len) {
	int i = 0;
	printf("LAST LOG  ");
	for (i = 0; i < len; i++) printf("%c", names[id][i]);
	printf(": %d -> %d\n", last_cost, last_true_cost);
}


int main() {
	int n;

	int length[10000] = { 0 };
	int true_costs[10000] = { 0 }, costs[10000] = { 0 }, count[10000] = { 0 };

	int last_id, last_cost, last_true_cost;

	scanf_s("%d", &n); scanf_s("%*c");
	while (n--) {
		int id = scan(length, true_costs, costs, count);
		scanf_s("%*c");
		last(id, length[id]);
	}
	form(costs, true_costs, count);
	calculate(true_costs);
	return 0;
}