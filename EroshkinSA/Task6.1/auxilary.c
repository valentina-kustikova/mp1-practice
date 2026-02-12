#include <stdio.h>
#include <stdlib.h>
#include "auxilary.h"
#include "library.h"

static int count(FILE* f) {
	int cnt = 0;
	char* buff;
	while (fgets(buff, 1000, f)) cnt++;
	return cnt;
}

static void parse(char* s, book* b) {
	int i, j = 0, z = 0, prev = 0, mx = 0, h = 0;
	for (i = 0; s[i] != ';'; i++) if (s[i] == ',') {
		z++;
		if (i - prev - 1 > mx) mx = i - prev - 1;
		prev = i;
	}
	if (i - prev - 1 > mx) mx = i - prev - 1;
	(*b).authors = (char**)malloc(z * sizeof(char*));
	for (i = 0; i < z; i++) (*b).authors[i] = (char*)malloc((mx + 1) * sizeof(char));
	
	for (i = 0; s[i] != ';'; i++) {
		if (s[i] == ',') {
			h++;
			j = 0;
		}
		else (*b).authors[h][j++] = s[i];
	}
}

void reader(const char* source, book* lib) {
	FILE* fl = fopen(source, 'r');
	int n;
	if (fl == NULL) {
		printf("File doesn't exist\n");
		return;
	}
	n = count(fl);
	lib = (book*)malloc(n * sizeof(book));

}