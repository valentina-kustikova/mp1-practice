#ifndef LIBRARY_H
#define LIBRARY_H

struct book
{
	char* author;
	char* title;
	char* publisher;
	int publishing_year;
};

struct book* find_books_by_author(struct book* books,
	int count,
	const char* author_request);

#endif