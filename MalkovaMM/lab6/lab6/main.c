#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "auxiliary.h"
#include <locale.h>

int main(int argc, char** argvv) {

    setlocale(LC_ALL, "Rus");
    char* fname;
    if (argc < 1)
    {
        printf("Incorrect parametres!");
        return 1;
    }
    //fname = argvv[1];
    fname = "task6.txt";
    printf("ָלÿ פאיכא: %s\n", fname);
    int n = countbooks(fname);
    Book* bss = createbooks(fname, n);
    int i = 0;
    int f = 0;
    char author[200];
    printf("ֲגוהטעו אגעמנא : \n");
    scanf("%s", author);
    int nnew;
    Book* bssnew = findByauthor(bss, n, author, &nnew);
    for (i = 0; i < nnew; i++)
    {
        prbook(&bssnew[i]);
    }
    free(bss);
    free(bssnew);
    return 0;
}
