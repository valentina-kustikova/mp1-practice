#include <stdio.h>
#include <stdlib.h>
#include "auxilary.h"
#include "library.h"

int main() {
	FILE *file = fopen("biblio.txt", "r");
	char aut[100];
	int biblen;
	book* books;
	int* ans;
	if (file == NULL) {
		printf("no file");
		return 0;
	}
	biblen = getrange(file);
	books = (book*)malloc(sizeof(book) * biblen);
	for (int i = 0; i < biblen; i++)
	{
		books[i].authors = (char*)malloc(sizeof(char) * 100);
		books[i].name = (char*)malloc(sizeof(char) * 100);
		books[i].publisher = (char*)malloc(sizeof(char) * 100);
	}
	loadbooks(file, books, biblen);
	if (fgets(aut, sizeof(aut), stdin) == NULL) {
		printf("getting error");
		return 0;
	}
	ans = find(books, aut, biblen);
	printer(books, ans);
	
	free(books);
	free(ans);
	return 0;
}