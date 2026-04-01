#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include <ctype.h>

phrase_library* file_to_struct(const char* file_name, int* count)
{
	char key_words_copy[512];
	int n = 0, i = 0;
	FILE* file = fopen(file_name, "r");
	char line[2048];
	quote* quotes = NULL;

	if (file == NULL)
	{
		printf("File reading error\n");
		*count = -1;
		return NULL;
	}

	while (fgets(line, sizeof(line), file))
	{
		n++;
	}

	if (n == 0)
	{
		*count = 0;
		printf("No info found in the file");
		fclose(file);
		return NULL;
	}

	rewind(file);

	quotes  = (quote*)malloc(n * sizeof(quote));
	if (quotes == NULL)
	{
		printf("Memory allocation error\n");
		*count = -1;
		fclose(file);
		return NULL;
	}

	while (i < n && fgets(line, sizeof(line), file))
	{
		line[strcspn(line, "\n")] = 0;

		char* the_line = strtok(line, ";");
		char* author = strtok(NULL, ";");
		char* source = strtok(NULL, ";");
		char* topic = strtok(NULL, ";");
		char* key_words = strtok(NULL, ";");

		quotes[i].the_line = (quote*)malloc(strlen(the_line) + 1);
		strcpy_s(quotes[i].the_line, strlen(the_line) + 1, the_line);

		quotes[i].author = (quote*)malloc(strlen(author) + 1);
		strcpy_s(quotes[i].author, strlen(author) + 1, author);

		quotes[i].source = (quote*)malloc(strlen(source) + 1);
		strcpy_s(quotes[i].source, strlen(source) + 1, source);

		quotes[i].topic = (quote*)malloc(strlen(topic) + 1);
		strcpy_s(quotes[i].topic, strlen(topic) + 1, topic);

		strcpy(key_words_copy, key_words);

		char* a_word = strtok(key_words_copy, ",");
		int key_words_count = 0;
		while (a_word != NULL)
		{	
			key_words_count += 1;
			a_word = strtok(NULL, ",");
		}

		quotes[i].key_words = (char**)malloc(sizeof(char*) * key_words_count);
		quotes[i].key_words_count = key_words_count;
		int j = 0;
		a_word = strtok(key_words, ",");
		while (a_word != NULL)
		{
			quotes[i].key_words[j] = (char*)malloc(sizeof(a_word) + 1);
			strcpy_s(quotes[i].key_words[j], strlen(a_word) + 1, a_word);
			j++;
			printf_s("%s", &quotes[i].key_words[j]);
			a_word = strtok(NULL, ",");
		}
		
		i++;
	}

	phrase_library* library = (phrase_library*)malloc(sizeof(phrase_library));
	library->phrases = quotes;
	library->count = n;

	fclose(file);
	return library;
}

void to_lowercase(const char* before, char* after)
{
	for (; *before != '\0'; before++, after++)
	{
		*after = tolower((unsigned char)*before);
	}
	*after = '\0';
}

void print_found_quotes(phrase_library* library)
{
	int i;
	for (i = 0; i < library->count; i++)
	{
		printf("The found quote: %s\n", library->phrases[i].the_line);
	}
}

void free_memory(phrase_library* library)
{
	int i, j = 0;
	for (i = 0; i < library->count; i++)
	{
		free(library->phrases[i].the_line);
		free(library->phrases[i].author);
		free(library->phrases[i].source);
		free(library->phrases[i].topic);
		for (j = 0; i < library->phrases[i].key_words_count; i++)
		{
			free(library->phrases[i].key_words[j]);
		}
		free(library->phrases[i].key_words);
	}
	free(library);
}