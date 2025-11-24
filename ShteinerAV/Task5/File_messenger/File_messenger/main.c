#include <stdio.h>
#include <locale.h>
#include <windows.h>


int is_directory_windows(const char* path);

void user_answer(char* user);

int main() {
	setlocale(LC_ALL, "rus");
	char file_way[100], user;

	

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

			if (is_directory_windows != 0) {
				printf("Директория найдена\n");
				system("pause");
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


int is_directory_windows(const char* path) {
	DWORD attrib = GetFileAttributesA(path);

	if (attrib == INVALID_FILE_ATTRIBUTES) {
		return 0; // Путь не существует
	}

	return (attrib & FILE_ATTRIBUTE_DIRECTORY);
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