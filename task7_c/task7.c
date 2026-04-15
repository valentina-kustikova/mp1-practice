#include <stdio.h>
#include "base.h"

int main() {
	int len = 0;
	Fmagaz ans;
	Fmagaz base = getbase(&len);
	if (base == NULL) {
		printf("BASE LOAD ERROR");
		return 1;
	}
	printf("finding 24h food stores");
	ans = findstores(base, len);
	printer(base, ans);
	return 0;
}