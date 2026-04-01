#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Book* findByauthor(Book* bss, int n, const char* findauthor, int* nnew)
{
    int i = 0, j = 0;
    Book* bssnew;
    *nnew = 0;    
    for (; i < n; i++)
    {
        if (strstr(bss[i].author, findauthor) != NULL)
        {
            (*nnew)++;
        }
    }
    bssnew = (Book*)malloc(sizeof(Book) * (*nnew));
    for (i = 0; i < n; i++)
    {
        if (strstr(bss[i].author, findauthor) != NULL)
        {
            bssnew[j].author = _strdup(bss[i].author);
            bssnew[j].publisher = _strdup(bss[i].publisher);
            bssnew[j].title = _strdup(bss[i].title);
            bssnew[j].year = bss[i].year;
            j++;
        }
    }
	return bssnew;
}