#ifndef __f
#define __f
#define MAX_LEN 512

typedef struct
{
	char name[MAX_LEN];
	float percentage;
} deposit;

typedef struct
{
	char name[MAX_LEN];
	char owner[MAX_LEN];
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
