#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include <ctype.h>

struct book* file_to_struct(const char* file_name, int* count)
{
	int n = 0;
	FILE* file = fopen(file_name, "r");

	if (file == NULL)
	{
		printf("");
		*count = -1;
		return NULL;
	}

	char line[512];

	while (fgets(line, sizeof(line), file))
	{
		n++;
	}

	if (n == 0)
	{
		*count = 0;
		return NULL;
	}

	rewind(file);

	struct book* books = malloc(n * sizeof(struct book));
	if (books == NULL)
	{
		printf("");
		*count = -1;
		fclose(file);
		return NULL;
	}

	int i = 0;
	while (i < n && fgets(line, sizeof(line), file))
	{
		line[strcspn(line, "\n")] = 0;

		char* author = strtok(line, ";");
		char* title = strtok(NULL, ";");
		char* publisher = strtok(NULL, ";");
		char* publishing_year = strtok(NULL, ";");

		books[i].author = malloc(strlen(author) + 1);
		strcpy_s(books[i].author, strlen(author) + 1, author);

		books[i].title = malloc(strlen(title) + 1);
		strcpy_s(books[i].title, strlen(title) + 1, title);

		books[i].publisher = malloc(strlen(publisher) + 1);
		strcpy_s(books[i].publisher, strlen(publisher) + 1, publisher);

		books[i].publishing_year = atoi(publishing_year);

		i++;
	}

	fclose(file);
	*count = n;
	return books;
}

void to_lowercase(const char* before, char* after)
{
	for (; *before != '\0'; before++, after++)
	{
		*after = tolower((unsigned char)*before);
	}
	*after = '\0';
}

void print_found_books(struct book* found_books, int found_count)
{
	int i;
	for (i = 0; i < found_count; i++)
	{
		printf(": %s, : %s, : %d\n", found_books[i].title, found_books[i].publisher, found_books[i].publishing_year);
	}
}

void free_memory(struct book* books, int count)
{
	for (int i = 0; i < count; i++)
	{
		free(books[i].author);
		free(books[i].title);
		free(books[i].publisher);
	}
	free(books);
}