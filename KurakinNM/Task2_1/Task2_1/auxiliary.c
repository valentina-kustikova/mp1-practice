#define _CRT_SECURE_NO_WARNINGS

#include "auxiliary.h"
#include <stdio.h>

void bariers(char* str, int* start, int* numOfSims)
{
	*numOfSims = 0;
	while (str[*start] == ' ' || str[*start] == ',' || str[*start] == ';') (*start)++;
	while (str[*start + *numOfSims] != ',' && str[*start + *numOfSims] != ';' && str[*start + *numOfSims] != '\0') (*numOfSims)++;
	while (str[*start + *numOfSims - 1] == ' ') (*numOfSims)--;
}

int read(char* fileName, BOOK** books)
{
	FILE* f; int n = 0, linesCount = 0, i, j, numOfSims, start; char s[100]; char c; char* str; char* year; unsigned int* numOfAuthors;
	char buffer[256];
	f = fopen(fileName, "r");
	while (!feof(f))
	{
		c = fgetc(f);
		if (c == ';') linesCount++;
		if (linesCount == 3) {
			n++;
			linesCount = 0;
		}
	}


	numOfAuthors = (unsigned int*)malloc(n*sizeof(unsigned int));
	for (i = 0; i < n; i++) { numOfAuthors[i] = 1; }
	i = 0;
	fseek(f, 0, SEEK_SET);
	while (!feof(f))
	{
		c = fgetc(f);
		if (c == ',') numOfAuthors[i]++;
		if (c == '\n') i++;
	}


	*books = (BOOK*)malloc(n * sizeof(BOOK));
	for (i = 0; i < n; i++)
	{
		(*books)[i].numberOfAuthors = numOfAuthors[i];
		(*books)[i].authors = (char**)malloc(numOfAuthors[i] * sizeof(char*));
	}
	free(numOfAuthors);


	fseek(f, 0, SEEK_SET);
	for (i = 0; i < n; i++)
	{
		numOfSims = 1;
		do {
			numOfSims++;
			c = fgetc(f);
		} while (c != '\n' && !feof(f));
		str = malloc(numOfSims);
		fseek(f, -numOfSims, SEEK_CUR);
		fgets(str, numOfSims, f);

		start = 0;

		for (j = 0; j < (*books)[i].numberOfAuthors; j++)
		{
			bariers(str, &start, &numOfSims);
			(*books)[i].authors[j] = (char*)malloc(numOfSims + 1);
			memcpy((*books)[i].authors[j], str + start, numOfSims);
			(*books)[i].authors[j][numOfSims] = '\0';

			start += numOfSims;
		}

		bariers(str, &start, &numOfSims);
		(*books)[i].title = (char*)malloc(numOfSims + 1);
		memcpy((*books)[i].title, str + start, numOfSims);
		(*books)[i].title[numOfSims] = '\0';
		start += numOfSims;

		bariers(str, &start, &numOfSims);
		(*books)[i].ed = (char*)malloc(numOfSims + 1);
		memcpy((*books)[i].ed, str + start, numOfSims);
		(*books)[i].ed[numOfSims] = '\0';
		start += numOfSims;

		bariers(str, &start, &numOfSims);
		year = (char*)malloc(numOfSims + 1);
		memcpy(year, str + start, numOfSims);
		year[numOfSims] = '\0';
		(*books)[i].year = atoi(year);

		free(year);
		free(str);
	}

	return n;
}

void output(BOOK* lib, int* idBooks, int numOfBooks)
{
	int i, j;
	for (i = 0; i < numOfBooks; i++)
	{
		printf("Название книги: %s\n", lib[idBooks[i]].title);
		printf("Авторы: ");
		for (j = 0; j < lib[idBooks[i]].numberOfAuthors - 1; j++)
		{
			printf("%s, ", lib[idBooks[i]].authors[j]);
		}
		printf("%s\n", lib[idBooks[i]].authors[j]);
		printf("Гздатель: %s\n", lib[idBooks[i]].ed);
		printf("Год издания: %d\n", lib[idBooks[i]].year);
		printf("\n");
	}
}