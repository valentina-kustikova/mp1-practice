#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

void pick(ULONGLONG a[], int *b, int n)
{
	int i, j, tmp;
	int minind;
	ULONGLONG t, min;
	for (i = 0; i < n; i++)
	{
		min = a[i];
		minind = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < min)
			{
			min = a[j];
			minind = j;
			}
			t = a[i];
			a[i] = a[minind];
			a[minind] = t;
			tmp = b[i];
			b[i] = b[minind];
			b[minind] = tmp;
		}
	}
}

void paste(ULONGLONG a[], int n, int *b)
{
	int i, j, t;
	ULONGLONG tmp;
	for (i = 1; i < n; i++)
	{
		j = i - 1;
		tmp = a[i];
		t = b[i];
		while ((j >= 0) && (a[j] > tmp))
		{
			a[j+1] = a[j];
			a[j] = tmp;
			b[j+1] = b[j];
			b[j] = t;
			j--;
		}
	}
}

void bubble_sort(ULONGLONG a[],int *b,  int n)
{
	int i, j, t;
	ULONGLONG tmp;
	for (i = 0; i < n - 1; i++)
		for (j = 1; j < n - i; j++)
			if (a[j - 1] > a[j])
			{
			tmp = a[j - 1];
			a[j - 1] = a[j];
			a[j] = tmp;
			t = b[j - 1];
			b[j - 1] = b[j];
			b[j] = t;
			}
}

/*void counting_sort(ULONGLONG a[], int n)//недоработана
{
    int *count_ind;
    ULONGLONG *sizes, *arr, k, max = a[n - 1], min = a[0];
    int i, b = 0, j;
    count_ind = (int*)malloc(n * sizeof(int));
    size = (ULONGLONG*)malloc(n * sizeof(ULONGLONG));
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
    k = max - min + 1;
    if (k * (ULONGLONG)sizeof(int) > (ULONGLONG)UINT_MAX)
        return;
    arr = (ULONGLONG*)malloc(k * sizeof(ULONGLONG));
    for (i = 0; i < k; i++) 
        arr[i] = 0;
    for (i = 0; i < n; i++)
    {
        arr[a[i] - min]++;
    }
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < arr[i]; j++)
            sizes[b++] = i + min;
    }
    for (j = 0; j < n; j++)
        arr[j] = a[j];
    b = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if ((size[i] == arr[j]))
            {
                count_ind[b] = j;
                arr[j] = -1;
                b++;
                break;
            }
    }
    free(arr);
    free(size);
    return;
}*/

void merge(ULONGLONG a[], int *b, int l, int m, int r)
{
    int i, j, v = 0;
    int *arr_ind;	
    ULONGLONG *arr;
    arr = (ULONGLONG*)malloc((r - l + 1) * sizeof(ULONGLONG));
    arr_ind = (int*)malloc((r - l + 1) * sizeof(int));
    i = l;
    j = m + 1;
    while ((i <= m) && (j <= r))
    {
        if (a[i] < a[j])
        {
	    arr_ind[v++] = b[i++];
            arr[v++] = a[i++];

        }
        else
        {
            arr_ind[v++] = b[j++];
            arr[v++] = a[j++];
        }
    }
    while (i <= m)
    {
	arr_ind[v++] = b[i++];
        arr[v++] = a[i++];
    }
    while (j <= r)
    {
	arr_ind[v++] = b[j++];
        arr[v++] = a[j++];
    }
    for (v = l; v <= r; v++)
	{
	arr_ind[v] = b[i - l];
        a[v] = arr[v - l];
    }
	free(arr);
	free(arr_ind);
}

void merge_sort(ULONGLONG a[], int l, int r, int *b)
{
    int m;
    if (l >= r) return;
    m = (l + r) / 2;
    merge_sort(a, l, r, b);
    merge_sort(a, m + 1, r, b);
    merge(a, b, l, m, r);
}

void hoarasort(ULONGLONG* a, int *b, int first, int last)
{
 int ind = (first + last)/2;
 int i, j;
 i = first;
 j = last;
 hoarasplit(a, b, &i, &j, a[ind]);
 if (i < last)
   hoarasort(a, b, i, last);
 if (first < j)
   hoarasort(a, b, first, j);
}

void hoarasplit(ULONGLONG* a, int* b, int *first, int *last, int p)
{
	int t;
	ULONGLONG tmp;
	do {
		while(a[*first] < p)(*first)++;
		while(a[*last] < p)(*last)++;
		if (*first < *last)
		{
			tmp = a[*first];
			a[*first] = a[*last];
			a[*last] = tmp;
			t = b[*first];
			b[*first] = b[*last];
			b[*last] = t;
		}
	   } while(*first <= *last);
}

int ListDirectoryContents(wchar_t *sDir, wchar_t ***filename, ULONGLONG **filesize)
{ 
    int q = 0;
    WIN32_FIND_DATA fdFile; //структура описания файлов 
    HANDLE hFind = NULL; 
    wchar_t sPath[2048];

    wsprintf(sPath, L"%s\\*.*", sDir); 
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE) //проверка введеного пути
    { 
        return -1; 
    } 
	 do
    {
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{
			q++;
		}
	} while (FindNextFile(hFind, &fdFile));// q - кол-во файлов в директории
	hFind = FindFirstFile(sPath, &fdFile);
	*filename = (wchar_t**)malloc(q * sizeof(wchar_t*));
	*filesize = (ULONGLONG*)malloc(q * sizeof(ULONGLONG));// создаю массив размеров файлов
	q = 0;

    do
    { 
        if (wcscmp(fdFile.cFileName, L".") != 0  && wcscmp(fdFile.cFileName, L"..") != 0) 
        {
			
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8; //Побитовый сдвиг влево, совмещённый с присваиванием
            fileSize |= fdFile.nFileSizeLow;
	    (*filename)[q] = (wchar_t*)malloc(2048 * sizeof(wchar_t));
            (*filesize)[q] = fileSize;
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf((*filename)[q], L"%s", sPath);
			q++;
        }
    } 
    while(FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    return q; //возвращаю кол файлов в директории 
} 

void Putpath(wchar_t* str, char* str1)
{
    fgets(str1, 2048, stdin);
    str1[strlen(str1) - 1] = '\0';
    swprintf(str, 2048, L"%hs", str1);
}

void call_menu()
{
	printf("\n1 - сортировка пузырьком\n");
	printf("2 - сортировка выбором\n");
	printf("3 - сортировка вставками\n");
	printf("4 - сортировка подсчетом\n");
	printf("5 - сортировка слиянием\n");
	printf("6 - быстрая сортировка\n");
	printf("7 - выход из программы\n");
}

void main()
{
	int p, user_pick, i;
	ULONGLONG* copy_filesize, *filesize;//массив размеров файлов
	wchar_t **filename;//массив имен файлов
	char* str = (char*)malloc(2048);
        wchar_t* strclon = (wchar_t*)malloc(2048);
	int* indfilename;//массив индексов для имен файлов
	clock_t start, stop, time;
	setlocale(LC_ALL, "Russian");
	printf("Введите путь к файлам(вместо <\\> необходимо ставить <\\\\>\n");
	Putpath(strclon, str);
	p = ListDirectoryContents(strclon, &filename, &filesize);
	if (p == 0)
	{
		printf("В директории не обнаружено файлов\n");
		return;
	}
	indfilename = (int*)malloc(p * sizeof(int));
	copy_filesize = (ULONGLONG*)malloc(p * sizeof(ULONGLONG));
	for(i = 0; i < p; i++)
	{
		indfilename[i] = i;
		copy_filesize[i] = filesize[i];
	}
	user_pick = 0;
	while(user_pick != 7)
	{
		printf("\nВыбирете сортировку ");
		call_menu();
		scanf("%d", &user_pick);
		for(i = 0; i < p; i++)
		{
			indfilename[i] = i;
			copy_filesize[i] = filesize[i];
		}
		switch (user_pick)
			{
			case 1: start = clock();
				bubble_sort(copy_filesize, indfilename, p); 
				stop = clock();
				break;
			case 2: start = clock(); 
				pick(copy_filesize, indfilename, p); 
				stop = clock();
				break;
			case 3:	start = clock();	
				paste(copy_filesize, p, indfilename);
				stop = clock();
				break;
			case 4: start = clock();
				counting_sort(copy_filesize, p);
				stop = clock();
				break;;
			case 5: start = clock();
				merge_sort(copy_filesize, p, 0, indfilename);
				stop = clock();
				break;
			case 6: start = clock();
				hoarasort(copy_filesize, indfilename, 0, p-1); 
				stop = clock();
				break;
			case 7: return;
			}
		for(i = 0; i < p; i++)
        	wprintf(L"Файл: %s Размер: %lld байт\n", filename[indfilename[i]], filesize[indfilename[i]]);
		printf("\n");
		time = stop - start;
		printf("Отсортировано за %.5f", ((float)time)/CLK_TCK);
	}
	free(str);
	free(strclon);
	free(indfilename);
	free(copy_filesize);
}
