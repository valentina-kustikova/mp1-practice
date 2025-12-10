#include <stdio.h>
#include <string.h>
#define brange 4
#define crange 100

int bd(char code[5], char tp[][30]);

void printer(char tp[3][30]) {
	printf("code %s name: %s cost: %s", tp[0], tp[1], tp[2]);
}


int main() {
	char tp[3][30];
	char cod = "9999";
	int sum = 0;
	while (1 == 1) {
		char inp[5];
		fgets(inp, 4, stdin);
		if (strcmp(inp, "end") ==0) {
			break;
		}
		else {
			sum += bd(inp, tp);
			printer(tp);
		}
	}
	printf("total: %d", sum);
}

int bd(char code[5], char tp[][30]) {
	char codes[brange][4] = { "0001", "0002", "0003", "0004" };
	char names[brange][29] = { "milk", "bread", "slave", "salt" };
	char costs[brange][29] = { "100", "30", "10", "20" };
	int icosts[brange] = { 100, 30, 10, 20 };
	int i, k;
	for (i = 0; i < brange; i++) {
		if (strcmp(code, codes[i]) == 0);
		k = i;
	}
	strcpy(tp[0], codes[k]);
	strcpy(tp[1], names[k]);
	strcpy(tp[2], costs[k]);
	return icosts[k];
}