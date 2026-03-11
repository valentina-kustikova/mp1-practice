#define _CRT_SECURE_NO_WARNINGS

#include "auxiliary.h"
#include <stdio.h>

void bariers(char* str, int* start, int* numOfSims)
{
	*numOfSims = 0;
	while (str[*start] == ' ' || str[*start] == ',' ||
		   str[*start] == ';') (*start)++;
	while (str[*start + *numOfSims] != ',' && str[*start + *numOfSims] != ';' &&
		   str[*start + *numOfSims] != '\0') (*numOfSims)++;
	while (str[*start + *numOfSims - 1] == ' ') (*numOfSims)--;
}

void readWord(char* input,char** output,int* start, int* numOfSims)
{
	bariers(input, start, numOfSims);
	*output = (char*)malloc(*numOfSims + 1);
	memcpy(*output, input + *start, *numOfSims);
	(*output)[*numOfSims] = '\0';
	*start += *numOfSims;
}

int read(char* fileName, BOOK** books) // fgets + strtok + strcpy + sscanf + strdub
{
	FILE* f;
	int n = 0, linesCount = 0, i, j, numOfSims, start;
	char c; char* str; char* year;
	unsigned int* numOfAuthors;

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
			readWord(str, &((*books)[i].authors[j]), &start, &numOfSims);
		}

		readWord(str, &((*books)[i].title), &start, &numOfSims);
		readWord(str, &((*books)[i].ed), &start, &numOfSims);
		readWord(str, &year, &start, &numOfSims);

		(*books)[i].year = atoi(year);

		free(year);
		free(str);
	}

	fclose(f);

	return n;
}

void output(BOOK* lib, int numOfBooks)
{
	int i, j;
	for (i = 0; i < numOfBooks; i++)
	{
		printf("Название книги: %s\n", lib[i].title);
		printf("Авторы: ");
		for (j = 0; j < lib[i].numberOfAuthors - 1; j++)
		{
			printf("%s, ", lib[i].authors[j]);
		}
		printf("%s\n", lib[i].authors[j]);
		printf("Гздатель: %s\n", lib[i].ed);
		printf("Год издания: %d\n", lib[i].year);
		printf("\n");
	}
}