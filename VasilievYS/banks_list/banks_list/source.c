#include<stdio.h>
#include<stdlib.h>
#include"banks.h"
#include"auxiliary.h"
int main(int argc, char** argv)
{
	int j=0, ch, i = 0, idx_ans;
	char udep[MAX_LEN];
	banks_library lib;
	if (argc < 2) { return 1; }
	lib.cnt = cnt_s(argv[1]);
	lib.banks = (bank*)malloc(sizeof(bank) * lib.cnt);
	read(argv[1], &lib);
	scanf("%[^\n]", udep);
	to_low(udep);
	idx_ans = find(&lib, udep);
	if (idx_ans == -1) { printf("NO"); free_b(&lib); return 1; }
	print(lib.banks[idx_ans]);
	free_b(&lib);
	return 0;
}