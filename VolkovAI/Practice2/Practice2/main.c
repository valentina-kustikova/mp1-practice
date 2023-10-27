#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int num = 0, current = 0, mode, border1 = 1, border2 = 1000, counter = 1;
    char sign;
    printf ("The program has two modes: \n1. The program makes a number; \n2. The user makes a number. \nPlease, select the mode [1/2]: ");
    scanf ("%d", &mode);
    if (mode == 1) {
        srand ((unsigned int) time (0));
        num = 1 + rand() % 1000;
        printf ("%d\n", num); // 
        while (current != num) {
            printf ("Please, input your number: ");
            scanf ("%d", &current);
            if (current > num) {
                printf("The hidden number is smaller. ");
            }
            else if (current < num) {
                printf("The hidden number is bigger. ");
            }
            else {
                printf("You guessed it! Number of trying: %d", counter);
            }
            counter++;
        }
    }
    if (mode == 2) {
        printf("Please, input your number: ");
        scanf("%d", &num);
        srand((unsigned int)time(0));
        current = rand() % 1000;
        while (1) {
            printf("I think it's: %d. If yes, then input =. If not, input > or <. ", current);
            while ((sign = getchar()) != '\n' && sign != EOF) {
                continue;
            }
            sign = getchar();
            if (sign == '>') {
                border1 = current + 1;
            }
            else if (sign == '<') {
                border2 = current - 1;
            }
            else if (sign == '=') {
                printf("I won! Number of trying: %d.", counter);
                break;
            }
            current = border1 + rand() % (border2 - border1 + 1);
            counter++;
        }
    }
    return 0;
}