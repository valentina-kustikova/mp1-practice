//#include <stdio.h>
//#include <locale.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main() {
//	
//	setlocale(LC_ALL, "");
//	int a, n, count;
//
//	srand((unsigned int)time(0));
//	a = rand() % 1000 + 1;
//	printf("��������� ����� �� 1 �� 1000\n");
//
//	for (count = 1; ; count++) {
//		printf("�������: %d\n", count);
//		scanf_s("%d", &n);
//
//		if (n < a) {
//			printf("���������� ����� ������\n");
//		}
//
//		else if (n > a) {
//			printf("���������� ����� ������\n");
//		}
//
//		else {
//			printf("������� �� %d �������\n", count);
//			break;
//		}
//	}
//	return 0;
//}


#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");

	int l = 1, h = 1000, count, guess;
	char r = 0;

	for (count = 1; l <= h; count++) {
		guess = (l + h) / 2;
		printf("�������: %d\n", count);
		printf("%d\n", guess);
		printf("������ >, <, = : \n");
		scanf_s("%c", &r);

		if (r == '>') {
			l = guess + 1;
		}

		else if (r == '<') {
			h = guess - 1;
		}

		else if (r == ' = ') {
			printf("������! �� %d �������");
			break;
		}
	}
	return 0;
}

