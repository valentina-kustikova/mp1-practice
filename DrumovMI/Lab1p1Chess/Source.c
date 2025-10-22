#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

#define LINE 512

int main() {
    char x1, x2;
    int y1, y2;
    bool king, queen, rook, bishop, knight;
    bool can = false, flag = true;
    char line[LINE], ch;

    setlocale(LC_ALL, "ru");
    setlocale(LC_NUMERIC, "C");
    system("chcp 1251");

    do {
        printf("Введите клетки k1 и k2: ");
        scanf("%c%d %c%d", &x1, &y1, &x2, &y2);
    } while (tolower(x1) < 'a' || 'h' < tolower(x1) ||
        tolower(x2) < 'a' || 'h' < tolower(x2) ||
        y1 < 1 || 8 < y1 || y2 < 1 || 8 < y2);
    
    x1 = tolower(x1) - 'a' + 1;
    x2 = tolower(x2) - 'a' + 1;

    king = abs(x1 - x2) <= 1 &&
        abs(y1 - y2) <= 1 &&
        !(x1 == x2 && y1 == y2);
    rook = (x1 == x2 || y1 == y2) &&
        !(x1 == x2 && y1 == y2);
    bishop = (abs(x1 - x2) == abs(y1 - y2)) &&
        !(x1 == x2 && y1 == y2);
    queen = rook || bishop;
    knight = (abs(x1 - x2) == 1 && abs(y1 - y2) == 2) ||
        (abs(x1 - x2) == 2 && abs(y1 - y2) == 1);
    getchar();

    while (flag) {
        printf("Введите название фигуры: ");
        scanf("%511s", line);
        if (!strncmp(line, "король", 6)) {
            can = king;
            flag = 0;
        }
        else if (!strncmp(line, "ферзь", 5)) {
            can = queen;
            flag = 0;
        }
        else if (!strncmp(line, "ладья", 5)) {
            can = rook;
            flag = 0;
        }
        else if (!strncmp(line, "слон", 4)) {
            can = bishop;
            flag = 0;
        }
        else if (!strncmp(line, "конь", 4)) {
            can = knight;
            flag = 0;
        }
    }

    if (can)
        printf("Выбранная фигура может перейти с k1 на k2 за один ход.\n");
    else {
        printf("Выбранная фигура не может перейти с k1 на k2 за один ход.\n"
            "Список фигур, способных перейти с k1 на k2 за один ход:\n");
        if (king)
            printf("Король\n");
        if (queen)
            printf("Ферзь\n");
        if (rook)
            printf("Ладья\n");
        if (bishop)
            printf("Слон\n");
        if (knight)
            printf("Конь\n");
    }
    system("chcp 866");
    return 0;
}