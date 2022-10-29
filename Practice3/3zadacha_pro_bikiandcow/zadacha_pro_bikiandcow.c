#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void  main() {
    start7:
    srand(time(NULL));
    int i, n, k, cows = 0, bulls = 0, try = 1;//i для цикла, n - колво цифр
    


    //Запрос количества загаданных цифр у пользователя
    printf("\t Welcome to the game <Bulls and Cows>\n\tEnter the number of digits (you should enter number from 2 to 5)\n");
    do{
        scanf("\t%d", &n);
    } while ((n < 2) || (n > 5));

    int secret[n];  //для хранения загаданных чисел
    
    //Генерация неповторяющихся цифр
    for(i=0; i < n; i++){
                secret[i] = rand()%9;
                for(k=0; k < i; k++){
                    if(secret[i] == secret[k]){
                       do{
                        secret[i] = rand()%9;
                       }
                       while(secret[i] == secret[k]); 
                    }
                }
            }

    //Вывод значений
    /*for(i=0; i < n; i++) printf("%d\t", secret[i]);
    getchar();*/

    //Игрок пытается отгадать число
    int answer[n];  //для хранения числа, которое предполагает игрок
    ent40:
    printf("\nEnter the expected number (one digit at a time, numbers cannot be repeated)\n");
    for(i=0; i<n; i++){

            scanf("%d", &answer[i]);

            if((answer[i]<0)||(answer[i]>9)){

                printf("wrong enter, try again");
                goto ent40;
            }
            int k;
            for(k=0; k < i; k++){
                if(answer[i]==answer[k]){
                    printf("wrong enter, try again");
                    goto ent40;
                }
            }    
        }



    //Вывод числа пользователя    
    printf("You guessed that number\n");        
    for(i=0; i<n; i++) printf("%d\t", answer[i]);
    printf("\n");
    


    //Проверка на наличие коров
    printf("im checking a cows...\n");
    for(i=0; i < n; i++){
        for(k=0; k < n; k++){
            if(secret[i]==answer[k]){
                cows++;
            }
        }
    }
    printf("number of cows = %d\n", cows);



    //Проверка на наличие быков
    printf("im checking a bulls...\n");    
    for(i=0; i < n; i++){
        if(secret[i]==answer[i]){
            bulls++;
        }
    }
    printf("number of bulls = %d\n", bulls);

    //Проверка окончания игры
    if (bulls==n){
        printf("\n\nYou win!\nHow many attempts have there been? - %d\n", try);
    }else{
        bulls = 0;
        cows = 0;
        try++;
        goto ent40;
    }

    //Запрос на повторную игру
    char request;
    printf("Do you want to play again (y/n)? ^-^ \t");
    do{
        request=getchar();

    }while((request!=121) && (request!=110));
    
    switch(request){
        case 121:
            printf("Lets play!\n\n\n");
            goto start7;
            break; 
        case 110:
            printf("Okey, see you space cowboy\n");
            break;
    }
     

    system("pause");
}