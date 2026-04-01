#include <stdio.h>
#include <stdlib.h>

#include "auxiliary.h"
#include "library.h"

int main() {
	FILE* file_cab = NULL;
	BOOK* _library = NULL, * author_library = NULL;
	int is_empty, counter = 0, au_counter = 0;
	char pathway[1000];
	printf("Input path:\n");
	scanf_s("%s", pathway);

	is_empty = cab_reader(pathway, _library, file_cab, &counter);

	if (is_empty) return 0;

	book_search(_library, author_library, counter, &au_counter);

	book_printer(author_library, au_counter);

	free(_library);
	free(author_library);
	return 0;
}