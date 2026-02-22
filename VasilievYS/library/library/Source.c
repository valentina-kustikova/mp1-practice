#include<stdio.h>
#include<stdlib.h>
#include"lib.h"
#include"auxiliary.h"

int main()
{
	int cnt, ch, i=0, cnt_ans;
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
	ans=find(col, cnt, uavtor, &cnt_ans);
	print(ans, cnt_ans);
	free(col);
	free(ans);
	return 0;
}