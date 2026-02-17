#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liblary.h"
#include "auxiliary.h"

int main() {
	char buff[1024], author[100];
	int count, searching_books;
	count = numberBooks("catalog.txt");
	struct Book* array = (struct Book*)malloc(count * sizeof(struct Book));
	readFile(count, array, "catalog.txt");
	
	printf("\nEnter the author\n");
	scanf("%[^\n]", author);
	struct Book* search = (struct Book*)malloc(count * sizeof(struct Book));
	
	searching_books = searching(array, count, author, search);

	printResults(search, searching_books);
	
	free(array);
	free(search);
	
	return 0;
}