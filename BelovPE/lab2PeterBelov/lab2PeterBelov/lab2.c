#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Режим 1: пользователь угадывает число
void user_guesses() {
    srand(time(NULL));
    int secret_number = rand() % 1000 + 1;
    int attempts = 0;
    int guess;

    printf("Я загадал число от 1 до 1000. Попробуйте угадать!\n");

    do {
        printf("Введите вашу догадку: ");
        if (scanf("%d", &guess) != 1) {
            printf("Ошибка ввода! Введите целое число.\n");
            // Очищаем буфер ввода
            while (getchar() != '\n');
            continue;
        }
        attempts++;

        if (guess < secret_number) {
            printf("Загаданное число больше\n");
        }
        else if (guess > secret_number) {
            printf("Загаданное число меньше\n");
        }
        else {
            printf("Угадали! Поздравляю!\n");
        }
    } while (guess != secret_number);

    printf("Число попыток: %d\n", attempts);
}

// Режим 2: программа угадывает число (бинарный поиск)
void computer_guesses() {
    int low = 1;
    int high = 1000;
    int attempts = 0;
    char response;
    int guess;

    printf("Загадайте число от 1 до 1000. Я попробую угадать!\n");
    printf("Вводите:\n'>' - если ваше число больше\n'<' - если ваше число меньше\n'=' - если я угадал\n");

    do {
        guess = (low + high) / 2;
        attempts++;

        printf("Моя догадка: %d\n", guess);
        printf("Ваш ответ: ");

        if (scanf(" %c", &response) != 1) {
            printf("Ошибка ввода!\n");
            while (getchar() != '\n');
            attempts--;
            continue;
        }

        if (response == '>') {
            low = guess + 1;
        }
        else if (response == '<') {
            high = guess - 1;
        }
        else if (response == '=') {
            printf("Ура! Я угадал за %d попыток!\n", attempts);
        }
        else {
            printf("Неверный ввод! Используйте только '>', '<' или '='\n");
            attempts--; // не считаем эту попытку
        }

        // Проверка на случай нечестной игры
        if (low > high) {
            printf("Вы где-то ошиблись с ответами! Начинаем заново.\n");
            low = 1;
            high = 1000;
            attempts = 0;
        }
    } while (response != '=');
}

int main() {
    int choice;

    printf("=== ИГРА 'УГАДАЙ ЧИСЛО' ===\n");

    do {
        printf("\nВыберите режим:\n");
        printf("1 - Я угадываю число\n");
        printf("2 - Компьютер угадывает число\n");
        printf("0 - Выход\n");
        printf("Ваш выбор: ");

        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода! Введите число.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            user_guesses();
            break;
        case 2:
            computer_guesses();
            break;
        case 0:
            printf("До свидания!\n");
            break;
        default:
            printf("Неверный выбор! Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}