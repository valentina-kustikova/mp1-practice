#include<stdio.h>
#include<stdlib.h>
#include"banks.h"
#include"auxiliary.h"
int main(int argc, char** argv)
{
	int cnt, ch, i = 0, idx_ans;
	char udep[50];
	bank* list;
	if (argc < 2) { return 1; }
	cnt = cnt_s(argv[1]);
	list = (bank*)malloc(sizeof(bank) * cnt);
	read(argv[1], list, cnt);
	scanf("%s", udep);
	/*for (i = 0; i < cnt; i++)
	{
		printf("%s; Ownership form:%s; %.2f; %.2f; %.2f\n", list[i].name, list[i].owner, list[i].demand, list[i].term, list[i].save);
	}*/
	/*printf("!%s!", udep);*/
	idx_ans = find(list, cnt, udep);
	if (idx_ans != -1) { print(list[idx_ans]); }
	else { printf("NO"); }
	free(list);
	return 0;
}