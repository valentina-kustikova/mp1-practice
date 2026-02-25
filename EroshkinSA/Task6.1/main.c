#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "auxilary.h"
#include <string.h>

int main(int argc, char** argv) {
	int n, i, cnt;
	book* lib;
	if (argc < 2) {
		printf("Incorrect parameters!");
		return 1;
	}
	lib = reader(argv[1], &n);
	if (lib == NULL) {
		printf("File doesn't exist or file is empty!\n");
		return 1;
	}
	printf("READ:\n\n");
	for (i = 0; i < n; i++) print_book(lib[i]);
	do {
		char author[1000];
		book* ans;
		printf("Enter finding author(or \"exit\" to end searching): ");
		fgets(author, 1000, stdin);
		author[strlen(author) - 1] = '\0';
		if (strcmp(author, "exit") == 0) break;
		ans = search(author, lib, n, &cnt);
		if (ans == NULL) printf("Doesn't have this author.\n");
		else for (i = 0; i < cnt; i++) print_book(ans[i]);
		free(ans);
	} while (1);
	//free_all(lib, n);
	return 0;
}