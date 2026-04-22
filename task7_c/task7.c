#include <stdio.h>
#include "base.h"

int main() {
	box ans;
	box list = getbase();
	if (list.len == 0) {
		printf("BASE LOAD ERROR");
		return 1;
	}
	printf("finding 24h food stores\n");
	ans = findstores(base, len);
	printer(base, ans);
	delit(base, len);
	return 0;
}