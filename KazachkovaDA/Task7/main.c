#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "list.h"
#include "additional.h"

int main()
{
	phrase_library* quotes;
	char file_name[] = "list.txt";
	int count = 0;
	quotes = file_to_struct(file_name, &count);


	char request_word[512];
	char exit[] = "exit";

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
			free_memory(quotes);
			return 0;
		}

		//find_quotes_by_key_words(quotes, request_word);

		print_found_quotes(quotes);		

	} while (1);
	free_memory(quotes);
	return 0;
}