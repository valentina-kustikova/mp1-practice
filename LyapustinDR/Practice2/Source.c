#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    int mode;
    srand((unsigned int)time(NULL));

    printf("Choose game mode: 1 or 2\n");
    do {
        scanf("%d", &mode);
    } while (mode != 1 && mode != 2);

    if (mode == 1) {
        int guessed;
        int num = rand() % 1000 + 1, moves = 0;
        
        printf("Guess number in [0, 1000]\n");
        do {
            scanf("%d", &guessed);
            while (guessed < 0 || guessed > 1000) {
                printf("Number out of [0, 1000]\n");
                scanf("%d", &guessed);
            }

            if (guessed > num) {
                printf("Less\n");
            }
            else if (guessed < num) {
                printf("More\n");
            }
            moves++;
        } while (guessed != num);
        printf("Number was: %d\nTotal moves: %d\n", num, moves);
    }
    else {
        int l = 1, r = 1000, mid, moves = 0;
        char sign;

        printf("Print '<' if your number is less than guessed\n");
        printf("Print '>' if your number is more than guessed\n");
        printf("Print '=' if your number equals guessed\n");
        
        while (l <= r) {
            moves++;
            mid = (r + l) / 2;
            printf("%d?\n", mid);
            do {
                scanf("%c", &sign);
            } while (sign != '=' && sign != '<' && sign != '>');

            if (sign == '=') break;
            if (sign == '<') r = mid - 1;
            else l = mid + 1;
        }
        printf("Your number is: %d\nTotal moves: %d\n", mid, moves);
    }
    return 0;
}