#include <stdio.h>
#include <locale.h>
#include <windows.h>
//#define CHER

int is_directory_windows(const char* path);

void user_answer(char* user);

#ifdef CHER
int main() {
	char res[100] = "Hello";
	char ch2[] = "World";

	snprintf(res, 100, "%s %s", res, ch2);
	printf("%s", res);

	return 0;
}
#endif