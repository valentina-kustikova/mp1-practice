#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>

#define LINE 512

int king(char x1, char y1,
         char x2, char y2) {
    return abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1 && !(x1 == x2 && y1 == y2);
}

int queen(char x1, char y1,
          char x2, char y2) {
    return (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) && !(x1 == x2 && y1 == y2);
}

int rook(char x1, char y1,
         char x2, char y2) {
    return (x1 == x2 || y1 == y2) && !(x1 == x2 && y1 == y2);
}

int bishop(char x1, char y1,
           char x2, char y2) {
    return (abs(x1 - x2) == abs(y1 - y2)) && !(x1 == x2 && y1 == y2);
}

int knight(char x1, char y1,
           char x2, char y2) {
    return (abs(x1 - x2) == 1 && abs(y1 - y2) == 2) || (abs(x1 - x2) == 2 && abs(y1 - y2) == 1);
}

int main() {
	char x1, y1, x2, y2;

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
	return 0;
}