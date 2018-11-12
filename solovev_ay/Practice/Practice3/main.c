#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h> 

void main() {
	int  ask1, a=0, b, x, y=0, choice, ask2=0, max=1000, min=1, ent;
	char quest;
	setlocale(LC_ALL, "Russian"); 
	printf("Èãðà \"Óãàäàé ÷èñëî îò 1 äî 1000!\", ñ äâóìÿ ðåæèìàìè!\n");
	printf("Åñëè òû õî÷åøü îòãàäàòü ÷èñëî, çàãàäàííîå êîìïüþòåðîì, ââåäè \"1\"!\nÅñëè õî÷åøü, ÷òîáû òâîå ÷èñëî îòãàäàë êîìïüþòåð, ââåäè \"2\"!\n");
	scanf("%d", &choice);
	if (choice == 1){
		printf("Îòãäàé ÷èñëî, êîòîðîå çàãàäàë êîìïüþòåð!\n");
		srand((unsigned int)time(0));
		x=0;
		while((x < 1) || (x > 1000))
			x=rand();
		do
		{
	scanf("%d", &ask1);
	a++;
if(ask1 > x)
	printf("Çàãàäàííîå ÷èñëî ìåíüøå!\n");
if (ask1 <x)
	printf("Çàãàäàííîå ÷èñëî áîëüøå!\n");
}
while( ask1 !=x);
if (x == ask1){
printf("Âû óãàäàëè, çàãàäàííîå ÷èñëî:%d\nÏîïûòîê - %d\n",x, a );
return;
}
}
	if(choice == 2){
	printf("Çàãàäàé ÷èñëî è ââåäè åãî!\n");
	scanf("%d",&ent);
	printf("Çàãàäàííîå âàìè ÷èñëî - %d\n",ent);
	printf("Â çàâèñèìîñòè îò òîãî ÷èñëà, êîòîðîå âû çàãàäàëè, èñïîëüçóéòå ñèìâîëû \">\", \"<\" è \"=\"\nÅñëè âàøå ÷èëî ìåíüøå, ââåäèòå\"<\"!\nÅñëè âàøå ÷èñëî áîëüøå, ââåäèòå \">\"!\nÅñëè êîìïüþòåð óãàäàë âàøå ÷èñëî, òî ââåäèòå \"=\"!\n");
b=0;
srand((unsigned int)time(0));
while((y < 1) || (y > 1000))
			y=rand();
printf("Ïðåäïîëîãàåìîå êîìïüþòåðîì ÷èñëî - %d!\n", y);
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
	printf("Ïðåäïîëîãàåìîå êîìïüþòåðîì ÷èñëî - %d!\n", y);
	}
}
if(quest == '<'){
	while((ask2 >= y) || (ask2 < min) || (ask2 > max))
		ask2=rand();
	{b=b+1;
	max=y;
	y=ask2;
	ask2=0;
	printf("Ïðåäïîëîãàåìîå êîìïüþòåðîì ÷èñëî - %d!\n", y);
	}
	
}
}


while(y != ent);
if(y == ent)
	printf("Êîìïüþòåð óãàäàë âàøå ÷èñëî %d çà %d ïîïûòîê!\n", y, b);
return;
}
	printf("Ýòîò ðåæèì åùå íå ïðèäóìàí!\n");
}
