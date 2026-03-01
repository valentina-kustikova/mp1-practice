#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "library.h"

struct book* find_books_by_author(struct book* books,
	int count, const char* author_request, int* found_count)
{
	*found_count = 0;

	int  i;
	for (i = 0; i < count; i++)
	{

		if (books[i].author && strstr(books[i].author, author_request))
		{
			(*found_count)++;
		}
	}

	if (*found_count == 0)
	{
		printf("Не найдено книг этого автора\n");
		return NULL;
	}

	struct book* found_books = malloc(*found_count * sizeof(struct book));
	if (found_books == NULL)
	{
		printf("Ошибка выделения памяти");
		*found_count = -1;
		return NULL;
	}

	int j = 0;
	for (i = 0; i < count; i++)
	{
		if (books[i].author && strstr(books[i].author, author_request))
		{
			found_books[j].author = malloc(strlen(books[i].author) + 1);
			strcpy_s(found_books[j].author, strlen(books[i].author) + 1, books[i].author);

			found_books[j].title = malloc(strlen(books[i].title) + 1);
			strcpy_s(found_books[j].title, strlen(books[i].title) + 1, books[i].title);

			found_books[j].publisher = malloc(strlen(books[i].publisher) + 1);
			strcpy_s(found_books[j].publisher, strlen(books[i].publisher) + 1, books[i].publisher);

			found_books[j].publishing_year = books[i].publishing_year;

			j++;
		}

	}

	*found_count = j;
	return found_books;
}
