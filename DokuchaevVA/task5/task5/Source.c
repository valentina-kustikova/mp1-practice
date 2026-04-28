#include <stdio.h>
#include <locale.h>
void find() {

	union sizze {
		unsigned short a;
		char b[2];
	} mysize;

	mysize.a = 256 * 4 + 64;//00000100.01000000
	//						        4 . 64

	unsigned char ub[2];
	ub[1] = mysize.b[1];
	ub[0] = mysize.b[0];

	setlocale(LC_ALL, "Rus");
	printf("%u\n", mysize.a);
	printf("%u\n", ub[1]);
	printf("%u\n", ub[0]);

	printf("%zu", sizeof(ub[0]));
}
int main() {
	find();
	return 0;
}