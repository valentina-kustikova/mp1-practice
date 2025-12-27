#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>

int input_directory(char directoryPath[], WIN32_FIND_DATA* FindFileData);
void print_files(unsigned long long* fileSizes, char** fileNames, int n);
void read_directory(int* n, unsigned long long** fileSizes, char*** fileNames, WIN32_FIND_DATA  FindFileData, char directoryPath[]);

void bubbleSort(char* names[], unsigned long long sizes[], int n, int increasing);
void fastSort(char* names[], unsigned long long sizes[], int start, int end, int increasing);
void mergeSort(char* names[], char* namesb[], unsigned long long sizes[], unsigned long long sizesb[], int start, int end, int increasing);
void simpleSort(char* names[], unsigned long long sizes[], int n, int increasing);
void selectSort(char* names[], unsigned long long sizes[], int n, int increasing);
void insertsSort(char* names[], unsigned long long sizes[], int n, int increasing);

int main() {
	WIN32_FIND_DATA  FindFileData;
	char **fileNames, **fileNamesB;
	unsigned long long *fileSizes, *fileSizesB;
	int n,i, increasing, userSelect,sorted;
	char directoryPath[MAX_PATH];
	clock_t work_time;

	setlocale(LC_ALL,"RUS");

	while (1) {
		/*do {
			printf("введите директорию (0 - выход): ");
			//gets(directoryPath);
			fgets(directoryPath, MAX_PATH, stdin);
			directoryPath[strlen(directoryPath) - 1] = '\0';
			if (strcmp(directoryPath,"0") == 0) return 0;
			strcat_s(directoryPath, sizeof(directoryPath), "\\*");
			hFind = FindFirstFileA(directoryPath, &FindFileData);
			if (hFind == INVALID_HANDLE_VALUE) printf("директория не найдена... (убедитесь, что она не содержит кириллицы)\n");

		} while (hFind == INVALID_HANDLE_VALUE);*/

		if (input_directory(directoryPath,&FindFileData)) return 0;

		read_directory(&n, &fileSizes, &fileNames, FindFileData, directoryPath);
		
		print_files(fileSizes, fileNames, n);


		printf("сортировать по 1-убыванию, 2-возрастанию: "); scanf_s("%d", &increasing);
		while (increasing < 1 || increasing > 2) { 
			while(getchar() != '\n');
			printf("не коректный ввод, сортировать по 1-убыванию, 2-возрастанию: "); 
			scanf_s("%d", &increasing); 
		}

		do {
			printf("выберите метод сортировки (1-пузырьком, 2-быстрая, 3-простая, 4-выбором, 5-слиянием, 6-вставками): "); scanf_s("%d", &userSelect);
			switch (userSelect)
			{
			case 1:
				work_time = clock();
				bubbleSort(fileNames, fileSizes, n, increasing);
				work_time = clock() - work_time;
				break;
			case 2:
				work_time = clock();
				fastSort(fileNames, fileSizes, 0, n - 1, increasing);
				work_time = clock() - work_time;
				break;
			case 3:
				work_time = clock();
				simpleSort(fileNames, fileSizes, n, increasing);
				work_time = clock() - work_time;
				break;
			case 4:
				work_time = clock();
				selectSort(fileNames, fileSizes, n, increasing);
				work_time = clock() - work_time;
				break;
			case 5:
				fileNamesB = (char**)malloc(n * sizeof(char*));
				fileSizesB = (unsigned long long*)malloc(n * sizeof(unsigned long long));
				work_time = clock();
				mergeSort(fileNames, fileNamesB, fileSizes, fileSizesB, 0, n - 1, increasing);
				work_time = clock() - work_time;
				free(fileNamesB); free(fileSizesB);
				break;
			case 6:
				work_time = clock();
				insertsSort(fileNames, fileSizes, n, increasing);
				work_time = clock() - work_time;
				break;
			default:
				printf("не коректный ввод, ");
				while(getchar() != '\n'); 
				break;
			}
		} while (userSelect < 1 || userSelect > 6);

		print_files(fileSizes, fileNames, n);

		printf("время: %.3f секунд\n", (double)work_time / CLOCKS_PER_SEC);

		for (i = 0; i < n; i++)
		{
			free(fileNames[i]);
		}
		free(fileNames);
		free(fileSizes);
		while (getchar() != '\n');
	}

	return 0;
}
void read_directory(int*n, unsigned long long** fileSizes, char*** fileNames, WIN32_FIND_DATA  FindFileData, char directoryPath[]) {
	HANDLE hFind;
	int i = 0;

	hFind = FindFirstFileA(directoryPath, &FindFileData);
	*n = 0;

	do {
		if (strcmp(FindFileData.cFileName, ".") != 0 && strcmp(FindFileData.cFileName, "..") != 0 &&
			!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) (*n)++;
	} while (FindNextFileA(hFind, &FindFileData) != 0);


	*fileNames = (char**)malloc(*n * sizeof(char*));
	*fileSizes = (unsigned long long*)malloc(*n * sizeof(unsigned long long));
	hFind = FindFirstFileA(directoryPath, &FindFileData);

	do {
		if (strcmp(FindFileData.cFileName, ".") != 0 && strcmp(FindFileData.cFileName, "..") != 0 &&
			!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			size_t len = strlen(FindFileData.cFileName) + 1;
			(*fileNames)[i] = malloc(len);
			memcpy((*fileNames)[i], FindFileData.cFileName, len);
			(*fileSizes)[i] = ((unsigned long long)FindFileData.nFileSizeHigh << 32)
				| FindFileData.nFileSizeLow;
			i++;
		}
	} while (FindNextFileA(hFind, &FindFileData) != 0);
}

void print_files(unsigned long long* fileSizes, char** fileNames,int n) {
	int i;
	if (n <= 20) {
		for (i = 0; i < n; i++)
		{
			printf("имя файла: %50s| размер файла: %lld bytes\n", fileNames[i], fileSizes[i]);
		}
	}
	printf("Число файлов: %d\n", n);
}
int input_directory(char directoryPath[], WIN32_FIND_DATA* FindFileData) {

	HANDLE hFind;
	do {
		printf("введите директорию (0 - выход): ");
		fgets(directoryPath, MAX_PATH, stdin);
		directoryPath[strlen(directoryPath) - 1] = '\0';
		if (strcmp(directoryPath, "0") == 0) return 1;
		strcat_s(directoryPath, sizeof(char) * MAX_PATH, "\\*");
		hFind = FindFirstFileA(directoryPath, FindFileData);
		if (hFind == INVALID_HANDLE_VALUE) printf("директория не найдена... (убедитесь, что она не содержит кириллицы)\n");

	} while (hFind == INVALID_HANDLE_VALUE);
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
void mergeSort(char* names[], char* namesb[], unsigned long long sizes[], unsigned long long sizesb[], int start, int end, int increasing)
{
	int i, j, k = start;
	if (start >= end) return;
	mergeSort(names, namesb, sizes, sizesb, start, (start + end) / 2, increasing);
	mergeSort(names, namesb, sizes, sizesb, (start + end) / 2 + 1, end, increasing);


	i = start;
	j = (start + end) / 2 + 1;
	while (i <= (start + end) / 2 && j <= end)
	{
		if ((sizes[i] > sizes[j] && increasing == 1) || (sizes[i] < sizes[j] && increasing == 2)) { sizesb[k] = sizes[i]; namesb[k++] = names[i++];}
		else { sizesb[k] = sizes[j]; namesb[k++] = names[j++];}
	}
	while (i <= (start + end) / 2) { sizesb[k] = sizes[i]; namesb[k++] = names[i++]; }
	while (j <= end) { sizesb[k] = sizes[j]; namesb[k++] = names[j++]; }


	for (k = start; k <= end; k++)
	{
		sizes[k] = sizesb[k];
		names[k] = namesb[k];
	}
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
void insertsSort(char* names[], unsigned long long sizes[], int n, int increasing)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		for (j = i; j > 0; j--)
		{
			if ((sizes[j] > sizes[j - 1] && increasing == 2) || (sizes[j] < sizes[j - 1] && increasing == 1)) break;
			swap(names, sizes, j, j - 1);
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