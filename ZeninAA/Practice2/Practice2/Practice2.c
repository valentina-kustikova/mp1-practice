#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RAND_MAX
int main()
{
    int mod, a, A, attempt1 = 0;
    int number;
    int B = 0, attempt2 = 0, left = 0, right = 1000;
    char dis;
    srand((unsigned int)time(0));
    printf("Hello, welcome to the game 'Guess the number'!\n");
    printf("Write the mode, that you want to play (1st or 2nd)\n");
    do {
        scanf("%d", &mod);
    } while ((mod != 1) && (mod != 2));
    if (mod == 1) {
        printf("You have chosen mode 1\n");
        printf("I have chosen a number from 1 to 999, you have to guess my number\n");
        a = 1 + rand() % 1000;
        printf("Input guesses\n");
        do {
            scanf("%d", &A);
            if (A < a)
            {
                printf("Your number is lower, than my number\n");
            }
            if (A > a)
            {
                printf("Your number is higher, than my number\n");
            }
            attempt1++;
        } while (A != a);
        printf("You have guessed the number\nThe number of your attempts is %d", attempt1);
    }
    else {
        printf("You have chosen mode 2\n");
        printf("You should choose the number from 1 to 999, I have to guess your number\n");
        printf("Input your number b\n");
        do {
            scanf("%d", &number);
        } while ((number < 1) || (number > 999));
        printf("I give you my guesses\n"); 
        B = (left + right) / 2; 
        do {
            printf("Your number is %d\n", B); 
            printf("Input >,< or =, while I give you number\n"); 
            scanf("%*c%c", &dis);  
            if (dis == '>') { 
                left = B + 1; 
                B = (left + right) / 2; 
            }
            if (dis == '<') { 
                right = B - 1;
                B = (left + right) / 2;
            }
            attempt2++;
        } while (dis != '=');
        printf("I have guessed the number\nThe number of my attempts is %d", attempt2);
        
    }
    return 0;
}
   



   
