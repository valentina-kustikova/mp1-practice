#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
int len(int n) {
    int length = 0;
    do {
        length++;
        n /= 10;
    } while(n);
    return length;
}
void main() {
    int attempts = 0; 
    int i, j, l, number, guess;
    int bulls = 0, cows = 0;
    int k = 0;
    int number1[N] = { 0 };
    int number2[N] = { 0 };
    printf("Welcome to the game 'Cows and Bulls'\n");
    do {
        printf("Choose the length of your number from 2 to 5\n");
        scanf("%d", &l);
    } while ((l < 2) || (l > 5));
    srand((unsigned int)time(0));
    number1[0] = 1+ rand() % (10 - 1); // первая цифра отлична от нуля
    for (i = 1; i < l; i++) {
        do {
            k = 0;
            number = rand() % 10;
            for (j = 0; j < i; j++) {
                if (number1[j] == number)
                    break;
                k++; 
            }
            if (k == i) {
                number1[i] = number;
                break;
            }
        } while (1);

    }
    do {
        attempts++;  
        cows = 0;
        bulls = 0;
        do {
            printf("Write the number. Be carefull! Your number should be with different symbols\n");
            scanf("%d", &guess);
            if (len(guess) != l)
                printf("Incorrect length of your number, write it again\n");
            else break;
        } while (1);

        for (i = l - 1; i >= 0; i--) {
            number2[i] = guess % 10;
            guess = guess / 10;
        }
        for (i = 0; i < l; i++) {
            for (j = 0; j < l; j++) {
                if (number2[i] == number1[j]) {
                    cows++;
                    if (i == j) {
                        bulls++;
                        cows--;
                    }
                    break;
                }
            }
        }
        if (bulls != l)
            printf("Bulls: %d, Cows: %d\n\n", bulls, cows);
        else {
            printf("Congratulations! You have guessed the number! The number of your attempts is %d.", attempts);
            break;
        }
    } while (1);
    return;
}
    
