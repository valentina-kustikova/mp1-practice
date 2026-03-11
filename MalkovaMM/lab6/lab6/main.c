#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "auxiliary.h"
#include <locale.h>

int main(int argc, char** argvv) {
    int i = 0;
    int f = 0;
    int nnew;
    char author[200];
    int n;
    Book* bss;
    char* fname;

    setlocale(LC_ALL, "Rus");
    
    if (argc < 2)
    {
        printf("Incorrect parametres!");
        return 1;
    }
    fname = argvv[1];
    printf("ָלÿ פאיכא: %s\n", fname);
    n = countbooks(fname);
    bss = createbooks(fname, n);
    printf("ֲגוהטעו אגעמנא : \n");
    scanf("%s", author);
    Book* bssnew = findByauthor(bss, n, author, &nnew);
    for (i = 0; i < nnew; i++)
       prbook(&bssnew[i]);
    free(bss);
    free(bssnew);
    return 0;
}
