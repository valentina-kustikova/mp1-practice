#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int rej = 0, ran, otv;
	int l = 0, r = 1000, ans, t = 0, cnt = 1;
	char h = '=';
	setlocale(LC_ALL, "Russian");
	do
	{
		printf("�������(0) ��� ��������(1) ");
		scanf_s("%d", &rej);
	} while (rej != 1 && rej != 0);

	if (rej == 0)
	{
		//���� cpyat

		srand(time(NULL));
		ran = rand() % 1000 + 1;
		printf("�������� ������� �����:\n ");
		scanf_s("%d", &otv);
		cnt = 1;
		while (otv != ran)
		{
			if (otv > ran)
			{
				printf("���������� ����� ������\n ");
				cnt++;
				scanf_s("%d", &otv);
			}
			else
			{
				printf("���������� ����� ������\n ");
				cnt++;
				scanf_s("%d", &otv);
			}
		}
		printf("�������.\n ����� ���� �������� �� %d �������(-��)", cnt);
		return 0;
	}


	else
	{


		do {
			printf("��������� ����� �� 1 �� 1000 ");
			scanf_s("%d", &ans);
		} while (ans < 1 || ans>1000);

		while (t != ans)
		{
			t = (l + r) / 2;
			printf("���� ����� %d?(>-���� ���� ����� ������, < - ���� ������, = - ���� �����) ", t);
			do
			{
				scanf_s(" %c", &h, 1);
			} while (h != '>' && h != '<' && h != '=');
			if (h == '=')
			{
				t = ans;
				break;
			}
			if (h == '>')
			{
				l = t + 1;
				cnt++;
			}
			else
			{
				r = t - 1;
				cnt++;
			}
		}
		printf("����� ���� ������� �� %d �������(-��)", cnt);
		return 0;
	}
}