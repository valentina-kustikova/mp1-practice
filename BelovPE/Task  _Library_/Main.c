#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "auxiliary.h"

#define MAX_LEN 256

int main(int argc, char** argv) {
    char buffer[MAX_LEN];
    int countBooks = 0;
    char* filename;

    if (argv < 2) {
        return 1;
    }
    filename = argv[1];


    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("File not found!\n");
        return 1;
    }


    countBooks = FileRead(f);
    if (countBooks == 0) {
        printf("No books found in file!\n");
        fclose(f);
        return 1;
    }


    Book* books = CreatMassive(countBooks);
    if (!books) {
        fclose(f);
        return 1;
    }


    EnterBook(f, books, countBooks, buffer);
    fclose(f);

    
    SearchByAuthor(countBooks, books);


    CleanMemories(countBooks, books);
    

    return 0;
}