#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Russian");
	int r, count = 0, chr, chp,chmin=1,chmax=1000;
	char c;
	printf("������ ����� 1-��������, 2-���������:");
	scanf_s("%d", &r);
	if (r == 1) {
		srand((unsigned int)time(0));
		chr = rand() % (1000) + 1;
		printf("���� �������:");
		do {
			scanf_s("%d", &chp);
			if (chp > 1000 || chp < 1) {
				printf("����� ������ ���� �� 1 �� 1000\n");
			}
			else if (chp < chr) {
				printf("���������� ����� ������\n");
				count += 1;
			}
			else if (chp > chr) {
				printf("���������� ����� ������\n");
				count += 1;
			}
		} while (chp != chr);
		printf("������ � %d-�� �������", count + 1);

	}
	if (r == 2) {
		printf("������� ����� �� 1 �� 1000\n");

		do {
			chr = (chmax + chmin) / 2;
			printf("%d\n", chr);
			printf("����� ������ >,<,=:");
			scanf_s(" %c", &c);

			if (c == '>') {
				chmin = chr + 1;
				count++;
			}

			if (c == '<') {
				chmax = chr - 1;
				count ++;
			}
			if (c == '=') {
				printf("��������� ������ � %d-�� �������", count+1);
				return 0;
			}
			if (c != '>' && c != '<' && c != '=') {
				printf("�������� ������\n");
			}
			
		} while (chmin <= chmax);
		printf("�� ���-�� ��������");
		return 1;
	}
	return 0;
}
	