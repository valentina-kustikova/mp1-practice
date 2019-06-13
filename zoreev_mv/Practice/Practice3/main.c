#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL, "Russian");
    srand((unsigned int) time(0));
    int mode, input, answer, i=0, dif,b1,b2;
    char out;

    do {
        printf("Select game mode 1 or 2\n");
        scanf("%d",&mode);
    } while ((mode < 1) || (mode > 2));

    //Режим 1

    if (mode == 1) {
        
        input = rand() % 1000 + 1;

        while (answer != input) {

            i++;
            
            while (1) {
                printf("Input number ");
                scanf("%d", &answer);
            } while ((answer < 1) || (answer > 1000));

            if (answer < input)
                printf("Введённое меньше\n\n");
            if (answer > input)
                printf("Введённое больше\n\n");
            if (answer == input) {
                printf("Вы угадали за %d попыток", i);
                return;
            }
        }
    }

    //Режим 2

    if (mode == 2) {

        do {
            printf("Input number ");
            scanf("%d", &input);
        } while ((input < 1) || (input > 1000));

        b1 = 0; b2 = 1001;

        do {

            i++;

            do {
                printf("Count %d ... then hidden ", (b2 - b1) / 2 +b1);
                scanf("%*c%c", &out);
            } while ((out != '>') && (out != '<') && (out != '='));

            if (out == '>') b2 = (b2-b1) / 2 +b1 ;
            if (out == '<') b1 = (b2-b1) / 2 +b1 ;
        } while (out != '=');
        printf("Computer win at %d step\n", i);
    }
}
