#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "library.h"
#include "auxiliary.h"

struct book* find_books_by_author(struct book* books,
	int count, const char* author_request, int* found_count)
{
	*found_count = 0;

	char lowercase_request[512];
	to_lowercase(author_request, lowercase_request);

	int  i;
	for (i = 0; i < count; i++)
	{
		if (books[i].author )
		{
			char lowercase_author[512];
			to_lowercase(books[i].author, lowercase_author);
			if (strstr(lowercase_author, lowercase_request))
			{	
				(*found_count)++;
			}
		}
		
	}

	if (*found_count == 0)
	{
		printf("The books of this author are not found\n");
		return NULL;
	}

	struct book* found_books = (struct book*)malloc(*found_count * sizeof(struct book));
	if (found_books == NULL)
	{
		printf("Storage allocation error\n");
		*found_count = -1;
		return NULL;
	}

	int j = 0;
	for (i = 0; i < count; i++)
	{
		if (books[i].author)
		{
			char lowercase_author[512];
			to_lowercase(books[i].author, lowercase_author);
			if (strstr(lowercase_author, lowercase_request))
			{

				found_books[j].author = (struct book*)malloc(strlen(books[i].author) + 1);
				strcpy_s(found_books[j].author, strlen(books[i].author) + 1, books[i].author);

				found_books[j].title = (struct book*)malloc(strlen(books[i].title) + 1);
				strcpy_s(found_books[j].title, strlen(books[i].title) + 1, books[i].title);

				found_books[j].publisher = (struct book*)malloc(strlen(books[i].publisher) + 1);
				strcpy_s(found_books[j].publisher, strlen(books[i].publisher) + 1, books[i].publisher);

				found_books[j].publishing_year = books[i].publishing_year;

				j++;
			}
		}

	}

	*found_count = j;
	return found_books;
}
