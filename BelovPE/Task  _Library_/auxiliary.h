#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#define MAX_LEN 256

int FileRead(FILE* f);

Book* CreatMassive(int countBooks);

void EnterBook(FILE* f, Book* books, int countBooks, char buffer[]);

void CleanMemories(int countBooks, Book* books);