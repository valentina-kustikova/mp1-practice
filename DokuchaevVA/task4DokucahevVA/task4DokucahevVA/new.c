#include <stdlib.h>
#define N 10
#include <stdio.h>
#include <locale.h>
#include <string.h>

void recorde(char a[], char b[], float c[], float discont, int n) {
	char k;
	a[0] = "0000";
	b[0] = "banan";
	c[0] = 100;
	a[1] = "0001";
	b[1] = "salt";
	c[1] = 200;
	a[2] = "0002";
	b[2] = "sugar";
	c[3] = 300;
	a[3] = "0003";
	b[3] = "apple";
}
int main() {
	char barcode[N][4];
	char name[N][5];
	float cost[N];
	float discont[N];
	recorde(a, N);
}
