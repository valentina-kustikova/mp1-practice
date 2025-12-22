#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length;
    do {
        printf("Enter number's lenght: ");
        scanf_s("%d", &length);
    } while (length < 2 || length > 5);


    int number[5];
    int used_digits[10] = { 0 }; 
    srand((unsigned int)time(0));

    for (int i = 0; i < length; i++) {
        int digit;
        do {
            digit = rand() % 9 + 1; 
        } while (used_digits[digit]);
        number[i] = digit;
        used_digits[digit] = 1;
    }

 
    printf("Number: ");
    for (int i = 0; i < length; i++) {
        printf("%d", number[i]);
    }
    printf("\n");

    int guess, attempts = 0;
    int bulls, cows;

    do {
        printf("Try to guess the number ", length);
        scanf_s("%d", &guess);

        int temp = guess;
        int digit_count = 0;
        while (temp != 0) {
            digit_count++;
            temp /= 10;
        }

        if (digit_count != length) {
            printf("Incorrect lenght\n", length);
            continue;
        }

      
        int attempt_digits[5];
        temp = guess;
        for (int i = length - 1; i >= 0; i--) {
            attempt_digits[i] = temp % 10;
            temp /= 10;
        }


        bulls = 0;
        cows = 0;

        for (int i = 0; i < length; i++) {
            if (attempt_digits[i] == number[i]) {
                bulls++;
            }
            else {
                for (int j = 0; j < length; j++) {
                    if (i != j && attempt_digits[i] == number[j]) {
                        cows++;
                        break;
                    }
                }
            }
        }

        attempts++;
        printf("Bulls: %d, Cows: %d\n", bulls, cows);

    } while (bulls != length);

    printf("U guessed, attemps: %d\n", attempts);
    return 0;
}