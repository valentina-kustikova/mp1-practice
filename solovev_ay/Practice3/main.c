#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h> 

void main() {
	int  ask1, a=0, b, x, y=0, choice, ask2=0, max=1000, min=1, ent;
	char quest;
	setlocale(LC_ALL, "Russian"); 
	printf("���� \"������ ����� �� 1 �� 1000!\", � ����� ��������!\n");
	printf("���� �� ������ �������� �����, ���������� �����������, ����� \"1\"!\n���� ������, ����� ���� ����� ������� ���������, ����� \"2\"!\n");
	scanf("%d", &choice);
	if (choice == 1){
		printf("������ �����, ������� ������� ���������!\n");
		srand((unsigned int)time(0));
		x=0;
		while((x < 1) || (x > 1000))
			x=rand();
		do
		{
	scanf("%d", &ask1);
	a++;
if(ask1 > x)
	printf("���������� ����� ������!\n");
if (ask1 <x)
	printf("���������� ����� ������!\n");
}
while( ask1 !=x);
if (x == ask1){
printf("�� �������, ���������� �����:%d\n������� - %d\n",x, a );
return;
}
}
	if(choice == 2){
	printf("������� ����� � ����� ���!\n");
	scanf("%d",&ent);
	printf("���������� ���� ����� - %d\n",ent);
	printf("� ����������� �� ���� �����, ������� �� ��������, ����������� ������� \">\", \"<\" � \"=\"\n���� ���� ���� ������, �������\"<\"!\n���� ���� ����� ������, ������� \">\"!\n���� ��������� ������ ���� �����, �� ������� \"=\"!\n");
b=0;
srand((unsigned int)time(0));
while((y < 1) || (y > 1000))
			y=rand();
printf("�������������� ����������� ����� - %d!\n", y);
do
{
scanf("%c", &quest);
if(quest == '>'){
	while((ask2 <= y) || (ask2>max) || (ask2 < min))
	ask2=rand();
	{b=b+1;
	min=y;
	y=ask2;
	ask2=0;
	printf("�������������� ����������� ����� - %d!\n", y);
	}
}
if(quest == '<'){
	while((ask2 >= y) || (ask2 < min) || (ask2 > max))
		ask2=rand();
	{b=b+1;
	max=y;
	y=ask2;
	ask2=0;
	printf("�������������� ����������� ����� - %d!\n", y);
	}
	
}
}


while(y != ent);
if(y == ent)
	printf("��������� ������ ���� ����� %d �� %d �������!\n", y, b);
return;
}
	printf("���� ����� ��� �� ��������!\n");
}
