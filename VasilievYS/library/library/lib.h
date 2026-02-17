#ifndef __f
#define __f
#define _CRT_SECURE_NO_WARNINGS
typedef struct
{
	char avtors[99];
	char name[99];
	char pub[99];
	int year;
}book;
void find(book* list, int cnt_s);
#endif 