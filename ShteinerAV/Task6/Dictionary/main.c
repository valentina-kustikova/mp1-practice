#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include "funcs.h"
#include "library.h"

int main() {
	int flag = 0, true = 1, cnt_books;
	char user, *file = "spisok.txt";

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
		case '1':
			system("cls");
			cnt_books = scan_file(file); 
			flag = 1;
			system("pause");
			break;
		case '2':
			if (flag == 0) {
				printf("The file has not been scanned!\n");
				system("pause");
			}
			else {
				system("cls");
				Book* arr = (Book*)malloc(sizeof(Book) * cnt_books);
				int* id_books, cnt_id;

				fill_arr(arr, file);
				cnt_id = find_book(arr, cnt_books, &id_books);
				print_books(arr, id_books, cnt_id);
				system("pause");
			}
			break;
		default:
			true = 0;
			break;
		}
	} while (true);

	printf("End of the programm");

	return 0;
}