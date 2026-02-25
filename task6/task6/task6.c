#include <stdio.h>
#include "auxilary.h"
#include "library.h"

int main() {
	FILE* file = fopen("biblo.txt", "r");
	int biblen = getrange(file);
	book* books = loadbooks(file, biblen);
	char aut[40];
	gets(aut);
}