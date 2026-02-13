#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "auxilary.h"

int main() {
	char* s, c;
	s = (char*)malloc(1000 * sizeof(char));
	int i = 0;
	book b;
	while (1) {
		c = getc(stdin);
		if (c == EOF) break;
		else if(c >= ' ' && c <= 'z') s[i++] = c;
	}
	s[i] = '\0';
	printf("%s \n\n", s);
	parse(s, &b);
	//print_book(b);
	return 0;
}