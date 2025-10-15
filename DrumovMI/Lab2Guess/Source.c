#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int cnt = 0, type, t;
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	printf("�������� ����� (1 - ��������� ����������, ������������ ����������,"
		"2 - ������������ ����������, ��������� ����������: ");
	do {
		t = scanf("%d", &type);
	} while ((t == 0) || (t == 1 && !(type == 1 || type == 2)));

	if (type == 1) {
		int x = 1 + (rand()) % (1000 - 1 + 1);
		int guess;
		while (true) {
			t = scanf("%d", &guess);
			cnt++;
			if (guess < x)
				printf("���������� ����� ������.\n");
			else if (guess > x)
				printf("���������� ����� ������.\n");
			else {
				printf("�������.\n");
				break;
			}
		}
	}
	else {
		int l = 0, r = 1001;
		while (l + 1 < r) {
			int c = l + (r - l) / 2;
			printf("%d: ", c);
		}
	}
	return 0;
}