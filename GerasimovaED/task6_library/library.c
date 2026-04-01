#include "library.h"

void book_search(BOOK* _library, BOOK* author_library, int counter, int* au_counter) {
	char author_surename[1000];
	int j = 0, i;
	printf("Input author's surmane:\n");
	scanf_s("%s", author_surename);
	for (i = 0; i < counter; i++) {
		if (strstr(_library[i].author, author_surename) != NULL) {
			*au_counter++;
		}
	}
	author_library = (BOOK*)malloc(*au_counter * sizeof(BOOK));
	for (i = 0; i < counter; i++) {
		if (strstr(_library[i].author, author_surename) != NULL) {
			strcpy_s(author_library[j].author, _library[i].author, MAXSIZE);
			strcpy_s(author_library[j].name, _library[i].name, MAXSIZE);
			strcpy_s(author_library[j].publishing, _library[i].publishing, MAXSIZE);
			author_library[j].year = _library[i].year;
			j++;
		}
	}
}