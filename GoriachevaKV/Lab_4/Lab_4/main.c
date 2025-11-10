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

int discounts[5] = { 5, 3, 10, 20, 50 };

void check_the_code(int* code, int code_array[]) {
	int tmp = code;
	for (int i = 3; i >= 0; i--) {
		code_array[i] = tmp % 10;
		tmp /= 10;
	}
}

int find_code(int code_array[], int codes[]) {
	int idx = -1, flag = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (code_array[j] != codes[i]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			idx = i;
			break;
		}
	}
	return idx;
}


int main() {
	int code, idx = -1;
	int code_array[4];
	while (1) {
		printf("Input a four-number code\n");
		scanf_s("%d", &code);
		check_the_code(code, code_array);
		//printf("ARRAY CODE: %d %d %d %d\n\n", code_array[0], code_array[1], code_array[2], code_array[3]);
		idx = find_code(code_array, codes);
		printf("Index = %d\n\n", idx);
		// idx = 2 for example
		idx = 2;
		printf("INFORMATION\n");
		printf("Name: %s    Cost: %d    Discount: %d percentages\n", names[idx], cost[idx], discounts[idx]);


		break;
	}

	return 0;
}