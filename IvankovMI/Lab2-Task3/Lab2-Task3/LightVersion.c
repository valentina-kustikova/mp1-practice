#include "C:\Users\User\git practice\mp1-practice\IvankovMI\Lab2-Task3\Lab2-Task3\Windows Kits\10\Include\10.0.19041.0\ucrt\stdio.h"
#include "C:\Users\User\git practice\mp1-practice\IvankovMI\Lab2-Task3\Lab2-Task3\Windows Kits\10\Include\10.0.19041.0\ucrt\locale.h"
#include <C:\Users\User\git practice\mp1-practice\IvankovMI\Lab2-Task3\Lab2-Task3\Windows Kits\10\Include\10.0.19041.0\ucrt\stdlib.h>
#include <C:\Users\User\git practice\mp1-practice\IvankovMI\Lab2-Task3\Lab2-Task3\Windows Kits\10\Include\10.0.19041.0\ucrt\time.h>

//RAND_MAX = 32767

int light_main() {
	long int pre_a;
	int a, k = 0, regim = 0;
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	//printf("%d", RAND_MAX);
	printf_s("ВЫБЕРЕТЕ РЕЖИМ ИГРЫ\n0 - Я ОТГАДЫВАЮ ЧИСЛО КОМПЬЮТЕРА\n1 - КОМПЬЮТЕР ОТГАДЫВАЕТ МОЕ ЧИСЛО\n\n");
	scanf_s("%d", &regim);
	if (regim == 0) {
		int s;
		pre_a = rand() % 1001;
		a = (pre_a == 0) ? 1 : pre_a;                //for (s = 0; s < 1000; s++) printf("Test: %d", rand() % 1001);
		printf_s("\nЯ загадал случайное целое число от 1 до 1000. Попробуй отгадать его. \nНа каждую твою попытку я буду давать подсказку, больше или меньше твоя догадка. \n\nВводи свою первую догадку:  ");
		do {
			scanf_s("%d", &s);
			k++;
			if (s > a) {
				printf_s("Не угадал — твое число слишком большое. \n");
			}
			if (s < a) {
				printf_s("Не угадал — твое число слишком маленькое. \n");
			}
		} while (a != s);
		printf_s("\nПоздравляю! Ты отгадал число! \nИ потратил всего %d попыток! \n", k);
		return 0;
	}
	
	if (regim == 1) {
		char s;
		int l = 0, r = 1000, win = 1;
		pre_a = rand() % 1001;
		a = (pre_a == 0) ? 1 : pre_a;                //for (s = 0; s < 1000; s++) printf("Test: %d", rand() % 1001);
		printf_s("\nЗагадай случайное целое число от 1 до 1000. Я попробую отгадать его. \nНа каждую мою попытку отвечай: \n> — если моя догадка больше твоего числа, \n< — если моя догадка меньше твоего числа, \n= — если я наконец-таки отгадал твое число\n\nЯ начинаю отгадывать: %d \n", a);
		do {
			scanf_s("%c", &s);
			k++;
			if (s == ">"[0]) {
				r = a - 1;
				if (l < r) { win = 0; continue; }
				a = l + rand() % (r - l + 1);
				printf_s("Ай, не угадал! А может это: %d ?\n", a);
			}
			else if (s == "<"[0]) {
				l = a + 1;
				if (l < r) { win = 0; continue; }
				a = l + rand() % (r - l + 1);
				printf_s("Да как так то! А может это: %d ?\n", a);
			}
			else {
				printf_s("Я не понял. Введи '<' '>' или '='\n");
				k--;
			}
				
		} while ((s != "="[0]) && (l < r));
		if (win == 1)
			printf_s("\nУра! Я отгадал твое число! \nИ потратил всего %d попыток! \n", k);
		else
			printf_s("\nПохоже, у меня не получилось отгадать твое число... \nЗа %d попыток я выяснил, что твое число не существует в поле целых чисел. \n", k);
		return 0;
	}
}