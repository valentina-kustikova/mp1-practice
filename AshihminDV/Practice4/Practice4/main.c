#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
//_CRT_SECURE_NO_WARNINGS

int proverka(int *m, int pos);
void gener(int *m, int n);

int main() 
{
	setlocale(LC_ALL, "Rus");
	srand((unsigned int)time(0));
	int n=0, i=0, ch = 0, pr = 1;
	int m[5], buk = 0, k = 0, cop_ch = 0, s = 0, ip=0;
	do 
	{
		printf("Введите длину числа(от 2 до 5)");
		scanf(" %d", &n);
	} while (n < 2 || n>5);

	gener(&m[0], n);
	//for (i = 0; i < n; i++) {
	//	printf("a[i] = %d \n", m[i]);
	//}
	do 
	{
		buk = 0, k = 0;
		printf("Введите число длиной %d \n", n);
		scanf("%d", &ch);
		cop_ch = ch;
		for (i = 0; i < n; i++) {
			
			s = cop_ch % 10;
			if (m[n-i-1] == s) {
				buk++;
			}
			else {
				for (ip = 0; ip < n; ip++) {
	
					if (m[ip] == s) {
						k++;
					}
				}
			}

			cop_ch = cop_ch / 10;
		}
		printf("Быков %d \n", buk);
		printf("Коров %d \n", k);
	} while (buk != n);

	printf("Вы победили, угадав число %d", ch);
	return 0;
}

/*int buk(int* m, int ch, int n) {
	int kop_ch = ch, i = 0, ks = 0, s = 0;
	for (i = 0; i < n; i++) {
		s = kop_ch / pow(10, n - i);
		if (m[i] == s) {
			ks++;
		}
	}
	return ks; 
}*/

/*int korova(int ch, int n, int *m)
{
	int kop_ch = ch, i = 0, k = 0, s = 0;
	for (i = 0; i < n; i++) {
		//s = kop_ch / pow(10, n - i);
		if (m[i] == s) {
			k++;
		}
	}
	return k;
}*/

int proverka(int *m, int pos)
{
	int i = 0, k = 0;
	for (i = 0; i < pos; i++) {
		if (m[i] == m[pos]) {
			k++;
		}
	}
	if (k == 0) {
		return 2;
	}
	else { return 1; }
}

void gener(int* m, int n)
{
	srand((unsigned int)time(0));
	int i = 0;
	m[i] = rand() % 9 + 1;
	for (i = 1; i < n; i++) {
		do {
			m[i] = rand() % 10;
		} while (proverka(&m[0], i) == 1);
		
	}
}