#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define K 200
#define N 10

int check(int* a, int n)
{
    int i = 0;
    for (; i < N - 1; i++)
        if (a[i] > a[i + 1])
            return 1;
    return 0;
}

void input(int* a, int n)
{
    int i = 0;
    for (; i < n; i++)
    {
        printf("Input a[%d]\n", i);
        scanf("%d", &(a[i]));
    }
}

void inputrand(int* a, int n)
{
    int i = 0;
    srand((unsigned int)time(0));
    for (; i < n; i++)
    {
        a[i] = (100 + 100) * rand() / RAND_MAX - 100;
    }
}

void inputzero(int* a, int n)
{
    int i = 0;
    for (; i < n; i++)
        a[i] = 0;
}

void output(int* a, int n)
{
    int i = 0;
    for (; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void copy(int* a, int* b, int n)
{
    int i = 0;
    for (; i < n; i++)
        b[i] = a[i];
}

void choose(int* a, int n)
{
    int i = 0, j, min, minindx;
    for (; i < n - 1; i++)
    {
        min = a[i];
        minindx = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < min)
            {
                min = a[j];
                minindx = j;
            }
        a[minindx] = a[i];
        a[i] = min;
    }
}

void insert(int* a, int n)
{
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > tmp))
        {
            a[j + 1] = a[j];
            a[j] = tmp;
            j--;
        }
    }
}

void bubble(int* a, int n)
{
    int i = 0, j, tmp;
    for (; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }

}

void count(int* a, int n)
{
    int i, j, z = 0;
    int b[K];
    inputzero(b, K);
    for (i = 0; i < n; i++)
        b[a[i] + 100]++;
    for (i = 0; i < K; i++)
        for (j = 0; j < b[i]; j++)
        {
            a[z] = i - 100;
            z++;
        }
}

void quicksplit(int* a, int* i, int* j, int p)
{
    do {
        while (a[*i] < p) (*i)++;
        while (a[*j] > p) (*j)--;
        if (*i <= *j)
        {
            int tmp = a[*i];
            a[*i] = a[*j];
            a[*j] = tmp;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void quicksort(int a[], int n1, int n2)
{
    if (n1 < n2)
    {
        int pidx = (n1 + n2) / 2;
        int i = n1, j = n2;
        quicksplit(a, &i, &j, a[pidx]);
        quicksort(a, n1, j);
        quicksort(a, i, n2);
    }
}

void merge(int* a, int* buffer, int l, int m, int r)
{
    int i, j, k;
    i = l; j = m + 1; k = l;
    while (k <= r)
    {
        while (i <= m && j <= r)
            if (a[i] < a[j])
                buffer[k++] = a[i++];
            else
                if (a[j] < a[i] && j <= r)
                    buffer[k++] = a[j++];
                else 
                    if (a[i] == a[j])
                    {
                        buffer[k++] = a[j++];
                        buffer[k++] = a[i++];
                    }
        while (i <= m)
        {
            buffer[k] = a[i];
            i++; k++;
        }
        while (j <= r)
        {
            buffer[k] = a[j];
            j++; k++;
        }
        for (i = l; i <= r; i++)
            a[i] = buffer[i];
    }
}

void mergesort(int* a, int* buffer, int l, int r)
{
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    mergesort(a, buffer, l, m);
    mergesort(a, buffer, m + 1, r);
    merge(a, buffer, l, m, r);
}

void main()
{
    int* a, *b, *buffer;
    a = (int*)malloc(sizeof(int) * (N));
    b = (int*)malloc(sizeof(int) * (N));
    buffer = (int*)malloc(sizeof(int) * (N));
    inputrand(a, N);
    output(a, N);
    copy(a, b, N);
    count(b, N);
    printf("count  ");
    printf("%d\n", check(b, N));
    output(b, N);
    copy(a, b, N);
    choose(b, N); 
    printf("choose  ");
    printf("%d\n", check(b, N));
    output(b, N);
    copy(a, b, N);
    insert(b, N); 
    printf("insert  ");
    printf("%d\n", check(b, N));
    output(b, N);
    copy(a, b, N);
    bubble(b, N);
    printf("bubble  ");
    printf("%d\n", check(b, N));
    output(b, N);
    copy(a, b, N);
    quicksort(b, 0, N-1);
    printf("quicksort ");
    printf("%d\n", check(b, N));
    output(b, N);
    copy(a, b, N);
    mergesort(a, buffer, 0, N - 1);
    copy(buffer, b, N);
    printf("mergesort ");
    printf("%d\n", check(b, N));
    output(b, N);
    free(a);
    free(b);
    free(buffer);
}