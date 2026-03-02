#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "additional.h"

struct quote* find_quotes_by_words(struct quote* quotes,
	int count, const char* word_request, int* found_count)
{
	*found_count = 0;

	char lowercase_request[512];
	to_lowercase(word_request, lowercase_request);

	int  i;
	for (i = 0; i < count; i++)
	{
		if (quotes[i].key_words)
		{
			char lowercase_key_words[512];
			to_lowercase(quotes[i].key_words, lowercase_key_words);
			if (strstr(lowercase_key_words, lowercase_request))
			{
				(*found_count)++;
			}
		}

	}

	if (*found_count == 0)
	{
		printf("No phrases found\n");
		return NULL;
	}

	struct quote* found_quotes = malloc(*found_count * sizeof(struct quote));
	if (found_quotes == NULL)
	{
		printf("");
		*found_count = -1;
		return NULL;
	}

	int j = 0;
	for (i = 0; i < count; i++)
	{
		if (quotes[i].key_words)
		{
			char lowercase_key_words[512];
			to_lowercase(quotes[i].key_words, lowercase_key_words);
			if (strstr(lowercase_key_words, lowercase_request))
			{

				found_quotes[j].the_line = malloc(strlen(quotes[i].the_line) + 1);
				strcpy_s(found_quotes[j].the_line, strlen(quotes[i].the_line) + 1, quotes[i].the_line);

				found_quotes[j].author = malloc(strlen(quotes[i].author) + 1);
				strcpy_s(found_quotes[j].author, strlen(quotes[i].author) + 1, quotes[i].author);

				found_quotes[j].source = malloc(strlen(quotes[i].source) + 1);
				strcpy_s(found_quotes[j].source, strlen(quotes[i].source) + 1, quotes[i].source);

				found_quotes[j].topic = malloc(strlen(quotes[i].topic) + 1);
				strcpy_s(found_quotes[j].topic, strlen(quotes[i].topic) + 1, quotes[i].topic);

				found_quotes[j].key_words = malloc(strlen(quotes[i].key_words) + 1);
				strcpy_s(found_quotes[j].key_words, strlen(quotes[i].key_words) + 1, quotes[i].key_words);

				j++;
			}
		}

	}

	*found_count = j;
	return found_quotes;
}