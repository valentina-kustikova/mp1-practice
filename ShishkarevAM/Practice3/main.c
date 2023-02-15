#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define n 5
int main() {
    int ox=0, cow=0, i, j, size=0, zifr, tmp, chisl, ch[n], ch1[n];
    srand((unsigned int)time(NULL));
    printf("Write a number of zifr\n");
    do {
        scanf("%d", &size);
    } while ((size<2)||(size>5));
    ch[0]=1+(rand()%9);
    for (i=1; i<size; i++){
        tmp=0;
        while(tmp==0) {
            zifr = rand() % 10;
            for (j = 0; j < i; j++) {
                if (ch[j] == zifr) {
                    tmp = 1;
                    break;
                }
            }
            if (tmp == 0) {
                ch[i] = zifr;
                break;
            }
        }
    }
    printf("Write a number with %d zifr\n", size);
    while (ox!=size){
        scanf("%d",&chisl);
        tmp=0;
        ox=0;
        cow=0;
        for (i=size-1; i>=0; i--){
            ch1[i]=chisl%10;
            chisl/=10;
        }
        for (i=1; i<size; i++) {
            for (j = 0; j < i; j++) {
                if (ch1[i] == ch1[j]) {
                    tmp++;
                    ox = 0;
                    break;
                }
            }
        }
        if (tmp>0||chisl != 0 || ch1[0] == 0) {
            printf("Wrong number\n");
            ox = 0;
        } else {
            for (i = 0; i < size; i++) {
                for (j = 0; j < size; j++) {
                    if (ch[i] == ch1[j]) {
                        if (i == j) {
                            ox++;
                        } else {
                            cow++;
                        }
                    }
                }
            }
            printf("Number of cow = %d, number of ox = %d\n", cow, ox);
        }
    }
    printf("Correct! It's number: ");
    for (i=0; i<size; i++){
        printf("%d",ch[i]);
    }
    return 0;
}
