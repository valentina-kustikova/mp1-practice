#include <stdio.h>

/*
������
����� ��������� ���������� ����� ��� ������
������ �����:
1) ��������� ������ �� ��� ������� h  180-220 ��
������� w �� 80-120�� � �������� 5��
2) 2 �������� �� ��� ������� h �������� d 50-90�� �������� 15��
3) ��������� ������� � ������ ������ �� ���
������� w �������� d � �������� 15��
4) 2 ��������� ����� �� ������ ������� h, ������� w , �������� 1��
5) ���������� ����� � ����� ����� ������ 40 �� �� ���

������,��� �������� ��������� ��� ��� � ������
����� ����� �����

���������:
���  950 ��/�^2
��� 750 ��/�^2
������ 720 ��/�^2 (������ == ���)
*/


/*
Testcases
Test1:
input : 180 80 50
output: 55.7kg

Test2:
input : 220 120 90
output:

*/



int main() {
    int dvp = 950;
    int dsp = 650; // ����� ����������
    int wood = 660;
    int k_polok = 0; // ���-�� �����
    double v1, m1; // ����� 1 � ����� 1
    double v2, m2; // ����� 2 � ����� 2
    double v3, m3; // ����� 3 � ����� 3   
    double v4, m4; // ����� 4 � ����� 4
    double v5, m5; // ����� 5 � ����� 5
    int wrong = 0;
    double h, w, d;
    printf("Type height , width and depth in centimeters \n");
    printf("  180 <= height <= 220\n");
    printf("   80 <=  width <= 120\n");
    printf("   50 <=  depth <=  90\n");
    do {
        wrong = 0;
        scanf("%lf %lf %lf", &h, &w, &d);
    //����          ���� �����-�� ���� ��������
        if (h > 220 || h < 180 || w > 120 || w < 80 || d >90 || d < 50) {
            printf("Wrong input!\n Check sizes of every parameter!\n");
            wrong = 1;
        }
    } while (wrong);
    
    h = h / 100; 
    w = w / 100;  // ������� ������� � �����
    d = d / 100;
    
    // 1) ��������� ������ �� ��� 
    // ������� h     ������� w    �������� 0.005�    
    v1 = w * h * 0.005; 
    m1 = dvp*v1; // ��������� * �����


    // 2) 2 �������� �� ��� 
    // ������� h      �������� d     �������� 15�� == 0.015 �
    v2 = 2*(h * d * 0.015); // ����� ���� �������
    m2 = dsp*v2;
     // ������� ������� �������
                    // ������� ��� ���� ������ ������� �����
                    

    // 3) ��������� ������� � ������ ������  �� ���
    // �������  w      ��������  d   �������� 0.015�    
    v3 = 2 * (w*d*0.015); // ����� ���� ������
    m3 = dsp * v3;


    // 4) 2 ��������� ����� �� ������  
    // ������� h      ������� w      ��������  1��==0.01�
    v4 = 2 * (h*w*0.01);
    m4 = wood * v4;


    w -= (0.015 * 2);
    // 5) ���������� ����� � ����� �� ���
    // ��������� �� ���������� >=40 �� ���� �� ����� � �� ����
    // ��������  d    �������  w   �������� 0.015�    
    v5 = w * d * 0.015; // ����� ����� �����
    m5 = dsp*v5;      // ����� ����� �����
    
    while ((h - (k_polok * 0.415))>0.4) {
        k_polok++;
    }
    k_polok--;
      
    
    m5 *= k_polok; // ����� ���� �����
    
    printf("This wardrobe weights %lfkg",m1+m2+m3+m4+m5);
    return 0;
}