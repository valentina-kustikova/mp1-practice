#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liblary.h"
#include "auxiliary.h"

int main() {
	char buff[1024], author[100];
	int count, countAuthorBooks;
	count = numberBooks("catalog.txt");
	struct Book* array = (struct Book*)malloc(count * sizeof(struct Book));
	readFile(count, array, "catalog.txt");
	 
	printf("\nEnter the author\n");
	scanf("%[^\n]", author);
	
	struct Book* search;
	searching(array, count, author, &search, &countAuthorBooks);
	printResults(search, countAuthorBooks);
	
	free(array);
	free(search);
	
	return 0;
}