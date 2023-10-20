#include <stdio.h>
#include <stdlib.h>
#include <time.h>







int main() {
    int gamemode;
    int number;
    int l = 0, r = 1000;// левая, правая грани
    int c = 0;   // центр (середина)
    int gss; // предположение игрока
    // (для режима, когда игрок угадывает число)

    int gg = 0;
    int c_attempts = 0; // счётчик попыток
    srand((unsigned int)time(0));
    
    printf("Welcome to make/guess number from 0 to 999 (999 included)!\n");
    printf("There are 2 modes\n 1: you guessing what my number is\n");
    printf("2: Im guessing what your number is\n");
    printf("(if you input whatever you want, you'll gussing!)\n");
    printf("So, what you choose?\n (input 1/2 for gamemode)\n");
    scanf("%d", &gamemode);
    if (gamemode == 2) {
        printf("Alright, i'll guess your nubmer\n");
        printf("Type it for your convenience\n i wont use it\n");
        scanf("%d",  &number);
        printf("Ok, there we go\n");
        
        while (!gg) {
            char znak;
            c = (l+r)/ 2;
            printf("Is it %d?\n", c);
            scanf("%c", &znak);
            while (getchar() != '\n') {
                ;
            }
            
            if (znak == '<') {
                r = c - 1;
                c_attempts++;
                
            }
            else if (znak == '>') {
                l = c + 1;
                c_attempts++;
                
            }
            else {
                gg = 1;
                c_attempts++;
                
                
            }
            
        }
        
        printf("Woah! I did it! For only  %d  attempts!\n", c_attempts);
        printf("Honestly, it was hard! Good job!\n");
        printf("See you later! I always waiting you to play with\n");
        
    }
    else {
        printf("Ok, im guessing number!\n");
        number = rand() % 1000;
        printf("What do you think it is?\n");
        scanf("%d", &gss);
        c_attempts++;
        while (gss != number) {
            
            if (gss < number) {
                printf("No,number its     more\n");
            }
            else if (gss > number) {
                printf("No, number its    less\n");
            }
            
            scanf("%d", &gss);
            c_attempts++;

        }
        printf("Woah! You did it! For only  %d  attempts!\n", c_attempts);
        printf("Congratulations!");
        

    }
}


