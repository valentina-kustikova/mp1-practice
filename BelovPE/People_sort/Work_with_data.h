#pragma once
#include "Sort.h"

int Count_the_data(FILE* file);


LibraryInfo* Create_the_library(int count);


void Cleaning_of_memories(LibraryInfo* library);


void Read_the_File(char* buffer, FILE* file, LibraryInfo* library);
