#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gen(int len);
int valid(int n, int len);

int main()
{
    srand((unsigned int) time(NULL));
    int len;
    printf("Enter number length: ");
    scanf_s("%d", &len);
    int n = gen(len);
    while (!valid(n, len))
        n = gen(len);
    printf("%d", n);
}

int gen(int len) {
    int i;
    int res = 0;
    for (i = 0; i < len; i++) {
        res *= 10;
        res += rand() % 10;
    }
    return res;
}

int valid(int n, int len) {
    int i;
    int arr[10] = { 0 };
    for (i = 0; i < len; i++) {
        arr[n % 10] += 1;
        if (n == 0 || arr[n % 10] > 1) return 0;
        n /= 10;
    }
    return 1;
}