#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include <stdio.h> 
#define N 5

void skd(int s[], int n) 
{
    int i;
    for (i = 0; i<n; i++) 
    {
        s[i] = rand() % 50 + 1;
    }
}


void schit(int n, int *k, char shtrih[][4]) 
{
    int i, kol, f;
    f = 1;
    char shtrihkod[5];
    while (f == 1) 
    {
        printf("Для закрытия чека введите 0\n");
        scanf("%s", &(shtrihkod));
        if (shtrihkod == 0) 
        {
            f = 0;
        }
        else 
        {
            while (strlen(shtrihkod) != 0) 
            {
                printf("Некорректный ввод\n");
                scanf("%s", &(shtrihkod));
            }
            for (i = 0; i < n; i++) 
            {
                if ((strncmp(shtrihkod, shtrih[i])) == 0) 
                {
                    printf("Введите кол-во\n");
                    scanf("%d", &kol);
                    k[i] += kol;
                }
            }

        }
    }
}

void chek(char name[][14], char shtrih[][4], int c[], int k[], int sk[], int n) 
{
    int t = 0, i, j;
    for (i = 0; i < n; i++) 
    {
        if (k[i] != 0) 
        {
            for (j = 0; j < 4; j++)
                printf("штрихкод:%s ", shtrih[i][j]);
            for (j = 0; j < 16; j++)
                printf("%s", name[i][j]);
            printf("ЦЕНА:%dруб - КОЛ-ВО:%d - СТОИМОСТЬ:%dруб - СКИДКА:%d%%\n", c[i], k[i], (k[i] * c[i]), sk[i]);
        }
    }
}

int pechat(int c[], int k[], int sk[], int n) 
{
    int i;
    float sos = 0, bez = 0, skid;
    for (i = 0; i<n; i++) 
    {
        if (k[i] != 0) 
        {
            bez += k[i] * c[i];
            sos += k[i] * c[i] * (1 - (0.01 * sk[i]));
        }
    }
    skid = 100 - sos / bez * 100;
    printf("Итог:%.0fруб   Скидка:%.0f%%   К оплате:%.0fруб \n", bez, skid, so);
}

void main() {
    char shtrih[N][4] = { "0001","0002","0003","0004","0005" };
    char namy[N][14] = { "Молоко","Колбаса","Сыр","Чай","Конфеты" };
    int cena[N] = { 200,70,150,25,37 };
    int kol[N] = { 0 };
    int skidka[N] = { 0 };
    int i;
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    skd(skidka, N);
    schit(N, kol, shtrih);
    for (i = 0; i<N; i++) {
        printf("%d\n", kol[i]);
    }
    chek(namy, shtrih, cena, kol, skidka, N);
    pechat(cena, kol, skidka, N);

}