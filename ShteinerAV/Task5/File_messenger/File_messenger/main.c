#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#define N 1000


int is_directory_windows(const char* path);
void user_answer(char* user, char right);
int read_and_print_files(int* cnt_files, int** FileSize, char*** FileName);

void simple_sort(int cnt_files, int* FileSize, int* PoridokList); 

void choose_sort(int cnt_files, int* FileSize, int* PoridokList); 

void insert_sort(int cnt_files, int* FileSize, int* PoridokList); 

void bubble_sort(int cnt_files, int* FileSize, int* PoridokList); 

void swap(int* a, int *b);

void merge_sort(int* FileSize, int* PoridokList, int left, int right);
void merge(int* FileSize, int* PoridokList, int start, int mid, int end);

void quick_sort_files(int* FileSize, int* PoridokList, int first, int last);

void printf_hand(int cnt_files, int* FileSize, int* PoridokList, char** FileName, int res);

void print_files(int cnt_files, int* FileSize, int* PoridokList, char** FileName, int status);


int main() {	
	char user;
	setlocale(LC_ALL, "rus");

	do {
		system("cls");
		printf("_____________________________\n");
		printf("1) Ввести путь к директории\n");
		printf("0) Выйти\n");
		printf("_____________________________\n");

		user_answer(&user, '1');
		if (user == '1') {
			int cnt_files = 0, flag;
			int* FileSize;
			char** FileName;	
			flag = read_and_print_files(&cnt_files, &FileSize, &FileName);

			if (flag) {
				int* PoridokList = (int*)malloc(cnt_files * sizeof(int));
				clock_t start, end;
				for (int i = 0; i < cnt_files; i++) {
					PoridokList[i] = i;
				}

				printf("----------СОРТИРОВКИ----------\n");
				printf("1) Simple sort (возрастание)\n");
				printf("2) Choose sort (возрастание)\n");
				printf("3) Insert Sort (возрастание)\n");
				printf("4) Bubble sort (убывание)\n");
				printf("5) Merge sort (убывание)\n");
				printf("6) Quic sort (убывание)\n");
				printf("0) Назад\n");
				printf("------------------------------\n\n");
				user_answer(&user, '6');
				printf("\n");

				
				if (user == '1') {
					start = clock();
					simple_sort(cnt_files, FileSize, PoridokList); 
					end = clock();

					printf("Simple sort\n");
				}
				else if (user == '2') {
					start = clock();
					choose_sort(cnt_files, FileSize, PoridokList); 
					end = clock();

					printf("Choose sort\n");;
				}
				else if (user == '3') {
					start = clock();
					insert_sort(cnt_files, FileSize, PoridokList);
					end = clock();

					printf("Insetr Sort\n");
					
				}
				else if (user == '4') {
					start = clock();
					bubble_sort(cnt_files, FileSize, PoridokList);
					end = clock();

					printf("Bubble Sort\n");
				}
				else if (user == '5') {					
					start = clock();
					merge_sort(FileSize, PoridokList, 0, cnt_files - 1);
					end = clock();

					printf("Merge sort\n");
				}
				else if (user == '6') {					
					start = clock();
					quick_sort_files(FileSize, PoridokList, 0, cnt_files - 1);
					end = clock();

					printf("Quick sort\n");
				}
				

				if (user != '0') {
					printf_hand(cnt_files, FileSize, PoridokList, FileName, end - start);
				}
				

				for (int i = 0; i < cnt_files; i++) {
					free(FileName[i]);
				}
				free(FileName);
				free(FileSize);
				free(PoridokList);

			}
			else {
				system("pause");
			}
		}	
		else {
			break;
		}

	} while (1);
	return 0;
}

void print_files(int cnt_files, int* FileSize, int* PoridokList, char** FileName) {

	if (cnt_files < 100) {
		printf("\n Размер() |  Названние\n");
		for (int i = 0; i < cnt_files; i++) {
			printf("----------|-------------------\n");
			printf("   %-7lld| ", FileSize[i]);
			printf(" %s \n", FileName[PoridokList[i]]);
		}
	}

}

int is_directory_windows(const char* path) {
	DWORD attributes = GetFileAttributesA(path);

	if (attributes == INVALID_FILE_ATTRIBUTES) {
		return 0; 
	}

	return (attributes & FILE_ATTRIBUTE_DIRECTORY) ;
}

void user_answer(char* user,  char right) {
	int c;
	int extrawords;

	while (1) {
		printf("Команда: ");
		scanf_s(" %c", user);

		extrawords = 0;
		while ((c = getchar()) != '\n') {
			extrawords++;
		}

		if ((*user >= '0' && *user <= right) && extrawords == 0) {
			break;
		}
		else {
			printf("Ошибка ввода!\n\n");
		}
	}
}

int read_and_print_files(int* cnt_files, int** FileSize, char*** FileName) {
	char file_way[100];
	WIN32_FIND_DATA find_file_data;
	HANDLE hFind = NULL;
	int file_count = 0;
	int i = 0;

	system("cls");
	printf("_____________________________\n");
	printf("Введите путь к директории: \n");
	printf("_____________________________\n");
	printf("->");

	gets_s(file_way, sizeof(file_way));

	if (is_directory_windows(file_way) != 0) {
		char search_path[200];
		char full_path[300];

		snprintf(search_path, sizeof(search_path), "%s\\*", file_way);

		hFind = FindFirstFileA(search_path, &find_file_data);
		if (hFind == INVALID_HANDLE_VALUE) {
			printf("Не удалось открыть директорию\n");
			return 0;
		}

		do {
			if (strcmp(find_file_data.cFileName, ".") == 0 ||
				strcmp(find_file_data.cFileName, "..") == 0) {
				continue;
			}

			snprintf(full_path, sizeof(full_path), "%s\\%s", file_way, find_file_data.cFileName);
			if (is_directory_windows(full_path)) {
				continue;
			}

			file_count++;
		} while (FindNextFileA(hFind, &find_file_data));

		FindClose(hFind);

		*cnt_files = file_count;

		if (file_count > 0) {
			*FileSize = (int*)malloc(file_count * sizeof(int));
			*FileName = (char**)malloc(file_count * sizeof(char*));
			for (i = 0; i < file_count; i++) {
				(*FileName)[i] = (char*)malloc(N * sizeof(char));
			}

			hFind = FindFirstFileA(search_path, &find_file_data);
			i = 0;

			system("cls");
			printf("Директория| %s\n\n", file_way);

			do {
				if (strcmp(find_file_data.cFileName, ".") == 0 ||
					strcmp(find_file_data.cFileName, "..") == 0) {
					continue;
				}

				snprintf(full_path, sizeof(full_path), "%s\\%s", file_way, find_file_data.cFileName);
				if (is_directory_windows(full_path)) {
					continue;
				}

				strcpy_s((*FileName)[i], strlen(find_file_data.cFileName) + 1, find_file_data.cFileName);
				(*FileSize)[i] = (int)((((LONGLONG)find_file_data.nFileSizeHigh << 32) | find_file_data.nFileSizeLow + 1023) / 1024);
				
				i++;
			} while (FindNextFileA(hFind, &find_file_data));
			FindClose(hFind);

			printf("Всего файлов: %d\n\n", file_count);
			return 1;
		}
		else {
			printf("В директории нет файлов\n");
			return 0;
		}
	}
	else {
		printf("Неверно введена директория\n");
		return 0;
	}
}

void simple_sort(int cnt_files, int* FileSize, int* PoridokList) {
	int i, j;

	for ( i = 0; i < cnt_files; i++) {
		for ( j = i + 1; j < cnt_files; j++) {
			if (FileSize[i] > FileSize[j]) {
				swap(&FileSize[i], &FileSize[j]);
				swap(&PoridokList[i], &PoridokList[j]);
			}
		}
	}
}

void choose_sort(int cnt_files, int* FileSize, int* PoridokList) {
	int i, j;

	for (int i = 0; i < cnt_files; i++) {
		int min = FileSize[i], id = i;
		for (int j = i + 1; j < cnt_files; j++) {
			if (FileSize[j] < min) {
				min = FileSize[j];
				id = j;
			}
		}
		
		swap(&FileSize[id], &FileSize[i]);
		swap(&PoridokList[id], &PoridokList[i]);
	}
}

void insert_sort(int cnt_files, int* FileSize, int* PoridokList) {
	int i, j;

	for (int i = 0; i < cnt_files; i++) {
		int j = i - 1;
		int buff = FileSize[i];
		while (j >= 0 && buff < FileSize[j]) {
			FileSize[j + 1] = FileSize[j];
			PoridokList[j + 1] = PoridokList[j];
			j--;
		}
		FileSize[j + 1] = buff;
		PoridokList[j + 1] = i;
	}
}

void bubble_sort(int cnt_files, int* FileSize, int* PoridokList) {
	int i, j;

	for (i = 0; i < cnt_files; i++) {
		for (j = 1; j < cnt_files - i; j++) {
			if (FileSize[j - 1] < FileSize[j]) {
				swap(&FileSize[j - 1], &FileSize[j]);
				swap(&PoridokList[j - 1], &PoridokList[j]);
			}
		}
	}
}

void swap(int* a, int* b) {
	int buff = *a;
	*a = *b;
	*b = buff;
}

void merge_sort(int* FileSize, int* PoridokList, int left, int right) {
	int mid;

	if (left >= right) {
		return;
	}

	mid = left + (right - left) / 2;
	merge_sort(FileSize, PoridokList, left, mid);
	merge_sort(FileSize, PoridokList, mid + 1, right);

	merge(FileSize, PoridokList, left, mid, right);
}

void merge(int* FileSize,int* PoridokList, int start, int mid, int end) {
	int it1 = start, it2 = mid + 1, k = 0;
	int* t1 = (int*)malloc(N * sizeof(int));
	int* t2 = (int*)malloc(N * sizeof(int));

	while (it1 <= mid && it2 <= end) {
		if (FileSize[it1] < FileSize[it2]) {
			t1[k] = FileSize[it2];
			t2[k] = PoridokList[it2];
			k++;
			it2++;

		}
		else {
			t1[k] = FileSize[it1];
			t2[k] = PoridokList[it1];
			k++;
			it1++;
		}
	}

	while (it1 <= mid) {
		t1[k] = FileSize[it1];
		t2[k] = PoridokList[it1];
		k++;
		it1++;
	}
	while (it2 <= end) {
		t1[k] = FileSize[it2];
		t2[k] = PoridokList[it2];
		k++;
		it2++;
	}

	for (int i = 0; i < k; i++) {
		FileSize[start + i] = t1[i];
		PoridokList[start + i] = t2[i];
	}

	free(t1);
	free(t2);
}

void quick_sort_files(int* FileSize, int* PoridokList, int first, int last) {
	if (first >= last) return;

	int left = first, right = last;
	int pivot = FileSize[(first + last) / 2];

	while (left <= right) {
		while (FileSize[left] > pivot) left++;   
		while (FileSize[right] < pivot) right--; 

		if (left <= right) {
			swap(&FileSize[left], &FileSize[right]);
			swap(&PoridokList[left], &PoridokList[right]);

			left++;
			right--;
		}
	}

	if (first < right) quick_sort_files(FileSize, PoridokList, first, right);
	if (left < last) quick_sort_files(FileSize, PoridokList, left, last);
}

void printf_hand(int cnt_files,int* FileSize, int* PoridokList, char** FileName, int res) {
	printf("Время сортировки: %.6f сек.\n", (double)(res) / CLOCKS_PER_SEC);
	print_files(cnt_files, FileSize, PoridokList, FileName);
	system("pause");
}