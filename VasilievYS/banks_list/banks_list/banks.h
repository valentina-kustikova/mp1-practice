#ifndef __f
#define __f
//константы как макс размер сьроки
typedef struct
{
	char name[100];
	float percentage;
} deposit;

typedef struct
{
	char name[99];
	char owner[99];
	deposit* deposites;
	int deposits_count;
}bank;

typedef struct
{
	bank* banks;
	int cnt;
} banks_library;

int find(banks_library* library, char* udep);
#endif 
