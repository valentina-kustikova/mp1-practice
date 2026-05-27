#include <stdio.h>
#include "base.h"
#pragma warning(disable : 4996)

int main(int argc, char*argv[]) {
	box ans;
	box list;
	if (argc < 2) {
		printf("no args");
		return 0;
	}
	list = getbase(argv[1]);
	if (list.len == 0) {
		printf("BASE LOAD ERROR");
		return 1;
	}
	printf("finding 24h food stores:\n");
	ans = findstores(&list);
	printer(&ans);
	printf(" \ntotal stores founded: %d", ans.len);
	delit(&list);
	delit(&ans);
	return 0;
}