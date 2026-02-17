#include <stdio.h>
#include <stdlib.h>
#include "auxilary.h"
#include "library.h"

static int count(FILE* f) {
	int cnt = 0;
	char* buff[1000];
	while (fgets(buff, 1000, f)) {
		cnt++;
	}
	fclose(f);
	return cnt;
}

static void parse(char* s, book* b) {
	int i, j = 0, prev = 0, mx = 0, k = 0, name_length = 0, pub_length = 0;
	(*b).cnt_aut = 1;
	for (i = 0; s[i] != ';'; i++) if (s[i] == ',') {
		(*b).cnt_aut++;
		if (i - prev - 1 > mx) mx = i - prev - 1;
		prev = i;
	}
	if (i - prev > mx) mx = i - prev;
	i++;
	for (; s[i] != ';'; i++) name_length++;
	i++;
	for (; s[i] != ';'; i++) pub_length++;
	i++;
	(*b).year = 0;
	for (; i < strlen(s) - 1; i++) (*b).year = (*b).year * 10 + (s[i] - '0');
	(*b).authors = (char**)malloc(((*b).cnt_aut) * sizeof(char*));
	for (i = 0; i < (*b).cnt_aut; i++) (*b).authors[i] = (char*)malloc((mx + 2) * sizeof(char));
	(*b).name = (char*)malloc((name_length + 1) * sizeof(char));
	(*b).publisher = (char*)malloc((pub_length + 1) * sizeof(char));
	//___________________________________
	//___________________________________

	for (i = 0; s[i] != ';'; i++) {
		if (s[i] == ',') {
			(*b).authors[k][j] = '\0';
			k++;
			i++;
			j = 0;
		}
		else (*b).authors[k][j++] = s[i];
	}
	(*b).authors[k][j] = '\0';
	i++;
	for (j = 0; s[i] != ';'; i++) (*b).name[j++] = s[i];
	(*b).name[j] = '\0';
	i++;
	for (j = 0; s[i] != ';'; i++) (*b).publisher[j++] = s[i];
	(*b).publisher[j] = '\0';
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
	if (*n == 0) return NULL;
	book* lib = (book*)malloc(*n * sizeof(book));
	char* buff[1000];
	FILE* f = fopen(source, "r");
	for (i = 0; i < *n; i++) {
		fgets(buff, 1000, f);
		parse(buff, lib + i);
	}
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