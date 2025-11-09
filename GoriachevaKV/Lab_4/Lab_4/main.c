#include <stdio.h>

int codes[5][4] = {
{1, 1, 1, 1},
{0, 1, 2, 3},
{1, 2, 3, 4},
{5, 6, 7, 8},
{9, 0, 1, 2}
};

char names[5][20] = {
"Pizza",
"Cucumber",
"Potato",
"Chocolate",
"Tea"
};

int cost[5] = { 100, 20, 50, 150, 300 };

int discount = 0.85; // 15%

int check_the_code(int* code, int code_array[]) {
	int tmp = code;
	for (int i = 3; i >= 0; i--) {
		code_array[i] = tmp % 10;
		tmp /= 10;
	}
}


int main() {
	int code;
	int code_array[4];
	while (1) {
		printf("Input a four-number code\n");
		scanf_s("%d", &code);
		check_the_code(code, code_array);
		printf("ARRAY CODE: %d %d %d %d\n\n", code_array[0], code_array[1], code_array[2], code_array[3]);
		break;
	}

	return 0;
}