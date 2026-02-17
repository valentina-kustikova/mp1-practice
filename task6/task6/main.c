#include <stdio.h>
#include <stdlib.h> //для памяти malloc()
#include <locale.h>

#include "struct.h"
#include "funcs.h"

int main() {
    char file_name[256];
    char author[256];
    int count = 0;

    setlocale(LC_ALL, "Russian")

    printf("введите файл: ");
    scanf_s("%255s", file_name);

    Book* books = read_books(file_name, &count);
    if (books==0) {
        return 1;
    }

    printf("введите автора: ");
    getchar();
    fgets(author, sizeof(author), stdin);

    author[strcspn(author, "\n")] = 0;

    search_author(books, count, author);

    free_books(books, count);

    return 0;
}