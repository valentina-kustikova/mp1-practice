#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define LFiles 100

void bubbleSort(char* names[], unsigned long long sizes[], int n, int increasing);
void fastSort(char* names[], unsigned long long sizes[], int start, int end, int increasing);
void simpleSort(char* names[], unsigned long long sizes[], int n, int increasing);
void selectSort(char* names[], unsigned long long sizes[], int n, int increasing);

int main() {
	WIN32_FIND_DATA  FindFileData;
	HANDLE hFind;
	char* fileNames[LFiles];
	unsigned long long fileSizes[LFiles];
	int n = 0, increasing, userSelect,i,sorted = 1;
	char directoryPath[MAX_PATH], trash[MAX_PATH];
	clock_t start_time;

	setlocale(LC_ALL,"RUS"); // замедляет сортировку

	printf("введите директорию: ");
	gets(directoryPath);
	strcat_s(directoryPath, sizeof(directoryPath), "\\*");

	hFind = FindFirstFileA(directoryPath, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("директория не найдена... (убедитесь, что она не содержит кириллицы)\n");
		return 1;
	}
	do {
		if (strcmp(FindFileData.cFileName, ".") != 0 && strcmp(FindFileData.cFileName, "..") != 0) {
			if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				size_t len = strlen(FindFileData.cFileName) + 1;
				fileNames[n] = malloc(len);
				memcpy(fileNames[n], FindFileData.cFileName, len);
				//fileNames[n] = FindFileData.cFileName;
				fileSizes[n] = ((unsigned long long)FindFileData.nFileSizeHigh << 32) | FindFileData.nFileSizeLow;
				n++;
			}
			/*else {
				char p[256] = "C:\\Users\\Max\\Desktop\\test000";
				strcat_s(strcat_s(p, sizeof(p), "\\"), sizeof(p), FindFileData.cFileName);
				printf("%s (Directory) - Size: %llu bytes\n", FindFileData.cFileName, SizeDir(p));
			}*/
		}
	} while (FindNextFileA(hFind, &FindFileData) != 0);

	while (1) {
		printf("сортировать по 1-убыванию, 2-возрастанию, 0-выход: "); scanf_s("%d", &increasing);
		while (increasing < 0 || increasing > 2) { gets(trash); printf("не коректный ввод, сортировать по 0-убыванию, 1-возрастанию: "); scanf_s("%d", &increasing); }

		if (increasing == 0) break;

		do {
			printf("выберите метод сортировки (1-пузырьком, 2-быстрая, 3-простая, 4-выбором): "); scanf_s("%d", &userSelect);
			switch (userSelect)
			{
			case 1: start_time = clock(); bubbleSort(fileNames, fileSizes, n, increasing); break;
			case 2: start_time = clock(); fastSort(fileNames, fileSizes, 0, n - 1, increasing); break;
			case 3: start_time = clock(); simpleSort(fileNames, fileSizes, n, increasing); break;
			case 4: start_time = clock(); selectSort(fileNames, fileSizes, n, increasing); break;
			default: printf("не коректный ввод, "), gets(trash); break;
			}
		} while (userSelect < 1 || userSelect > 4);

		start_time = clock() - start_time;

		for (i = 0; i < n; i++)
		{
			printf("имя файла: %50s| размер файла: %lld bytes\n", fileNames[i], fileSizes[i]);
		}

		printf("время: %.3f секунд\n", (double)start_time / CLOCKS_PER_SEC);
	}

	for (i = 0; i < n; i++)
	{
		free(fileNames[i]);
	}

	return 0;
}
void swap(char* names[], unsigned long long sizes[],int ind1, int ind2) {
	char* tmpN;
	unsigned long long tmpS;
	tmpN = names[ind1];
	tmpS = sizes[ind1];
	names[ind1] = names[ind2]; names[ind2] = tmpN;
	sizes[ind1] = sizes[ind2]; sizes[ind2] = tmpS;
}
void bubbleSort(char* names[], unsigned long long sizes[], int n, int increasing)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if ((sizes[j] > sizes[j + 1] && increasing == 2) || (sizes[j] < sizes[j + 1] && increasing == 1))
			{
				swap(names, sizes, j, j + 1);
			}
		}
	}
}
void fastSort(char* names[], unsigned long long sizes[], int start, int end, int increasing)
{
	unsigned long long mid = sizes[(start + end) / 2];
	int l = end, r = start;
	while (l > r)
	{
		while ((sizes[l] > mid && increasing == 2) || (sizes[l] < mid && increasing == 1)) l--;
		while ((sizes[r] < mid && increasing == 2) || (sizes[r] > mid && increasing == 1)) r++;

		if (l >= r)
		{
			swap(names, sizes, l, r);
			l--; r++;
		}
	}
	if (l > start) fastSort(names, sizes, start, l, increasing);
	if (r < end) fastSort(names, sizes, r, end, increasing);
}
void simpleSort(char* names[], unsigned long long sizes[], int n, int increasing)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if ((sizes[i] > sizes[j] && increasing == 2) || (sizes[i] < sizes[j] && increasing == 1))
			{
				swap(names, sizes, i,j);
			}
		}
	}
}
void selectSort(char* names[], unsigned long long sizes[], int n, int increasing)
{
	int i, j,swapNum;
	for (i = 0; i < n; i++)
	{
		swapNum = i;
		for (j = i + 1; j < n; j++)
		{
			if ((sizes[swapNum] > sizes[j] && increasing == 2) || (sizes[swapNum] < sizes[j] && increasing == 1))
			{
				swapNum = j;
			}
		}
		swap(names, sizes, i, swapNum);
	}
}

/*void copyStr(char* s1, const char* s2, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		s1[i] = s2[i];
	}
}

unsigned long long SizeDir(char* p)
{
	WIN32_FIND_DATA  FindFileData;
	HANDLE hFind;
	unsigned long long size = 0;

	char pc[256];
	copyStr(pc, p, 256);
	p = strcat(p + strlen(p), "\\*");
	hFind = FindFirstFileA(p, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE){return 0;}
	do {
		if (strcmp(FindFileData.cFileName, ".") != 0 && strcmp(FindFileData.cFileName, "..") != 0) {
			if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				size += ((unsigned long long)FindFileData.nFileSizeHigh << 32) | FindFileData.nFileSizeLow;
			}
			else {
				char p2[256];
				copyStr(p2, pc, 256);
				strcat_s(strcat_s(p2, sizeof(p2), "\\"), sizeof(p2), FindFileData.cFileName);
				size += SizeDir(p2);
			}
		}
	} while (FindNextFileA(hFind, &FindFileData) != 0);
	return size;
}*/