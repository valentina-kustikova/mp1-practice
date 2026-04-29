//./src/library.h

#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "platform_compability.h"


// структура представлени€ книги
struct book_ {
	char* authors;  // авторы
	char* name;     // название
	char* publ;     // издательство
	unsigned year;  // год издани€
	char* str;      // указатель на строку с исходной информацией о книге дл€ очистки пам€ти
};
typedef struct book_ book; // структура представлени€ книги


// структура представлени€ бибилиотеки
struct lib_t_ {
	book* library; // ƒинамический массив структур book
	size_t lib_size;  // –азмер данного массива
};
typedef struct lib_t_ lib_t; // структура представлени€ книги




// ‘ункции:

// создание библиотеки из информации из файла
void init_library(lib_t* library, char* path);

// ”даление библиотеки - освобождение пам€ти всех книг и установка указател€ в NULL (на вс€кий случай)
void delete_library(book** lib, size_t* lib_s);

// ќсновна€ функци€ поиска, возвращает указатель на массив указателей на книги в куче, измен€ет f_cnt на кол-во найденных книг, завершает массив NULL
book** find_books(book* lib, size_t size, const char* substr, size_t* f_cnt);

// вывести инфо каждой книги из массива
void print_books(book** bks, size_t cnt);

// ¬опрос в stdin о пути файла базы данных и заполнение библиотеки
void start_ask(lib_t* library);

// ќбработка запроса из stdin, возвращает false, если требуетс€ выйти
bool process_query(lib_t library);

// тестова€ функци€ дл€ вывода книги по номеру
void test(book* lib, int n);

// тестова€ функци€ дл€ вывода всех книг
void test_all(book* lib, size_t n);
