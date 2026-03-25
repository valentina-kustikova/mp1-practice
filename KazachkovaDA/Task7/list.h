#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct
{
	char* the_line;
	char* author;
	char* source;
	char* topic;
	char** key_words;
	int key_words_count;
	
} quote;

typedef struct
{
	quote* phrases;//указывает на область памяти, в которой подряд лежат структуры
	int count;
} phrase_library;

//void find_quotes_by_key_words(phrase_library* library, const char* keyword_request);


#endif
