#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "auxilary.h"
#include <string.h>

int main() {
	int n, i, cnt;
	book* lib = reader("library.txt", &n);
	if (lib == NULL) {
		printf("Empty file!\n");
		return 0;
	}
	for (i = 0; i < n; i++) {
		print_book(lib[i]);
		printf("#___#\n");
	}
	printf("\n\n");
	char author[1000];
	fgets(author, 1000, stdin);
	author[strlen(author) - 1] = '\0';
	book* ans = search(author, lib, n, &cnt);
	if (ans == NULL) printf("Doesn't have :(\n");
	else for (i = 0; i < cnt; i++) {
		print_book(ans[i]);
		printf("#___#\n");
	}
	free(ans);
	return 0;
}