#include "library.h"
#include <stdio.h>
#include <string.h>

void cpy(char* input, char** output, int len)
{

	(*output) = (char*)malloc(len+1);
	memcpy(*output, input, len);
	(*output)[len] = '\0';
}

int find(BOOK* lib, BOOK** findedBooks, int numOfBooks, char* str)
{
	int i,j,k,n = 0, strLen;
	strLen = strlen(str) - 1;
	for (i = 0; i < numOfBooks; i++)
	{
		for (j = 0; j < lib[i].numberOfAuthors; j++)
		{
			if (strncmp(str, lib[i].authors[j], strLen) == 0) n++; // strstr
		}
	}

	*findedBooks = (BOOK*)malloc(n * sizeof(BOOK));
	n = 0;

	for (i = 0; i < numOfBooks; i++)
	{
		for (j = 0; j < lib[i].numberOfAuthors; j++)
		{
			if (strncmp(str, lib[i].authors[j], strLen) == 0) // strstr
			{
				cpy(lib[i].title, &((*findedBooks)[n].title), strlen(lib[i].title));
				cpy(lib[i].ed, &((*findedBooks)[n].ed), strlen(lib[i].ed));

				(*findedBooks)[n].year = lib[i].year;
				(*findedBooks)[n].numberOfAuthors = lib[i].numberOfAuthors;

				(*findedBooks)[n].authors = (char**)malloc(lib[i].numberOfAuthors * sizeof(char*));
				for (k = 0; k < lib[i].numberOfAuthors; k++)
				{
					cpy(lib[i].authors[k], &((*findedBooks)[n].authors[k]), strlen(lib[i].authors[k]));
				}
				n++;
				break;
			}
		}
	}
	return n;
}