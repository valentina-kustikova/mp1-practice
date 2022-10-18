#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //Начало программы, ввод переменных.
    srand(time(NULL));
    int gamemode;
    int try = 0, x = 0, y = 1000;
    int answer, guess, result;
    char a;
    printf("Hello, user!\n");
    //Проверка ввода режима.
    do{
        printf("Choose gamemode(1 - bot guess the number, 2 - user guess the number)\n");
        scanf("%d", &gamemode);
        getchar();
    }while((gamemode!=1)&&(gamemode!=2));
    
    

    //Даем пользователю выбор игрового режима.
    switch(gamemode){
        case 1: 
            //Выбор первого режима игры (компьютер загадывает число).
            result=0;
            answer=rand()%1000;
            printf("Enter the value\n");
            //Система do-while.
            do {
              scanf("%d", &guess);
                if(guess==answer){
                    printf("You found the number!!!\n");
                    result=1;
                    break;
                }else if(guess<answer){
                    printf("Your value less of answer. Try again!");
                }else{
                    printf("Your value more of answer. Try again!");
                }
                try++;


            



                }
            while(result!=1);
            break;

           
        case 2:
            //Выбор второго режима игры (пользователь загадывает число).
            result=0;
            //Пользователь загадывает число.
            do{
                printf("Enter the value, which you want to guess");
                scanf("%d", &answer);
                getchar();
                }while((answer<0)||(answer>1000));
            //Компьютер пытается его отгадать.
            guess=rand()%1000;
            do{
                printf("Its %d? (y, >, <)\n", guess);
                scanf("%c", &a);
                getchar();
                switch(a){
                    case 'y':
                        printf("YEEEAH, I FOUND VALUE\n");
                        result=1;
                        break;
                    case '>': 
                        printf("Okey, i will try again :( ");
                        y=guess;
                        guess=x+rand()%(y-x+1);
                    

                        break;
                    case '<':
                        printf("Okey, i will try again :( ");
                        x=guess;
                        guess=x+rand()%(y-x+1);
                        

                        break;



                }

                try++;
            }while(result!=1);


            break;






    }
    printf("number of attempts is %d\nDont forget me!!! Im your friend!!! <3", try);
    system("pause");
    return 0;
    }













