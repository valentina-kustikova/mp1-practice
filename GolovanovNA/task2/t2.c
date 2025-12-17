#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int r;
	scanf_s("%d", &r);
	if (r == 1) {
		int x = 1 + rand() % (1000);
		int dog = 0;
		int c = 0;
		do {
			scanf_s("%d", &dog);
			c += 1;
			if (dog > x) {
				printf("menshe");
			}
			if (dog < x) {
				printf("bolshe");
			}
		} while (dog != x);
		printf("ugadal za %d popitok!", c);
	}
	else {
		int dog;
		int c = 0;
		char ans = 'n';
		int low = 0;
		int up = 1001;
		while (ans != '=') {
			int try = low + rand() % (up - low + 1);
			printf("%d", try);
			scanf_s(" %c", &ans);
			c += 1;
			if (ans == '>') {
				low = try;
			}
			if (ans == '<') {
				up = try;
			};
		}
		printf("ura im ugadal za %d popitok", c);
	}
	return 0;
}