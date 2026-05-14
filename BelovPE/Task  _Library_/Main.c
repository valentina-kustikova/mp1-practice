#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "auxiliary.h"

#define MAX_LEN 256

int main(int argc, char** argv) {
    char string[MAX_PATH];
    char buffer[MAX_LEN];
    int countBooks = 0;
    int found = 0;
    char* filename;
    Book* books_of_struct = NULL;


    if (argc < 2) {
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
        printf("Error of func. CreatMassive\n");
        fclose(f);
        return 1;
    }


    EnterBook(f, books, countBooks, buffer);
    fclose(f);

    
    printf("Enter the author to search: ");
    scanf_s("%s", string, (unsigned)sizeof(string));

    
    books_of_struct = SearchByAuthor(&found, countBooks, books, string);
    if (!books_of_struct) {
        printf("Error of func. SearchByAuthor\n");
    }

    
    EnterBook_of_struct(books_of_struct, found);


    CleanMemories(countBooks, books);
    CleanMemories(found, books_of_struct);


    return 0;
}