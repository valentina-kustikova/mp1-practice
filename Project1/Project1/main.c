#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liblary.h"
#include "auxiliary.h"

int main(int argc, char **argv) {
	char author[100], *filename;
	int count, countAuthorBooks;
	if (argc < 2) {
		printf("incorrect number of argc");
		return 1;
	}
	filename = argv[1];

	count = numberBooks(filename);
	Book* array = (Book*)malloc(count * sizeof(Book));
	readFile(count, array, filename);
	 
	printf("\nEnter the author\n");
	scanf("%[^\n]", author);
	
	Book* search;
	searching(array, count, author, &search, &countAuthorBooks);
	printResults(search, countAuthorBooks);
	
	free(array);
	free(search);
	
	return 0;
}