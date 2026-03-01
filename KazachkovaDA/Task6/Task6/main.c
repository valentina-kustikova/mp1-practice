#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "library.h"
#include "auxiliary.h"
#include <ctype.h>

void to_lowercase()

int main()
{
	setlocale(LC_ALL, "Russian");

	char file_name[] = "library.txt";
	int count = 0;
	struct book* books = file_to_struct(file_name, &count);


	char request_author[512];

	printf("¬ведите фамилию автора (на английском): ");
	if (!fgets(request_author, sizeof(request_author), stdin))
	{
		printf("ќшибка ввода\n");
		return 1;
	}

	request_author[strcspn(request_author, "\n")] = 0;

	int found_count;
	struct book *found_books = find_books_by_author(books, count, request_author, &found_count);

	print_found_books(found_books, found_count);
	
	free_memory(books, count);

	return 0;

}