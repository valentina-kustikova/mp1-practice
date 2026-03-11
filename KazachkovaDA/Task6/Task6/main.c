#include <stdio.h>
#include <locale.h>
#include "library.h"
#include "auxiliary.h"

//int main(int argc, char **argv)
int main()
{
	setlocale(LC_ALL, "Russian");

	//char file_name[] = argv[2];
	char file_name[] = "library.txt";
	int count = 0;
	struct book* books = file_to_struct(file_name, &count);


	char request_author[512];
	char exit[] = "exit";

	do
	{
		printf("Enter the author's surname: ");
		if (!fgets(request_author, sizeof(request_author), stdin))//В случае успеха функция возвращает указатель на строкy
		{
			printf("Entry error\n");
			return 1;
		}

		request_author[strcspn(request_author, "\n")] = 0;

		if (strcmp(request_author, exit) == 0)
		{
			free_memory(books, count);
			return 0;
		}

		int found_count;
		struct book* found_books = find_books_by_author(books, count, request_author, &found_count);

		print_found_books(found_books, found_count);

	} while (1);

}