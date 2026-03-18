#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // todo
#include <locale.h>
#include <string.h>
#include "funcs.h"
#include "library.h"

int main(int argc, char **argv) {
	int flag = 0, true = 1, cnt_books;
	char user, *file;
	if (argc < 2) {
		printf("Incorrect number of arguments");
		return 1;
	}
	file = argv[1];

	do {
		system("cls");
		printf("|--------------------------------|\n");
		printf("|      HOME LIBRARY SYSTEM       |\n");
		printf("|--------------------------------|\n");
		printf("|  1. Scan library catalog       |\n");
		printf("|  2. Search by author           |\n");
		printf("|  0. Exit                       |\n");
		printf("|--------------------------------|\n");

		u_answer(&user);

		switch (user) {
			system("cls");
		case '1':
			cnt_books = scan_file(file); 
			flag = 1;
			break;
		case '2':
			if (flag == 0) {
				printf("The file has not been scanned!\n");
			}
			else {				
				Book* arr = (Book*)malloc(sizeof(Book) * cnt_books), *id_books;
				int cnt_id;
				char* users_choice;

				system("cls");
				fill_arr(arr, file);
				enter_the_author(&users_choice);
				cnt_id = find_book(arr, cnt_books, &id_books, users_choice);
				print_books(id_books, cnt_id);
				free(arr);
				free(id_books);
			}
			break;
		default:
			true = 0;
			break;
		}
		system("pause");
	} while (true);

	printf("End of the programm");

	return 0;
}