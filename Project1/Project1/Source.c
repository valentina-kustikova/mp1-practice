#define _CRT_NO_WORNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>


int main() {

	float x1, y1, radius1; // ������ ������ ���������� 
	float  x2, y2, radius2; // ������ ������ ���������� 
	float length_between_centers; // ���������� ����� �������� ����������
	float sum_of_radiuses; // ����� ��������
	float larger_radius; // ������� ������

	setlocale(LC_ALL, "");


	// ���� ������ ������ ����������
	printf("������� ���������� ������ ������ ���������� �� ��� ��\n");
	scanf_s("%f", &x1);
	printf("������� ���������� ������ ������ ���������� �� ��� �y\n");
	scanf_s("%f", &y1);
	printf("������� ����� ������� ������ ����������\n");
	scanf_s("%f", &radius1);
	

	// ���� ������ ������ ����������
	printf("������� ���������� ������ ������ ���������� �� ��� ��\n");
	scanf_s("%f", &x2);
	printf("������� ���������� ������ ������ ���������� �� ��� �y\n");
	scanf_s("%f", &y2);
	printf("������� ����� ������� ������ ����������\n");
	scanf_s("%f", &radius2);




	length_between_centers = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); //  ���������� ����� �������� ����������

	sum_of_radiuses = radius1 + radius2; // ����� ��������


	// ����������� �������� �������
	if (radius1 > radius2)
		larger_radius = radius1;
	else 
		larger_radius = radius2;
	


	if (length_between_centers == sum_of_radiuses) {
		printf("���������� �������� ���� �����");
	}
	
	if (length_between_centers > (sum_of_radiuses)) {
		printf("���������� �� �������� ���� �����");
	}

	if ((length_between_centers < sum_of_radiuses) && (larger_radius < length_between_centers)) {
		printf("���������� ������������");
	}

	if ((length_between_centers < sum_of_radiuses) && (larger_radius > length_between_centers)) {
		printf("���������� ������ ������");
	}

	if ((length_between_centers < sum_of_radiuses) && (sum_of_radiuses == larger_radius)) {
		printf("���������� ������ ������ � �������� ��");
	}

	if ((radius1 == radius2) && (x1 == x2) && (y1 == y2)) {
		printf("���������� ���������");
	}

	return 0;
}