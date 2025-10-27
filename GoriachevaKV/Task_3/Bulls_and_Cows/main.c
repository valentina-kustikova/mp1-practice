#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
//#define DEBUG

int main() {
    srand((unsigned int)time(NULL));
    int n, i, bulls = 0, cows = 0, player_number_int = 0, player_number_int_copy = 0;
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
        do {
            printf("Input number >> ");
            scanf_s("%d", &player_number_int);
            if (player_number_int > pow(10, n) || player_number_int < pow(10, n - 1)) {
                printf("Error! Try again.\n\n");
                system("pause");
            }
        } while (player_number_int > pow(10, n) || player_number_int < pow(10, n - 1));

        int j = n - 1;
        player_number_int_copy = player_number_int;
        while (j >= 0) {
            player_number[j] = player_number_int_copy % 10;
            player_number_int_copy /= 10;
            j--;
        }

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

        printf("Your number is %d.\n", player_number_int);
        printf("You have %d bulls and %d cows.\n\n", bulls, cows);
    } while (bulls != n);

    system("cls");
    printf("CONGRATULATIONS!\n");
    printf("YOU WON!!!\n");
    printf("The guessed number was %d.\n\n", player_number_int);
    return 0;
}
