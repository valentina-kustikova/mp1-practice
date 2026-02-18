#ifndef __f
#define __f

typedef struct
{
	char avtors[99];
	char name[99];
	char pub[99];
	int year;
}book;

book* find(book* list, int cnt_s, char *uavtor); // todo: author
#endif 