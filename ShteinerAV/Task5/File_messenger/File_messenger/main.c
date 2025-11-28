#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#define MAIN

int is_directory_windows(const char* path);

void user_answer(char* user);

#ifdef MAIN
int main() {
	setlocale(LC_ALL, "rus");
	char file_way[100], user;
	WIN32_FIND_DATA find_file_data;
	HANDLE hFind;

	do {
		system("cls");
		printf("_____________________________\n");
		printf("1) Ввести путь к директории\n");
		printf("2) Выйти\n");
		printf("_____________________________\n");

		user_answer(&user);
		if (user == '1') {
			system("cls");
			printf("_____________________________\n");
			printf("Введите путь к директории: \n");
			printf("_____________________________\n");
			printf("->");
			
			scanf_s("%s", file_way, (unsigned*)sizeof(file_way));

			if (is_directory_windows(&file_way) != 0) {
				printf("Директория найдена\n");
				printf("_____________________________\n");

				snprintf(file_way, 100, "%s\\*", file_way);

				hFind = FindFirstFileA(file_way, &find_file_data);
				
				do {
		
					if (strncmp(find_file_data.cFileName, ".", 1) == 0 || strncmp(find_file_data.cFileName, "..", 2) == 0) {
						continue;
					}

					snprintf(file_way, 100, "%s \ %s", file_way, find_file_data.cFileName);
					
					//if (is_directory_windows())
					printf("%s\n", file_way);
					printf("%s\n\n", find_file_data.cFileName);
				} while (FindNextFileA(hFind, &find_file_data));

				FindClose(hFind);
				return 1;

			}
			else {
				printf("Неверно введена директория\n");
				system("pause");
			}

		}

	} while (1);


	printf("%d\n", is_directory_windows(&file_way));

	return 0;
}
#endif

int is_directory_windows(const wchar_t* path) {
	DWORD attributes = GetFileAttributesA(path);

	if (attributes == INVALID_FILE_ATTRIBUTES) {
		return 0; 
	}

	return (attributes & FILE_ATTRIBUTE_DIRECTORY) ;
}

void user_answer(char* user) {
	int c;
	int extrawords;

	while (1) {
		printf("Команда: ");
		scanf_s(" %c", user);

		extrawords = 0;
		while ((c = getchar()) != '\n') {
			extrawords++;
		}

		if ((*user == '1' || *user == '2') && extrawords == 0) {
			break;
		}
		else {
			printf("Ошибка ввода!\n\n");
		}
	}
}