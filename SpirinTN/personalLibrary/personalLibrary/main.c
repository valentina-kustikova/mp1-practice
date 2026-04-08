#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>

#include "library.h"
#include "auxiliary.h"

int main(int argc, char** argv) {
    STATUS status;
	char* fileName = NULL;
    BOOK* books = NULL;
    int countBooks;
    setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

	if (argc < 2) {
		status = INSUFFICIENT_ARGUMENTS_ERROR;
		printFrame();
		printError(status);
		return status;
	}
	
	fileName = argv[1];
    status = readLibrary(&books, &countBooks, fileName);
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