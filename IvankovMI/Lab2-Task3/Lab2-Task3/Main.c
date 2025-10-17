#include "C:\Users\User\git practice\mp1-practice\IvankovMI\Lab2-Task3\Lab2-Task3\Windows Kits\10\Include\10.0.19041.0\ucrt\stdio.h"
#include "C:\Users\User\git practice\mp1-practice\IvankovMI\Lab2-Task3\Lab2-Task3\Windows Kits\10\Include\10.0.19041.0\ucrt\locale.h"
#include <C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\ucrt\stdlib.h>
#include <C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\ucrt\time.h>
int main() {
	long int a;
	int regim = 0;
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	//regim = MessageBoxA("�������� ����� ����", "� ��������� ����� ����������", "�������� ���������� ��� �����", &regim);
	printf_s("�������� ����� ����\n0 - � ��������� ����� ����������\n1 - �������� ���������� ��� �����\n");
	scanf_s("%d", &regim);
	if (regim == 0) {
		int s;
		a = rand();
		printf_s("� ������� ��������� ����� �����. �������� �������� ���. \n�� ������ ���� ������� � ���� ������ ���������, ������ ��� ������ ���� �������. \n����� ���� ������ �������.");
		do {
			scanf_s("%d", &s);
			
		} while (a == s);
	}
}