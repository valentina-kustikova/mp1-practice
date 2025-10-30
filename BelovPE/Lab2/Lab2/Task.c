#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(void) {
    int a, i = 0;
    setlocale(LC_ALL, "RU");
    printf("�������� �����:\n\"������ ����� (1)\"\n\"������� ����� (2)\"\n��� �����: ");
    scanf_s("%d", &a);


    if (a != 1 && a != 2) {
        printf("������������ ����� ������");
        return 1;
    }


    switch (a) {
    case 1:
        printf("����� \"������ �����\"\n \"�������� ����� �� 1 �� 1000:\"\n");
        srand(time(NULL));
        int c = rand() % 1000 + 1;
        int r;
        do {
            scanf_s("%d", &r);
            i++;
            if (c > r) printf("���������� ����� ������\n");
            else if (c < r) printf("���������� ����� ������\n");
        } while (c != r);
        printf("�������!\n����� �������: %d", i);
        break;

    case 2:
        printf("����� \"������� �����\"\n \"��������� ����� �� 1 �� 1000:\"\n");
        int min = 1, max = 1000, attempt;
        char answer;

        do {
            attempt = min + (max - min) / 2;
            i++;
            printf("������� %d: %d\n ��� ����� (> , < , =): ", i, attempt);
            scanf_s(" %c", &answer);

            if (answer == '>') {
                min = attempt + 1;
            }
            else if (answer == '<') {
                max = attempt - 1;
            }
            else if (answer == '=') {
                printf("� ������� ����� %d �� %d �������!\n", attempt, i);
                break;
            }
            else {
                printf("����������� ������ >, < ��� =\n");
                i--;
                continue;
            }

            if (min > max) {
                printf("���-�� ������ � ����� �������");
                break;
            }

        } while (1); //�������� 1 (������� ������ �������), ����� ��� ����������� ����, ���� �� ��������� ���� �� break. ������� ����

        break;
    }
}