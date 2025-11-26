#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

char name[1000][256] = { "" };

void swap(int* a, int* ai, int* b, int* bi) {
	int tmp = *b, tmpi = *bi;
	*b = *a;
	*bi = *ai;
	*a = tmp;
	*ai = tmpi;
}

void BubbleSort(int num[], int v[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (v[j] > v[j + 1]) swap(&v[j], &num[j], &v[j + 1], &num[j + 1]);
		}
	}
}

void ClassicSort(int num[], int v[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (v[j] < v[i]) swap(&v[i], &num[i], &v[j], &num[j]);
		}
	}
}

void ChoiceSort(int num[], int v[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		int min = v[i], idx = i;
		for (j = i + 1; j < n; j++) {
			if (v[j] < min) {
				min = v[j];
				idx = j;
			}
		}
		swap(&v[i], &num[i], &v[idx], &num[idx]);
	}
}

void InsertSort(int num[], int v[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		int j = i - 1, tmp = v[i];
		while (j >= 0 && v[j] > tmp) {
			v[j + 1] = v[j];
			num[j + 1] = num[j];
			j--;
		}
		v[j + 1] = tmp;
		num[j + 1] = i;
	}
}

void RadixSort(int num[], int v[], int n) {
	int digitn[10][1000] = { {-1} }, digitv[10][1000] = { {-1} }, div = 1, cnt, d, i, p[10] = { 0 }, k, j;
	do {
		cnt = 0;
		for (i = 0; i < n; i++) {
			d = (v[i] / div) % 10;
			if (d) cnt++;
			digitn[d][p[d]] = num[i];
			digitv[d][p[d]++] = v[i];
		}
		k = 0;
		for (d = 0; d < 10; d++) {
			for (j = 0; j < p[d]; j++) {
				num[k] = digitn[d][j];
				v[k++] = digitv[d][j];
			}
			p[d] = 0;
		}
		div *= 10;
	} while (cnt != 0);
}

void path(char dir[]);

int read(char dir[], int num[], int sz[], int pos) {
	int k = pos;
	WIN32_FIND_DATA data;
	HANDLE hFind = FindFirstFileA(dir, &data);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (data.dwFileAttributes == 16) {
				char newdir[1024] = "";
				strncpy(newdir, dir, strlen(dir) - 1);
				strcat(newdir, data.cFileName);
				path(newdir);
				if (strcmp(data.cFileName, ".") != 0 && strcmp(data.cFileName, "..") != 0) {
					printf("Open directory: %s\n", newdir);
					k = read(newdir, num, sz, k);
					printf("Close directory: %s\n", newdir);
				}
				continue;
			}
			if (data.dwFileAttributes != 32) continue;
			printf("Read: %s of %d bytes\n", data.cFileName, data.nFileSizeLow);
			strcpy(name[k], data.cFileName);
			sz[k] = data.nFileSizeLow;
			num[k] = k;
			k++;
		} while (FindNextFileA(hFind, &data) && k < 1000);
		FindClose(hFind);
	}
	return k;
}
void path(char dir[]) {
	char add[3] = "\\*\0";
	strcat(dir, add);
}

char fsort(char method[], int num[], int sz[], int k) {
	if (strcmp(method, "classic") == 0) {
		ClassicSort(num, sz, k); return 1;
	}
	if (strcmp(method, "insert") == 0) {
		InsertSort(num, sz, k); return 1;
	}
	if (strcmp(method, "choice") == 0) {
		ChoiceSort(num, sz, k); return 1;
	}
	if (strcmp(method, "bubble") == 0) {
		BubbleSort(num, sz, k); return 1;
	}
	if (strcmp(method, "radix") == 0) {
		RadixSort(num, sz, k); return 1;
	}
	printf("Incorrect sort method\n");
	return 0;
}

int main() {
	char method[50], dir[1000] = "";
	int i, k = 0, type = -1, f;
	char ways[5][50] = { "classic", "insert", "choice", "bubble", "radix" };
	int num[1000], sz[1000];
	printf("Instruction:\n1 <path_to_directory> - Enter of usage directory\n2 - Read of files from entered directory\n3 <sort_type> - Sort and print a list of files and time of sort\n0 - Exit\n");
	while (type != 0) {
		scanf("%d%*c", &type);
		switch (type) {
		case 1:
			scanf("%s", dir);
			path(dir);
			break;
		case 2:
			if (strcmp(dir, "") == 0) {
				printf("Nothing to read!\n");
			}
			else k = read(dir, num, sz, 0);
			break;
		case 3:
			if (k == 0) {
				printf("Nothing to sort!\n");
				break;
			}
			scanf("%s", method);
			clock_t a = clock();
			f = fsort(method, num, sz, k);
			clock_t b = clock();
			if (f) {
				for (i = 0; i < k; i++) printf("%d) %s -> %d\n", i + 1, name[num[i]], sz[i]);
				printf("Time: %.2f ms\n", (b - a) / CLOCKS_PER_SEC);
			}
			break;
		case 0:
			return 0;
		default:
			printf("Incorrect input!\n");
		}
	}
	return 0;
}
