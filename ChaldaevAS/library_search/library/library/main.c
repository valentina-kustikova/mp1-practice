#define _CRT_SECURE_NO_WARNINGS
#include "reader.h"
#include "filter.h"
#include <stdio.h>

int main() {
    char filepath[MAX_FILEPATH];
    struct Book* books = NULL;
    char search_text[MAX_TOKEN];
    int* filtered_indexes = NULL;
    int book_count = 0;
    int choice = -1;
    int filtered_count = 0;

    printf("+=================================+\n");
    printf("|         [BOOK MANAGER]          |\n");
    printf("+=================================+\n");


    while (1) {

        printf("+=================================+\n");
        printf("|              MENU               |\n");
        printf("|=================================+\n");
        printf("|   [1] Read books                |\n");
        printf("|   [2] Show all books            |\n");
        printf("|   [3] Search by author          |\n");
        printf("|   [4] Search by title           |\n");
        printf("|   [5] Exit                      |\n");
        printf("|=================================+\n");
        printf("|   Please, write your choice:  ");
        scanf_s("%d", &choice);
        getchar();
        printf("\n+=================================+\n");

        switch (choice) {
        case 1:
            printf("\n[1] Read books\n");
            get_filepath(filepath, sizeof(filepath));

            if (check_correct_path(filepath)) {
                if (books != NULL) {
                    free_books(books);
                    books = NULL;
                }

                books = read_books_from_file(filepath, &book_count);

                if (books != NULL && book_count > 0) {
                    printf("\n[INFO] Readed %d books from file.\n", book_count);
                }
                else {
                    printf("\n[ERROR]: No books were read\n");
                    books = NULL;
                }
            }
            else {
                printf("\n[ERROR]: File does not exist or cannot be opened\n");
            }
            break;

        case 2:
            printf("\n[2] Show all books\n");
            if (books != NULL && book_count > 0) {
                print_all_books(books, book_count);
            }
            else {
                printf("\n[INFO]: No books to show. Please read a file first (option 1)\n");
            }
            break;
        case 3:
            printf("\n[3] Search by author\n");

            if (books == NULL || book_count == 0) {
                printf("\n[INFO]: No books to search.\n");
                break;
            }
            printf("\nPlease, write author name:  ");
            fgets(search_text, sizeof(search_text), stdin);
            search_text[strcspn(search_text, "\n")] = '\0';

            if (filtered_indexes != NULL) {
                free_indexes(filtered_indexes);
                filtered_indexes = NULL;
            }
            filtered_indexes = search_by_author(books, book_count, search_text, &filtered_count);

            if (filtered_count > 0) {
                print_filtered_books(books, filtered_indexes, filtered_count);
            }
            else {
                printf("\n[INFO]: No books found by author: %s\n", search_text);
            }
            break;
        case 4:
            printf("\n[4] Search by title\n");

            if (books == NULL || book_count == 0) {
                printf("\n[INFO]: No books to search.\n");
                break;
            }
            printf("\nPlease, write title of the book:  ");
            fgets(search_text, sizeof(search_text), stdin);

            search_text[strcspn(search_text, "\n")] = '\0';

            if (filtered_indexes != NULL) {
                free_indexes(filtered_indexes);
                filtered_indexes = NULL;
            }
            filtered_indexes = search_by_title(books, book_count, search_text, &filtered_count);

            if (filtered_count > 0) {
                print_filtered_books(books, filtered_indexes, filtered_count);
            }
            else {
                printf("\n[INFO]: No books found by title: %s\n", search_text);
            }
            break;

        default:
            printf("\n[INFO]: Exiting program...\n");
            if (books != NULL) {
                free_books(books);
                books = NULL;
            }

            if (filtered_indexes != NULL) {
                free_indexes(filtered_indexes);
                filtered_indexes = NULL;
            }
            return 0;
        }
    }

    return 0;
}


// 0_0