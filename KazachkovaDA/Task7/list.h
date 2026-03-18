#ifndef LIST_H
#define LIST_H

typedef struct
{
	char* the_line;
	char* author;
	char* source;
	char* topic;
	char **key_words;
	int words_num;
	
} quote;

typedef struct
{
	quote* phrases;//указывает на область памяти, в которой подряд лежат структуры
	int count;
} phrase_library;

quote* find_quotes_by_words(quote* quotes,
	int count, const char* keyword_request, int* found_count);
/*
void find_quotes_by_words(phrase_library *library, const char* keyword_request,
	phrase_library *keyword_phrases)
*/

#endif
