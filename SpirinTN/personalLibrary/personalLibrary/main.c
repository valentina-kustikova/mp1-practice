#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>

#include "library.h"
#include "auxiliary.h"


int main() {
    STATUS status;
    BOOK* books = NULL;
    int countBooks;
    setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
	
    status = readLibrary(&books, &countBooks);
    if (status != SUCCESS) {
        printFrame();
		printError(status);
        free(books);
        books = NULL;
        return status;
    }
    status = programCycle(books, countBooks);

    free(books);
    books = NULL;
    return status;
}