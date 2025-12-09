#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
//#define CHER
#define N 5

int is_directory_windows(const char* path);

void user_answer(char* user);

#ifdef CHER
int main() {
	setlocale(LC_ALL, "rus");

	int res[] = { 51,52,56,54,50 };
	int res1[] = { 0,1,2,3,4 };
	time_t start, end;
	double time_used;

	start = time(NULL);
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (res[i] < res[j]) {
				int buff = res[i];
				res[i] = res[j];
				res[j] = buff;

				buff = res1[i];
				res1[i] = res1[j];
				res1[j] = buff;
			}
		}
	}
	end = time(NULL);

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", res[i], res1[i]);
	}
	time_used = end - start;
	printf("Время выполнения: %f секунд\n", time_used);

	return 0;
}
#endif