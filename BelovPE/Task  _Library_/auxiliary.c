#include "auxiliary.h"


int FileRead(FILE* f) {
    int countBooks = 0;
    int ch;
    while ((ch = fgetc(f)) != EOF) {
        if (ch == '\n') {
            countBooks++;
        }
    }
    printf("Count of Books: %d\n", countBooks);
    rewind(f);
    return countBooks;
}


Book* CreatMassive(int countBooks) {
    Book* books = malloc(countBooks * sizeof(Book));
    if (!books) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    printf("Location massive of books = %p\n\n", books);

    for (int i = 0; i < countBooks; i++) {
        books[i].author = NULL;
        books[i].name = NULL;
        books[i].publisher = NULL;
        books[i].year = 0;
    }
    return books;
}


void EnterBook(FILE* f, Book* books, int countBooks, char buffer[]) {
    int i = 0;
    char* context = NULL;


    while (i < countBooks && fgets(buffer, MAX_LEN, f)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // strnspn(buffer, '\n') вернет индекс символа в строке, указанного во втором параметре

        char* line = malloc(strlen(buffer) + 1);
        strcpy_s(line, strlen(buffer) + 1, buffer);

        context = NULL;
        char* token = strtok_s(line, ";", &context);


        if (token) {
            size_t len = strlen(token) + 1;
            books[i].author = malloc(len);
            if (books[i].author) {
                strcpy_s(books[i].author, len, token);
            }
        }
        token = strtok_s(NULL, ";", &context);

        if (token) {
            size_t len = strlen(token) + 1;
            books[i].name = malloc(len);
            if (books[i].name) strcpy_s(books[i].name, len, token);
        }
        token = strtok_s(NULL, ";", &context);

        if (token) {
            size_t len = strlen(token) + 1;
            books[i].publisher = malloc(len);
            if (books[i].publisher) strcpy_s(books[i].publisher, len, token);
        }
        token = strtok_s(NULL, ";", &context);

        if (token) {
            books[i].year = atoi(token);
        }
        free(line);
        i++;
    }
}


void CleanMemories(int countBooks, Book* books) {
    for (int j = 0; j < countBooks; j++) {
        if (books[j].author) free(books[j].author);
        if (books[j].name) free(books[j].name);
        if (books[j].publisher) free(books[j].publisher);
    }
    free(books);
}