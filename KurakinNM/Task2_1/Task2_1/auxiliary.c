#define _CRT_SECURE_NO_WARNINGS

#include "auxiliary.h"
#include <stdio.h>

void bariers(char* str, int* start, int* numOfSims)
{
	while (str[*start] == ' ') (*start)++;
	while (str[*numOfSims - 1] == ' ') (*numOfSims)--;
	*numOfSims -= *start;
}

void readWord(char* input,char** output)
{
	int start = 0, numOfSims = strlen(input);
	bariers(input, &start, &numOfSims);
	(*output) = (char*)malloc(numOfSims+1);
	strncpy(*output, input + start, numOfSims);
	(*output)[numOfSims] = '\0';
}

int read(char* fileName, BOOK** books) // fgets + strtok + strcpy + fscanf + strdub
{
	FILE* f;
	int n = 0, i, j;
	char* year;
	char buffer[255]; char* token;
	unsigned int* numOfAuthors;

	f = fopen(fileName, "r");
	while (!feof(f))
	{
		fgets(buffer,255,f);
		n++;
	}


	numOfAuthors = (unsigned int*)malloc(n*sizeof(unsigned int));
	for (i = 0; i < n; i++) { numOfAuthors[i] = 0; }
	i = 0;
	fseek(f, 0, SEEK_SET);
	for (i = 0; i < n; i++)
	{
		fgets(buffer, 255, f);
		token = strtok(buffer, ";");
		while (token != NULL)
		{
			token = strstr(token+1, ",");
			numOfAuthors[i]++;
		}
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
		fgets(buffer, 255, f);
		token = strtok(buffer, ",;");
		for (j = 0; j < (*books)[i].numberOfAuthors; j++)
		{
			readWord(token, &((*books)[i].authors[j]));
			token = strtok(NULL, ",;");
		}
		readWord(token, &((*books)[i].title));
		token = strtok(NULL, ",;");
		readWord(token, &((*books)[i].ed));
		token = strtok(NULL, ",;");
		readWord(token, &year);

		(*books)[i].year = atoi(year);

		free(year);
	}

	fclose(f);

	return n;
}

void output(BOOK* lib, int numOfBooks)
{
	int i, j;
	for (i = 0; i < numOfBooks; i++)
	{
		printf("Íàçâàíèå êíèãè: %s\n", lib[i].title);
		printf("Àâòîðû: ");
		for (j = 0; j < lib[i].numberOfAuthors - 1; j++)
		{
			printf("%s, ", lib[i].authors[j]);
		}
		printf("%s\n", lib[i].authors[j]);
		printf("Ãçäàòåëü: %s\n", lib[i].ed);
		printf("Ãîä èçäàíèÿ: %d\n", lib[i].year);
		printf("\n");
	}
}
