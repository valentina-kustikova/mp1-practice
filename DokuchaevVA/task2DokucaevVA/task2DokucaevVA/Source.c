#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#define N 1000

int main() {
	int a[N]; int x; int chooese; int y; int l, r, c, count=0; char ans;
	setlocale(LC_ALL, "Rus");
	srand((unsigned int)time(0));
	x = rand() % N;
	//printf("%d\n", x);

	do {
		printf("������� ����� ������ (1 ��� 2):");
		scanf_s("%d", &chooese);
	}
	while ((chooese <1 || chooese>2));

	if (chooese == 1)	{
		printf("�� ������� ���� <������ ����� �� 1 �� 1000>\n");
		do {
			count++;
			printf("����� ����� � �������?\n");
			scanf_s("%d", &y);
			if (x<y) {
				printf("���������� ����� ������!\n");
			}
			else if (x>y){
				printf("���������� ����� ������!\n");
			}
		} while (y != x);
		printf("������!!! ����� �������: %d", count);
	}
	else {
		count = 0;
		printf("�� ������� ���� <������� �����>. ��������, ����������, ������������ �����.\n");
		scanf_s("%d", &y);
		printf("������ � ���� ��������� �����, � �� ������ ������� ����� '>, <, ='. ������!\n");
		l = 0;
		r = N;
		do {
			count++;
			c = (l + r) / 2;
			printf("���� ����� %d?\n", c);
			scanf_s(" %c", &ans);
			switch (ans) {
			case '>': {
				l = c+1;
				break;
			}
			case  '<': {
				r = c-1;
				break;
			}
			case '=': {
				break;
			}
			default: printf("������\n");
			}
		} while (ans != '=');
		printf("Win! ����� �������: %d", count);
	}

	return 0;
}