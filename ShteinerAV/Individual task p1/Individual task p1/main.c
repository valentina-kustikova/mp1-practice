#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
#include <locale.h>
#include <string.h>
#include "funcs.h"
#include "data.h"

int main(int argc, char** argv) {
	int flag1 = 0, true = 1, cnt_company, cnt_vacancy;
	char *user1, * file1, * file2;
	if (argc < 3) {
		printf("Incorrect number of arguments");
		return 1;
	}
	file1 = argv[1];
	file2 = argv[2];

	do {
		system("cls");
		printf("|--------------------------------|\n");
		printf("|      SEARCH FOR VACANCIES      |\n");
		printf("|--------------------------------|\n");
		printf("|  1. Scan the list              |\n");
		printf("|  2. Search for vacancies       |\n");
		printf("|  0. Exit                       |\n");
		printf("|--------------------------------|\n");

		u_answer(&user1, 2);
		system("cls");

		if (strncmp(user1, "1", strlen(user1)) == 0) {
			cnt_company = scan_company(file1);
			cnt_vacancy = scan_vacancy(file2);
			flag1 = 1;
		}
		else if (strncmp(user1, "2", strlen(user1)) == 0) {
			if (flag1 == 0) {
				printf("The file has not been scanned!\n");
			}
			else {
				DbCompanies comp_s;
				DbVacancies vcn_s;
				DbCompanies valid_comp_s;
				DbCompanies dif_valid_com_s;
				char* users_choice, *user2;
				comp_s.size = cnt_company;
				comp_s.arr = (Company*)malloc(sizeof(Company) * cnt_company);
				vcn_s.size = cnt_vacancy;
				vcn_s.arr = (Vacancy*)malloc(sizeof(Vacancy) * cnt_vacancy);

				system("cls");
				fill_company(&comp_s, file1);
				fill_vacancy(&vcn_s, file2);

				enter_the_vcn(&users_choice);
				// &comp_s, &vcn_s
				find_vacancy(&comp_s, &vcn_s, &valid_comp_s, users_choice);
				different_company(&valid_comp_s, &dif_valid_com_s);

				print_company(&dif_valid_com_s);

				if (dif_valid_com_s.size != 0) {
					u_answer(&user2, dif_valid_com_s.size);

					if (strncmp(user1, "0", strlen(user1)) == 0) {
						break;
					}
					else {
						int id = atoi(user2);
						print_info(&dif_valid_com_s.arr[id - 1], &vcn_s);
					}
				}

				free(users_choice);
				free_company(&comp_s);
				free_company(&valid_comp_s);
				free_vacancy(&vcn_s);
				free_company(&dif_valid_com_s);
			}
		}
		else {
			break;
		}
		system("pause");
	} while (true);

	printf("End of the programm");

	return 0;
}