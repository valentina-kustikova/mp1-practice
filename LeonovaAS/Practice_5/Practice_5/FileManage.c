#include <stdio.h>
#include "dirent.h"
#include <string.h>
#include <time.h>


DIR* dir;
struct dirent* ent;

int stat(const char* file_name, struct stat* buf);
char* charconv(const char* a);
char* file_name(char* a, const char* b);
int colvo_files(char* path);

void get_sorted(long int* a, long int* a1, int* b, char** c, int n);
void sort_bubble(long int* a, int* b, int n);
void sort_choose(long int* a, int* b, int n);
void sort_input(long int* a, int* b, int n);
void sort_merge(long int* a, int* b, int left, int right);
void sort_quick(long int* a, int* b, int left, int right);

void swap(long int* a, long int* b);
void print_sorted(long int* a, int* b, char** c, int n);
void print_original(long int* a, char** b, int n);
void merge(long int* a, int* b, int left, int mid, int right);

int main()
{
    struct stat fsize;
    char path[255], ** names;
    long int* sizes, * copy_sizes;
    int* idx;
    int i = 0, colvo, j;


    printf("Input path to the directory: ");
    scanf("%s", path);

    colvo = colvo_files(path);
    names = (char**)malloc(sizeof(char*) * colvo);
    sizes = (long int*)malloc(sizeof(long int) * colvo);
    idx = (int*)malloc(sizeof(int) * colvo);
    copy_sizes = (long int*)malloc(sizeof(long int) * colvo);

    dir = opendir(path);

    if (dir)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            char* tmp;
            if (ent->d_type != DT_REG)
            {
                continue;
            }
            names[i] = charconv(ent->d_name);
            tmp = file_name(path, ent->d_name);
            stat(tmp, &(fsize));
            free(tmp);
            sizes[i] = (long int)fsize.st_size;
            i++;
        }
        closedir(dir);

    }

    get_sorted(sizes, copy_sizes, idx, names, colvo);

    free(idx);
    free(copy_sizes);
    free(sizes);
    for (i = 0; i < colvo; i++)
    {
        free(names[i]);
    }
    free(names);
    return 0;
}

char* charconv(const char* a)
{
    size_t b = strlen(a), c = b + 1;
    char* norm = malloc(c * sizeof(char));
    if (norm != 0)
    {
        strcpy(norm, a);
    }
    return norm;
}
char* file_name(char* a, const char* b)
{
    char* name = malloc((strlen(a) + strlen(b) + 2) * sizeof(char));
    if (name != NULL)
    {
        strcpy(name, a);
        strcat(name, "\\");
        strcat(name, b);
        return name;
    }
    return 0;

}
int colvo_files(char* path)
{
    int i = 0;
    dir = opendir(path);
    while ((ent = readdir(dir)) != NULL)
    {
        if (ent->d_type != DT_REG)
        {
            continue;
        }
        i++;
    }
    return i;
}

void get_sorted(long int* a, long int* a1, int* b, char** c, int n)
{
    clock_t start = 0;
    clock_t end = 0;
    double ttl = 0;
    int flag = 1, method = 0, i;
    while (flag == 1)
    {

        printf("\nOriginal order:\n\n");
        print_original(a, c, n);
        printf("\nDo you want to sort these files?\n");
        scanf("%d", &flag);

        if (flag == 0)
        {
            return;
        }

        for (i = 0; i < n; i++)
        {
            b[i] = i;
            a1[i] = a[i];
        }

        printf("1.Bubble sort\n2.Input sort\n3.Choice sort\n4.Merge sort\n5.Quick sort\n");

        do
        {
            scanf("%d", &method);
        } while (method <= 0 || method >= 6);

        switch (method)
        {
        case 1:
            start = clock();
            sort_bubble(a1, b, n);
            end = clock();
            print_sorted(a1, b, c, n);
            ttl = (double)((end - start)) / CLOCKS_PER_SEC;
            printf("\nTime of the sorting: %.5lf\n", ttl);
            break;
        case 2:
            start = clock();
            sort_input(a1, b, n);
            end = clock();
            print_sorted(a1, b, c, n);
            ttl = (double)((end - start)) / CLOCKS_PER_SEC;
            printf("\nTime of the sorting: %.5lf\n", ttl);
            break;
        case 3:
            start = clock();
            sort_choose(a1, b, n);
            end = clock();
            print_sorted(a1, b, c, n);
            ttl = (double)((end - start)) / CLOCKS_PER_SEC;
            printf("\nTime of the sorting: %.5lf\n", ttl);
            break;
        case 4:
            start = clock();
            sort_merge(a1, b, 0, n - 1, n);
            end = clock();
            print_sorted(a1, b, c, n);
            ttl = (double)((end - start)) / CLOCKS_PER_SEC;
            printf("\nTime of the sorting: %.5lf\n", ttl);
            break;
        case 5:
            start = clock();
            sort_quick(a1, b, 0, n - 1);
            end = clock();
            print_sorted(a1, b, c, n);
            ttl = (double)((end - start)) / CLOCKS_PER_SEC;
            printf("\nTime of the sorting: %.5lf\n", ttl);
            break;
        }
    }
}
void sort_bubble(long int* a, int* b, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                swap(&b[j], &b[j + 1]);
            }
        }
    }
}
void sort_choose(long int* a, int* b, int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(&a[min], &a[i]);
        swap(&b[min], &b[i]);
    }
}
void sort_input(long int* a, int* b, int n)
{
    int i, j;
    int min;
    for (i = 1; i < n; i++)
    {
        min = a[i];

        j = i - 1;
        while (j >= 0 && a[j] > min)
        {
            a[j + 1] = a[j];
            swap(&b[j + 1], &b[j]);

            j--;
        }
        a[j + 1] = min;

    }
}
void sort_merge(long int* a, int* b, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    sort_merge(a, b, left, (left + right) / 2);
    sort_merge(a, b, (left + right) / 2 + 1, right);
    merge(a, b, left, (left + right) / 2, right);
}
void sort_quick(long int* a, int* b, int left, int right)
{
    int l = left, r = right;
    int pivot = a[(l + r) / 2];
    while (l <= r)
    {
        while (a[l] < pivot)
            l++;
        while (a[r] > pivot)
            r--;
        if (l <= r)
        {
            swap(&a[l], &a[r]);
            swap(&b[l], &b[r]);
            l++;
            r--;
        }
    }
    if (left < r)
        sort_quick(a, b, left, r);
    if (right > l)
        sort_quick(a, b, l, right);
}

void swap(long int* a, long int* b)
{
    long int t = *a;
    *a = *b;
    *b = t;
}
void print_sorted(long int* a, int* b, char** c, int n)
{
    int i, j;
    printf("Sorted order:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (b[i] == j)
            {
                printf("SORTED| %s ... %ld\n", c[j], a[i]);
            }
        }

    }
}
void print_original(long int* a, char** b, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("ORIG| %s ... %ld\n", b[i], a[i]);
    }
}
void merge(long int* a, int* b, int left, int mid, int right)
{
    int i1 = 0, i2 = 0, n;
    int* f1, * s1;
    long int* f, * s;

    f = (long int*)malloc(sizeof(long int) * (mid - left + 1));
    f1 = (int*)malloc(sizeof(int) * (mid - left + 1));
    s = (long int*)malloc(sizeof(long int) * (right - mid));
    s1 = (int*)malloc(sizeof(int) * (right - mid));



    for (i1 = 0; i1 < mid - left + 1; i1++)
    {
        f[i1] = a[left + i1];
        f1[i1] = b[left + i1];
    }

    for (i2 = 0; i2 < right - mid; i2++)
    {
        s[i2] = a[mid + 1 + i2];
        s1[i2] = b[mid + 1 + i2];

    }

    i1 = 0;
    i2 = 0;
    n = left;

    while (i1 < mid - left + 1 && i2 < right - mid)
    {
        if (f[i1] <= s[i2])
        {

            b[n] = f1[i1];
            a[n++] = f[i1++];

        }
        else
        {
            b[n] = s1[i2];
            a[n++] = s[i2++];

        }

    }

    while (i1 < mid - left + 1)
    {
        b[n] = f1[i1];
        a[n++] = f[i1++];

    }

    while (i2 < right - mid)
    {
        b[n] = s1[i2];
        a[n++] = s[i2++];

    }

    free(f);
    free(f1);
    free(s);
    free(s1);
}