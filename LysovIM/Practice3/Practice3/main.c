#include <stdlib.h> //Подключение Библиотек
#include <stdio.h>
#include <time.h>

#define MIN_DIGITS_NUM 2 //Задание размером массива
#define MAX_DIGITS_NUM 5
#define NUM_OF_DIGITS 10

void reverse(int n, int* array) { // реверсирование массива
	int temp;
	for (int i = 0; i < n / 2; i++) {
		temp = array[i];
		array[i] = array[n - i - 1];
		array[n - i - 1] = temp;
	}
}


int is_win(int n, int* needed, int* cur) { // проверка, совпадает ли загаданное число с введенным 
	for (int i = 0; i < n; i++) 
		if (needed[i] != cur[i])
			return 1;
	return 0;
}

int process(int n, int* needed, int cur, int playing) {
	// выделяем память под введенное число
	int* recieved = (int*)malloc(n * sizeof(int));
	// преобразование числа int в массив
	for (int i = 0; i < n; i++) {
		recieved[i] = cur % 10;
		cur /= 10;
	}
	// реверсируем полученный массив
	reverse(n, recieved);
	int cows = 0, bulls = 0, i, j;  // инициализируем счетчики и итераторы
	
for (i = 0; i < n; i++)
		// подсчет быков
		if (needed[i] == recieved[i]) bulls++;
		else
			for (j = 0; j < n; j++)
				// подсчет корова
				if (needed[i] == recieved[j])
					cows++;

	// Проверка не победили ли
	if (!is_win(n, needed, recieved)) {
		printf(" You won!");
		return 0;
	}
	// Вывод количества быков и коров
	printf(" There're %d bulls and %d cows\n", bulls, cows);
}

int read(int n) {//функция считывания числа и проверка на то подходит ли введенное число под критерии n-значного числа.
	int temp = 0;
	int c = 0;
	char ch = 'a';
	while (c < n) {
		ch = getchar();
		switch (ch) {
			case'0':
			case'1':
			case'2':
			case'3':
			case'4':
			case'5':
			case'6':
			case'7':
			case'8':
			case'9': {
				temp = temp * 10 + atoi(&ch);
				c++;
				break;
			}
		}
	}
	return temp;
}

void shuffle(int* array) { // перемешивает массив 
	 // устанавливаем текущее время в качестве семени для генератора псевдослучайных чисел
	srand(time(NULL));
	int j, temp;
	for (int i = NUM_OF_DIGITS - 1; i >= 1; i--) {
		// выбираем случайной индекс, не превосходящий i
		j = rand() % (i + 1);
		// меняем значения в массиве местами
		temp = array[j];
		array[j] = array[i];
		array[i] = temp;
	}

}

void check(int* array) { // перемешивает массив 
	 // устанавливаем текущее время в качестве семени для генератора псевдослучайных чисел
	int j, temp;
	for (int i = NUM_OF_DIGITS - 1; i >= 1; i--) {
		// выбираем случайной индекс, не превосходящий i
		j = rand() % (i + 1);
		// меняем значения в массиве местами
		temp = array[j];
		array[j] = array[i];
		array[i] = temp;
	}
}
int* gen(int n) { // генерирует случайное число-массив заданной длинны
	int digits[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// перемешиваем созданный выше массив до тех пор, пока первая цифра не будет отлична от нуля
	do
		shuffle(digits);
	while (digits[0] == 0);
	// чтобы вернуть результат, создаем указатель на массив, выделяем под него память
	int* result = (int*)malloc(n * sizeof(int));
	// переписываем в result полученный перемешанный массив
	for (int i = 0; i < n; i++)
		result[i] = digits[i];
	return result;
}

int introduction() {//Вступление
	int n = 0;
	printf(" ==================== BULLS & COWS ====================\n\n");
	printf(" You have to quess the num I've made.  You should  tell\n");
	printf(" me how many digits there'll be in the made num (2 - 5)\n");
	printf(" Number length: ");
	while (1) { //Бесконечный цикл
		 // считываем длину числа
		scanf("%d", &n);
		// проверяем на корректность
		if (n >= 2 && n <= 5) {
			printf("\n");
			printf(" I've made the num with length of %d. Try to quess it!\n", n);
			return n;
		}
		printf("\n Something went wrong, try again!");
	}
}

void main() {
	int n = introduction();
	int* num = gen(n);
	int playing = 1, cur;

	while (playing) {  // цикл игры
		cur = read(n); // считываем пользовательское число
		playing = process(n, num, cur, playing); // обрабатываем
		if (!playing) { // предлагаем сыграть снова, обрабатываем ответ
			printf("\n\n Do you want to play again?\n 1 - play again\n 0 - exit\n\n ");
			scanf("%d", &playing);
			if (playing) {
				system("cls");//чистка визуала
				n = introduction();
				num = gen(n);
			}
		}
	}
	printf("\n\n\n");
}