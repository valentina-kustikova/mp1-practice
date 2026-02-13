#include <stdio.h>
#include <stdlib.h>
#include "auxilary.h"
#include "library.h"

/*static int count(FILE* f) {
	int cnt = 0;
	char* buff;
	while (fgets(buff, 1000, f)) cnt++;
	return cnt;
}*/

void parse(char* s, book* b) {
	int i, j = 0, z = 0, prev = 0, mx = 0, h = 0, name_length = 0, pub_length = 0;
	for (i = 0; s[i] != ';'; i++) if (s[i] == ',') {
		z++;
		if (i - prev - 1 > mx) mx = i - prev - 1;
		prev = i;
	}
	for (; s[i] != ';'; i++) name_length++;
	for (; s[i] != ';'; i++) pub_length++;
	(*b).year = 0;
	for (; i < strlen(s); i++) (*b).year = (*b).year * 10 + (s[i] - '0');
	if (i - prev - 1 > mx) mx = i - prev - 1;
	(*b).authors = (char**)malloc(z * sizeof(char*));
	for (i = 0; i < z; i++) (*b).authors[i] = (char*)malloc((mx + 1) * sizeof(char));
	(*b).name = (char*)malloc(name_length * sizeof(char));
	(*b).publisher = (char*)malloc(pub_length * sizeof(char));
	for (i = 0; s[i] != ';'; i++) {
		if (s[i] == ',') {
			h++;
			j = 0;
		}
		else (*b).authors[h][j++] = s[i];
	}
	for (j = 0; s[i] != ';'; i++) (*b).name[j++] = s[i];
	for (j = 0; s[i] != ';'; i++) (*b).publisher[j++] = s[i];
}

void print_book(book b) {
	int i, n = sizeof(b.authors) / sizeof(char*);
	printf("Authors: ");
	for (i = 0; i < n; i++) printf("%s AND ", b.authors[i]);
	printf("\nName: %s\nPublished by %s in %d\n", b.name, b.publisher, b.year);
}

/*void reader(const char* source, book* lib) {
	FILE* fl = fopen(source, 'r');
	int n;
	if (fl == NULL) {
		printf("File doesn't exist\n");
		return;
	}
	n = count(fl);
	lib = (book*)malloc(n * sizeof(book));

}*/