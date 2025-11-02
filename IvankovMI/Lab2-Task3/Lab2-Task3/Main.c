#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

//RAND_MAX = 32767

void procedure_try_n(int k) {
	;
}

int heavy_main() {
	long int a;
	int k = 0, regim = 0;
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	//printf("%d", RAND_MAX);
	//regim = MessageBoxA("ÂÛÁÅÐÅÒÅ ÐÅÆÈÌ ÈÃÐÛ", "ß ÎÒÃÀÄÛÂÀÞ ×ÈÑËÎ ÊÎÌÏÜÞÒÅÐÀ", "ÊÌÏÜÞÒÅÐ ÎÒÃÀÄÛÂÀÅÒ ÌÎÅ ×ÈÑËÎ", &regim);
	printf_s("ÂÛÁÅÐÅÒÅ ÐÅÆÈÌ ÈÃÐÛ\n0 - ß ÎÒÃÀÄÛÂÀÞ ×ÈÑËÎ ÊÎÌÏÜÞÒÅÐÀ\n1 - ÊÎÌÏÜÞÒÅÐ ÎÒÃÀÄÛÂÀÅÒ ÌÎÅ ×ÈÑËÎ\n");
	scanf_s("%d", &regim);
	if (regim == 0) {
		int s;
		a = rand();
		printf_s("\nß çàãàäàë ñëó÷àéíîå öåëîå ÷èñëî. Ïîïðîáóé îòãàäàòü åãî. \nÍà êàæäóþ òâîþ ïîïûòêó ÿ áóäó äàâàòü ïîäñêàçêó, áîëüøå èëè ìåíüøå òâîÿ äîãàäêà. \n\nÂâîäè ñâîþ ïåðâóþ äîãàäêó:  ");
		do {
			scanf_s("%d", &s);
			k++;
			if (s > a) {
				printf_s("Íå óãàäàë — òâîå ÷èñëî ñëèøêîì áîëüøîå. \n");
				procedure_try_n(k);

			}
			if (s < a) {
				printf_s("Íå óãàäàë — òâîå ÷èñëî ñëèøêîì ìàëåíüêîå. \n");
				procedure_try_n(k);

			}
		} while (a != s);

	}
}

int main() {
	int v;
	setlocale(LC_ALL, "Rus");
	printf_s("ÂÛÁÅÐÅÒÅ ÂÅÐÑÈÞ ÈÃÐÛ\n\n0 - ÎÁËÅÃ×ÅÍÍÀß, \nÂÛÏÎËÍÅÍÍÛ ÌÈÍÈÌÀËÜÍÛÅ ÒÐÅÁÎÂÀÍÈß, \nÐÀÁÎÒÀÅÒ \n\n1 - ÓÒßÆÅËÅÍÍÀß, \nÐÅÀËÈÇÎÂÀÍÛ ÐÀÇÍÛÅ ÔÈ×È, \nÊÎÍÒÐÎËÜ ÂÂÎÄÀ \nÈ ÏÐ. \n\n");
	scanf_s("%d", &v);
	printf_s("\n\n\n");
	if (v == 0) {
		printf_s("*çàïóñê ëåãêîé âåðñèè*\n\n");
		light_main();
	}
	else {
		printf_s("*çàïóñê òÿæåëîé âåðñèè*\n\n");
		heavy_main();
	}
}
// —\\_/(–_–)\\_/—