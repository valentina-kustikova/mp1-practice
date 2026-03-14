#include <stdio.h>
#include "auxilary.h"
#include "library.h"

int main() {
	FILE* file = fopen("biblio.txt", "r");
	if (file == NULL) {
		printf("no file");
		return 0;
	}
	int biblen = getrange(file);
	book* books = loadbooks(file, biblen);
	char aut[40];
	if (fgets(aut, sizeof(aut), stdin) == NULL) {
		printf("getting error");
		return 0;
	}
	int* ans = find(books, aut, biblen);
	printer(books, ans);
	free(books);
	free(ans);
	return 0;
}