#include "book_searcher.h"
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <windows.h>

int main() {
    Book books[MAX_BOOKS];
    int results[MAX_BOOKS];
    char filename[MAX_STR_LEN];
    char search_author[MAX_STR_LEN];

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "RUS");

    printf("========================================\n");
    printf("ПОИСК КНИГ ПО АВТОРУ\n");
    printf("========================================\n");

    printf("Введите имя файла с картотекой: ");
    fgets(filename, MAX_STR_LEN, stdin);
    filename[strcspn(filename, "\n")] = 0;

    int book_count = read_books_from_file(filename, books, MAX_BOOKS);

    if (book_count <= 0) {
        printf("Не удалось прочитать файл или файл пуст.\n");
        return 1;
    }

    printf("\nЗагружено %d книг.\n", book_count);

    while (1) {
        printf("\n----------------------------------------\n");
        printf("Введите имя автора для поиска (или 'exit' для выхода): ");
        fgets(search_author, MAX_STR_LEN, stdin);
        search_author[strcspn(search_author, "\n")] = 0;

        if (strcmp(search_author, "exit") == 0) {
            break;
        }

        if (strlen(search_author) == 0) {
            printf("Введите имя автора!\n");
            continue;
        }

        int result_count = search_books_by_author(books, book_count, search_author, results);

        print_search_results(books, book_count, results, result_count);
    }

    printf("\nПрограмма завершена.\n");
    return 0;
}