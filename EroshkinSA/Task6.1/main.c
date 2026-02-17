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
	printf("READ:\n\n");
	for (i = 0; i < n; i++) print_book(lib[i]);
	do {
		char author[1000];
		printf("Enter finding author(or \"exit\" to end searching): ");
		fgets(author, 1000, stdin);
		author[strlen(author) - 1] = '\0';
		if (strcmp(author, "exit") == 0) break;
		book** ans = search(author, lib, n, &cnt);
		if (ans == NULL) printf("Doesn't have this author.\n");
		else for (i = 0; i < cnt; i++) print_book(*ans[i]);
		free(ans);
	} while (1);
	free_all(lib, n);
	return 0;
}