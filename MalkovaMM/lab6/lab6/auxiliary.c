#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliary.h"

Book createbook(const char* line)
{
	Book book;
	char* t;
	char* linec = malloc(strlen(line)+1);
	strcpy(linec, line);	
	t = strtok(linec, ";");
	book.author = _strdup(t);
	t = strtok(NULL, ";");
	book.title = _strdup(t);
	t = strtok(NULL, ";");
	book.publisher = _strdup(t);
	t = strtok(NULL, ";");
	book.year = atoi(t);
	return book;
}
int countbooks(const char* fname)
{
	int count = 0;
	FILE* f = fopen(fname, "r");
	char line[MAX_LEN];
	if (f == NULL)
	{
		printf("Файл по заданному пути не существует");
		return -1;
	}
	
	while (fgets(line, sizeof(line), f))
		count++;
	fclose(f);
	return count;
}
Book* createbooks(const char* fname, int count)
{
	Book* bs = (Book*)malloc(sizeof(Book)*count);
	FILE* f = fopen(fname, "r");
	char line[MAX_LEN];
	int i = 0;
	for (; i < count; i++)
	{
		fgets(line, sizeof(line), f);
		bs[i] = createbook(line);
	}
	fclose(f);
	return bs;
}
void prbook(const Book* b)
{
	printf("Автор: %s\n", b->author);
	printf("Название: %s\n", b->title);
	printf("Издательство: %s\n", b->publisher);
	printf("Год выпуска: %d\n\n", b->year);
}