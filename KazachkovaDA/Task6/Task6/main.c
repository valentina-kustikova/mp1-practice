#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

struct book
{
	char* author, * title, * publisher;
	int publishing_year;
};

struct book* file_to_struct(const char* file_name, int *count);

int main()
{
	setlocale(LC_ALL, "Russian");
	char file_name[] = "library.txt";
	int count = 0;
	
	return 0;

}

struct book* file_to_struct(const char* file_name, int *count)
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
			//элеменрт строки с этим номером заменяем на 0
		}

		if (n == size)
		{
			size += 1;
			books = realloc(books, size * sizeof(struct book));

		}

		char* author = strtok(line, ";");
		char* title = strtok(NULL, ";");
		char* publisher = strtok(NULL, ";");
		char* publishing_year = strtok(NULL, ";");

		books[n].author = malloc(strlen(author) + 1);
		books[n].title = malloc(strlen(title) + 1);
		books[n].publisher = malloc(strlen(publisher) + 1);
		books[n].publishing_year = malloc(strlen(publishing_year) + 1);

		n++;

	}
	fclose(file);
	*count = n;
	return books;
}
