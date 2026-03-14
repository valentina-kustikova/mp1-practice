#include "library.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int* find(book* books, char* aut, int n) {
	int i, k = 0;
	for (i = 0; i < n; i++) {
		if (strstr(books[i].autors, aut) != NULL) {
			k++;
		}
	}
	int *ans = (int*)malloc(sizeof(int) * (k + 1));
	if (ans == NULL) {
		printf("memory error");
	}
	ans[0] = k;
	k = 1;
	for (i = 0; i < n; i++) {
		if (strstr(books[i].autors, aut) != NULL) {
			ans[k] = i;
			k++;
		}
	}
	return ans;
}

void printer(book* books, int* ans) {
	int n = ans[0], i;
	printf("finded books: \n");
	for (i = 1; i < n + 1; i++) {
		printf("%39s; %19s; %19s; %d", books[ans[i]].autors, books[ans[i]].name, books[ans[i]].publisher, books[ans[i]].year);
	}
}