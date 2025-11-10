#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define DEBUG

#define SALES_REGISTER_FRAME "\
|---------------------------|\n\
|     Ёлектронна€ касса     |\n\
|---------------------------|\n\n"

int main() {
	setlocale(LC_ALL, "rus");
	printf(SALES_REGISTER_FRAME);

	return 0;
}