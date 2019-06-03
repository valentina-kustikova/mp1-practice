#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    int type, N, U, c = 0;
    float a = 0.0, b = 1000.0;
    char ch;
    printf("Choose the type of program (1 or 2) \n");
    scanf("%d%*c", &type);
    srand((unsigned int)time(0));
    if (type == 1) {
        N = 1000.0 / RAND_MAX * rand();
        do {
            printf("Enter a number \n");
            scanf("%d", &U);
            c++;
            if (N < U) printf("My number less \n");
            else if (N > U) printf("My number more \n");
            else printf("You are right \n");
        } while (U != N);
        printf("Number of tries %d \n", c);
    }
    else {
        printf("Imagine a number from 0 to 1000 \n");
        do {
            U = (int)((b - a) / RAND_MAX * rand() + a);
            printf("Entering a number %d. Is it right?  <  >  = \n", U);
            scanf("%c%*c", &ch);
            printf("%c", ch);
            c++;
            if (ch == '<')    b = U - 1;
            else if (ch == '>') a = U + 1;
            else if (ch == '=') printf("I`m right, I`m smart \n");
            else {
                printf("You enter the wrong character \n");
                return;
            }
            printf("Number of tries %d \n", c);
        } while (ch != '=');
    }
}