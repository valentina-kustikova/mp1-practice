#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h> 
void main() {
	int  ask1, a = 0, b=1, x, y = 0, choice, ask2 = 0, max = 1000, min = 1, ent;
	char quest;
	setlocale(LC_ALL, "Russian");
	printf("Игра \"Угадай число от 1 до 1000!\", с двумя режимами!\n");
	printf("Если ты хочешь отгадать число, загаданное компьютером, введи \"1\"!\nЕсли хочешь, чтобы твое число отгадал компьютер, введи \"2\"!\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("Отгдай число, которое загадал компьютер!\n");
		srand((unsigned int)time(0));
		x = 0;
		x = 1 + rand() % 1000;
		do
		{
			scanf("%d", &ask1);
			a++;
			if (ask1 > x)
				printf("Загаданное число меньше!\n");
			if (ask1 < x)
				printf("Загаданное число больше!\n");
		} while (ask1 != x);
		if (x == ask1)
		{
			printf("Вы угадали, загаданное число:%d\nПопыток - %d\n", x, a);
			return;
		}
	}
	if (choice == 2)
	{
		printf("Загадай число и введи его!\n");
		do {
			scanf("%d", &ent);
		} while (ent < min || ent > max);
		printf("Загаданное вами число - %d\n", ent);
		printf("В зависимости от того числа, которое вы загадали, используйте символы \">\", \"<\" и \"=\"\nЕсли ваше чило меньше, введите\"<\"!\nЕсли ваше число больше, введите \">\"!\nЕсли компьютер угадал ваше число, то введите \"=\"!\n");
		do {
			ask2 = (min + max) / 2;
			printf("%d\n", ask2);
			b++;
			if (ask2 == ent) {
				break;
			}
			do {
				scanf("%c", &quest);
			} while ((quest != '<') && (quest != '>'));
			if (quest == '>') {
				min = ask2;
			}
			else if (quest == '<') {
				max = ask2;
			}
		} while (ask2 != ent);
		printf("Компьютер угадал твое число за %d попыток.", b);
	}
	printf("Этот режим еще не придуман!\n");
}

