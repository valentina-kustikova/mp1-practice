#include<stdio.h>
#include<locale.h>
#include<time.h>



int main() {
    int flag, n, count,ans,a,b,mid;
    char ret;
    setlocale(LC_ALL, "Rus");
    printf("Выберите режим игры. 1 - Программа загадывает число или  2 - Программа угадывает число: ");
    scanf("%d",&flag);
    //printf("%d",flag);
    if (flag == 1) {
        srand((unsigned int)time(0));
        n = 1 + rand() % 1000;
        //printf("%d", n);
        ans = 0;
        count = 0;
        do{
            printf("Введите число:");
            scanf("%d", &ans);
            if (ans < n)
                printf("Число больше \n");
            if (ans > n)
                printf("Число меньше \n");
            count++;
        }while (ans != n);
        printf("Вы победили! Загаданное число: %d. Количество попыток: %d",n,count);
    }
    if (flag == 2) {
        printf("Загадайте число в диапазоне 1-1000: ");
        scanf("%d", &n);
        count = 0;
        a = 0;
        b = 1000;
        ans = (a + b) / 2;
        do{
            printf("Ваше число %d?", ans);
            scanf("%*c%c", &ret);
            if (ret == '>') {
                a = ans + 1;
                ans = (a + b) / 2;
            }
            if (ret == '<') {
                b = ans - 1;
                ans = (a + b) / 2; 
            }
            count++;
        } while (ret != '=');
        printf("Ваше число: %d. Количество попыток: %d", ans, count);
    }
    return 0;
}