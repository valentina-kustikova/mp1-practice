#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 999

int main()
{
    int mode;
    do {
        printf("Enter 0 if you want gues or 1 if you want ask: \n");
        scanf("%d", &mode);
    } while ((mode != 1) && (mode != 0));
    if (mode == 0)
    {
        int m_answer = 0, kol = 0, number;
        printf("You gues\n");
        srand((unsigned int)time(0));
        number = 1+ rand() % 1000;        
        do {
            do {
                printf("Input number: \n");
                scanf("%d", &m_answer);

            } while ((m_answer > 1000) || (m_answer < 1));
            kol++;
            if (number > m_answer) printf("%d < answer\n", m_answer);
            else if (number < m_answer) printf("%d > answer\n", m_answer);
        } while (m_answer != number);
        printf("Right answer == %d, number of attempts == %d", number, kol);
        return 0;
    }
    if (mode == 1)
    {
        int answer, min = 0, max = 1000, bot_ans = 0, kol = 0;
        char znak;
        printf("You ask\n");        
        do {
            printf("Input answer: \n ");
            scanf("%d", &answer);
            printf("%d \n", answer);
        } while ((answer < 1) || (answer > 1000));        
        
        do {
            printf("%d\n", bot_ans = min + ((max-min) / 2));  
            kol++;
            scanf("%*c%c", &znak);
            if (znak == '<')
            {
                max = bot_ans;
            }
            else if (znak == '>')
            {
                min = bot_ans;
            }
        } while (znak != '=');
        printf("Answer = %d, number of attempts == %d \n", bot_ans, kol);
        return 0;
    }
}