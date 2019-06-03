#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

void main() 
{
    int rezhim, nkomp = 0, nchel = 0, popitki = 0, gr1 = 1, gr2 = 1000, f = 0; //gr1 � gr2 - ������� �����
    char znak;
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(0));
    printf("����� ���������� � '������ �����'! �������� �����: �� ���������� ����� ����������(������� 1) ��� ��������� ��������� ���� �����(������� 2): \n");
    scanf("%d", &rezhim);
    if ((rezhim != 1) && (rezhim != 2))
    {
        printf("������ � ������ ������\n");
        return;
    }
    if (rezhim == 1) 
    {
        printf("��������� ����� �� 1 �� 1000... \n");
        nkomp = gr1 + rand() % (gr2 - gr1);
        printf("���������� ������� ���!\n");
        while (nchel != nkomp)
        {
            if (f == 0) printf("������� � %d: \n", popitki + 1); //������ f ����� � ��������, ����� ������������ ������ ��� ����� �����, � ��� �� ������ ��������� �� ����������� �������
            f = 0;
            scanf("%d", &nchel);
            if ((nchel < gr1) || (nchel >= gr2))
            {
                printf("������, ������� ����� �� ��������� ���������. ���������� ��� ���:\n");
                f = 1; //��������� ������ ��� ������������ ������� �� ������ 27
                continue;
            }
            if (nchel < nkomp) 
            {
                printf("���� ����� ������ �����������. ���������� ��� ���.\n");
                popitki++;
            }
            if (nchel > nkomp) 
            {
                printf("���� ����� ������ �����������. ���������� ��� ���.\n");
                popitki++;
            }
            if (nchel == nkomp) 
            {		
                popitki++;
                printf("�����������, �� ������� ����� c %d �������(-��)!!!\n", popitki);
                return;
            }
        }
    }
    printf("��������� ����� �� 1 �� 1000 � ������� ���:\n");
    scanf("%d", &nchel);
    if ((nchel < gr1) || (nchel > (gr2 - gr1)))
    {
        printf("������. ������� ����� �� ��������� ���������.\n");
        return;
    }
    printf("������ ������� �����...\n");
    while (nkomp != nchel)
    {
        if (f == 0) //f - ������. ����� ��� ��������, ����� ������������ �������� ���� �� ��� ���� � �� �����, ����� �������������� ����� �����
        {
            if (gr2 != gr1) //���� �������� ��������� ��������, ����� ��������� �������� 2 ���������� ����� ������
            {
                nkomp = gr1 + rand() % (gr2 - gr1); 
                if (nkomp == gr1) nkomp++;
                if (nkomp == gr2) nkomp--;
            }
            else nkomp = gr2; //� ������ ������ ��������� 2 ���������� �������, ����� ��������� ������� ������ � 71 ������, ��� ��� (gr2-gr1)=0
            printf("������� � %d: �� �����: %d. ������� ���� ��������� ����� ����� � ����������(���� ��� ����� ������ ������, ������� '>'; ���� ��� ����� ������ ������, ������� '<'; ���� � ������, ������� '='). \n", popitki + 1, nkomp);
        }
        if (gr1 > gr2) //������� 1 �� ����� ���� ������ ������� 2 ��� ������ �����
        {
            printf("������� ������������ �����. ������� ��������� ������.\n"); 
            return;
        }
        f = 0;
        scanf("%*c%c", &znak);
        if(znak == '>') 
        {
            gr2 = nkomp;
            popitki++;
            if ((nkomp == gr2) && (gr1 == gr2)) //� ������, ����� ������� ����� � ����� ������ �� ���� = ��������� ������ �������� ������
            {
                printf("��� �������, �� ���������� � ������. ���������� ��� �������.\n");
                return;
            }
        }
        else if(znak == '<') 
        {
            gr1 = nkomp;
            popitki++;
            if ((nkomp == gr2) && (gr1 == gr2))
            {
                printf("��� �������, �� ���������� � ������. ���������� ��� �������.\n");
                return;
            }
        }
        else if (znak == '=') 
        {
            popitki++;
            printf("���! � ������ ���� ����� � %d �������(-��)\n", popitki);
            return;		
        }
        else 
        {
            printf("������, ���� ������ �������. ������� ��� ���:\n");
            f = 1; //����� ������ "������������", ����� �� ��������� ������� � ������ 67
            continue;
        }		
    }
}