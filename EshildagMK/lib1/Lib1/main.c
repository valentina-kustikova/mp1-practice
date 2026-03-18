#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "libfi.h"	
#include "auxlib.h"	


int main() {
	int lines = 0, kfound = 0;
	char author_name[NAME_max];

	book_info* books = NULL;
	book_info* found_books = NULL;

	get_library("LibList.txt", &books, &lines);

	if (books == NULL) {
		printf("Failed to load library. Exiting.\n");
		return 1;
	}

	//print_books(books, lines);

	while (1) {
		printf("\nEnter author name (or 'exit' to quit): ");
		if (fgets(author_name, sizeof(author_name), stdin) == NULL) break;

		
		size_t len = strlen(author_name);
		if (len > 0 && author_name[len - 1] == '\n') {
			author_name[len - 1] = '\0';
		}

		if (strcmp(author_name, "exit") == 0) break;

		if (strlen(author_name) > 0) {
			searcher(books, lines, author_name, &found_books, &kfound);

			if (found_books != NULL && kfound > 0) {
				print_books(found_books, kfound);

				
				for (int i = 0; i < kfound; i++) {
					free(found_books[i].author);
					free(found_books[i].book_name);
					free(found_books[i].publisher);
				}
				free(found_books);
				found_books = NULL;
				kfound = 0;
			}
			else {
				printf("No books found for author '%s'.\n", author_name);
			}
		}
	}


	for (int i = 0; i < lines; i++) {
		free(books[i].author);
		free(books[i].book_name);
		free(books[i].publisher);
	}
	free(books);

	return 0;
}