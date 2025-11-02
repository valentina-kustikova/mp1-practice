#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int len(int a);


int main() {
    srand(time(NULL));
    int n, i, j, digit, userGuess;
    int number[5];
    while (1) {
        int digits[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        printf("Input number from 2 to 5: "); scanf_s("%d", &n);
        while (n < 2 || n>5) {
            printf("\nInput correct number from 2 to 5: "); scanf_s("%d", &n);
        }

        for (i = 0; i < n; i++) {
            digit = rand() % 10;
            if (i == 0 && digit == 0) {
                digit = 1 + rand() % 9;
            }
            while (digits[digit] != 0) {
                digit = rand() % 10;
            }
            digits[digit] = 1;
            number[i] = digit;
        }
        printf("\nA number with length %d is hidden. Try to guess it\n", n);

        while (1) {
            printf("Input your guess with %d unique digits: ", n); scanf_s("%d", &userGuess);
            int userGuessNumber[5], cow, bull;
            int ds[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, flag = 0, userGuessForCheck = userGuess;  //ds - это "бронь" цифр в числе,
            cow = 0; bull = 0;
            while (userGuessForCheck != 0) {
                int d = userGuessForCheck % 10;
                if ((ds[d] == 1) || (len(userGuess) != n)) {   // если кака€-то цифра в числе уже находитс€ в нашем "броне" или длина числа иной, то завершаем цикл и заставл€ем пользовател€ ввести число еще раз.
                    flag = 1;
                    break;
                }
                ds[d] = 1;
                userGuessForCheck /= 10;
            }

            if (flag == 0) {   // если флаг=1 - значит игрок где-то накос€чил и мы должны продолжать цикл, пока игрок не введет число в допустимой форме.
                int N = (n - 1);
                for (i = 0; i < n; i++) {
                    int s = pow(10, N); // 10 в N-ой степени
                    userGuessNumber[i] = userGuess / s; //берем первую цифру числа: 12345/10000 = 1
                    userGuess %= s; //затем избавл€емс€ от первой цифры числа: 12345%10000 = 2345
                    N--; // уменьшаем степень на 1
                }
                cow = 0; bull = 0;
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        if ((number[i] == userGuessNumber[j]) && (i == j)) bull++;
                        if ((number[i] == userGuessNumber[j]) && (i != j)) cow++;
                    }
                }
                printf("%d cow   %d bull\n", cow, bull);
                if (bull == n) {
                    printf("Congratulations! You guessed number right!\n");
                }
            }
        }
    }
    return 0;
}


int len(int a) {
    if (a == 0) return 1;
    int l = 0;
    while (a) {
        l++;
        a /= 10;
    }
    return l;
}