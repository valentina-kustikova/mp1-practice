#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    char ind;
    printf("Take the letter (A or B) \n");
    do{
        scanf("%c", &ind);
    } while ((ind!='A') && (ind!='B'));

    if (ind=='A'){
        int i=0;
        int n, comm;
        srand(time(NULL));
        n=rand()%1000;
        printf("Write a number\n");
        do {
            i++;
            scanf("%d",&comm);
            if (comm==n) {
                printf("Correct\n");
                printf("Number of attempts: %d", i);
                printf("\n");
            }
            if (comm<n) {
                printf("More\n");
                printf("Write a number\n");
            }
            if (comm>n) {
                printf("Less\n");
                printf("Write a number\n");
            }
        } while (comm!=n);
    }
    else {
        int znach=0, init, mini=1, maxi=1000, count=0;
        char com;
        printf("Rules: \n");
        printf("More==M, Less==L, Correct==C\n");
        printf("Pick a number\n");

        do {
            scanf("%d",&init);
        } while ((init<0)||(init>1000));
        do {
            count++;
            znach=(mini+maxi)/2;
            printf("It's %d", znach);
            printf("?\n");

            do {
                scanf("%c",&com);
            } while ((com != 'M')&&(com != 'L')&&(com != 'C'));
            if (com == 'M'){
                mini=znach;
            }
            else if (com == 'L'){
                maxi=znach;
            }
            else {
                printf("It's a number %d", znach);
                printf("!\n");
                printf("Number of attempts %d", count);
                return 0;
            }
        } while(1);

    }
    return 0;
}
