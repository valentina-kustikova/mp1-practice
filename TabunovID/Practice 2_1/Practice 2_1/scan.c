#include "comand.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int new_initializing(Scommandbook* phonebook) {
	if (phonebook->comands != NULL) {
		//SPhone* copy = phonebook->phones;
		if (phonebook->comands == (Scommand*)malloc(100 * sizeof(Scommand))) {
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
		if (!(phonebook->comands == (Scommand*)malloc(100 * sizeof(Scommand)))) {
			printf("Something went wrong\n");
			return 0;
		}
		phonebook->length = 100;
	}
	return 1;
}

void scan(Scommandbook* book) {
	char filename[1023];
	printf("Enter file path: ");
	// scanf("%s", filename);
	fgets(filename, 1023,stdin);
	FILE* f;
	int len;
	len = strlen(filename);
	filename[len-1] = 0;
	f = fopen(filename, "r");
	if (f == NULL) {
		printf("I can not open %s", filename);
		return 1;
	}

	int length;
	fscanf(f,"%d",&length);
	book->length = length;
	// file operations...


	book->comands = (Scommand*)malloc(book->length * sizeof(Scommand));
	for (int i = 0; i < book->length; i++) {
			char bufer[STRLEN] = { 0 };
			fgets(bufer, STRLEN, f);
			size_t length = strlen(bufer) - 1;
			bufer[length] = '\0';
			book->comands[i].Name = (char*) malloc((length + 1) * sizeof(char));
			memcpy(book->comands[i].Name, bufer, (length + 1) * sizeof(char));
			fgets(bufer, STRLEN, f);
			length = strlen(bufer) - 1;
			bufer[length] = '\0';
			book->comands[i].City = (char*) malloc((length + 1) * sizeof(char));
			memcpy(book->comands[i].City, bufer, (length + 1) * sizeof(char));
			fscanf(f, "%d %d %d", &(book->comands[i].Games), 
				&(book->comands[i].Points), &(book->comands[i].Players));
			fgetc(f);
	}
	fclose(f);
	return;
	
}

void output() {
	Scommandbook book;
	book.comands = NULL;
	book.length = 0;
	scan(&book);
	size_t best_id = 0;
	if (book.comands != NULL) {
		for (size_t i = 1; i < book.length; i++)
		{
			if (book.comands[best_id].Points < book.comands[i].Points)
				best_id = i;
		}
		printf("%s\n%s\n%d\n%d\n%d", book.comands[best_id].Name, 
			book.comands[best_id].City, book.comands[best_id].Games, 
			book.comands[best_id].Players, book.comands[best_id].Points);
	}
}