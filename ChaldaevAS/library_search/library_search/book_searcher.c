#define _CRT_SECURE_NO_WARNINGS
#include "book_searcher.h"

int is_author_in_list(const char* authors_str, const char* search_author) {
    char authors_copy[MAX_STR_LEN];
    char search_lower[MAX_STR_LEN];
    char* token;
    int found = 0;

    strcpy(authors_copy, authors_str);

    for (int i = 0; search_author[i]; i++) {
        search_lower[i] = tolower(search_author[i]);
    }
    search_lower[strlen(search_author)] = '\0';

    token = strtok(authors_copy, ",");

    while (token != NULL) {
        char token_lower[MAX_STR_LEN];

        while (*token == ' ') token++;
        char* end = token + strlen(token) - 1;
        while (end > token && (*end == ' ')) end--;
        *(end + 1) = '\0';

        for (int i = 0; token[i]; i++) {
            token_lower[i] = tolower(token[i]);
        }
        token_lower[strlen(token)] = '\0';

        if (strstr(token_lower, search_lower) != NULL) {
            found = 1;
            break;
        }

        token = strtok(NULL, ",");
    }

    return found;
}

int search_books_by_author(Book books[], int book_count, const char* author, int results[]) {
    int result_count = 0;

    printf("\n>Поиск книг автора '%s'\n", author);

    for (int i = 0; i < book_count; i++) {
        Book* book = &books[i];

        if (is_author_in_list(book->authors, author)) {
            results[result_count] = i;
            result_count++;
            printf(">Найдена книга %d: %s\n", result_count, book->title);
        }
    }

    return result_count;
}

void print_book(const Book* book) {
    printf("--------------------------------------------------\n");
    printf("Авторы: %s\n", book->authors);
    printf("Название: %s\n", book->title);
    printf("Издательство: %s\n", book->publisher);
    printf("Год: %d\n", book->year);
    printf("--------------------------------------------------\n");
}

void print_search_results(Book books[], int book_count, int results[], int result_count) {
    if (result_count == 0) {
        printf("\n>Книги не найдены.\n");
        return;
    }

    printf("\n==================================================\n");
    printf("НАЙДЕНО КНИГ: %d\n", result_count);
    printf("==================================================\n");

    for (int i = 0; i < result_count; i++) {
        printf("\nКНИГА №%d:\n", i + 1);
        print_book(&books[results[i]]);
    }
}