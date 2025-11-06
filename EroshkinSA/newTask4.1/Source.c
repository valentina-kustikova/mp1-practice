#include <stdio.h>
#define F 5
#define N 30

struct thing {
	char code[F], name[256];
	float cost, sale;
	int count;
};

struct thing things[N];

void input() {
	int i = 0;
	for (i = 0; i < N; i++) {
		struct thing t;
		scanf("%s %s %f %f", t.code, t.name, &t.cost, &t.sale);
		t.count = 0;
		t.sale = t.cost * t.sale / 100.0f;
		things[i] = t;
	}
}

void scan(struct thing* last) {
	char code[5];
	int i;
	scanf("%s%*c", code);
	for (i = 0; i < N; i++) {
		if (strcmp(code, things[i].code) == 0) {
			*last = things[i];
			return;
		}
	}
}

void Last(struct thing* last) {
	struct thing t = *last;
	printf("Last scanned: %s %s %f %f\n", t.code, t.name, t.cost, t.sale);
}

void add(struct thing* last) {
	struct thing t = *last;
	int i = 0;
	for (i = 0; i < N; i++) {
		if (strcmp(t.code, things[i].code) == 0) {
			things[i].count++;
			printf("Добавлено в чек!\n");
			return;
		}
	}
}

void receipt() {
	float sum = 0, sale = 0;
	int i;
	printf("-------\n");
	for (i = 0; i < N; i++) {
		if (things[i].count) {
			printf("%s - %f - %d - %f\n", things[i].name, things[i].cost, things[i].count, things[i].cost * things[i].count);
			sum += things[i].cost * things[i].count;
			sale += things[i].sale;
		}
	}
	printf("-------\nСуммарная стоимость: %f\nОбщая скидка: %f\nИтоговая стоимость: %f\n-------\n", sum, sale, sum - sale);
}



int main() {
	system("chcp 1251");
	freopen("database.txt", "r", stdin);
	input();
	struct thing last = { "0000", "empty", 0.0f, 0.0f, 0};
	freopen("CON", "r", stdin);
	char type = -1;
	while (1) {
		scanf("%c%*c", &type);
		switch (type) {
		case '0':
			return 0;
		case '1':
			scan(&last);
			break;
		case '2':
			if (strcmp(last.code, "0000") == 0) {
				printf("Пусто\n");
			}
			else Last(&last);
			break;
		case '3':
			if (strcmp(last.code, "0000") == 0) {
				printf("Пусто\n");
			}
			else add(&last);
			break;
		case '4':
			receipt();
			break;
		default:
			printf("Неверный ввод!\n");
		}
	}
	return 0;
}