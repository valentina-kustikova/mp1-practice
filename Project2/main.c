#include <stdio.h>
int main() {
	int a, b, m;
	scanf_s("%d %d", &a, &b);
	m = a;
		if (m < b)
			m = b;
	printf("%d", m);
	return 0;
}

