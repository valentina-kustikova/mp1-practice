#include <stdio.h>
#include <locale.h>
#include <math.h>
int main()
{
	int c1, c2, i, index1, index2, yrf=0, K = 0, F = 0, L = 0, S = 0, H = 0;
	char f, k1, k2;
	char a[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	setlocale(LC_ALL, "Russian");
	do
	{
		printf("���������� ������ ������: ");
		scanf_s(" %c%d", &k1, 1, &c1);
		
		printf("���������� ������ ������: ");
		scanf_s(" %c%d", &k2, 1, &c2);
		
		printf("���� ������(������ - K, ����� - F, ����� - L, ���� - S, ���� - H): ");
		scanf_s(" %c", &f);
	} while (((k1 == k2) && (c1 == c2)) || f != 'K' && f != 'F' && f != 'L' && f!= 'S' && f!= 'H');
	for (i = 0; i < ((sizeof(a) / sizeof(a[0])) - 1); i++)
	{
		if (a[i] == k1)
		{
			index1 = i;
		}
		if (a[i] == k2)
		{
			index2 = i;
		}
	}
	
	
	//������
	if ((c2 == c1) && ((index2 == (index1 - 1)) || (index2 == (index1 + 1))))
	{
		if ((f == 'K'))
		{
			yrf = 1;
		}
		else
		{
			K = 1;
		}
		F = 1;
	}
	if ((index2 == index1) && ((c2 == (c1 - 1)) || (c2 == (c1 + 1))))
	{
		if ((f == 'K'))
		{
			yrf = 1;
		}
		else
		{
			K = 1;
		}
		F = 1;
	}
	if ( ((index2 ==(index1 - 1))&&((c2 == (c1+1))||(c2 == (c1-1)))) || ((index2 == (index1 - 1)) && ((c2 == (c1 + 1)) || (c2 == (c1 - 1)))))
	{
		if ((f == 'K'))
		{
			yrf = 1;
		}
		else
		{
			K = 1;
		}
		F = 1;
	}
	//�����
	if (((c2 == c1) && (index2 != index1)) || ((index1 == index2) && (c2 != c1)))
	{
		if (f == 'L')
		{
			yrf = 1;
		}
		else
		{
			L = 1;
		}
		F = 1;
	}
	//����
	if (((c1 != c2) && (index1 != index2)) && (abs(index1 - index2) == abs(c1 - c2)))
	{
		if (f == 'S')
		{
			yrf = 1;
		}
		else
		{
			S = 1;
		}
		F = 1;
	}
	//����
	if ((abs(c1 - c2) == 2 && abs(index1 - index2) == 1) || (abs(index1 - index2) == 2 && abs(c1 - c2) == 1))
	{
		if (f == 'H')
		{
			yrf = 1;
		}
		else
		{
			H = 1;
		}
		F = 0;
	}
	//�����
	if (F == 1)
	{
		if (f == 'F')
		{
			yrf = 1;
			F = 0;
		}
	}
	if (yrf == 1)
	{
		printf("���� ������ ����� ������� ���� ���");
		return 0;
	}
	else
	{
		printf("���� ������ �� ����� ������� ���� ���\n");
	}
	if (K != 0 || L != 0 || S != 0 || H != 0 || F != 0)
	{
		printf("�� ���� ��� ����� �������:\n");
		if (K != 0)
			printf("������\n");
		if (F != 0)
			printf("�����\n");
		if (L != 0)
			printf("�����\n");
		if (S != 0)
			printf("����\n");
		if (H != 0)
			printf("����\n");
	}
	return 0;
}