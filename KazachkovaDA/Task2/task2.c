#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int mode, guess, answ, max, min, tries;
	char sign;
	printf_s("�������� ����� ����:\n");
	printf_s("1 - ����� ����������� ��, 2 - ����� ���������� ���������\n");
	do
	{	
		printf_s("������� �����:");
		scanf_s("%d", &mode);
	} while ((mode <= 0)|| (mode >= 3));

	if (mode == 1)
	{
		tries = 0;
		srand(time(NULL));
		answ = (rand() % 1000) + 1;
		do
		{
			printf_s("������� �������:");
			scanf_s("%d", &guess);
			if (guess > answ) 
			{
				printf_s("���������� ����� ������\n");
				tries += 1;
			}
			if (guess < answ)
			{
				printf_s("���������� ����� ������\n");
				tries += 1;
			}
			
		} while (guess != answ);
		tries += 1;
		printf_s("�������\n");
		printf_s("����� �������: %d", tries);
		return 0;

	}
	else {
		tries = 0;
		max = 1000;
		min = 1;
		do
		{
			srand(time(NULL));
			guess = (rand()%(max-min + 1)) + min;
			printf_s("������� ����������: %d\n", guess);
			printf_s("������� ����: <, >, =\n");
			do
			{
				scanf_s("%c", &sign);
			} while ((sign != '<') && (sign != '>') && (sign != '='));
			if (sign == '<')
			{
				max = guess - 1;
				tries += 1;
			}
			if (sign == '>')
			{
				min = guess + 1;
				tries += 1;
			}
			if (min >= max) {
				printf_s("������ ����� �� ���������� ��������");
				return 1;
			}
		} while (sign != '=');
		tries += 1;
		printf_s("��������� ������!");
		printf_s("����� �������: %d", tries);
		return 0;
	}
}