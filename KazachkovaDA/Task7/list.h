#ifndef LIST_H
#define LIST_H

struct quote
{
	char* the_line;
	char* author;
	char* source;
	char* topic;
	char* key_words;
};

struct quote* find_quotes_by_words(struct quote* quotes,
	int count, const char* author_request, int* found_count);

#endif
