#include <stdio.h>
#include <locale.h>

#define LEN 512

int main() {
	float a, b, c;

	setlocale(LC_ALL, "RUS");
	
	char line[LEN];
	fgets(line, LEN, stdin);
	sscanf_s(line, "%f%f%f", &a, &b, &c);
	
	if (a <= 0 || b <= 0 || c <= 0) {
		printf("������� ������ ���� ��������������.");
		return 1;
	}

	if (a >= b + c || b >= a + c || c >= a + b) {
		printf("����������� �� ����������.");
		return 2;
	}

	if (a == b && b == c) {
		printf("��������������");
	} else if (a == b || b == c || a == c) {
		printf("��������������");
	} else {
		printf("����������� ������ ����");
	}

	return 0;
}