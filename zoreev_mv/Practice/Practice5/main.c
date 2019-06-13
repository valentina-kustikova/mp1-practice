#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define PATH_BUFFER 2048

//Прототипы функций

void choose_sort(LONGLONG *size, int *index, int n);
void insert_sort(LONGLONG *size, int *index, int n);
void bubble_sort(LONGLONG *size, int *index, int n);
void counting_sort(LONGLONG *size, int *index, LONGLONG min, LONGLONG max, int n);
void quick_sort(LONGLONG *size, int *index, int first, int last);
void merge_sort(LONGLONG *size, int *index, int left, int right);
int file_counter(wchar_t *sDir);
int file_reader(wchar_t *sDir, LONGLONG *size, char **name, LONGLONG* min, LONGLONG* max);
void printer(LONGLONG *size, wchar_t **name, int *index, int n, int mode);
void head_printer();
void path_reader(wchar_t** path);

void main() {
    int sort_mode = 0, sort_directon = 0, sort_command = 0, counting_lock = 0, n = 0, i = 0;
    LONGLONG max, min;
    float start, end;
	int *index;
	LONGLONG *size;
    wchar_t  *path;
    wchar_t  **name;

    setlocale(LC_ALL, "Russian");

    path = (wchar_t*)malloc(PATH_BUFFER * sizeof(wchar_t));

    do {

        counting_lock = 0;
        max = 0;
        min = 1024 * 1024 * 1024 * 2;

        head_printer();

        printf("Введите директорию\n");

        do {
            path_reader(&path);
            n = file_counter(path);
            if (n == 0) printf("Директоририя пуста\n");
        } while (n < 1);

        size = (LONGLONG*)malloc(n * sizeof(LONGLONG));
        index = (int*)malloc(n * sizeof(int));
        name = (wchar_t**)malloc(n * sizeof(wchar_t*));
        for (i = 0; i < n; i++) {
            index[i] = i;
            name[i] = (wchar_t*)malloc(256 * sizeof(char));
            memset(name[i], 0, 256);
        }

        file_reader(path, size, name, &min, &max);
        head_printer();

        do {
            printf("Для выбора соритровки введите цифру:\n");
            printf("Сортировка выбором                    1\n");
            printf("Сортировка вставками                  2\n");
            printf("Сортировка пузырьком                  3\n");
            if ((max - min + 1) < (1024*1024*1024*2 / sizeof(int))) {
                printf("Сортировка подсчётом                  4\n");
            }
            else {
                printf("Сортировка подсчётом не доступна\n");
                counting_lock = 1;
            }
            printf("Быстрая сортировка                    5\n");
            printf("Сортировка слиянием                   6\n");

            do {
                scanf("%d", &sort_mode);
            } while (((sort_mode < 1) || (sort_mode > 6)) || ((sort_mode == 4) && (counting_lock == 1)));

            head_printer();

            if (sort_mode == 1) {
                start = clock();
                choose_sort(size, index, n);
                end = clock();
            }
            if (sort_mode == 2) {
                start = clock();
                insert_sort(size, index, n);
                end = clock();
            }
            if (sort_mode == 3) {
                start = clock();
                bubble_sort(size, index, n);
                end = clock();
            }
            if (sort_mode == 4) {
                start = clock();
                counting_sort(size, index, min, max, n);
                end = clock();
            }
            if (sort_mode == 5) {
                start = clock();
                quick_sort(size, index, 0, n - 1);
                end = clock();
            }
            if (sort_mode == 6) {
                 start = clock();
                merge_sort(size, index, 0, n - 1);
                end = clock();
            }

            printf("Чтобы сортировать по возрастанию введите    1\n");
            printf("Чтобы сортированть по убыванию введите      2\n");

            do {
                scanf("%d", &sort_directon);
            } while ((sort_directon != 1) && (sort_directon != 2));

            head_printer();

            printer(size, name, index, n, sort_mode);

            printf("\nОтсортировано за %f секунд\n", ((end - start) / CLOCKS_PER_SEC));
            printf("\nЧтобы выбрать другую сортировку введите   1\n");
            printf("Чтобы сменить директорию введите          2\n");
            printf("Чтобы выйти из программы введите          3\n");

            do {
                scanf("%d%*c", &sort_command);
            } while ((sort_command < 1) && (sort_command > 3));

            head_printer();

        } while ((sort_command != 2) && (sort_command != 3));
        free(index);
        free(size);
        free(*name);
        free(name);
    } while (sort_command != 3);

}

//Сортировки

void choose_sort(LONGLONG *size, int *index, int n) {
	int i, j, minindx;
    LONGLONG min, temp;
	for (i = 0; i < n; i++) {
		min = size[index[i]];
		minindx = i;
		for (j = i + 1; j < n; j++) {
			if (size[index[j]] < min) {
				min = size[index[j]];
				minindx = j;
			}
		}
		temp = index[minindx];
		index[minindx] = index[i];
		index[i] = temp;
	}
}

void insert_sort(LONGLONG *size, int *index, int n) {
    int i, j, swap;
    LONGLONG temp;
    for (i = 1; i < n; i++) {
        temp = size[index[i]];
		swap = index[i];
        j = i - 1;
            while ((j >= 0) && (size[index[j]] > temp)) {
                index[j + 1] = index[j];
                index[j] = swap;
                j--;
            }
    }
}

void bubble_sort(LONGLONG *size, int *index, int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 1; j < n - i; j++) {
            if (size[index[j - 1]] > size[index[j]]) {
                temp = index[j];
                index[j] = index[j - 1];
                index[j - 1] = temp;
            }
        }
    }
}

void counting_sort(LONGLONG *size, int *index, LONGLONG min, LONGLONG max, int n) {
    int *count;
    LONGLONG i, j, d, k = 0, s = 0;
    d = (max - min) + 1;
    count = (int*)malloc(d * sizeof(int));
    for (i = 0; i < d; i++) {
        count[i] = 0;
    }
    for (i = 0; i < n; i++) {
        count[(size[i] - min)]++;
    }
    for (i = 0; i < d; i++) {
        k = 0;
        for (j = 0; j < count[i]; j++) {
            while (size[k] != i + min) {
                k++;
            }
            index[s++] = k;
            k++;
        }
    }
    free(count);
}

void quick_sort(LONGLONG *size, int *index, int first, int last) {
    int left = first, right = last;
    LONGLONG middle = size[index[(left + right) / 2]];
    if (first < last) {
        do {
            while (size[index[left]] < middle) left++;
            while (size[index[right]] > middle) right--;
            if (left <= right) {
                int temp = index[left];
                index[left] = index[right];
                index[right] = temp;
                left++;
                right--;
            } 
        } while (left <= right);
        quick_sort(size, index, first, right);
        quick_sort(size, index, left, last);
    }
}

void merge_sort(LONGLONG *size,int *index, int left, int right) {
    int i = 0, j = 0, k = 0, length = (right - left + 1), middle;
    int *temp;
    if (left >= right) return;
    middle = (left + right) / 2;
    merge_sort(size, index, left, middle);
    merge_sort(size, index, middle + 1, right);
    temp = (int*)malloc(length * sizeof(int));
    i = left;
    j = middle + 1;
    while ((i <= middle) && (j <= right)) {
        if (size[index[i]] < size[index[j]]) {
            temp[k++] = index[i++];
        }
        else {
            temp[k++] = index[j++];
        }
    }
    while (i <= middle) {
            temp[k++] = index[i++];
    }
    while (j <= right) {
        temp[k++] = index[j++];
    }
    for (i = left; i <= right; i++) {
        index[i] = temp[i - left];
    }
    free(temp);
}

int file_counter(wchar_t *sDir) {
	int n = 0;
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t sPath[2048];

	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		wprintf(L"Путь не найден: [%s]\n", sDir);
		return -1;
	}

	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{
			n++;
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);
	return n;
}

int file_reader(wchar_t *sDir, LONGLONG *size, char **name, LONGLONG* min, LONGLONG* max) {
	int i = 0;
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t sPath[2048];

	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		wprintf(L"Путь не найден: [%s]\n", sDir);
		return -1;
	}

	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{
			ULONGLONG fileSize = fdFile.nFileSizeHigh;
			fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
			fileSize |= fdFile.nFileSizeLow;
            if (fileSize < *min) *min = fileSize;
            if (fileSize > *max) *max = fileSize;
			wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf(name[i], L"%s", fdFile.cFileName);
			size[i++] = fileSize;
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);
	return 0;
}

void printer(LONGLONG *size, wchar_t **name, int *index, int n, int mode) {
    int i = 0;
    if (mode == 1) {
        for (i = 0; i < n; i++) {
            wprintf(L"Размер: %-14lli   %s\n", size[index[i]], name[index[i]]);
        }
    }
    else {
        for (i = n-1; i >= 0; i--) {
            wprintf(L"Размер: %-14lli    %s\n", size[index[i]], name[index[i]]);
        }
    }
}

void head_printer() {
    system("cls");
    printf("===========================================\n");
    printf("Файловый  менеджер  ННГУ  им.  Лобачевского\n");
    printf("2018 год                 Все права защищены\n");
    printf("===========================================\n\n");
}

void path_reader(wchar_t** path) {
    char *s_path;
    s_path = (char*)malloc(PATH_BUFFER * sizeof(char));
    fgets(s_path, PATH_BUFFER, stdin);
    s_path[strlen(s_path) - 1] = '\0';
    swprintf(*path, PATH_BUFFER, L"%hs", s_path);
}