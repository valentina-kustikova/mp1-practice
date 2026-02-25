#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "auxiliary.h"
#include <locale.h>

int main(int argc, char** argvv) {

    setlocale(LC_ALL, "Rus");
    char* fname;
    if (argc < 2)
    {
        printf("Incorrect parametres");
        return 1;
    }
    fname = argvv[1];
    int n = countbooks(fname);
    Book* bss = createbooks(fname, n);
    int i = 0;
    int f = 0;
    char author[200];
    printf("¬ведите автора : \n");
    scanf("%s", author);
    int nnew = 0;
    for (; i < n; i++)
    {
        if (findByauthor(&bss[i], author))
        {
            f = 1;
            nnew++;
        }
    }
    Book* bssnew = (Book*)malloc(sizeof(Book) * nnew);
    int j = 0;
    for (i=0; i < n; i++)
    {
        if (findByauthor(&bss[i], author))
        {
            bssnew[j] = bss[i];
            j++;
        }
    }
    for (i = 0; i < j; i++)
    {
        prbook(&bssnew[i]);
    }
    free(bss);
    free(bssnew);
    return 0;
}
