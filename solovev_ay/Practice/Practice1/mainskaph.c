#include <stdio.h>
#include <math.h>
#include <locale.h>

	void main() {
	float h, w, d, rodvp, rodsp, rodereva, kolvopolok, m, mstenki, mbokovin, mkrishki, mdverei, mpolok;
	int b;
	setlocale(LC_ALL, "Russian");
	printf("���������� ����� ������������ ����� ����� ������ �����\n");
	printf("������� ������ � ������ ������ ������ ����� � �����������!\n");
	printf("������:");
	scanf("%f",&h);
	if ((h < 180) || (h > 220))
	{
	printf("������!\n������ ������ ���� �� 180 �� 220 ��.");
	return;
	}
	printf("������:");
	scanf("%f",&w);
	if ((w < 80)||(w > 120))
	{
	printf("������!\n������ ������ ���� �� 80 �� 120 ��.\n");
	return;
	}
	printf("��������� ����� ������ ��������� ������ �����:%.3f x %.3f\n",h, w);
	printf("������� ������� ������� � �����������:");
	scanf("%f", &d);
	if ((d < 50)||(d > 90))
	{
	printf("\n������!\n������� ������ ���� �� 50 �� 90 ��.");
	return;
	}
	printf("��������� ����� ��������:%.3f x %.3f\n",h, d);
	printf("��������� ����� ������ � ������� ������:%.3f x %.3f\n",w, d);
	printf("��������� ����� �����:%.3f x %.3f\n",h, w/2);
	kolvopolok = h/40;
	b = kolvopolok;
	printf("������� ��������� ������ � �/��^3:");
	scanf("%f", &rodereva);
	printf("������� ��������� ��� � �/��^3:");
	scanf("%f", &rodsp);
	printf("������� ��������� ��� � �/��^3:");
	scanf("%f", &rodvp);
	mstenki = rodvp * h * w * 0.5;
	mbokovin = 2 * h * d * 1.5 * rodsp;
	mkrishki = 2 * w * d * 1.5 * rodsp;
	mdverei = h * w * rodereva;
	mpolok = b * rodsp * (w-3) * d * 1.5;//���� ������� ����� 15��
	m = mstenki + mbokovin + mkrishki + mdverei + mpolok;
	m = m/1000;
	printf("����� �����:=%.3f ���������!\n",m);
	return;
	}