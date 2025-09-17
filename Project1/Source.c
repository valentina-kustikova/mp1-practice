#include <stdio.h>
#include <stdlib.h>

#define LEN 20

int main() {
	int a, b;
	char line[LEN];
	fgets(line, LEN, stdin);
	a = atoi(line);
	fgets(line, LEN, stdin);
	b = atoi(line);
	//sscanf_s(line, "%d%d", &a, &b);
	printf("S=%d", a + b);
	return 0;
}