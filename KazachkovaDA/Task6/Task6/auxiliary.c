#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

struct book* file_to_struct(const char* file_name, int* count)
{
	FILE* file = fopen(file_name, "r");

	int size = 10;
	struct book* books = malloc(size * sizeof(struct book));
	char line[512];
	int n = 0;

	while (fgets(line, sizeof(line), file)) //куда, кол-во символов для считывания, откуда;
	{											//возвращает NULL, когда достигнут конец файла
		{
			line[strcspn(line, "\n")] = 0;//strcspn выводит, сколько символов было встречено до "\n"
			//элемент строки с этим номером заменяем на 0
		}

		if (n == size)
		{
			size += 1;
			struct book* temp = realloc(books, size * sizeof(struct book));
			if (temp == 0)
			{
				printf("Ошибка выделения памяти");
				for (int i = 0; i < n; i++)
				{ 
					free(books[i].author);
					free(books[i].title);
					free(books[i].publisher);

				}
				free(books);
				fclose(file);
				*count = 0;
				return NULL;
			}
			books = temp;
		}

		char* author = strtok(line, ";");//возвращает указатель на первую найденную лексему в строке 
		char* title = strtok(NULL, ";");
		char* publisher = strtok(NULL, ";");
		char* publishing_year = strtok(NULL, ";");


		books[n].author = malloc(strlen(author) + 1);
		strcpy_s(books[n].author, strlen(author) + 1, author);

		books[n].title = malloc(strlen(title) + 1);
		strcpy_s(books[n].title, strlen(title) + 1, title);

		books[n].publisher = malloc(strlen(publisher) + 1);
		strcpy_s(books[n].publisher, strlen(publisher) + 1, publisher);

		books[n].publishing_year = atoi(publishing_year);


		n++;

	}
	fclose(file);
	*count = n;
	return books;
}

void free_memory(struct book *books, int count)
{
	for (int i = 0; i < count; i++)
	{
		free(books[i].author);
		free(books[i].title);
		free(books[i].publisher);
	}
	free(books);
}
