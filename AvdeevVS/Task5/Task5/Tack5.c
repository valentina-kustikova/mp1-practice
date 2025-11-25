#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <string.h>
#include <time.h>
#define T 1000
void Start(int* cn, char ad[], char name[][T], int size[]) {
	printf("Enter the address of the directory\n");
	scanf("%s", ad);
	//"C:\\Users\\1\\Desktop\\Maybe\\*\0"
	//"C:\\Users\\1\\Desktop\\Maybe\\*"
	//C:\Users\1\Desktop\Maybe
	WIN32_FIND_DATA data;
	HANDLE hFind = FindFirstFileA(ad, &data);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (data.dwFileAttributes == 32) {
				strcpy(name[*cn], data.cFileName);
				size[*cn++] = data.nFileSizeLow;
				printf("FILE --> %s --> %d\n", data.cFileName, data.nFileSizeLow);
			}
		} while (FindNextFile(hFind, &data));
		FindClose(hFind);
	}
}
void Clean(char name[][T], char cl[][T], int size[], int ch[], int cnt) {
	int i;
	for (i = 0; i < cnt; i++) {
		strcpy(name[i], cl[i]);
		size[i] = ch[i];
	}
}
void BubbleSort(int cnt, int size[], char name[][T]) {
	time_t start_time, end_time;
	double elapsed_time;
	start_time = time(0);
	int i, j, p;
	char temp[T];
	for (i = 0; i < cnt - 1; i++) {
		for (j = 0; j < cnt - i - 1; j++) {
			if (size[j] > size[j + 1]) {
				strcpy(temp, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], temp);
				p = size[j];
				size[j] = size[j + 1];
				size[j + 1] = p;
			}
		}
	}
	end_time = time(0);
	elapsed_time = difftime(end_time, start_time);
	for (i = 0; i < cnt; i++) {
		printf("%s -- %d\n", name[i], size[i]);
	}
	printf("Execution time - %.3f seconds\n", elapsed_time);
}
void InsertSort(int cnt, int size[], char name[][T]) {
	int i, j, temp;
	char s[T];
	time_t start_time, end_time;
	double elapsed_time;
	start_time = time(0);
	for (i = 0; i < cnt; i++) {
		temp = size[i];
		strcpy(s, name[i]);
		j = i - 1;
		while (j >= 0 && (size[j] > temp)) {
			size[j + 1] = size[j];
			strcpy(name[j + 1], name[j]);
			j--;
		}
		size[j + 1] = temp;
		strcpy(name[j + 1], s);
	}
	end_time = time(0);
	elapsed_time = difftime(end_time, start_time);
	for (i = 0; i < cnt; i++) {
		printf("%s -- %d\n", name[i], size[i]);
	}
	printf("Execution time - %.3f seconds\n", elapsed_time);
}
void Merge(char name[][T], int a[], int l, int m, int r) {
	int i = 0, j = 0, k = l;
	int n1 = m - l + 1;
	int n2 = r - m;
	int lArr[n1], rArr[n2];
	char s1[n1][T], s2[n2][T];
	for (i = 0; i < n1; i++) {
		lArr[i] = a[l + i];
		strcpy(s1[i], name[l + i]);
	}
	for (j = 0; j < n2; j++) {
		rArr[j] = a[m + 1 + j];
		strcpy(s2[j], name[m + 1 + j]);
	}
	i = 0, j = 0;
	while (i < n1 && j < n2) {
		if (lArr[i] <= rArr[j]) {
			strcpy(name[k], s1[i]);
			a[k++] = lArr[i++];
		}
		else {
			strcpy(name[k], s2[j]);
			a[k++] = rArr[j++];
		}
	}
	while (i < n1) {
		strcpy(name[k], s1[i]);
		a[k++] = lArr[i++];
	}
	while (j < n2) {
		strcpy(name[k], s2[j]);
		a[k++] = rArr[j++];
	}
}
void MergeSort(char name[][T], int a[], int l, int r) {
	int m;
	if (l + 1 <= r) {
		m = l + (r - l) / 2;
		MergeSort(name, a, l, m);
		MergeSort(name, a, m + 1, r);
		Merge(name, a, l, m, r);
	}
}
void Msort(char name[][T], int a[], int cnt) {
	int l = 0, r = cnt - 1, i;
	time_t start_time, end_time;
	double elapsed_time;
	start_time = time(0);
	MergeSort(name, a, l, r);
	end_time = time(0);
	elapsed_time = difftime(end_time, start_time);
	for (i = 0; i < cnt; i++) {
		printf("%s -- %d\n", name[i], a[i]);
	}
	printf("Execution time - %.3f seconds\n", elapsed_time);
}
void SimpleSort(char name[][T], int size[], int cnt) {
	time_t start_time, end_time;
	double elapsed_time;
	start_time = time(0);
	int i, j, p;
	char temp[T];
	for (i = 0; i < cnt; i++) {
		for (j = i + 1; j < cnt; j++) {
			if (size[i] > size[j]) {
				strcpy(temp, name[i]);
				strcpy(name[i], name[j]);
				strcpy(name[j], temp);
				p = size[i];
				size[i] = size[j];
				size[j] = p;
			}
		}
	}
	end_time = time(0);
	elapsed_time = difftime(end_time, start_time);
	for (i = 0; i < cnt; i++) {
		printf("%s -- %d\n", name[i], size[i]);
	}
	printf("Execution time - %.3f seconds\n", elapsed_time);
}
void ChoiceSort(char name[][T], int size[], int cnt) {
	int i, j, min, in, p;
	char temp[T];
	time_t start_time, end_time;
	double elapsed_time;
	start_time = time(0);
	for (i = 0; i < cnt; i++) {
		min = size[i];
		in = i;
		for (j = i + 1; j < cnt; j++) {
			if (size[j] < min) {
				min = size[j];
				in = j;
			}
		}
		strcpy(temp, name[i]);
		strcpy(name[i], name[in]);
		strcpy(name[in], temp);
		p = size[i];
		size[i] = size[in];
		size[in] = p;
	}
	end_time = time(0);
	elapsed_time = difftime(end_time, start_time);
	for (i = 0; i < cnt; i++) {
		printf("%s -- %d\n", name[i], size[i]);
	}
	printf("Execution time - %.3f seconds\n", elapsed_time);
}
void ProtectandPrint(int cnt, char cl[][T], char name[][T], int ch[], int size[]) {
	int i;
	for (i = 0; i < cnt; i++) {
		strcpy(cl[i], name[i]);
		ch[i] = size[i];
	}
	printf("\n");
	printf("Select sorting or end the program:\n");
	printf("1 - Bubble sorting\n");
	printf("2 - Insertion sorting\n");
	printf("3 - Merge sorting\n");
	printf("4 - Simplest sorting\n");
	printf("5 - Choice sorting\n");
	printf("6 - End the program\n");
}
int main() {
	setlocale(LC_ALL, "Russian");
	int size[T], ch[T], i, j, cnt = 0, fl, b = 1;
	int* cn = &cnt;
	char name[T][T], cl[T][T], ad[T];
	Start(cn, ad, name, size);
	ProtectandPrint(cnt, cl, name, ch, size);
	while (b != 0) {
		scanf("%d", &fl);
		switch (fl) {
		case 1:
			BubbleSort(cnt, size, name);
			Clean(name, cl, size, ch, cnt);
			break;
		case 2:
			InsertSort(cnt, size, name);
			Clean(name, cl, size, ch, cnt);
			break;
		case 3:
			Msort(name, size, cnt);
			Clean(name, cl, size, ch, cnt);
			break;
		case 4:
			SimpleSort(name, size, cnt);
			Clean(name, cl, size, ch, cnt);
			break;
		case 5:
			ChoiceSort(name, size, cnt);
			Clean(name, cl, size, ch, cnt);
			break;
		case 6:
			b = 0;
			printf("The end!");
			break;
		default:
			printf("Fatal -- There is no sorting with a given number\n");
		}
	}
	return 0;
}