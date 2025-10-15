#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define N 10
int main()
{
	setlocale(LC_ALL, "Rus");
	int arr[N];
	int n;
	int numb;
	int i;
	i = 0;
	scanf_s("¬ведите длину слова: %d", &n);
	srand(time(NULL));
	numb = (rand()%100000)+10;
	printf_s("%d\n", numb);
	while (numb > 0) {
		arr[i] = numb % 10;
		numb /= 10;
		i += 1;
		printf_s("%d", numb);
	}
	for (i = 0; i < n; i++) {
		printf_s("%d", arr[i]);
	}
	return 0;

}