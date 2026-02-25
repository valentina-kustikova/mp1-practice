#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliary.h"

Book createbook(const char* line)
{
	Book book;
	char* linec = malloc(strlen(line)+1);
	strcpy(linec, line);
	char* t;
	t = strtok(linec, ";");
	book.author = strdup(t);
	t = strtok(NULL, ";");
	book.title = strdup(t);
	t = strtok(NULL, ";");
	book.publisher = strdup(t);
	t = strtok(NULL, ";");
	book.year = atoi(t);
	return book;
}
int countbooks(const char* fname)
{
	int count = 0;
	FILE* f = fopen(fname, "r");
	if (f == NULL)
	{
		return -1;
	}
	char line[1000];
	while (fgets(line, sizeof(line), f))
		count++;
	fclose(f);
	return count;
}
Book* createbooks(const char* fname, int count)
{
	Book* bs = (Book*)malloc(sizeof(Book)*count);
	FILE* f = fopen(fname, "r");
	char line[1000];
	int i = 0;
	for (; i < count; i++)
	{
		fgets(line, sizeof(line), f);
		bs[i] = createbook(line);
	}
	fclose(f);
	return bs;
}
void freeb(Book* bs, int count)
{
	int i = 0;
	for (; i < count; i++)
	{
		free(bs[i].author);
		free(bs[i].title);
		free(bs[i].publisher);
	}
	free(bs);
}
void prbook(const Book* b)
{
	printf("Автор: %s\n", (*b).author);
	printf("Название: %s\n", (*b).title);
	printf("Издательство: %s\n", (*b).publisher);
	printf("Год выпуска: %d\n", (*b).year);
}