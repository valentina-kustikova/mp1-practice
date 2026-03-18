#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "list.h"
#include "additional.h"

int main()
{
	quote* quotes;
	quote* found_quotes;
	char file_name[] = "list.txt";
	int count = 0;


	char request_word[512];
	char exit[] = "exit";
	quotes = file_to_struct(file_name, &count);
	int found_count;

	setlocale(LC_ALL, "Russian");

	do
	{
		printf("Enter the key word: ");
		if (!fgets(request_word, sizeof(request_word), stdin))
		{
			printf("Entry error\n");
			return 1;
		}

		request_word[strcspn(request_word, "\n")] = 0;

		if (strcmp(request_word, exit) == 0)
		{
			free_memory(quotes, count);
			return 0;
		}

		found_quotes = find_quotes_by_words(quotes, count, request_word, &found_count);

		print_found_quotes(found_quotes, found_count);

		free_memory(found_quotes, found_count);

	} while (1);

}