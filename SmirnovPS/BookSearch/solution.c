#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "auxiliary.h"


int main() {
	char author[256];
	int count = book_amount("books.txt"), found_amount = 0;
	Book* library = (Book*)malloc(count * sizeof(Book));
	read_file(count, library, "books.txt");
	
	printf("Enter author's name: ");
	fgets(author, sizeof(author), stdin);
	author[strcspn(author, "\n")] = '\0';
	Book* found_books = (Book*)malloc(count * sizeof(Book));

	found_amount = searching(library, count, author, found_books);
	print_books(found_books, found_amount);

	free_library(library, count);

	free(library);
	free(found_books);

	return 0;
}