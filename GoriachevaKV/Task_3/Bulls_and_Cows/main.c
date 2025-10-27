#include <stdio.h>
#include <windows.h>
#include <time.h>
//#define DEBUG

int main() {
    srand(time(NULL));
    int n, i, digit, bulls = 0, cows = 0, player_number_int = 0;
    int comp_number[5] = { -1, -1, -1, -1, -1 }, player_number[5] = { -1, -1, -1, -1, -1 };

    do {   //player choose the number of digits
        printf("Input number of digits (2-5) >> ");
        scanf_s("%d", &n);
        if (n < 2 || n > 5) {
            printf("Error! Try again.\n\n");
            system("pause");
        }
        system("cls");
    } while (n < 2 || n > 5);

    comp_number[0] = 1 + rand() % 9;

    i = 1;
    while (i < n) {
        int digit_repeats = 0;
        comp_number[i] = 0 + rand() % 9;
        for (int j = 0; j < i; j++) {
            if (comp_number[j] == comp_number[i]) {
                digit_repeats = 1;
            }
        }
        if (digit_repeats == 0) {
            i++;
        }
    }

    do {    //main game code
#ifdef DEBUG
        printf("DEBUG The guessed number is %d%d%d%d%d.\n", comp_number[0], comp_number[1], comp_number[2], comp_number[3], comp_number[4]);
#endif
        bulls = 0;
        cows = 0;
        for (i = 0; i < n; i++) {
            do {
                printf("Input digit %d >> ", i + 1);
                scanf_s("%d", &digit);
                player_number[i] = digit;
                if (digit < 0 || digit > 9) {
                    printf("Error! Try again.\n\n");
                    system("pause");
                }
            } while (digit < 0 || digit > 9);
        }
        system("cls");
        for (i = 0; i < n; i++) {
            if (player_number[i] == comp_number[i]) {
                bulls += 1;
            }
            else {
                for (int j = 0; j < n; j++) {
                    if (player_number[i] == comp_number[j]) {
                        cows += 1;
                    }
                }
            }
        }
        player_number_int = player_number[0];
        for (i = 1; i < n; i++) {
            player_number_int = player_number_int * 10 + player_number[i];
        }
        printf("Your number is %d.\n", player_number_int);
        printf("You have %d bulls and %d cows.\n", bulls, cows);
        system("pause");
    } while (bulls != n);

    system("cls");
    printf("CONGRATULATIONS!\n");
    printf("YOU WON!!!\n");
    printf("The guessed number was %d.\n\n", player_number_int);
    return 0;
}
