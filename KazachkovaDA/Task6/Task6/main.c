#include <stdio.h>
#include <locale.h>
#include "library.h"
#include "auxiliary.h"

struct book* file_to_struct(const char* file_name, int *count);

int main()
{
	setlocale(LC_ALL, "Russian");

	char file_name[] = "library.txt";
	int count = 0;
	file_to_struct(file_name, count);
	
	//struct book* books = file_to_struct(file_name, &count);

    /*if (!books || count == 0)
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
	
	free_memory(books, count);*/

	return 0;

}

struct book* file_to_struct(const char* file_name, int *count)
{
	int n = 0;
	FILE* file = fopen(file_name, "r");

	if (file == NULL)
	{
		printf("Ошибка считывания файла");
		return 1;
	}

	char line[512];
	while (fgets(line, sizeof(line), file))
	{
		n++;
	}

	struct book* books = malloc(n * sizeof(struct book));

	if (books == NULL)
	{
		printf("Ошибка выделения памяти");
		free(books);
		return 1;
	}

	while (fgets(line, sizeof(line), file))
	{
		line[strcspn(line, "\n")] = 0;

		char* author = strtok(line, ";");//возвращает указатель на первую найденную лексему в строке 
		char* title = strtok(NULL, ";");
		char* publisher = strtok(NULL, ";");
		char* publishing_year = strtok(NULL, ";");

		printf("%p", author);
		printf("%p", books);

		/*books[i].author = malloc(strlen(author) + 1);
		strcpy_s(books[i].author, strlen(author) + 1, author);

		books[i].title = malloc(strlen(title) + 1);
		strcpy_s(books[i].title, strlen(title) + 1, title);

		books[i].publisher = malloc(strlen(publisher) + 1);
		strcpy_s(books[i].publisher, strlen(publisher) + 1, publisher);

		books[i].publishing_year = atoi(publishing_year);*/

	}
}


