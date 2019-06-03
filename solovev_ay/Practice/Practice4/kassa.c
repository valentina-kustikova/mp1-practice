#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 8
int cost[N];
int skidka[N];
int codes[N][5] = {"1234", "1235", "1236", "2341","1434", "6235", "7236", "8341"};
float costs[N];
int numbers[N]={0};
int kolvo=0;
int povtorov[N];
char name[N][20]=
{
	"default", "Cервелат Финский", "Филе куриное", "Фарш домашний", "Окорок куриный", "Стейк из свинины",
	"Филе грудки индейки", "Филе грудки индейки"
};//имена только от 1-7, при вводе других, получим тоже товары, но без имени!


int findcode(char* code)
{
 	int i;
 	for (i = 0; i < N; i++) 
	{
 		if (strcmp(codes[i], code)) 
			break;
 	}
 	if (i >= N) 
	{
 		return -1;
 	}
 	else 
	{
 		return i;
	}
}//проверка
void menu()
{
	printf("Меню кассы!\n");
	printf("Введите 1 для получения информации о товаре!\n");
	printf("Введите 2 чтобы добавить товар в чек!\n");
	printf("Введите 3, чтобы распечатать чек!\n");
	printf("Введите 4, чтобы расчитать стоимость!\n");
	printf("Введите 5, для получения справки!\n");
	printf("Введите 0 для выхода из программы!");
}//меню

void info(char* code)
{
	printf("%s Название  %s Цена %d Скидка %d Цена со скидкой: %2.f\n", code, name[id], cost[id], skidka[id], costs[id]);
}//получение информация о товаре
int scan()
{
	char s[5];
	printf("Введите номер товара(1-9999): ");
	scanf("%s", &s);
	if ((s[1] == '0')&&(s[2]== '0')&&(s[3]== '0')&&(s[4]== '0'))   
	{
		printf("Отмена сканирования");
		return;
	}
	else 
		info(s);
	return s;	
}//реализация функции скан
int main()
{
	int nomer=0, i=0, x=0, flag=1, choice, b, j=0,  vla=0, kat=0, love=0, rofl=0, lasttry=0, superflag=0;
	int kolvopovtorov[N]={1};
	float sum=0, taktaev=0;
	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(0));
	for (i = 0; i < N; i++)
	{
		x = 10 + rand() % (15000 - 10 + 1);
		cost[i]=x;
		x=0;

	}
	for (i = 0; i < N; i++)
	{

		x= 2 + rand() % (50 - 10 + 1);
		skidka[i]=x;
		x=0;

	}
	for (i = 0; i < N; i++)
	{
		codes[i]=i;
	}//циклы с заполнением массивов скидок цен и номеров
	for (i = 0; i < N; i++)
	{
		costs[i]=((100 - skidka[i]) * cost[i])/100;
	}
	costs[0]=0;
	skidka[0]=0;
	cost[0]=0;//занулил нулевой товар
	menu();
	do {
 		scanf("%d", &choice);
 		switch (choice) 
		{
 		case 1:
 			printf("[Сканирование товара] ");
 			scan();
 			break;
 		case 2:
 			printf("Добавить товар в чек\n");
			b=scan();
			superflag=0;
			if (kolvo==0)
			{
				numbers[kolvo]=b;
				kolvo++;
			}
			else
			{
				for (i = 0; i < kolvo; i++)
				{
					if(numbers[i]==b)
					{
						superflag=0;
						kolvopovtorov[i]++;
						printf("Добавлен повторный товар!\n");
						break;//проверка на уже добавленный товар(реализация функции повторного ввода товара)
					}
					else
					{
						superflag=1;
					}
				}
			if (superflag==1)
			{
				kolvopovtorov[kolvo]=1;
				numbers[kolvo]=b;
				kolvo++;
			}
			}
			printf("Товар добавлен!");
			break;
 		case 3:
 			j=0;
			printf("                              Печать чека!\n");
			printf("_________________________________________________________________________\n");
			printf("   Наименование       |  Цена   |  Скидка | цена со скидкой  |Количество \n");
			for(i=0; i<kolvo; i++)
			{
				vla=numbers[i];
				if(vla != 0)
				{
					printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %d         %d        %2.f               %d\n", name[vla][0], name[vla][1], name[vla][2], name[vla][3], name[vla][4], name[vla][5], name[vla][6], name[vla][7], name[vla][8], name[vla][9], name[vla][10], name[vla][11], name[vla][12], name[vla][13], name[vla][14], name[vla][15], name[vla][16], name[vla][17], name[vla][18], name[vla][19], cost[vla], skidka[vla], costs[vla], kolvopovtorov[i]);
					printf("_________________________________________________________________________\n");
				}
			} 
 			break;
 		case 4:
			for (i = 0; i < kolvo; i++)
			{
				vla=numbers[i];
				taktaev=costs[vla] * (kolvopovtorov[i]);
				sum+=taktaev;
			}//подсчет суммы
			printf("Итого:");
			printf("%f рублей", sum);
 			break;
		case 0:
			flag=0;
			break;
 		default:
 			menu();
 		}
		}while(flag != 0);
}
