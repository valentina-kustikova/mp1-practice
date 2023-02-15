//Поделючение библиотек
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
	char mode_game;
	printf("Select the game mode: \n1) Mode 1. The program makes a number from 0 to 1000. The user has to guess the number\n2) Mode 2. The user makes a number from 0 to 1000. The program must guess the number\n");
	do {
		scanf("%c", &mode_game);
	} while ((mode_game != '1') && (mode_game != '2'));//Проверка на корректность ввода
	if (mode_game == '1')
	{
		int i = 0, supposition_play_1, hidden_number;//i - счётчик попыток
		srand((unsigned int)time(NULL));
		hidden_number = rand() % 1001;//Загадывание числа
		printf("Game start\n");
		do {
			i++;
			scanf("%d", &supposition_play_1);
			if (hidden_number == supposition_play_1)
			{
				printf("You  Win\n Your number of attempts = %d", i);
				return 0;
			}
			else if (supposition_play_1 < hidden_number)
				printf("Probably the hidden number is more\n");
			else
				printf("Probably the hidden number is less\n");

		} while (1);//Бесконечный цикл
	};
	if (mode_game == '2')
	{
		int start = 1, finish = 1001, mid, attempts = 0; //mid - текущее среднее значение
		char symbols = 'n'; // Переменная куда записывается ответ пользователя
		printf("Tell me, please. Your number > or < or = than need");
		while (symbols != '=')
		{
			mid = ((start + finish) / 2);
			printf("\n I think your number is %d\n", mid);
			scanf(" %c", &symbols);
			if (symbols == '=' || symbols == '>' || symbols == '<')
				attempts++;
			if (symbols == '>')
				start = mid;
			else if (symbols == '<')
				finish = mid;
			else if (symbols == '=')
				printf("Hooray, I guessed it in %d attempts", attempts);
		}
	}
	return 0;
}
