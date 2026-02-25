#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxiliary.h"


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

void printError(STATUS status) {
	switch (status) {
	case INSUFFICIENT_ARGUMENTS_ERROR:
		printf("Количество аргументов при запуске программы меньше двух!\n");
		break;
	case ERROR_MEMORY:
		printf("Ошибка выделения памяти!\n");
		break;
	case INVALID_FILE:
		printf("Текстовый файл некорректный!\n");
		break;
	case FILE_OPENING_ERROR:
		printf("Ошибка при открытии файла!\n");
		break;
	case FILE_CLOSE_ERROR:
		printf("Ошибка при закрытии файла!\n");
		break;
	case ERROR_NO_BOOKS:
		printf("В картотеке книг нет!\n");
		break;
	case ERROR_NO_FILTRED_BOOKS:
		printf("Книг заданного автора не найдено!\n");
		break;
	}
}

STATUS programCycle(BOOK* books, int countBooks) {
	int operation;
	STATUS status = SUCCESS;
	while (1) {
		if (status != SUCCESS) {
			printError(status);
			break;
		}
		printFrame();
		operation = inputOperation();

		if (operation == 1) {
			printFrame();
			status = printListBooks(books, countBooks);
		}
		else if (operation == 2) {
			status = searchBooksInterface(books, countBooks);
		}
		else {
			break;
		}
	}
	return status;
}

STATUS printListBooks(const BOOK* books, int countBooks) {
    int i;
    if (countBooks == 0) {
		return ERROR_NO_BOOKS;
    }

    for (i = 0; i < countBooks; i++) {
        printf("%d. %s\nАвторы: %s\nИздательство: %s\nГод изд-ва: %d\n\n", 
        i+1, books[i].title, books[i].authors, books[i].publishingHouse, books[i].yearPublishing);
    }
    system("pause");
    return SUCCESS;
}

STATUS searchBooksInterface(const BOOK* books, int countBooks) {
	int i;
	char author[LENGTH_STRING + 1];
	int countAuthorBooks = 0;
	BOOK* authorBooks = NULL;
	STATUS status;

	printFrame();
	inputAuthor(author, sizeof(author));
	
	status = searchBooksByAuthor(books, countBooks, author, &authorBooks, &countAuthorBooks);
	if (status == ERROR_MEMORY) {
		return status;
	}

	if (status != ERROR_NO_FILTRED_BOOKS) {
		printf("\nКниги автора ...%s... (найдено всего - %d):\n\n", author, countAuthorBooks);
		printListBooks(authorBooks, countAuthorBooks);
	}
	else {
		printf("\nКниг автора ...%s... не найдено!\n\n", author);
		system("pause");
	}	

	free(authorBooks);
	authorBooks = NULL;
	return SUCCESS;
}

void inputAuthor(char author[], int maxLen) {
	printf("Введите фамилию автора: ");
	while (getchar() != '\n');
	fgets(author, maxLen, stdin);
	author[strcspn(author, "\n")] = '\0';
}