#include <stdio.h>
#include <time.h>
#include <stdlib.h>



void cr_number(int *digits,int n,int *d) {
    int i = 0,digit;
    digit = 1 + rand() % 9;
    for (i; i < n; i++) {
        
        while (d[digit] == 0) {
            digit = rand() % 10;
        }
        *digits += digit;
        *digits *= 10;
        d[digit]--;

    }
    *digits /= 10;
}

void cr_number_mas(int number,int n,int *sm) {
    int i;
    for (i = (n - 1); i >= 0; i--) {
        sm[i] = (number)% 10;
        (number) /= 10;
    }
}

//void get_n(int *n) {
//    do {
//        scanf("%d", &n);
//    } while (n < 2 || n>5);
//}


int main() {
    int attempts = 0; // кол-во попыток
    int n;
    int digits = 0; // число которое программа загадывает
    int d[10] = { 1,1,1,1,1,1,1,1,1,1 }; 
    // массив с доступными цифрами (индекс == цифра)
    // заполнен единицами т.к. каждую цифру можно исп. 1 раз
    int cows = 0, bulls = 0;
    int cb = 0; // cows & bulls
    int suggest = 0; // предположение игрока
    int dm[5]; // массив числа
    int sm[5]; // массив предположени€ игрока
    
    printf("Welcome! This is 'Cow and Bull' game!\n");
    printf("Lets start with amout of bulls you'll guess\n Type it\n");
    printf("(it must be 2,3,4, or 5, no more!)\n");
    
    do {
        scanf("%d", &n);
    } while (n < 2 || n>5);

    printf("Good! Now lets play\n");
    srand((unsigned int)time(0));

    
    cr_number(&digits, n, &d);
    
    
    
    // create number     function call
    

    // create massive of 'digits'     function call
    cr_number_mas(digits, n, &dm);
    // 1) само число  
    // 2) n - длина числа 
    // 3) dm - массив, который заполн€етс€ цифрами числа
    

    printf("Type number with %d  different digits\n", n);
    
    while (bulls != n) {
        scanf("%d", &suggest);
        int i, j;
        int bc = 0; // bulls & cows
        cows = 0, bulls = 0;

        // create massive of 'suggest'    function call
        cr_number_mas(suggest, n, &sm);
        
        for (i = 0; i < n;i++) {
            for (j = 0; j < n;j++) {
                if (dm[i] == sm[j]) {
                    bc++;

                }
            }
        }
        for (i = 0; i < n;i++) {
            if (dm[i] == sm[i]) {
                bulls++;
            }
        }
        
        cows = bc - bulls;
        // считаю кол-во совпадающих цифр 
        // вычитаю кол-во быков  и получаю кол-во коров
        // gg

        printf("cows    _%d_\n", cows);
        printf("bulls   _%d_\n", bulls);
        attempts++;
    }
    printf("Good game!\n");
    printf("You did it for only %d attempts!\n",attempts);
    return 0;
}
/*
разработать прогу реализующую игру быки-коровы
ѕравила
1) играют 2 игрока 1 чел 1 комп
2) игрок выбирает длину n загаданного числа от 2 до 5
3) пк задумывает n значное число с неповтор€ющимис€ цифрами
4) игрок делает попытку отгадать число - вводит n значное число
с неповтор€ющимис€ цифрами
5) пк сообщает сколько цифр угадано без совпадени€ с их позици€ми в числе
( это кол-во коров) и сколько угадано вплоть до позиции в загаданном числе (это кол-во быков)
123
524   -  1 бык 0 коров
251  -  0 быков  2 коровы
6) игрок делает попытки , пока не отгадает всю последовательность
n = 4
3219

2310
2 коровы 1 бык
(2 и 3 - коровы , 1 - бык)

*/