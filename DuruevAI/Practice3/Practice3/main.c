#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(void) {
    int number1,number2;
    srand((unsigned int)time(0));
    number1 = 1 + rand() % 1000;
    scanf("%d", & number2);
    while (number2 != number1) {
        if ((number2 > 1000) || (number2 < 1)) {
            printf("Error\n");
            scanf("%d", &number2);
        }
        else if (number2 > number1) {
            printf("The specified number is less\n");
            scanf("%d", & number2);
        }
        else {
            printf("The specified number is greater\n");
            scanf("%d", & number2);
        }
    }
    printf("You guessed right");
    }

       
    
    
