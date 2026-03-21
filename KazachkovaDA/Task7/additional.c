 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include <ctype.h>

struct phrase_library* file_to_struct(const char* file_name, int* count)
{
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

	quotes  = (struct quote*)malloc(n * sizeof(quote));
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

		quotes[i].the_line = (struct quote*)malloc(strlen(the_line) + 1);
		strcpy_s(quotes[i].the_line, strlen(the_line) + 1, the_line);

		quotes[i].author = (struct quote*)malloc(strlen(author) + 1);
		strcpy_s(quotes[i].author, strlen(author) + 1, author);

		quotes[i].source = (struct quote*)malloc(strlen(source) + 1);
		strcpy_s(quotes[i].source, strlen(source) + 1, source);

		quotes[i].topic = (struct quote*)malloc(strlen(topic) + 1);
		strcpy_s(quotes[i].topic, strlen(topic) + 1, topic);

		char* a_word = strtok(key_words, ",");
		if (a_word == NULL)
		{
			printf("No keywords found in this line");
			continue;
		}

		int key_words_count = 0;
		while (a_word != NULL)
		{	

			a_word = strtok(NULL, ",");
		}

		i++;
	}

	fclose(file);
	*count = n;
	return phrase_library;
}

void to_lowercase(const char* before, char* after)
{
	for (; *before != '\0'; before++, after++)
	{
		*after = tolower((unsigned char)*before);
	}
	*after = '\0';
}

void print_found_quotes(struct quote* found_quotes, int found_count)
{
	int i;
	for (i = 0; i < found_count; i++)
	{
		printf("The found quote: %s\n", found_quotes[i].the_line);
	}
}

void free_memory(struct quote* quotes, int count)
{
	for (int i = 0; i < count; i++)
	{
		free(quotes[i].the_line);
		free(quotes[i].author);
		free(quotes[i].source);
		free(quotes[i].topic);
		free(quotes[i].key_words);
	}
	free(quotes);
}