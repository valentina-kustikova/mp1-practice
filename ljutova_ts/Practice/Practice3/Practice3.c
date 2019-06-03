#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <locale.h>

void main()
{
    int n, ch, r, min = 1, max = 1000, count = 0;
    char z[3];
    setlocale(LC_ALL, "Russian");

    printf("Режимы работы:\n");
    printf("1-Компьютер загадывает число\n");
    printf("2-Пользователь загадывает число\n");
    printf("Выберите режим: ");
    scanf("%d", &r);
    if (r == 1)
    {
	    srand((unsigned int)time(0));
	    ch = rand() % 1000 + 1;
	    while (1)
	    {
		    do
		    {
			    printf("Введите число: \n");
			    scanf("%d", &n);
			    if ((n <= 0) || (n >= 1000))
				    printf("Ошибка.Число должно быть в диапазоне 1 - 1000 \n");
		    } while ((n <= 0) || (n >= 1000));
		    count++;
		    if (n == ch)
		    {
			    printf("Поздравляю! Вы угадали число\n");
			    printf("Число попыток: %d \n", count);
			    return;
		    }
		    if (n > ch)
			    printf("Введенное число больше загаданного \n");
		    else
			    printf("Введенное число меньше загаданного \n");
	    }
    }
	else if (r == 2)
    do
    {
	    printf("Введите число: \n");
	    scanf("%d", &n);
	    if ((n <= 0) || (n >= 1000))
		    printf("Ошибка.Число должно быть в диапазоне 1 - 1000 \n");
    } while ((n <= 0) || (n >= 1000));
    srand((unsigned int)time(0));
    while (z[0] != '=')
    {
	    ch = rand() % (max - min + 1) + min;
	    printf("Компьютер: %d \n", ch);
	    printf("Введите (>),(<),(=) заданное число и отгадки компьютера\n");
	    scanf("%s", &z);
	    switch (z[0])
	    {
	    case '>': min = ch;
		    count++;
		    break;
	    case '<': max = ch;
		    count++;
		    break;
	    case '=':count++;
		    printf("Компьютер угадал число! \n");
		    printf("Число попыток : %d \n", count);
		    break;
	    default: printf("Введено неккоректное значение \n");
		    break;
	    }
    }
}