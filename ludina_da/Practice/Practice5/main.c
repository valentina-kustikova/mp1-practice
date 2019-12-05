#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#define MAX_LEN 2048
#define K 10000

struct fail //структура для хранения имени и размера файла
{
    unsigned long size;
    wchar_t name[32];
};
//функция сравнения двух элементов  
int compare(struct fail a, struct fail b, int k)
{
    if (k == 1)
        if (a.size > b.size)
            return 1;
        else
            return 0;
    if (k == 2)
        if (a.size < b.size)
            return 1;
        else
            return 0;
}
//функция сортировки пузырьком
void buble_sort(struct fail a[], long size, int k)
{
    long i, j;
    struct fail tmp;
    for (i = 0; i < size; i++)
    {
        for (j = 1; j < size - i; j++)
        {
            if (compare(a[j], a[j - 1], k) == 1)
            {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }
}
//функция сортировки выбором
void choose(struct fail a[], long size, int k)
{
    long i, j;
    struct fail min;
    long minidx;
    for (i = 0; i < size; i++)
    {
        minidx = i;
        min = a[i];
        for (j = i + 1; j < size; j++)
        {
            if (compare(a[j], min, k) == 1)
            {
                min = a[j];
                minidx = j;
            }
        }
        a[minidx] = a[i];
        a[i] = min;
    }
}
//функция сортировки вставками
void insert_sort(struct fail a[], long size, int k)
{
    long i, j;
    struct fail tmp;
    for (i = 0; i < size; i++)
    {
        tmp = a[i];
        j = i - 1;
        while (j >= 0 && (compare(tmp, a[j], k) == 1))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
}
//функция организующая слияние, двух упорядоченных последовательностей
void merge(struct fail a[], long l, long mid, long r, int k)
{
    long p1 = mid - l + 1;
    long p2 = r - mid;
    int i, j;
    int d;
    struct fail* L = (struct fail*)malloc(p1 * sizeof(struct fail));
    struct fail* R = (struct fail*)malloc(p2 * sizeof(struct fail));
    for (i = 0; i < p1; i++)
        L[i] = a[l + i];
    for (j = 0; j < p2; j++)
        R[j] = a[mid + 1 + j];
    i = 0;
    j = 0;
    d = l;
    while (i < p1 && j < p2)
    {
        if (compare(L[i], R[j], k) == 1)
        {
            a[d] = L[i];
            i++;
        }
        else
        {
            a[d] = R[j];
            j++;
        }
        d++;
    }
    while (i < p1)
    {
        a[d] = L[i];
        i++;
        d++;
    }
    while (j < p2)
    {
        a[d] = R[j];
        j++;
        d++;
    }
}
//функция сортировки слиянием
void merge_sort(struct fail a[], long l, long r, int k)
{
    long mid;
    if (l < r)
    {
        mid = l + (r - l) / 2;
        merge_sort(a, l, mid, k);
        merge_sort(a, mid + 1, r, k);
        merge(a, l, mid, r, k);
    }
}
//функция сортировки Хоара
void quick_sort(struct fail *a, long size, int k)
{
    long i = 0, j = size - 1;
    struct fail buf, mid;
    mid = a[size >> 1];
    do
    {
        while (compare(a[i], mid, k) == 1)
            i++;
        while (compare(mid, a[j], k) == 1)
            j--;
        if (i <= j)
        {
            buf = a[i];
            a[i] = a[j];
            a[j] = buf;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0)
        quick_sort(a, j + 1, k);
    if (size > i)
        quick_sort(a + i, size - i, k);
}
//сортировка подсчетом
void count_sort(struct fail a[], int size, int k)
{
    int i, b = 0;
    int j;
    struct fail* c = (struct fail*)malloc(K * sizeof(struct fail));
    for (i = 0; i < size; i++)
        c[a[i].size] = a[i];
    for (j = 0; j < K; j++)
        if (a[j].size == 0)
        {
            a[b] = c[j];
            b++;
        }
}
int ListDirectoryContents(const wchar_t *sDir, struct fail a[], int n)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t sPath[2048];
    int i = 0;

    wsprintf(sPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Путь не найден: [%s]\n", sDir);
        return 1;
    }

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;
            struct fail file;
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wcsncpy(file.name, sPath, 100);
            file.size = fileSize;
            a[i] = file;
            i++;
        }
    } while (FindNextFile(hFind, &fdFile) && i < n);
    FindClose(hFind);
    return 0;
}
int NumOfFiles(const wchar_t *sDir)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t sPath[2048];
    int i = 0;

    wsprintf(sPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        return 0;
    }

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            i++;
        }
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    return i;
}
void Putpath(wchar_t* str, char* str1)
{
    fgets(str1, 2048, stdin);
    str1[strlen(str1) - 1] = '\0';
    swprintf(str, 2048, L"%hs", str1);
}
int main()
{
    char* a;
    wchar_t* xa;
    int f = 1;
    int par, i, n;
    struct fail* b;
    int N = 0;//Число файлов в каталоге
    clock_t start, stop;
    float t = 0;
    //order_sort - по убыванию или возрастанию сортировать, number_sort - какая сортировка
    int order_sort = 0, number_sort = 0;
    setlocale(LC_ALL, "Rus");
    printf("Введите путь к файлам в форме c:\\\\....\\\\\n");
    a = (char*)malloc(MAX_LEN);
    xa = (wchar_t*)malloc(MAX_LEN);
    Putpath(xa, a);
    n = NumOfFiles(xa);
    b = (struct fail*)malloc(n * sizeof(struct fail));
    par = ListDirectoryContents(xa, b, n);
    if (par == 0)
    {
        printf("В директории не обнаружено файлов\n");
        return;
    }
    while (1)
    {
        printf("Выберите сортировку:\n");
        printf("    1 - Пузырек\n");
        printf("    2 - Выбором\n");
        printf("    3 - Вставками\n");
        printf("    4 - Слиянием\n");
        printf("    5 - Хоара, более известная как быстрая сортировка\n");
        printf("    6 - Подсчетом\n");
        do
        {
            scanf("%d", &number_sort);
        } while (number_sort < 1 || number_sort > 6);
        printf("Как хотите отсортировать?\n1 - по убыванию, 2 -по возрастанию\n");
        do
        {
            scanf("%d", &order_sort);
        } while (order_sort < 1 || order_sort > 2);
        switch (number_sort)
        {
        case 1:
            start = clock();
            buble_sort(a, N, order_sort);
            stop = clock();
            break;
        case 2:
            start = clock();
            choose(a, N, order_sort);
            stop = clock();
            break;
        case 3:
            start = clock();
            insert_sort(a, N, order_sort);
            stop = clock();
            break;
        case 4:
            start = clock();
            merge_sort(a, 0, N - 1, order_sort);
            stop = clock();
            break;
        case 5:
            start = clock();
            quick_sort(a, N, order_sort);
            stop = clock();
            break;
        case 6:
            start = clock();
            count_sort(a, N, order_sort);
            stop = clock();
            break;
        }
        t = stop - start;
        printf("Отсортировано за %.5f\n", t / CLOCKS_PER_SEC);
        printf("Введите 1, если хотите продолжить, или 0, если хотите выйти: ");
        scanf("%d", &f);
        free(b);
        b = (struct fail*)malloc(n * sizeof(struct fail));
        ListDirectoryContents(xa, b, n);
        if (f == 0) return;
    }
}