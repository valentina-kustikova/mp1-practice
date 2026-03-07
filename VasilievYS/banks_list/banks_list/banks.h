#ifndef __f
#define __f

typedef struct
{
	char name[99];
	char owner[99];
	float demand;
	float term;
	float save;
}bank;
int find(bank* list, int cnt_s, char* udep);
#endif 
