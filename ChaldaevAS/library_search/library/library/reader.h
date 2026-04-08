#ifndef READER_H
#define READER_H

#define MAX_TOKEN 128
#define MAX_FILEPATH 1024

struct Book {
	char authors[MAX_TOKEN];
	char name[MAX_TOKEN];
	char publisher[MAX_TOKEN];
	int year;
};


void get_filepath(char* filepath, int size);
int check_correct_path(char* filepath);
int count_lines_(char* filepath);
struct Book* memory_allocate_(int book_count);
struct Book* read_books_from_file(char* filepath, int* book_count);
void print_all_books(struct Book* books, int book_count);
void free_books(struct Book* books);



#endif