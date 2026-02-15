#include "library.h"
#include <stdio.h>
#include <string.h>

int find(BOOK* lib, int numOfBooks, char* str, unsigned int** idBooks)
{
	int i,j,n = 0, strLen;
	strLen = strlen(str) - 1;
	for (i = 0; i < numOfBooks; i++)
	{
		for (j = 0; j < lib[i].numberOfAuthors; j++)
		{
			if (strncmp(str, lib[i].authors[j], strLen) == 0) n++;
		}
	}

	*idBooks = (unsigned int*)malloc(n*sizeof(unsigned int));
	n = 0;

	for (i = 0; i < numOfBooks; i++)
	{
		for (j = 0; j < lib[i].numberOfAuthors; j++)
		{
			if (strncmp(str, lib[i].authors[j], strLen) == 0)
			{
				(*idBooks)[n] = i;
				n++;
				break;
			}
		}
	}
	return n;
}