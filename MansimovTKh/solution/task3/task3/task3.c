#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int n;
	
	printf("Input number\'s length: "); scanf_s("%d", &n);
	while (n < 2 || n>5) {
		printf("Wrong length! Input number from 2-5: "); scanf_s("%d", &n);
	}
	return 0;
}

