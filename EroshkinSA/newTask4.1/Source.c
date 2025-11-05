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
		things[i] = t;
	}
}

void scan(struct thing* last) {
	char code[5];
	int i;
	scanf("%s", code);
	for (i = 0; i < N; i++) {
		if (strcmp(code, things[i].code) == 0) {
			*last = things[i];
			break;
		}
	}
}

void Last(struct thing* last) {
	struct thing t = *last;
	printf("Last scanned: %s %s %f %f\n", t.code, t.name, t.cost, t.sale);
}



int main() {
	system("chcp 1251");
	freopen("database.txt", "r", stdin);
	input();
	printf("%s\n", things[0].name);
	struct thing last;
	freopen("CON", "r", stdin);
	scan(&last);
	Last(&last);
	return 0;
}