#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "additional.h"

void find_quotes_by_key_words(phrase_library* library, const char* keyword_request,
	phrase_library* keyword_phrases)
{
	int  i, j, k = 0;
	char lowercase_request[512];
	quote* found_quotes = NULL;
	int found_count = 0;
	to_lowercase(keyword_request, lowercase_request);


	for (i = 0; i < (*library).count; i++)
	{
		for (j = 0; j < (*library).phrases[i].key_words_count; j++)
		{
			char lowercase_key_words[512];
			to_lowercase((*library).phrases[i].key_words[j], lowercase_key_words);
			if (strstr(lowercase_key_words, lowercase_request))
			{
				found_count++;
				break;
			}
		}

	}

	if (found_count == 0)
	{
		printf("No phrases found\n");
	}

	found_quotes = (struct quote*)malloc(found_count * sizeof(quote));
	if (found_quotes == NULL)
	{
		printf("Memory allocation error");
	}

	for (i = 0; i < (*library).count; i++)
	{
		for (j = 0; j < (*library).phrases[i].key_words_count; j++)
		{
			char lowercase_key_words[512];
			to_lowercase((*library).phrases[i].key_words[j], lowercase_key_words);
			if (strstr(lowercase_key_words, lowercase_request))
			{

				found_quotes[i].the_line = (char*)malloc(strlen((*library).phrases[i].the_line) + 1);
				strcpy_s(found_quotes[j].the_line, strlen((*library).phrases[i].the_line) + 1, (*library).phrases[i].the_line);

				found_quotes[i].author = (char*)malloc(strlen((*library).phrases[i].author) + 1);
				strcpy_s(found_quotes[j].author, strlen((*library).phrases[i].author) + 1, (*library).phrases[i].author);

				found_quotes[i].source = (char*)malloc(strlen((*library).phrases[i].source) + 1);
				strcpy_s(found_quotes[j].source, strlen((*library).phrases[i].source) + 1, (*library).phrases[i].source);

				found_quotes[i].topic = (char*)malloc(strlen((*library).phrases[i].topic) + 1);
				strcpy_s(found_quotes[j].topic, strlen((*library).phrases[i].topic) + 1, (*library).phrases[i].topic);

				for (k = 0; k < (*library).phrases[i].key_words_count[j]; k++)
				{
					found_quotes[i].key_words = (char**)malloc(sizeof(char*) * (*library).phrases[i].key_words_count);
					found_quotes[i].key_words_count = (*library).phrases[i].key_words_count;
					found_quotes[i].key_words[k] = (char*)malloc(sizeof((*library).phrases[i].key_words[k]) + 1);
					strcpy_s(found_quotes[i].key_words[k], strlen((*library).phrases[i].key_words[k]) + 1, 
																		(*library).phrases[i].key_words[k]);
				}

			}

		}

	}
}