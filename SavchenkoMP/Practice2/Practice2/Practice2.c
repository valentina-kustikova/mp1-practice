#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int r(int a, int b) {
	int n;
	n = rand() % (b - a + 1) + a;
	return n;
}

void mode1() {

	int num, n, k = 1;
	num = r(1, 1000);

	//printf("%d\n", num);
	printf("Enter the expected number:\n");
	scanf("%d", &n);
	while (n != num) {
		if (n > num)
			printf("The hidden number is LESS than the entered one\n");
		else
			printf("The hidden number is GREATER than the entered one\n");
		scanf("%d", &n);
		k++;
	}
	printf("Congratuletion! The hidden number is %d\n", num);
	printf("Number of attempts: %d\n", k);

}

void mode2() {

	int num, k = 0, n;
	int a = 1, b = 1000;
	printf("Enter the hidden number:\n");
	scanf("%d", &num);
	if (num < 1 || num > 1000) {
		printf("The hidden number must be 1 <= num <= 1000\n");
		mode2();
	}
	else {

		n = r(a, b); //2
		k++;
		printf("%d) %d\n", k, n);
		while (n != num) {
			if (n > num)
				b = n - 1;
			else
				a = n + 1;
			n = r(a, b); //2
			k++;
			printf("%d) %d\n", k, n);
		}
		printf("The program found %d in %d attempts\n", n, k);
	}

}

void main() {

	int m;
	srand((unsigned int)time(NULL));
	printf("Choose mode #1 or mode #2:\n");
	scanf("%d", &m);
	switch (m) {
	case 1: {
		mode1();
		break;
	}
	case 2: {
		mode2();
		break;
	}
	default: {
		printf("There is no such mode here\n\n");
		return main();
	}
	}

}