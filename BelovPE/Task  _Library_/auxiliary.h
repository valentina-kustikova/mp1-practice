#pragma once
#include "library.h"
#define MAX_LEN 256

int FileRead(FILE* f);

Book* CreatMassive(int countBooks);

void EnterBook(FILE* f, Book* books, int countBooks, char buffer[]);


void EnterBook_of_struct(Book* books_of_struct, int found);


void CleanMemories(int countBooks, Book* books);