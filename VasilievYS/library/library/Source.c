#include<stdio.h>
#include<stdlib.h>
#include"lib.h"
#include"auxiliary.h"

int main(int argc,char**argv)
{
	int cnt, ch, i=0, cnt_ans;
	char uavtor[99];
	book* col,*ans;
	if (argc < 2) { return 1; }
	cnt = cnt_s(argv[1]);
	col = (book*)malloc(sizeof(book) * cnt);
	read(argv[1], col, cnt);
	scanf("%s", uavtor);
	ans=find(col, cnt, uavtor, &cnt_ans);
	print(ans, cnt_ans);
	free(col);
	free(ans);
	return 0;
}