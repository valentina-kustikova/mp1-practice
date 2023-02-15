#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <malloc.h>
#include <time.h>

typedef struct {
	long long int mas;
	char name[260];
}file;
void copy_name(char name[], wchar_t nm[]) {
	int ind = 0;
	while (strcmp(&nm[ind], "\0") != 0) {
		name[ind] = nm[ind];
		ind += 1;
	}
	strcpy(&name[ind], "\0");
}
void copy_mas(file a[], file b[], int ind) {
	for (int j = 0; j < ind; j++) {
		a[j].mas = b[j].mas;
		strcpy(a[j].name, b[j].name);
	}
}
void collect_data(char *pPath, file *pMas) {
	char path_copy1[500];
	HANDLE hFile;
	WIN32_FIND_DATA data;
	int ind = 0;

	hFile = FindFirstFileA(pPath, &data);
	while (FindNextFile(hFile, &data) != 0) {
		char name[500];
		copy_name(name, data.cFileName);
		if (strcmp(&name, "..") != 0) {
			if (!(data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				pMas[ind].mas = data.nFileSizeLow;
				strcpy(pMas[ind].name, &name);
				ind += 1;
			}
		}
	}
}
void counting(char path[], int *cnt) {
	HANDLE hFile;
	WIN32_FIND_DATA data;

	strcat(path, "/*");
	hFile = FindFirstFileA(path, &data);
	while (FindNextFile(hFile, &data) != 0) {
		if (!(data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			*cnt += 1;
		}
	}
}

void swap(int a, int b, file mas[]) {
	file tmp;
	tmp.mas = mas[a].mas;
	strcpy(&(tmp.name), &(mas[a].name));

	mas[a].mas = mas[b].mas;
	strcpy(&(mas[a].name), &(mas[b].name));

	mas[b].mas = tmp.mas;
	strcpy(&(mas[b].name), &(tmp.name));
}
void merge(file mas[], int m1, file left[], int l1, file right[], int r1) {
	int l = 0, r = 0, m = 0;
	while (l < l1 && r < r1) {
		if (left[l].mas < right[r].mas) {
			mas[m].mas = left[l].mas;
			strcpy(mas[m].name, left[l].name);
			l += 1;
		}
		else {
			mas[m].mas = right[r].mas;
			strcpy(mas[m].name, right[r].name);
			r += 1;
		}
		m += 1;
	}
	while (l < l1) {
		mas[m].mas = left[l].mas;
		strcpy(mas[m].name, left[l].name);
		l += 1;
		m += 1;
	}
	while (r < r1) {
		mas[m].mas = right[r].mas;
		strcpy(mas[m].name, right[r].name);
		r += 1;
		m += 1;
	}
}
void choice_sort(file mas[], int n) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i; j < n; j++) {
			if (mas[j].mas < mas[min].mas) {
				min = j;
			}
		}
		swap(k, min, mas);
		k += 1;
	}
}
void insert_sort(file mas[], int n) {
	for (int i = 0; i < n; i++) {
		int k = i - 1;
		for (int j = i; j > 0; j--) {
			if (mas[j].mas < mas[k].mas) {
				swap(k, j, mas);
			}
			k -= 1;
		}
	}
}
void merge_sort(file mas[], int n) {
	int mid = n / 2;
	file* left = (file*)malloc(mid * sizeof(file));
	file* right = (file*)malloc((n - mid) * sizeof(file));
	if (n < 2) {
		return;
	}
	for (int i = 0; i < mid; i++) {
		left[i].mas = mas[i].mas;
		strcpy(left[i].name, mas[i].name);
	}
	for (int i = mid; i < n; i++) {
		right[i - mid].mas = mas[i].mas;
		strcpy(right[i - mid].name, mas[i].name);
	}
	merge_sort(left, mid);
	merge_sort(right, (n - mid));
	merge(mas, n, left, mid, right, (n - mid));
	free(left);
	free(right);
}

void output(file mas[], int ind) {
	for (int j = 0; j < ind; j++) {
		printf("\t%s %lld \n", mas[j].name, mas[j].mas);
	}
}
void sorting(void (*func)(file mas[], int n), file mas[], int n) {
	clock_t begin = clock();
	func(mas, n);
	clock_t end = clock();
	output(mas, n);
	long double total = (end - begin) / CLOCKS_PER_SEC;
	printf("\ttime spent: %llf\n", total);
}
void init() {
	system("chcp 1251");
	file* pMas = { 0 }, *copy = {0};
	int count = 0;
	char path[300], command[5];
	WIN32_FIND_DATA t;
	HANDLE hFile;
	clock_t begin, end;
	void (*srt)(file mas[], int n);

	printf("\nList of available commands:\n");
	printf("\tnew --- Set/change path\n");
	printf("\tchs --- Choice sort\n");
	printf("\tins --- Insert sort\n");
	printf("\tmrs --- Merge sort\n");
	printf("\texit\n");

	do {
		printf(">> ");
		gets(command);
		if (strcmp(command, "new") == 0) {
			gets(path);
			count = 0;
			counting(path, &count);
			free(pMas);
			free(copy);
			pMas = (file*)malloc(count * (sizeof(file)));
			copy = (file*)malloc(count * (sizeof(file)));
			collect_data(path, pMas);
			copy_mas(copy, pMas, count);
		}
		else if (strcmp(command, "chs") == 0) {
			srt = choice_sort;
			sorting(srt, copy, count);
		}
		else if (strcmp(command, "ins") == 0) {
			srt = insert_sort;
			sorting(srt, copy, count);
		}
		else if (strcmp(command, "mrs") == 0) {
			srt = merge_sort;
			sorting(srt, copy, count);
		}
		else if (strcmp(command, "exit") != 0) printf("Incorrect command\n");
		copy_mas(copy, pMas, count);
	} while (strcmp(command, "exit") != 0);
	free(pMas);
	free(copy);
}

int main(){
	init();
	return 0;
}