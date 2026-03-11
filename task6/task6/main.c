#include <stdio.h>
#include <stdlib.h> //для памяти malloc()
#include <locale.h>
#include <string.h>//для strtok


#define MAX_LINE_LEN 512

typedef struct {
	char* authors;
	char* title;
	char* publisher;
	int year;
}Book;


//выделение памяти 
void* safe_malloc(size_t size) {
	void* memory_book = malloc(size);
	return memory_book;
}

//деление строки
Book divide_line(char* line) {
	Book book;
	char* token;

	book.authors = safe_malloc(MAX_LINE_LEN);
	book.title = safe_malloc(MAX_LINE_LEN);
	book.publisher= safe_malloc(MAX_LINE_LEN);
	//год


	token = strtok(line, ";");
	if (token != NULL) {
		strcpy(book.authors, token);
	}
	else {
		strcpy(book.authors, "");
	}


	token = strtok(line, ";");
	if (token != NULL) {
		strcpy(book.title, token);
	}
	else {
		strcpy(book.title, "");
	}

	token = strtok(line, ";");
	if (token != NULL) {
		strcpy(book.publisher, token);
	}
	else {
		strcpy(book.publisher, "");
	}
	//год

	return book;
}

//освобождение памяти



int main() {
	char* filename = "gggg.txt";
	setlocale(LC_ALL, "Russian");

	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		return NULL;
	}


}