#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findByauthor(const Book* book, const char* findauthor)
{
	if (book == NULL || (*book).author == NULL || findauthor == NULL)
		return 0;
	if (strstr((*book).author, findauthor) != NULL)
	{
		return 1;
	}
	return 0;
}