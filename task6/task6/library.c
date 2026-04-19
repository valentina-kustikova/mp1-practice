#include "library.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

char* trim(char* s) {
	while (isspace(*s)) s++;
	char* end = s + strlen(s) - 1;
	while (end > s && isspace(*end)) end--;
	*(end + 1) = '\0';
	return s;
}
//strstr(books[i].authors, aut)
Fbooks find(Fbooks *books, char* aut) {
	int i, k = 0;
	Fbooks ans;
	for (i = 0; i < books->len; i++) {
		if (strstr(books->books[i].authors, trim(aut)) != NULL) {
			k++;
		}
	}
	ans.len = k;
	ans.books = (book*)malloc(sizeof(book) * k);
	k = 0;
	for (i = 0; i < books->len; i++) {
		if (strstr(books->books[i].authors, trim(aut)) != NULL) {
			ans.books[k] = books->books[i];
			k++;
		}
	};
	return ans;
}

void printer(Fbooks ans) {
	int n = ans.len, i;
	printf("finded books: \n");
	for (i = 0; i < n; i++) {
		printf("%s; %s; %s; %d\n", ans.books[i].authors, ans.books[i].name, ans.books[i].publisher, ans.books[i].year);
	}
}