#include "auxiliary.h"
#include "library.h"

int cab_reader(const char* pathway, BOOK* _library, FILE* file_cab, int* counter) {
	int i;
	char _string[500] = " ";
	fopen_s(file_cab, pathway, "r, ccs=UTF-8");
	if (file_cab == NULL) {
		printf("Error: File cabinet was not found\n");
		return 1;
	}

	while (_string) {
		fgets(_string, sizeof(_string), file_cab);
		*counter++;
	}

	rewind(file_cab);

	_library = (BOOK*)malloc(*counter * sizeof(BOOK));

	for (i = 0; i < counter; i++) {
		fgets(_string, sizeof(_string), file_cab);
		strcpy_s(_library[i].author, strtok_s(_string, ";", NULL), MAXSIZE);
		strcpy_s(_library[i].name, strtok_s(_string, ";", NULL), MAXSIZE);
		strcpy_s(_library[i].publishing, strtok_s(_string, ";", NULL), MAXSIZE);
		_library[i].year = (int)strtok_s(_string, ";", NULL);
	}
	return 0;
}

void book_printer(BOOK* author_library, int au_counter) {
	int i;
	printf("BOOKS\n\n");
	for (i = 0; i < au_counter; i++) {
		printf("%20s | %20s | %4d\n", author_library[i].name, author_library[i].publishing, author_library[i].year);
	}
}