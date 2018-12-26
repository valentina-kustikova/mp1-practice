#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h> 

void main() {
	int  ask1, a=0, b, x, y=0, choice, ask2=0, max=1000, min=1, ent;
	char quest;
	setlocale(LC_ALL, "Russian"); 
	printf("Игра \"Угадай число от 1 до 1000!\", с двумя режимами!\n");
	printf("Если ты хочешь отгадать число, загаданное компьютером, введи \"1\"!\nЕсли хочешь, чтобы твое число отгадал компьютер, введи \"2\"!\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("Отгдай число, которое загадал компьютер!\n");
		srand((unsigned int)time(0));
		x=0;
		x= 1 +rand() % 1000;
		do
		{
			scanf("%d", &ask1);
			a++;
			if(ask1 > x)
				printf("Загаданное число меньше!\n");
			if (ask1 <x)
				printf("Загаданное число больше!\n");
		}while( ask1 !=x);
		if (x == ask1)
		{
			printf("Вы угадали, загаданное число:%d\nПопыток - %d\n",x, a );
			return;
		}
	}
	if(choice == 2)
	{
		printf("Загадай число и введи его!\n");
		scanf("%d",&ent);
		printf("Загаданное вами число - %d\n",ent);
		printf("В зависимости от того числа, которое вы загадали, используйте символы \">\", \"<\" и \"=\"\nЕсли ваше чило меньше, введите\"<\"!\nЕсли ваше число больше, введите \">\"!\nЕсли компьютер угадал ваше число, то введите \"=\"!\n");
		b=0;
		srand((unsigned int)time(0));
		y= 1 +rand() % 1000;
		printf("Предпологаемое компьютером число - %d!\n", y);
		do
		{
			scanf("%c", &quest);
			if(quest == '>')
			{
				while((ask2 <= y) || (ask2>max) || (ask2 < min))
				ask2=rand();
				b=b+1;
				min=y;
				y=ask2;
				ask2=0;
				printf("Предпологаемое компьютером число - %d!\n", y);
	
			}
			if(quest == '<')
			{
				while((ask2 >= y) || (ask2 < min) || (ask2 > max))
				ask2=rand();
				b=b+1;
				max=y;
				y=ask2;
				ask2=0;
				printf("Предпологаемое компьютером число - %d!\n", y);
			}
		}while(y != ent);
		if(y == ent)
			printf("Компьютер угадал ваше число %d за %d попыток!\n", y, b);
		return;
	}
	printf("Этот режим еще не придуман!\n");
}
