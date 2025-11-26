#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

char** name;
int* num;
int* sz;

void swap(int* a, int* ai, int* b, int* bi) {
	int tmp = *b, tmpi = *bi;
	*b = *a;
	*bi = *ai;
	*a = tmp;
	*ai = tmpi;
}

void BubbleSort(int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (sz[j] > sz[j + 1]) swap(&sz[j], &num[j], &sz[j + 1], &num[j + 1]);
		}
	}
}

void ClassicSort(int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (sz[j] < sz[i]) swap(&sz[i], &num[i], &sz[j], &num[j]);
		}
	}
}

void ChoiceSort(int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		int min = sz[i], idx = i;
		for (j = i + 1; j < n; j++) {
			if (sz[j] < min) {
				min = sz[j];
				idx = j;
			}
		}
		swap(&sz[i], &num[i], &sz[idx], &num[idx]);
	}
}

void InsertSort(int n) {
	int i;
	for (i = 0; i < n; i++) {
		int j = i - 1, tmp = sz[i];
		while (j >= 0 && sz[j] > tmp) {
			sz[j + 1] = sz[j];
			num[j + 1] = num[j];
			j--;
		}
		sz[j + 1] = tmp;
		num[j + 1] = i;
	}
}

/*void RadixSort(int n) {
	int digitn[10][1000] = { {-1} }, digitv[10][1000] = { {-1} }, div = 1, cnt, d, i, p[10] = { 0 }, k, j;
	do {
		cnt = 0;
		for (i = 0; i < n; i++) {
			d = (sz[i] / div) % 10;
			if (d) cnt++;
			digitn[d][p[d]] = num[i];
			digitv[d][p[d]++] = sz[i];
		}
		k = 0;
		for (d = 0; d < 10; d++) {
			for (j = 0; j < p[d]; j++) {
				num[k] = digitn[d][j];
				sz[k++] = digitv[d][j];
			}
			p[d] = 0;
		}
		div *= 10;
	} while (cnt != 0);
}*/


int read(char dir[], char flag) {
	int k = 0, mx = 1;
	WIN32_FIND_DATAA data;
	HANDLE hFind = FindFirstFileA(dir, &data);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (data.dwFileAttributes != 32) continue;
			if (strlen(data.cFileName) > mx) mx = strlen(data.cFileName);
			k++;
		} while (FindNextFileA(hFind, &data));
		FindClose(hFind);
	}
	sz = (int*)malloc(k * sizeof(int));
	num = (int*)malloc(k * sizeof(int));
	name = (char**)malloc(k * sizeof(char*));
	for (int i = 0; i < k; i++) {
		name[i] = (char*)malloc(mx * sizeof(char));
	}
	k = 0;
	hFind = FindFirstFileA(dir, &data);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (data.dwFileAttributes != 32) continue;
			if(flag) printf("Read: %s of %d bytes\n", data.cFileName, data.nFileSizeLow);
			strcpy(name[k], data.cFileName);
			sz[k] = data.nFileSizeLow;
			num[k] = k;
			k++;
		} while (FindNextFileA(hFind, &data));
		FindClose(hFind);
	}
	return k;
}

char fsort(char method[], int k) {
	if (strcmp(method, "classic") == 0) {
		ClassicSort(k); return 1;
	}
	if (strcmp(method, "insert") == 0) {
		InsertSort(k); return 1;
	}
	if (strcmp(method, "choice") == 0) {
		ChoiceSort(k); return 1;
	}
	if (strcmp(method, "bubble") == 0) {
		BubbleSort(k); return 1;
	}
	if (strcmp(method, "radix") == 0) {
		//RadixSort(num, sz, k); return 1;
	}
	printf("Incorrect sort method\n");
	return 0;
}

int main() {
	char method[50], dir[1000] = "";
	int i, k = 0, type = -1, f;
	char ways[5][50] = { "classic", "insert", "choice", "bubble", "radix" };
	printf("Instruction:\n1 <path_to_directory> - Enter of usage directory\n2 - Read of files from entered directory\n3 <sort_type> - Sort and print a list of files and time of sort\n0 - Exit\n");
	while (type != 0) {
		scanf("%d%*c", &type);
		switch (type) {
		case 1:
			scanf("%s", dir);
			strcat(dir, "\\*\0");
			break;
		case 2:
			if (strcmp(dir, "") == 0) {
				printf("Nothing to read!\n");
			}
			else k = read(dir, 1);
			break;
		case 3:
			if (k == 0) {
				printf("Nothing to sort!\n");
				break;
			}
			scanf("%s", method);
			LARGE_INTEGER st, end, freq;
			double t;
			QueryPerformanceFrequency(&freq);
			QueryPerformanceCounter(&st);
			clock_t a = clock();
			f = fsort(method, k);
			clock_t b = clock();
			QueryPerformanceCounter(&end);
			t = (double)(end.QuadPart - st.QuadPart) * 1000.0 / freq.QuadPart;
			if (f) {
				for (i = 0; i < k; i++) printf("%d) %s -> %d\n", i + 1, name[num[i]], sz[i]);
				printf("Time: %.3f ms\n", t);
			}
			//for (i = 0; i < k; i++) num[i] = i;
			read(dir, 0);   // Обратная перестановка массива
			break;
		case 0:
			free(sz);
			free(num);
			for (int i = 0; i < k; i++) {
				free(name[i]);
			}
			free(name);
			return 0;
		default:
			printf("Incorrect input!\n");
		}
	}
	return 0;
}
