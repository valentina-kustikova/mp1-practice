#include "C:\Users\User\git practice\mp1-practice\IvankovMI\Lab2-Task3\Lab2-Task3\Windows Kits\10\Include\10.0.19041.0\ucrt\stdio.h"
#include "C:\Users\User\git practice\mp1-practice\IvankovMI\Lab2-Task3\Lab2-Task3\Windows Kits\10\Include\10.0.19041.0\ucrt\locale.h"
#include <C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\ucrt\stdlib.h>
#include <C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\ucrt\time.h>
int main() {
	long int a;
	int regim = 0;
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	//regim = MessageBoxA("ВЫБЕРЕТЕ РЕЖИМ ИГРЫ", "Я ОТГАДЫВАЮ ЧИСЛО КОМПЬЮТЕРА", "КМПЬЮТЕР ОТГАДЫВАЕТ МОЕ ЧИСЛО", &regim);
	printf_s("ВЫБЕРЕТЕ РЕЖИМ ИГРЫ\n0 - Я ОТГАДЫВАЮ ЧИСЛО КОМПЬЮТЕРА\n1 - КМПЬЮТЕР ОТГАДЫВАЕТ МОЕ ЧИСЛО\n");
	scanf_s("%d", &regim);
	if (regim == 0) {
		int s;
		a = rand();
		printf_s("Я загадал случайное целое число. Попробуй отгадать его. \nНа каждую твою попытку я буду давать подсказку, больше или меньше твоя догадка. \nВводи свою первую догадку.");
		do {
			scanf_s("%d", &s);
			
		} while (a == s);
	}
}