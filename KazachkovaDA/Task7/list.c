#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "additional.h"

void find_quotes_by_key_words(phrase_library* library, const char* keyword_request,
							  phrase_library* founded)
{
	int  i, j, k, l;
	char lowercase_request[512];
	char lowercase_key_words[512];
	int found_count = 0;
	to_lowercase(keyword_request, lowercase_request);


	for (i = 0; i < library->count; i++)
	{
	
		for (j = 0; j < library->phrases[i].key_words_count; j++)
		{	
			to_lowercase(library->phrases[i].key_words[j], lowercase_key_words);
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

 	founded->count = found_count;
	founded->phrases = (quote*)malloc(found_count * sizeof(quote));
	if (founded->phrases == NULL)
	{
		printf("Memory allocation error");
		return;
	}

	l = 0;
	for (i = 0; i < library->count; i++)
	{
		for (j = 0; j < library->phrases[i].key_words_count; j++)
		{
			to_lowercase(library->phrases[i].key_words[j], lowercase_key_words);
			if (strstr(lowercase_key_words, lowercase_request))
			{
				
				founded->phrases[l].the_line = (char*)malloc(strlen(library->phrases[i].the_line) + 1);
				strcpy_s(founded->phrases[l].the_line, strlen(library->phrases[i].the_line) + 1, library->phrases[i].the_line);

				founded->phrases[l].author = (char*)malloc(strlen(library->phrases[i].author) + 1);
				strcpy_s(founded->phrases[l].author, strlen(library->phrases[i].author) + 1, library->phrases[i].author);

				founded->phrases[l].source = (char*)malloc(strlen(library->phrases[i].source) + 1);
				strcpy_s(founded->phrases[l].source, strlen(library->phrases[i].source) + 1, library->phrases[i].source);

				founded->phrases[l].topic = (char*)malloc(strlen(library->phrases[i].topic) + 1);
				strcpy_s(founded->phrases[l].topic, strlen(library->phrases[i].topic) + 1, library->phrases[i].topic);

				for (k = 0; k < library->phrases[i].key_words_count; k++)
				{
					founded->phrases[l].key_words = (char**)malloc(sizeof(char*) * library->phrases[i].key_words_count);
					founded->phrases[l].key_words_count = library->phrases[i].key_words_count;
					founded->phrases[l].key_words[k] = (char*)malloc(sizeof(library->phrases[i].key_words[k]) + 1);
					strcpy_s(founded->phrases[l].key_words[k], strlen(library->phrases[i].key_words[k]) + 1,
																		library->phrases[i].key_words[k]);
				}

				l++;
			}
			
		}
		
	}
}