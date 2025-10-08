#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>

#define LINE 512

bool king(char x1, char y1, char x2, char y2);
bool queen(char x1, char y1, char x2, char y2);
bool rook(char x1, char y1, char x2, char y2);
bool bishop(char x1, char y1, char x2, char y2);
bool knight(char x1, char y1, char x2, char y2);

int main() {
    char line[LINE];
    enum { NONE, KING, QUEEN, ROOK, BISHOP, KNIGHT } type = NONE;
    char x1, y1, x2, y2;
    bool win = false;
    bool ans_king, ans_queen, ans_rook, ans_bishop, ans_knight;

    setlocale(LC_ALL, "ru");

    do {
        printf("Введите клетки k1 и k2: ");
        fgets(line, LINE, stdin);
        sscanf_s(line, "%c%d %c%d", &x1, &y1, &x2, &y2);
    } while ('a' <= tolower(x1) && tolower(x1) <= 'h' &&
        'a' <= tolower(x2) && tolower(x2) <= 'h' &&
        1 <= y1 && y1 <= 8 &&
        1 <= y2 && y2 <= 8);

    x1 = tolower(x1) - 'a' + 1;
    x2 = tolower(x2) - 'a' + 1;

    while (type == NONE) {
        printf("Введите фигуру (king, queen, rook, bishop, knight): ");
        fgets(line, LINE, stdin);
        if (!strncmp(line, "king", 4)) {
            type = KING;
        }
        else if (!strncmp(line, "queen", 5)) {
            type = QUEEN;
        }
        else if (!strncmp(line, "rook", 4)) {
            type = ROOK;
        }
        else if (!strncmp(line, "bishop", 6)) {
            type = BISHOP;
        }
        else if (!strncmp(line, "knight", 6)) {
            type = KNIGHT;
        }
    }

    ans_king = king(x1, y1, x2, y2);
    ans_queen = queen(x1, y1, x2, y2);
    ans_rook = rook(x1, y1, x2, y2);
    ans_bishop = bishop(x1, y1, x2, y2);
    ans_knight = knight(x1, y1, x2, y2);

    switch (type) {
    case KING:
        if (ans_king)
            win = true;
        break;
    case QUEEN:
        if (ans_queen)
            win = true;
        break;
    case ROOK:
        if (ans_rook)
            win = true;
        break;
    case BISHOP:
        if (ans_bishop)
            win = true;
        break;
    case KNIGHT:
        if (ans_knight)
            win = true;
        break;
    }

    if (win) {
        printf("Можно переместиться за один ход.");
    }
    else {
        if (ans_king)
            printf("Король\n");
        if (ans_queen)
            printf("Ферзь\n");
        if (ans_rook)
            printf("Ладья\n");
        if (ans_bishop)
            printf("Слон\n");
        if (ans_knight)
            printf("Конь\n");
        if (!(ans_king || ans_queen || ans_rook || ans_bishop || ans_knight))
            printf("Ни одна из фигур не может переместиться за один ход.");
    }

    return 0;
}

bool king(char x1, char y1,
    char x2, char y2) {
    return abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1 && !(x1 == x2 && y1 == y2);
}

bool queen(char x1, char y1,
    char x2, char y2) {
    return (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) && !(x1 == x2 && y1 == y2);
}

bool rook(char x1, char y1,
    char x2, char y2) {
    return (x1 == x2 || y1 == y2) && !(x1 == x2 && y1 == y2);
}

bool bishop(char x1, char y1,
    char x2, char y2) {
    return (abs(x1 - x2) == abs(y1 - y2)) && !(x1 == x2 && y1 == y2);
}

bool knight(char x1, char y1,
    char x2, char y2) {
    return (abs(x1 - x2) == 1 && abs(y1 - y2) == 2) || (abs(x1 - x2) == 2 && abs(y1 - y2) == 1);
}