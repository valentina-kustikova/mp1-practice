#include "comand.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "scan.h"
#define STRLEN 10
int new_initializing(Scommandbook* phonebook) {
	if (phonebook->comands != NULL) {
		//SPhone* copy = phonebook->phones;
		if (phonebook->comands = (Scommand*)malloc(100 * sizeof(Scommand))) {
			phonebook->length = 100;
		}
		else
		{
			printf("You have to much contacts");
			return 0;
		}
	}
	else
	{
		if (!(phonebook->comands = (Scommand*)malloc(100 * sizeof(Scommand)))) {
			printf("Something went wrong\n");
			return 0;
		}
		phonebook->length = 100;
	}
	return 1;
}
void scan(Scommandbook* book) {
	errno_t err;
	FILE* f;
	err = fopen_s(&f, "input.txt", "r");
	if (err == NULL) {
		printf("I can open input.txt\n");
		fscanf_s(f, "%d", &(book->length));
		fgetc(f);
		book->comands = (Scommand*)malloc(book->length* sizeof(Scommand));
		for (int i = 0; i < book->length; i++) {
				char bufer[STRLEN] = { 0 };
				fgets(bufer, STRLEN, f);
				size_t length = strlen(bufer) - 1;
				book->comands[i].Name = calloc(length + 1, sizeof(char));
				for (size_t j = 0; j < length; j++)
				{
					book->comands[i].Name[j] = bufer[j];
				}
				fgets(bufer, STRLEN, f);
				length = strlen(bufer) - 1;
				book->comands[i].City = calloc(length + 1, sizeof(char));
				for (size_t j = 0; j < length; j++)
				{
					book->comands[i].City[j] = bufer[j];
				}
				fscanf_s(f, "%d %d %d", &(book->comands[i].Games), &(book->comands[i].Points), &(book->comands[i].Players));
				fgetc(f);
		}
	}
	else {
		printf("I can not open input.txt");
	}
	fclose(f);
	return;
	
}
void output() {
	Scommandbook book = { 0,0 };
	scan(&book);
	size_t best_id = 0;
	if (book.comands != NULL) {
		for (size_t i = 1; i < book.length; i++)
		{
			if (book.comands[best_id].Points < book.comands[i].Points)
				best_id = i;
		}
		printf("%s\n%s\n%d\n%d\n%d", book.comands[best_id].Name, book.comands[best_id].City, book.comands[best_id].Games, book.comands[best_id].Players, book.comands[best_id].Points);
	}
}