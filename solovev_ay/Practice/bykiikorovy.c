#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 10
void main (){
	int randommas[N];
	int osnova[N]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};//���� ������ ��� ���� ��� �������� ��������� �����
	int otvet[N];
	int i=0, kolvoznakov=0, kolvokorov=0, kolvobykov=0, x=100, y, z, score=0;
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));
	printf("������� ���������� ������ �� 1 �� 10\n");
	while((kolvoznakov < 1) || (kolvoznakov > 10))
		scanf("%d", &kolvoznakov);//�������� �� ���� ���������� ������
	printf("��������� ������� %d ������� �����!", kolvoznakov);
	//��������� ��������� ������ randommas
	i=kolvoznakov;
	while (i>0)
	{
		x = 10.0/RAND_MAX * rand();
		if (i == kolvoznakov) 
			x=9.0/RAND_MAX * rand() +1;
		//�� ������� ����� ��������� �� 0 �� 9
		if (osnova[x] != -1) //����������� ��� ������ ������ � ��� �� ��������������� ��-��� osnova
		{
			randommas[i] = osnova[x];
			osnova[x]=-1;//�������� ��������� �������� � ������//�������� �������
			i--;
		} 
	}
	
		do {
			
			x = 0;
			printf("����� ����� ��� ������������� ���� = ");
			kolvobykov=0;
			kolvokorov=0;//������� �������� ���������� �������� 
			scanf("%d", &y);

			score++;//��������� ����� �������
			for (i = kolvoznakov; i >0; i--)
			{
				otvet[i] = y % 10;
				y = y / 10;
				
			}//����������� �������� ������������� ����� � ������ ���� 
			for (i = kolvoznakov; i > 0; i--)
			{
				for (y = (i - 1); y > 0; y--)
				{
					if (otvet[i] == otvet[y]) x++;
				}
			
		} while (x != 0);
for (i = kolvoznakov; i >0; i--) 
{ 
for (y = kolvoznakov; y >0 ; y--) 
{
if ((randommas[i] == otvet[y]) && (i == y)) 
kolvobykov++; //���������� �����



if ((randommas[i] == otvet[y]) && (i != y)) 
kolvokorov++; //���������� �����
 } 
}
printf("����� = %d � ����� = %d \n", kolvokorov, kolvobykov);

		
} 
while (kolvobykov != kolvoznakov);
	printf("�� �������! ����� ������� - %d!", score);
}

