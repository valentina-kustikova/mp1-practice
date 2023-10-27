#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int mode, num, count, pop, a = 0, b = 1000;
    char znak;
    printf("enter game mode 1 or 2: ");
    scanf("%d", &mode);
    if (mode == 1){
        srand((unsigned int)time(0));
        num = rand() % 1000;
        count = 0;
        pop = 0;
        do{
            printf("guess number: ");
            scanf("%d", &pop);
            if (pop > num)
                printf("smaller\n");
            if (pop < num)
                printf("bigger\n");
            count++;
        } while (pop != num);
        if (pop == num)
            printf("You win!!!\n");
        printf("Number of attempts: %d ", count);
    }
    if (mode == 2){
        printf("Input number 1-1000: ");
        scanf("%d", &num);
        srand((unsigned int)time(0));
        count = 0;
        do{
            pop = a + rand() % (b-a);
            printf("This is your number? %d", pop);
            printf("\nWrite >,<,=: ");
            scanf("%*c%c", &znak);
            if (znak == '>')
                a = pop + 1;
            if (znak == '<')
                b = pop-1;
            count++;
        } while (znak != '=');
        if (znak == '=')
            printf("I win!!!\n");
        printf("Number of attempts: %d ", count);
    }
    return 0;
}