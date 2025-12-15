#include <stdio.h>
#include <time.h>

int main() {
    int n, level, k, choice;
    char help;
    srand((unsigned int)time(0));
    printf("choose game level: enter 1 or 2\n");
    scanf_s("%d", &level);

    if (level == 1) {
        n = rand() % 1000 + 1;
        //printf("%d\n", n);
        k = 0;
        printf("try to guess the number\n");
        while (1) {
            scanf_s("%d", &choice);
            k += 1;
            if (choice == n) {
                printf("right, amount of attempt: %d", k);
                return 0;
            }
            else if (choice > n) {
                printf("< \n");
            }
            else if (choice < n) {
                printf("> \n");
            }
        }
    }
    if (level == 2) {
        printf("enter a number\n");
        scanf_s("%d", &n);
        if (n > 1000) {
            printf("incorrect number\n");
            return 0;
        }
        k = 0;
        int minimum = 1, maximum = 1000;
        while (1) {
            choice = (maximum + minimum) / 2;
            printf("%d\n", choice);
            k += 1;
            scanf_s(" %c", &help);
            if (help == '=') {
                printf("amount of attempt: %d", k);
                return 0;
            }
            else if (help == '>') {
                minimum = choice + 1;
            }
            else if (help == '<') {
                maximum = choice - 1;
            }
            else {
                printf("incorrect char\n");
                k -= 1;
            }
        }
    }
    else {
        printf("incorrect level\n");
        return 0;
    }
}