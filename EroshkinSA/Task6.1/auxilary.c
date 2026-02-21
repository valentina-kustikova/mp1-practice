#include <stdio.h>
#include <stdlib.h>
#include "auxilary.h"
#include "library.h"
#include <string.h>

static int count(FILE* f) {
	int cnt = 0;
	char* buff[1000];
	while (fgets(buff, 1000, f)) {
		cnt++;
	}
	return cnt;
}

extern void print_book(book b) {
	int i;
	printf("#___#\n");
	printf("Authors: ");
	for (i = 0; i < b.cnt_aut; i++) {
		printf("%s ", b.authors[i]);
		if (i != b.cnt_aut - 1) printf("& ");
	}
	printf("\nName: %s\nPublished by %s in %d\n", b.name, b.publisher, b.year);
	printf("#___#\n\n");
}

extern book* reader(const char* source, int* n) {
	FILE* fl = fopen(source, "r");
	int i;
	if (fl == NULL) {
		printf("File doesn't exist\n");
		return;
	}
	*n = count(fl);
	fclose(fl);
	if (*n == 0) return NULL;
	book* lib = (book*)malloc((*n) * sizeof(book));
	char* buff[1000];
	FILE* f = fopen(source, "r");
	for (i = 0; i < *n; i++) {
		fgets(buff, 1000, f);
		parse(buff, &(lib[i]));
	}
	fclose(f);
	return lib;
}

extern void free_all(book* lib, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < lib[i].cnt_aut; j++) {
			free(lib[i].authors[j]);
		}
		free(lib[i].authors);
		free(lib[i].name);
		free(lib[i].publisher);
	}
	free(lib);
}

static void parse(char* s, book* b) {
	int i;
	(*b).cnt_aut = 1;
	char* authors = _strdup(strtok(s, ";"));
	(*b).name = _strdup(strtok(NULL, ";"));
	(*b).publisher = _strdup(strtok(NULL, ";"));
	(*b).year = atoi(strtok(NULL, ";"));
	for (i = 0; i < strlen(authors); i++) if (authors[i] == ',') (*b).cnt_aut++;
	(*b).authors = (char**)malloc((*b).cnt_aut * sizeof(char*));
	(*b).authors[0] = _strdup(strtok(authors, ","));
	for (i = 1; i < (*b).cnt_aut; i++) (*b).authors[i] = _strdup(strtok(NULL, ","));
}