#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define N 1000
#define sizedb 15

char* code[sizedb] = { "0001", "0002", "0003", "0004", "0005", "0006", "0007", "0008", "0009", "0010", "0011", "0012", "0013", "0014", "0015"};
char* name[sizedb] = { "apples", "milk", "bananas", "bread", "juice", "ketchup", "mayonaise", "eggs", "cheese", "tomatoes", "sausages", "salad", "meat", "butter", "fish"};
int price[sizedb] = {100, 90, 75, 30, 300, 80, 75, 60, 140, 200, 300, 250, 400, 170, 270};
int discount[sizedb] = {15, 10, 25, 35, 5, 20, 40, 35, 10, 35, 45, 10, 10, 20, 40};
int cnt[sizedb] = { 0 };

int scan(char code[]);
void add(char code[]);
void print_reciept();

int main()
{
	do {
		char code[5];
		char ans;
		int err = scan(code);
		if (err != 0) continue;
		printf("Add?");
		scanf("%c", &ans);
		if (ans == 'y') add(code);
	} while (exit_prog);
	print_reciept();
	return 0; 
}

int scan(char code[])
{
	int idx = -1;
	printf("Input code: ");
	scanf("%s", code);
	idx = search(code);
	return (idx > 0 ? 0 : 1);
}

void add(char code[])
{}

void print_reciept()
{}
