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
    enum {NONE, KING, QUEEN, ROOK, BISHOP, KNIGHT} type = NONE;
	char x1, y1, x2, y2;
    bool win = false;

	setlocale(LC_ALL, "ru");
	setlocale(LC_NUMERIC, "C");

	do {
		printf("Введите клетки k1 и k2: ");
		fgets(line, LINE, stdin);
		sscanf_s(line, "%c%d %c%d", &x1, &y1, &x2, &y2);
	} while ('a' <= tolower(x1) && tolower(x1) <= 'h' &&
             'a' <= tolower(x2) && tolower(x2) <= 'h' &&
              1 <= y1 && y1 <= 8 &&
              1 <= y2 && y2 <= 8);

    while (type == NONE) {
        printf("Введите фигуру (король, ферзь, ладья, слон, конь): ");
        fgets(line, LINE, stdin);
        if (!strcmp(line, "король")) {
            type = KING;
        }
        else if (!strcmp(line, "ферзь")) {
            type = QUEEN;
        }
        else if (!strcmp(line, "ладья")) {
            type = ROOK;
        }
        else if (!strcmp(line, "слон")) {
            type = BISHOP;
        }
        else if (!strcmp(line, "конь")) {
            type = KNIGHT;
        }
    }

    switch (type) {
    case KING:
        if (king(x1, y1, x2, y2))
            win = true;
        break;
    case QUEEN:
        if (queen(x1, y1, x2, y2))
            win = true;
        break;
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