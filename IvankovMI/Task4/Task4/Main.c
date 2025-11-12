#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <string.h>


//ОТЛАДКА:  для релиза убрать из кода все макросы и переменные с "DEBB"/"debb" в названии
#define DEBB //printf("     ~~~ Отладка № %d ~~~     \n", debb++);
#define DEBB1 //printf("    ~~~ Отладка: заг. сл. - %d%d%d%d%d ~~~\n", sl[0], sl[1], sl[2], sl[3], sl[4]);

int debb = 0;    //отладка
int глобальный_костыль = 1;      //КОСТЫЛЬ (осторожно) !!!

int unique(int a[5], int i);
void get_int_arr_lenth_n(int a[5],int n);
int arr_is_digit(char a[], int n);

#define ADEBB {-1, -1, -1, -1, -1}  //тоже для отладки
int main() {
	int n, sl[5] = ADEBB, mysl[5] = ADEBB, i, j, cows = 0, bulls = 0, ok = 0, tryn = 1, tryp = 0;  //массивы инициализированны для отладки

	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	printf("      --- Вы запустили игру «Быки и коровы­®» --- \nВ ней вам надо будет угадывать слово \nпо необычным подсказкам\n\n");
	printf("Введите длину загадываемого слова (2, 3, 4 или 5)\n");
	scanf_s("%d", &n);
	if (n > 5)
		printf("Вы просите загадать число больше 5, но делаете это без уважения. \nТак что я не гарантирую корректную работу программы\n");       //Вы ввели число больше 5. Дальше нет гарантий корректной работы программы
	if (n == 1)
		printf("Игра, конечно, запустится, но будет ли в этом смысл...\n");
	sl[0] = rand() % 10;
	for (i = 1; i < n; i++) {
		sl[i] = rand() % 10;
		while (! unique(sl, i))               //(sl[i] == sl[i - 1]) || (sl[i] == sl[abs(i - 2)])     (for (j = i; j > 0; j--) sl[i] == sl[j])
			sl[i] = rand() % 10;
	}
	
	DEBB1;
	printf("\nOk'эй, я загадал \"слово\" из %d уникальных цифр. Вводите свою отгадку, \nа я отвечу, сколько в ней коров (цифра есть, но не на своем месте) \nи быков (цифра и её положение угаданы верно).\n", n);
	DEBB;
	get_int_arr_lenth_n(mysl, n);
	DEBB;
	while (!ok) {
		//char repl[] = "В вашем слове";     --неудачная попытка
		for (i = 0; i < n; i++) {
			int t = mysl[i];
			for (j = 0; j < n; j++)
				if (t == sl[j]) {
					if (i == j)
						bulls++;
					else
						cows++;
				}
		}
		if (bulls == n)
			ok = 1;
		else {
			if (!(bulls == 0 && cows == 0 && tryn < 2))
				printf("%s %d бык%s и %d коров%s%s\n",
					(tryn < 2 + tryp) ? "Вы не отгадали слово, но в нем случайно затесались" : "В вашем слове",
					bulls, (bulls == 0 || bulls == 5) ? "ов" : (bulls == 1) ? "" : "а",
					cows, (cows == 0 || cows == 5) ? "" : (cows == 1) ? "а" : "ы",
					(tryn < 2 + tryp) ? ". Вы на верном пути, продолжайте отгадывать" : "");
			else {
				printf("Вы не отгадали слово, и в нем нет быков и коров. Но не отчаивайтесь и продолжайте отгадывать\n");
				tryp = 1; 
			}
			bulls = 0;
			cows = 0;
			tryn++;
			get_int_arr_lenth_n(mysl, n);
		}
	}
	printf("Поздравляю! Вы отгадали слово, и потратили на это всего %d попыток!\n\n", tryn);
	return 0;
}

int unique(int a[5], int i) {
	//ф-я проверяет уникальность i-того элемента в срезе массива от 0 до i
	int j = 0;
	for (; j < i; j++)
		if (a[j] == a[i])
			return 0;
	return 1;
}

void get_int_arr_lenth_n(int a[5], int n) {
	char inp[100];
	int i = 0, debbl, caps = 0, debb1;
	DEBB;
	if (глобальный_костыль == 1) {
		fgets(inp, sizeof(inp), stdin); глобальный_костыль = 0;         //КОСТЫЛЬ --\_/(- _ - )\_/--
	}
	fgets(inp, sizeof(inp), stdin);                                                        //scanf_s(" %s", inp) - почему-то не работает
	DEBB;
	while (((debbl = strlen(inp) - 1) != n) || (debb1 =(caps = !arr_is_digit(inp, n)))) {
		printf("Введите \"слово\" из %d %s\n", n, (caps)? "ЦИФР":"цифр"); caps = 0;
		fgets(inp, sizeof(inp), stdin);
	}
	for (i = 0; i < n; i++)
		//a[i] = ((int)(inp[i]));      --ага, как бы ни так -- это C, детка
		switch (inp[i]){
		case '0': a[i] = 0; break;
		case '1': a[i] = 1; break;
		case '2': a[i] = 2; break;
		case '3': a[i] = 3; break;
		case '4': a[i] = 4; break;
		case '5': a[i] = 5; break;
		case '6': a[i] = 6; break;
		case '7': a[i] = 7; break;
		case '8': a[i] = 8; break;
		case '9': a[i] = 9; break;    //вот так -- это вам не пайтон (да пипец, даже break вкаждом писать надо)
		}
}

int arr_is_digit(char a[], int n) {
	char digits[10] = "0123456789", debb3;
	int i = 0, j, ok, debb2 = 4;
	for (; i < n; i++) {
		ok = 0;
		for (j = 0; j < 10; j++)
			if (debb2 = ((debb3 = a[i]) == digits[j])) {
				ok = 1; 
				break;
			}
		if (ok == 0)
			return 0;
	}
	return 1;
}




//Просто полезные функции, которые пригодятся позже

void get_str_didg_arr_lenth_n(int a[5], int n) {
	char inp[100];
	int i = 0, l;
	fscanf_s("%s", inp);
	while ((l = (strlen(inp)) != n) || (!arr_is_digit(inp, l))) {
		printf("Введите ЧИСЛО из %d цифр\n", n);
		fscanf_s("%s", inp);
	}
	for (; i < n; i++)
		a[i] = ((int)(inp[i]));
}

void get_int_arr_in_range(int a[5], int n) {
	char inp[100];
	fscanf_s("%s", inp);
	if ((strlen(inp) < 2) || (strlen(inp) > n))
		printf("Введите число от ");
}