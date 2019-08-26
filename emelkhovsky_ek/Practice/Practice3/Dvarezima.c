#include "stdio.h"
#include "locale.h"
#include "time.h"
void mode_1() {
	int random, user, kol;
	random = rand() % 1000 + 1;
	kol = 0;
	printf("Êîìïüþòåð çàãàäàë ÷èñëî îò 1 äî 1000!\nÏîïðîáóé óãàäàòü!\n");
	//	printf("%d\n",random);
	scanf("%d", &user);
	while (user != random) {
		while ((user<1) || (user>1000)) {
			printf("Êîððåêòíûé ââîä îò 1 äî 1000\n");
			scanf("%d", &user);
		}
		kol++;
		if (user>random) {
			printf("Âû ââåëè ÷èñëî áîëüøå, ÷åì çàãàäàííîå\n");
		}
		else if (user<random) {
			printf("Âû ââåëè ÷èñëî ìåíüøå ÷åì çàãàäàííîå\n");
		}
		scanf("%d", &user);
	}
	printf("Âû óãàäàëè ÷èñëî ñ %d ïîïûòêè \n", kol);
}


void mode_2() {
	int user, random, a, b, kol;
	kol = 0;
	b = 1001;
	a = 1;
	char o;
	printf("Ââåäèòå ÷èñëî êîòîðîå áóäåò îòãàäûâàòü êîìïüþòåð\n");
	scanf("%d", &user);

	while ((user<1) || (user>1000)) {
		printf("Êîððåêòíûé ââîä îò 1 äî 1000\n");
		scanf("%d", &user);
	}

	random = rand() % (b - a) + a;
	printf("Êîìïüþòåð çàãàäàë ÷èñëî %d, ââåäèòå Âàøå ÷èñëî áîëüøå, ìåíüøå èëè ðàâíî?\n", random);

	while (random != user) {
		kol++;
		scanf("%s", &o);

		if (o == '>') {
			a = random + 1;
		}
		else if (o == '<') {
			b = random;
		}

		else break;
		random = rand() % (b - a) + a;
		printf("Êîìïüþòåð çàãàäàë ÷èñëî %d, ââåäèòå Âàøå ÷èñëî áîëüøå, ìåíüøå èëè ðàâíî?\n", random);
	}
	printf("Êîìïüþòåð óãàäàë ñ %d ïîïûòêè \n", kol);
}
void main() {

	int mode;
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	printf("Ââåäèòå ðåæèì:\n1 ÷òîáû ðàçãàäûâàòü ÷èñëî\n2 ÷òîáû çàãàäûâàòü ÷èñëî\n");
	scanf("%d", &mode);
	if (mode == 1) {
		mode_1();
	}
	else if (mode == 2) {
		mode_2();
	}
	else {
		printf("Âñåãî 2 ðåæèìà");
	}

}