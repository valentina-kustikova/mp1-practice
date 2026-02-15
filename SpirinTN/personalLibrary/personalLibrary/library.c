#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "auxiliary.h"

STATUS programCycle(BOOK* books, const int countBooks) {
    int operation;
    STATUS status = SUCCESS;
    while (1) {
        if (status != SUCCESS) {
            break;
        }
        printFrame();
        operation = inputOperation();

        if (operation == 1) {
            printFrame();
            status = printListBooks(books, countBooks);
        }
        else if (operation == 2) {
            status = searchBooksByAuthor(books, countBooks);
        }
        else {
            break;
        }
    }
    return status;
}

void printFrame() {
    system("cls");
    printf(MAIN_FRAME);
}

int inputOperation() {
    int operation;
    printf(OPERATIONS);
    printf("Введите операцию: ");
    scanf("%d", &operation);
    while (operation < 0 || operation > 2) {
        printf("Неверная операция! Введите операцию: ");
        scanf("%d", &operation);
    }
    return operation;
}

STATUS searchBooksByAuthor(BOOK* books, const int countBooks) {
    int i;
    char author[64];
    int countFiltredBooks = 0;
    BOOK* filtredBooks = NULL;
    printFrame();
    if (countBooks == 0) {
        printf("В картотеке пусто!\n");
        return ERROR_NO_BOOKS;
    }
    filtredBooks = (BOOK*)malloc(countBooks * sizeof(BOOK));
    if (filtredBooks == NULL) {
        printf("Ошибка выделения памяти!\n");
        return ERROR_MEMORY;
    }
    printf("Введите фамилию автора: ");
    while (getchar() != '\n');
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0';
    for (i = 0; i < countBooks; i++) {
        if (strstr(books[i].authors, author) != NULL) {
            filtredBooks[countFiltredBooks++] = books[i];
        }
    }

    if (countFiltredBooks == 0) {
        printf("Книг авторов с фамилией ...%s... не найдено!\n\n", author);
        system("pause");
    }
    else {
        printf("\nСписок книг авторов с фамилией ...%s...: \n\n", author);
        printListBooks(filtredBooks, countFiltredBooks);
    }

    free(filtredBooks);
    filtredBooks = NULL;
    return SUCCESS;
}