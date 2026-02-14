#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "auxilary.h"

int main() {
	int n, i;
	book* lib = reader("library.txt", &n);
	for (i = 0; i < n; i++) {
		print_book(lib[i]);
		printf("#___#\n");
	}
	return 0;
}