#include "C:\Users\User\git practice\mp1-practice\IvankovMI\Lab2-Task3\Lab2-Task3\Windows Kits\10\Include\10.0.19041.0\ucrt\stdio.h"
#include "C:\Users\User\git practice\mp1-practice\IvankovMI\Lab2-Task3\Lab2-Task3\Windows Kits\10\Include\10.0.19041.0\ucrt\locale.h"
#include <C:\Users\User\git practice\mp1-practice\IvankovMI\Lab2-Task3\Lab2-Task3\Windows Kits\10\Include\10.0.19041.0\ucrt\stdlib.h>
#include <C:\Users\User\git practice\mp1-practice\IvankovMI\Lab2-Task3\Lab2-Task3\Windows Kits\10\Include\10.0.19041.0\ucrt\time.h>

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
	//regim = MessageBoxA("ВЫБЕРЕТЕ РЕЖИМ ИГРЫ", "Я ОТГАДЫВАЮ ЧИСЛО КОМПЬЮТЕРА", "КМПЬЮТЕР ОТГАДЫВАЕТ МОЕ ЧИСЛО", &regim);
	printf_s("ВЫБЕРЕТЕ РЕЖИМ ИГРЫ\n0 - Я ОТГАДЫВАЮ ЧИСЛО КОМПЬЮТЕРА\n1 - КОМПЬЮТЕР ОТГАДЫВАЕТ МОЕ ЧИСЛО\n");
	scanf_s("%d", &regim);
	if (regim == 0) {
		int s;
		a = rand();
		printf_s("\nЯ загадал случайное целое число. Попробуй отгадать его. \nНа каждую твою попытку я буду давать подсказку, больше или меньше твоя догадка. \n\nВводи свою первую догадку:  ");
		do {
			scanf_s("%d", &s);
			k++;
			if (s > a) {
				printf_s("Не угадал — твое число слишком большое. \n");
				procedure_try_n(k);

			}
			if (s < a) {
				printf_s("Не угадал — твое число слишком маленькое. \n");
				procedure_try_n(k);

			}
		} while (a != s);

	}
}

int main() {
	int v;
	setlocale(LC_ALL, "Rus");
	printf_s("ВЫБЕРЕТЕ ВЕРСИЮ ИГРЫ\n\n0 - ОБЛЕГЧЕННАЯ, \nВЫПОЛНЕННЫ МИНИМАЛЬНЫЕ ТРЕБОВАНИЯ, \nРАБОТАЕТ \n\n1 - УТЯЖЕЛЕННАЯ, \nРЕАЛИЗОВАНЫ РАЗНЫЕ ФИЧИ, \nКОНТРОЛЬ ВВОДА \nИ ПР. \n\n");
	scanf_s("%d", &v);
	printf_s("\n\n\n");
	if (v == 0) {
		printf_s("*запуск легкой версии*\n\n");
		light_main();
	}
	else {
		printf_s("*запуск тяжелой версии*\n\n");
		heavy_main();
	}
}