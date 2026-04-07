#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liblary.h"
#include "auxiliary.h"

int main(int argc, char **argv) {
    char avtor[256], *filename;
    int count, kolvonaydenknig;
    Book* arr;
    Book* itogpoiska;
    if (argc < 2) {
        printf("incorrect number of arg");
        return 1;
    }
    filename = argv[1];

    count = numberBooks(filename);
    
    arr = (Book*)malloc(count * sizeof(Book));
    readFile(count, arr, filename);

    printf("Vvedite avtora: ");
    scanf("%[^\n]", avtor);
    
    
    poisk(arr, count, avtor, &itogpoiska, &kolvonaydenknig);
    printResults(itogpoiska, kolvonaydenknig);
     
    free(arr);
    free(itogpoiska);
    return 0;
}