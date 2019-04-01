#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#include <time.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 4048//���� ����� ��� �����
#define ROFL 2000
#define MAX_FILES 1000//����������������� ���������� ������
int kolvo = 0;//���������� ������
#define K 150//��� ���������� ���������

void Merge(int *a, ULONGLONG *size, int l, int m, int r) //�������
{
	int i, j = m + 1, h, tmp;
	ULONGLONG tmp1;
	for (i = l; ((i < r) && (j <= r)); i++)
	{
		if (size[a[i]] > size[a[j]])//��������� ��������
		{
			tmp = a[j];
			for (h = j; h > i; h--)
				a[h] = a[h - 1];
			a[i] = tmp;//������ ��������
			j++;
		}
	}

}

void MergeSort(int *a, ULONGLONG *size, int l, int r)//���������
{
	int m;
	if (l >= r) return;
	m = (l + r) / 2;
	MergeSort(a, size, l, m);
	MergeSort(a, size, m + 1, r);
	Merge(a, size, l, m, r);
}
void anihilation(ULONGLONG*filesize, ULONGLONG*filesizecopy, int* filesindex, int* newindex, int kolvo)//��������� ����� �����������
{
	int i;
	for (i = 0; i < kolvo; i++)
	{
		filesize[i] = filesizecopy[i];
		newindex[i] = filesindex[i];

	}
}
int ListDirectoryContents(const wchar_t *sDir, ULONGLONG*filesize, wchar_t **fileNames)//����� ������ ������
{
	int i = 0;
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t *sPath;
	sPath = (wchar_t*)malloc(ROFL * sizeof(wchar_t));
	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		wprintf(L"���� �� ������: [%s]\n", sDir);
		return 1;
	}
	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{
			ULONGLONG fileSize = fdFile.nFileSizeHigh;
			fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
			fileSize |= fdFile.nFileSizeLow;
			filesize[i] = fileSize;
			fileNames[i] = (wchar_t*)malloc(ROFL * sizeof(wchar_t));
			wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
			wsprintf(fileNames[i], L"%s", sPath);
			i++;
			kolvo++;
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);
	return 0;
}
int* quicksort(ULONGLONG* size, int n1, int n2, int n, int* id)//������� ����������
{
	ULONGLONG tmp;
	int i = n1, j = n2, p = size[(n1 + n2) / 2], tmp1, k;
	do {
		while (size[i] < p) i++;
		while (size[j] > p) j--;
		if (i <= j)
		{
			if (size[i] > size[j])
			{
				tmp = size[i];
				size[i] = size[j];
				size[j] = tmp;
				tmp1 = id[i];
				id[i] = id[j];
				id[j] = tmp1;
			}
			i++;
			j--;
		}
	} while (i <= j);
	if (i < n2)
		id = quicksort(size, i, n2, n, id);
	if (n1 < j)
		id = quicksort(size, n1, j, n, id);
	return id;
}
void podschetom(ULONGLONG*a, int n, int*newindex)//���������� ���������
{
	int i, j, b = 0;
	ULONGLONG *count;//������ ��������
	ULONGLONG *dopmass;//��� ������ ��� �������� ��������
	ULONGLONG min = a[0], max = a[n - 1], k;
	dopmass = (ULONGLONG*)malloc(n * sizeof(ULONGLONG));
	for (i = 0; i < n; i++)
	{
		dopmass[i] = a[i];
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	k = max + min + 1;
	count = (ULONGLONG*)malloc(k * sizeof(ULONGLONG));
	for (i = 0; i < k; i++)
		count[i] = 0;
	for (i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < count[i]; j++)
			a[b++] = i + min;
	}
	for (j = 0; j < n; j++)
		b = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			if ((a[i] == dopmass[j]))
			{
				newindex[b] = j;
				dopmass[j] = -1;
				b++;
				break;
			}
	}
}
void choose(ULONGLONG* filesize, int kolvo, int*newindex)//���������� �������
{
	int i, j, minind;
	ULONGLONG min;
	for (i = 0; i < kolvo; i++)
	{
		min = filesize[i];
		minind = i;

		for (j = i + 1; j < kolvo; j++)
		{
			if (filesize[j] < min)
			{
				min = filesize[j];
				minind = j;
				newindex[i] = j;
				filesize[minind] = filesize[i];
				filesize[i] = min;
			}
		}
	}
}
void bubble(ULONGLONG* filesize, int *numer, int kolvo)//���������� ���������
{
	int i, j, swap;
	ULONGLONG tmp;
	for (i = 0; i < kolvo; i++)
	{
		for (j = 1; j < kolvo; j++)
		{
			if (filesize[j - 1] > filesize[j])
			{
				tmp = filesize[j];
				filesize[j] = filesize[j - 1];
				filesize[j - 1] = tmp;
				swap = numer[j];
				numer[j] = numer[j - 1];
				numer[j - 1] = swap;
			}
		}
	}
}
void insert(ULONGLONG* filesize, int *numer, int kolvo)//���������� ���������
{
	int i, j, swap;
	ULONGLONG tmp;
	for (i = 0; i < kolvo; i++)
	{
		j = i - 1;
		tmp = filesize[i];
		swap = numer[i];
		while ((j >= 0) && (filesize[j] > tmp))
		{
			filesize[j + 1] = filesize[j];
			filesize[j] = tmp;
			numer[j + 1] = numer[j];
			numer[j] = swap;
			j--;
		}
	}
}
void print(ULONGLONG* filesize, wchar_t **fileNames, int kolvo)//������
{
	int i;
	for (i = 0; i < kolvo; i++)
	{
		wprintf(L"file  %s ������ %lld \n", fileNames[i], filesize[i]);
	}
}
void menu()//
{
	printf("���� ���������!\n");
	printf("������� 1 ��� ���������� ���������!\n");
	printf("������� 2 ��� ���������� ��������!\n");
	printf("������� 3 ��� ���������� �������!\n");
	printf("������� 4 ��� ���������� ���������!\n");
	printf("������� 5 ��� ������� ����������(���������� �����)!\n");
	printf("������� 6 ��� ���������� ��������!\n");
	printf("�� ������� ���������� �����: ");
}
void main()
{
	int i = 0;
	double total_time;
	char e;
	int choice, flag = 1;
	clock_t start, end;
	wchar_t **fileNames;
	wchar_t* ca;
	int*filesindex;
	char*a;
	ULONGLONG*filesize;
	ULONGLONG*filesizemain;
	int*newindex;
	setlocale(LC_ALL, "Russian");
	printf("�������� ��������!\n");
	while (flag = 1)
	{
		printf("������� ����!\n");
		fileNames = (wchar_t**)malloc(ROFL * sizeof(wchar_t*));
		filesindex = (int*)malloc((kolvo + 1) * sizeof(int));
		newindex = (int*)malloc(kolvo * sizeof(int));
		filesizemain = (ULONGLONG*)malloc(MAX_FILES * sizeof(ULONGLONG));
		filesize = (ULONGLONG*)malloc(MAX_FILES * sizeof(ULONGLONG));
		a = (char*)malloc(MAX_LEN);
		ca = (wchar_t*)malloc(MAX_LEN);
		fgets(a, MAX_LEN, stdin);
		a[strlen(a) - 1] = '\0';
		swprintf(ca, MAX_LEN, L"%hs", a);
		ListDirectoryContents(ca, filesize, fileNames);
		if (kolvo > 0)
		{
			print(filesize, fileNames, kolvo);
			flag = 1;
			for (i = 0; i < kolvo; i++)
			{
				filesindex[i] = i;
				newindex[i] = i;
			}
			menu();
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				scanf("%c", &e);
				anihilation(filesizemain, filesize, filesindex, newindex, kolvo);
				start = clock();
				printf("���������� ���������!\n");
				bubble(filesize, newindex, kolvo);
				end = clock();
				for (i = 0; i < kolvo; i++)
				{
					wprintf(L"file %s ������ %lld \n", fileNames[newindex[i]], filesize[i]);
				}
				total_time = (double)(end - start) / CLOCKS_PER_SEC;
				printf("����� ����������: %.3lf �\n", total_time);
				break;
			case 2:
				scanf("%c", &e);
				anihilation(filesizemain, filesize, filesindex, newindex, kolvo);
				start = clock();
				printf("���������� ��������\n");
				insert(filesize, newindex, kolvo);
				end = clock();
				for (i = 0; i < kolvo; i++)
				{
					wprintf(L"file %s ������ %lld \n", fileNames[newindex[i]], filesize[i]);
				}
				total_time = (double)(end - start) / CLOCKS_PER_SEC;
				printf("����� ����������: %.3lf �\n", total_time);
				break;
			case 3:
				scanf("%c", &e);
				anihilation(filesizemain, filesize, filesindex, newindex, kolvo);
				start = clock();
				printf("���������� �������\n");
				choose(filesize, kolvo, newindex);
				end = clock();
				for (i = 0; i < kolvo; i++)
				{
					wprintf(L"file %s ������ %lld \n", fileNames[newindex[i]], filesize[i]);
				}
				total_time = (double)(end - start) / CLOCKS_PER_SEC;
				printf("����� ����������: %.3lf �\n", total_time);
				break;
			case 4:
				scanf("%c", &e);
				anihilation(filesizemain, filesize, filesindex, newindex, kolvo);
				start = clock();
				printf("���������� ���������!");
				podschetom(filesize, kolvo, newindex);
				end = clock();
				for (i = 0; i < kolvo; i++)
				{
					wprintf(L"file %s ������ %lld \n", fileNames[newindex[i]], filesize[i]);
				}
				total_time = (double)(end - start) / CLOCKS_PER_SEC;
				printf("����� ����������: %.3lf �\n", total_time);
				break;
			case 5:
				scanf("%c", &e);
				anihilation(filesizemain, filesize, filesindex, newindex, kolvo);
				start = clock();
				newindex = quicksort(filesize, 0, kolvo - 1, kolvo, filesindex);
				end = clock();
				for (i = 0; i < kolvo; i++)
				{
					wprintf(L"file %s ������ %lld \n", fileNames[newindex[i]], filesize[i]);
				}
				total_time = (double)(end - start) / CLOCKS_PER_SEC;
				printf("����� ����������: %.3lf �\n", total_time);
				break;
			case 6:
				scanf("%c", &e);
				anihilation(filesizemain, filesize, filesindex, newindex, kolvo);
				start = clock();
				MergeSort(newindex, filesize, 0, (kolvo - 1));
				end = clock();
				for (i = 0; i < kolvo; i++)
				{
					wprintf(L"file %s ������ %lld \n", fileNames[newindex[i]], filesize[newindex[i]]);
				}
				total_time = (double)(end - start) / CLOCKS_PER_SEC;
				printf("����� ����������: %.3lf �\n", total_time);
				break;
			default:
				menu();
				scanf("%d", &choice);
			}
			kolvo = 0;
		}
	}
}