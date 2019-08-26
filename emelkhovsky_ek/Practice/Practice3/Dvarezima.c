#include  < stdio.h > 
#include  < locale.h > 
#include  < time.h > 
void mode_1() {
    int random, user, kol;
    random = rand() % 1000  +  1;
    kol = 0;
    printf("Компьютер загадал число от 1 до 1000!\nПопробуй угадать!\n");
    //    printf("%d\n",random);
    scanf("%d", &user);
    while (user != random) {
        while ((user  <  1) || (user  >  1000)) {
            printf("Корректный ввод от 1 до 1000\n");
            scanf("%d", &user);
        }
        kol ++ ;
        if (user  >  random) {
            printf("Вы ввели число больше, чем загаданное\n");
        }
        else if (user  <  random) {
            printf("Вы ввели число меньше чем загаданное\n");
        }
        scanf("%d", &user);
    }
    printf("Вы угадали число с %d попытки \n", kol);
}


void mode_2() {
    int user, random, a, b, kol;
    kol = 0;
    b = 1001;
    a = 1;
    char o;
    printf("ведите число которое будет отгадывать компьютер\n");
    scanf("%d", &user);

    while ((user < 1) || (user > 1000)) {
        printf("Корректный ввод от 1 до 1000\n");
        scanf("%d", &user);
    }

    random = rand() % (b - a)  +  a;
    printf("Компьютер загадал число %d, введите Ваше число больше, меньше или равно?\n", random);

    while (random != user) {
        kol ++ ;
        scanf("%s", &o);

        if (o == ' > ') {
            a = random  +  1;
        }
        else if (o == ' < ') {
            b = random;
        }
        random = rand() % (b - a)  +  a;
        printf("Компьютер загадал число %d, введите Ваше число больше, меньше или равно?\n", random);
    }
    printf("Компьютер угадал с %d попытки \n", kol);
}

void main() {
    int mode;
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    printf("ведите режим:\n1 чтобы разгадывать число\n2 чтобы загадывать число\n0 чтобы закончит игру");
    scanf("%d", &mode);
    while (mode != 0) {
        if (mode == 0) {
            break;
        }
        else if (mode == 1) {
            mode_1();
        }
        else if (mode == 2) {
            mode_2();
        }
        else {
            printf("Всего 2 режима");
        }
    }
}


