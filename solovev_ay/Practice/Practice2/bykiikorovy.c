#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 10
void main (){
	int randommas[N];
	int osnova[N]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};//ââåë ìàññèâ êàê áàçó äëÿ ñîçäàíèÿ ðàíäîìíûõ ÷èñåë
	int otvet[N];
	int i=0, kolvoznakov=0, kolvokorov=0, kolvobykov=0, x=100, y, z, score=0;
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));
	printf("Ââåäèòå êîëè÷åñòâî çíàêîâ îò 1 äî 10\n");
	while((kolvoznakov < 1) || (kolvoznakov > 10))
		scanf("%d", &kolvoznakov);//ïðîâåðêà íà ââîä êîëè÷åñòâà çíàêîâ
	printf("Êîìïüþòåð çàãàäàë %d çíà÷íîå ÷èñëî!", kolvoznakov);
	//ãåíåðèðóþ ñëó÷àéíûé ìàññèâ randommas
	i=kolvoznakov;
	while (i>0)
	{
		x = 10.0/RAND_MAX * rand();
		if (i == kolvoznakov) 
			x=9.0/RAND_MAX * rand() +1;
		//ñî âòîðîãî çíàêà ãåíåðèðóþ îò 0 äî 9
		if (osnova[x] != -1) //âûïîëíÿåòñÿ ïðè íà÷àëå ðàáîòû ñ åùå íå çàäåéñòâîâàííûì ýë-òîì osnova
		{
			randommas[i] = osnova[x];
			osnova[x]=-1;//ïðèíèìàþ ðàíäîìíûå çíà÷åíèÿ â ìàññèâ//èñêëþ÷àþ ïîâòîðû
			i--;
		} 
	}
	
		do {
			
			x = 0;
			printf("Ââåäè ÷èñëî áåç ïîâòîðÿþùèõñÿ öèôð = ");
			kolvobykov=0;
			kolvokorov=0;//îáíóëèë ñ÷åò÷èêè êîëè÷åñòâà æèâîòíûõ 
			scanf("%d", &y);

			score++;//çàïèñûâàþ ÷èñëî ïîïûòîê
			for (i = kolvoznakov; i >0; i--)
			{
				otvet[i] = y % 10;
				y = y / 10;
				
			}//êîíâåðòèðóþ ââîäèìîå ïîëüçîâàòåëåì ÷èñëî â ìàññèâ âèäà 
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
kolvobykov++; //âûñ÷èòûâàþ áûêîâ



if ((randommas[i] == otvet[y]) && (i != y)) 
kolvokorov++; //âûñ÷èòûâàþ êîðîâ
 } 
}
printf("Êîðîâ = %d è Áûêîâ = %d \n", kolvokorov, kolvobykov);

		
} 
while (kolvobykov != kolvoznakov);
	printf("Òû âûèãðàë! ×èñëî ïîïûòîê - %d!", score);
}

