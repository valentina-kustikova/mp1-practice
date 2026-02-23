#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "auxiliary.h"

struct book* find_books_by_author(struct book* books, int count, const char* author_request);

int main()
{
	setlocale(LC_ALL, "Russian");

	char file_name[] = "library.txt";
	int count = 0;
	
	struct book* books = file_to_struct(file_name, &count);

    if (!books || count == 0)
        {
            printf("Ошибка чтения книг\n");
            return 1;
        }

	char request_author[512];
	printf("Введите фамилию автора (на английском): ");
	if (!fgets(request_author, sizeof(request_author), stdin))
	{
		printf("Ошибка ввода\n");
		return 1;
	}

	request_author[strcspn(request_author, "\n")] = 0;

	find_books_by_author(books, count, request_author);
	
	free_memory(books, count);

	return 0;

}


