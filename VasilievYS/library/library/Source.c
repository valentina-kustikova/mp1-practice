#include<stdio.h>
#include<stdlib.h>
#include"lib.h"
#include"auxiliary.h"

int main()
{
	int cnt,  ch, i=0;
	char uavtor[99];
	book* col,*ans;
	cnt = cnt_s("data.txt");
	col = (book*)malloc(sizeof(book) * cnt);
	read("data.txt", col, cnt);
	while ((ch = getchar()) != '\n')
	{
		uavtor[i] = ch;
		i++;
	}
	uavtor[i] = '\0';
	ans=find(col, cnt, uavtor);
	printf("%s", ans[0].avtors);
	free(col);
	free(ans);
	return 0;//todo: печать ответа и доделать read
}