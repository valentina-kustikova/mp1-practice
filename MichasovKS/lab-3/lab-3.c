#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LEN 2
#define MAX_LEN 5

int gen(int guess);
int valid(int secret_number, int guess);
int get_cows(int secret_number, int tmp, int guess);
int get_bulls(int secret_number, int tmp, int guess);

int main()
{
    srand((unsigned int) time(NULL));
    int guess;
    do {
        printf("Enter secret_number length: ");
        scanf_s("%d", &guess);
    } while (guess < MIN_LEN || guess > MAX_LEN);
    int secret_number;
    do {
        secret_number = gen(guess);
    } while (!valid(secret_number, guess));
    printf("%d\n", secret_number);
    int tmp;
    do {
        do {
            printf("Enter your guess: ");
            scanf_s("%d", &tmp);
        } while (tmp < 0 || !valid(tmp, guess));
        printf("cows: %d, bulls: %d\n", get_cows(secret_number, tmp, guess), get_bulls(secret_number, tmp, guess));
    } while (secret_number != tmp);
    printf("You win!");
}

int gen(int guess) {
    int i;
    int res = 0;
    for (i = 0; i < guess; i++) {
        res *= 10;
        res += rand() % 10;
    }
    return res;
}

int valid(int n, int len) {
    if (n < 0) return 0;

    int digits[10] = { 0 };
    int count = 0;

    while (n > 0) {
        int digit = n % 10;
        if (digits[digit] > 0) return 0;
        digits[digit]++;
        count++;
        n /= 10;
    }

    return count == len;
}

int get_cows(int secret_number, int tmp, int guess) {
    char secret_number_str[MAX_LEN +1];
    char tmp_str[MAX_LEN +1];
    sprintf_s(secret_number_str, MAX_LEN +1, "%d", secret_number);
    sprintf_s(tmp_str, MAX_LEN + 1, "%d", tmp);
    int i, j, count = 0;
    for (i = 0; i < guess; i++) {
        for (j = 0; j < guess; j++) {
            if (secret_number_str[i] == tmp_str[j]) {
                count++;
                break;
            }
        }
    }
    return count - get_bulls(secret_number, tmp, guess);
}

int get_bulls(int secret_number, int tmp, int guess) {
    char secret_number_str[MAX_LEN + 1];
    char tmp_str[MAX_LEN + 1];
    sprintf_s(secret_number_str, MAX_LEN + 1, "%d", secret_number);
    sprintf_s(tmp_str, MAX_LEN + 1, "%d", tmp);
    int i, count = 0;
    for (i = 0; i < guess; i++) {
        if (secret_number_str[i] == tmp_str[i]) {
            count++;
            break;
        }
    }
    return count;
}