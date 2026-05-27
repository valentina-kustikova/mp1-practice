#include <stdio.h>
#define N 5

void processpokupki(char shtrix[][4], int tsena[], int skidka[], char nazvan[][7], int kol[]);
void print(int tsena[], int skidka[], char nazvan[][7], int kol[]);

int main() {
    int pokup, i, j, k, match, otvet, obshtsena = 0;
    float obshskidki = 0.0;
    char shtrixpok[N];

    char shtrix[N][4] = { "1001", "2002", "3003", "4004" };
    int tsena[N] = { 89, 35, 50, 149 };
    int skidka[N] = { 10, 5, 15, 20 };
    char nazvan[N][7] = { "Moloko", "Voda", "Sok", "Chipsi" };
    int kol[N] = { 0 };

    processpokupki(shtrix, tsena, skidka, nazvan, kol);

    print(tsena, skidka, nazvan, kol);

    return 0;
}

void processpokupki(char shtrix[][4], int tsena[], int skidka[], char nazvan[][7], int kol[]) {
    char shtrixpok[5];
    int match, otvet, i;

    do {
        printf("Vvedite shtrix kod, esli pokupki zakonchilis, vvedite 0\n");
        scanf_s("%s", &shtrixpok, 5);

        if (shtrixpok[0] == '0' && shtrixpok[1] == '\0') {
            break;
        }

        match = 0;
        for (i = 0; i < N; i++) {
            if (shtrixpok[0] == shtrix[i][0] &&
                shtrixpok[1] == shtrix[i][1] &&
                shtrixpok[2] == shtrix[i][2] &&
                shtrixpok[3] == shtrix[i][3]) {

                printf("Shtrix kod - %s, Nazvanie - %s, Tsena - %d, Skidka - %d%%\n",
                    shtrixpok, nazvan[i], tsena[i], skidka[i]);
                match = 1;
                printf("Berete tovar? 1 - da, 0 - net\n");
                scanf_s("%d", &otvet);
                if (otvet == 1) {
                    kol[i] += 1;
                }
                break;
            }
        }

    } while (1);

    return 0;
}

void print(int tsena[], int skidka[], char nazvan[][7], int kol[]) {
    int obshtsena = 0;
    float obshskidki = 0.0;

    printf("Check:\n");
    for (int i = 0; i < N; i++) {
        if (kol[i] != 0) {
            printf("Nazvanie - %s, tsena - %d, kolichstvo - %d, obshaya tsena - %d\n",
                nazvan[i], tsena[i], kol[i], kol[i] * tsena[i]);
            obshtsena += kol[i] * tsena[i];
            obshskidki += kol[i] * (tsena[i] * (skidka[i] / 100.0));
        }
    }
    printf("\nObshaya tsena bez skidki - %d, Summarnaya skidka - %f, Itogovaya summa - %f\n",
        obshtsena, obshskidki, obshtsena - obshskidki);
}