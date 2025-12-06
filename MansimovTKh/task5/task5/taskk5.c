#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

//E:\PS5\CREATE\Screenshots\Ghost of Tsushima
//E:\school\2 class
//E:\school\1 - 2
//E:\school\4class

struct FileInfo {		 // создаю структуру - тип данных, который хранит несколько переменных разныъ типов. Описывает файлы: имя и их размер
	char name[256];
	long long size;
};


//____функция чтения файлов из директории
int directory_reader(char user_path[], struct FileInfo files[]);

void simple_sort(struct FileInfo files[], int n, int order);
void choice_sort(struct FileInfo files[], int n, int order);
void insert_sort(struct FileInfo files[], int n, int order);
void bubble_sort(struct FileInfo files[], int n, int order);

void merge(struct FileInfo files[], int l, int mid, int r, int order);
void merge_sort(struct FileInfo files[], int n, int order);
void recursion_merge(struct FileInfo files[], int l, int r, int order);

void recursion_quick(struct FileInfo files[], int first, int last, int order);
void quick_sort(struct FileInfo files[], int n, int order);

void sorted_print(struct FileInfo files[], int count, int sort_type, double time);


int main() {
	char user_path[261];	//макс размер пути 260, + 1 символ для нуля
	int is_true = 1, sort_num, sort_order;
	struct FileInfo* files = NULL;

	LARGE_INTEGER start_time, end_time, frequency;
	double milisec;

	setlocale(LC_ALL, "rus");

	do {
		printf("Введите путь до директории: "); fgets(user_path, sizeof(user_path), stdin);  /* stdin - значит читаем с клавиатуры,
																								sizeof-макс колво символов для чтения,
																								функция не может изменить строку */

		if (strlen(user_path) > 0 && user_path[strlen(user_path) - 1] == '\n') {	//убираем символ '\n' в конце user_path
			user_path[strlen(user_path) - 1] = '\0';
		}

		if (strlen(user_path) == 0) {
			printf("Путь не может быть пустым!\n\n");
			continue;
		}

		//____________ПЕРЕХОД К ДИРЕКТОРИИ ПО ВВЕДЕННОМУ ПУТИ______________

		//проверяем на существование директории.
		DWORD attributes = GetFileAttributesA(user_path);
		if (attributes == INVALID_FILE_ATTRIBUTES) {
			printf("Ошибка: директория не существует!\n\n");
			continue;
		}
		printf("Введенный путь: %s\n\n", user_path);

		//Выделяем память для файлов
		files = (struct FileInfo*)malloc(1000 * sizeof(struct FileInfo));
		if (files == NULL) {
			printf("Ошибка выделения памяти\n\n");
			continue;
		}

		//чтение файлов по веденной директории
		int file_count = directory_reader(user_path, files); // колво файлов в директории
		if (file_count == 0) {
			printf("По введенному пути к директории не нашлось файлов!\n\n");
			free(files);
			files = NULL;
			continue;

		}

		printf("Количество файлов: %d\n\n", file_count);


		printf("1. Простейшая сортировка\n2. Сортировка выбором\n3. Сортировка вставками\n4. Пузырьковая сортировка\n5. Сортировка слиянием\n6. Быстрая сортировка\nВведите номер сортировки:"); scanf_s("%d", &sort_num);
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		while (sort_num < 1 || sort_num>6) {
			printf("Введите верный номер: "); scanf_s("%d", &sort_num);
		}
		printf("Выбрана сортировка %d для пути: %s\n\n", sort_num, user_path);


		printf("Выберите порядок сортировки:\n1. По возрастанию\n2. По убыванию\n");
		scanf_s("%d", &sort_order);
		while ((c = getchar()) != '\n' && c != EOF);
		while (sort_order != 1 && sort_order != 2) {
			printf("Введите 1 или 2: ");
			scanf_s("%d", &sort_order);
			while ((c = getchar()) != '\n' && c != EOF);
		}



		//начало отсчета времени сортировки
		//clock_t start = clock();
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&start_time);
		if (sort_num == 1) {
			simple_sort(files, file_count, sort_order);
		}
		else if (sort_num==2) {
			choice_sort(files, file_count, sort_order);
		}
		else if (sort_num == 3) {
			insert_sort(files, file_count, sort_order);
		}
		else if (sort_num == 4) {
			bubble_sort(files, file_count, sort_order);
		}
		else if (sort_num == 5) {
			merge_sort(files, file_count, sort_order);
		}
		else if (sort_num == 6) {
			quick_sort(files, file_count, sort_order);
		}
		QueryPerformanceCounter(&end_time);
		milisec = (double)(end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart;
		//clock_t end = clock();
		//double time = ((double)(end - start)) / CLOCKS_PER_SEC;

		sorted_print(files, file_count, sort_num, milisec);

		free(files);
		files = NULL;

		while ((c = getchar()) != '\n' && c != EOF); // так как после сканф остается символ \n, то мы должны его считать до того, как его считает fgets()

	} while (is_true);

	return 0;
}

void simple_sort(struct FileInfo files[], int n, int order) {

	int i, j;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (order == 1) { //по возрастанию
				if (files[i].size > files[j].size) {
					struct FileInfo buff = files[i];
					files[i] = files[j];
					files[j] = buff;
				}
			}
			else { //по убыванию
				if (files[i].size < files[j].size) {
					struct FileInfo buff = files[i];
					files[i] = files[j];
					files[j] = buff;
				}
			}
		}
	}
}

void choice_sort(struct FileInfo files[], int n, int order) {
	int i, j, ind;
	for (i = 0; i < n; i++) {
		long long min = files[i].size;
		ind = i;
		for (j = i + 1; j < n; j++) {
			if (order == 1) {
				if (min > files[j].size) {
					min = files[j].size; ind = j;
				}
			}
			else {
				if (min < files[j].size) {
					min = files[j].size;
					ind = j;
				}
			}
		}
		
		struct FileInfo buff = files[ind]; //заводим структурный буффер, так как должны передавать не только обьем, но и имя файла
		files[ind] = files[i];
		files[i] = buff;

	}
}

void insert_sort(struct FileInfo files[], int n, int order) {
	int i, j;
	for (i = 1; i < n; i++) {
		struct FileInfo buff = files[i];
		j = i - 1;

		if (order == 1) {
			while ((j >= 0) && (files[j].size > buff.size)) {
				files[j + 1] = files[j];
				j--;
			}
		}
		else {
			while ((j >= 0) && (files[j].size < buff.size)) {
				files[j + 1] = files[j];
				j--;
			}
		}
		files[j + 1] = buff;
	}
}

void bubble_sort(struct FileInfo files[], int n, int order) {
	int i, j;
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (order==1) {
				if (files[j + 1].size < files[j].size) {
					struct FileInfo buff = files[j];
					files[j] = files[j + 1];
					files[j + 1] = buff;
				}
			}
			else {
				if (files[j + 1].size > files[j].size) {
					struct FileInfo buff = files[j];
					files[j] = files[j + 1];
					files[j + 1] = buff;
				}
			}
		}
	}
}

void merge(struct FileInfo files[], int l, int mid, int r, int order) {
	int i, j, k;
	int n1 = mid - l + 1;
	int n2 = r - mid;

	struct FileInfo* L = (struct FileInfo*)malloc(n1 * sizeof(struct FileInfo));
	struct FileInfo* R = (struct FileInfo*)malloc(n2 * sizeof(struct FileInfo));

	for (i = 0; i < n1; i++) L[i] = files[l + i];
	for (j = 0; j < n2; j++) R[j] = files[mid + 1 + j];

	i = 0; j = 0; k = l;

	while (i < n1 && j < n2) {
		if (order == 1) {
			if (L[i].size <= R[j].size) {
				files[k] = L[i];
				i++;
			}
			else {
				files[k] = R[j];
				j++;
			}
		}
		else {
			if (L[i].size >= R[j].size) {
				files[k] = L[i];
				i++;
			}
			else {
				files[k] = R[j];
				j++;
			}
		}
		k++;
	}
	while (i < n1) {
		files[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		files[k] = R[j];
		j++;
		k++;
	}

	free(L);
	free(R);
}
void merge_sort(struct FileInfo files[], int n, int order) {
	recursion_merge(files, 0, n - 1, order);
}
void recursion_merge(struct FileInfo files[], int l, int r, int order) {
	if (l < r) {
		int mid = l + (r - l) / 2;

		recursion_merge(files, l, mid, order);
		recursion_merge(files, mid + 1, r, order);

		merge(files, l, mid, r, order);
	}
}

void recursion_quick(struct FileInfo files[], int first, int last, int order) {
	int f = first, l = last;
	long long mid = files[(first + last) / 2].size;
	struct FileInfo buff;

	while (f <= l) {
		if (order == 1) {
			while (files[f].size < mid) f++;
			while (files[l].size > mid) l--;
		}
		else {
			while (files[f].size > mid) f++;
			while (files[l].size < mid) l--;
		}
		if (f <= l) {
			buff = files[f];
			files[f] = files[l];
			files[l] = buff;
			f++; l--;
		}
	}
	if (first < l) {
		recursion_quick(files, first, l, order);
	}
	if (f < last) {
		recursion_quick(files, f, last, order);
	}
	
}
void quick_sort(struct FileInfo files[], int n, int order) {
	recursion_quick(files, 0, n - 1, order);
}

//____функция чтения файлов из директории
int directory_reader(char user_path[], struct FileInfo files[]) {		//files[] - это массив структур , т.е. files[0] - это {name: "..."; size: 1024} 
	char path_for_search[512];		//для поиска всех файлов в директории
	snprintf(path_for_search, sizeof(path_for_search), "%s\\*", user_path); /*т.е.тут будет "C:\\Folder\*" - значит будет искать все файлы в папке.
																			snprintf берет содержимое user_path(т.е.путь к директории)
																			и копирует его в path_for_search с добавлением */

	WIN32_FIND_DATAA find_data;		//WIN32_FIND_DATAA - спец тип для хранения инфы о найденном файле, как АНКЕТА      
	HANDLE find_handle = FindFirstFileA(path_for_search, &find_data); //path_for_search - где искать, find_data - куда записать инфо о найденном файле, как АНКЕТУ
	//в find_handle возвращается "номерок" для продолжения поиска. это номерок для поисковой операции.
	if (find_handle == INVALID_HANDLE_VALUE) { //если номерок_поиска равен неправильному_значению, то ошибка
		return 0;                             //пример: если нет такой папки, или нет доступа, или путь пустой
	}

	int count = 0;

	do {
		if (find_data.cFileName[0] == '.') continue;  /* "." ".." - это текущая и родительские папки соответственно, они весят 0 бит, поэтому в них нет смысла.
														сFileName - содержит имя найденного файла  */

		strcpy_s(files[count].name, sizeof(files[count].name), find_data.cFileName);	 //копируем имя файла, которая в find_data.cFileName, в структуру в поле "name" под индексом count
		files[count].size = (long long)find_data.nFileSizeLow + ((long long)find_data.nFileSizeHigh << 32);

		/*  find_data.nFileSizeLow - младшая часть размера файла(до 4 гб)
		find_data.nFileSizeHigh - старшая часть размера(больше 4гб)
		(long long) - преобразовываем в большое число, чтоб не было переполнения
		<<32 - сдвигает на 32 позиции влево, будто добавляя нули */

		count++;
	} while (FindNextFileA(find_handle, &find_data) && count < 1000); /*	если FindNextFileA() возвращает 1, значит он нашел еще один файл,
																		если возвращает 0, то файлы закончились и заканчиваем цикл.
																		count < 1000 - зашита от переполнения	*/

	FindClose(find_handle);		// прекращает поиск

	return count;	 //возвращение кол-ва файлов в директории
}

void sorted_print(struct FileInfo files[], int count, int sort_type, double time) {
	printf("\n----- ОТСОРТИРОВАННЫЕ ФАЙЛЫ -----\n");
	printf("%-40s %15s\n", "Имя файла", "Размер (байт)");
	printf("----------------------------------------|-----------------\n");
	for (int i = 0; i < count; i++) {
		printf("%-40s %15lld\n", files[i].name, files[i].size);
	}
	printf("----------------------------------------|-----------------\n");

	printf("Метод сортировки: %d\n", sort_type);
	printf("Время сортировки: %.3f милисекунд\n", time);
}