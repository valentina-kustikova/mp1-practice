#include <stdio.h>
int main() {
	int a, b;
	scanf_s("%d %d", &a, &b);
	if (a%b == 0) {
		printf("a ������� �� b");
		return 0;
	}
	printf("a �� ������� �� b");
	return 1;
}