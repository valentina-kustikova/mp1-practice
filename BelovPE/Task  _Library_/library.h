#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char* authors;
    char* name;
    char* publisher;
    int year;
} Book;

// ќЅЏя¬Ћя≈ћ глобальные переменные (extern - они существуют где-то в другом файле)
extern Book* lib;
extern int bookCount;
extern int maxBooks;


void readFile(FILE* f);
void search();