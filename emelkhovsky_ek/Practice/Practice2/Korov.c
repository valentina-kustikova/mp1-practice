#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#define N 10
void main() {
	int n, nk, nch, f, r, cop1, cop2, i, kol, k, kor, bik, j, t;
	/*
	���������
	n-���-�� ���� � ������
	nk-�����, ���������� �����������
	nch-�����, ������� ������ �������
	f,t-������
	r-��������� �����, ���������� ����������� ��������� ���� ����������
	cop1,cop2-������ ����� �����, ����� �� ������� nk � nch
	i,k,j-��������
	kol-������� ���-�� ���� � �������� ����� ��� ��������
	kor,bik-������ � ����
	*/
	int a[N] = { 0 };//������ ������������ ������� ��� �������� ����������, � ����� � ���� ���������� nch
	int b[N] = { 0 };//� ���� ������ ���������� nk
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	printf("������� ���-�� ���� � �����\n");
	//������ ������� ����� �����������
	nk = rand() % 9 + 1;
	i = 1;
	while (i<n) {
	  r = rand() % 10;
	    cop1 = nk;
		f = 0;
		while (cop1>0) {
	  	  if (cop1 % 10 == r) {
			f = 1;
		  }
		  cop1 = cop1 / 10;
		}
		if (f == 0) {
		  nk = nk * 10 + r;
			i++;
		}
	}
	printf("%d\n", nk);
	printf("����� ��������, �������� �������\n");

	t = 1;
	while (t == 1) {
	  //�������� ��������� ����� �� ���-�� ����
	  printf("������� %d ������� ����� ��� ������������� ����\n", n);
	  scanf("%d", &nch);
      f = 0;
	  while (f == 0) {
	    kol = 0;
		cop2 = nch;
		while (cop2 > 0) {
		  a[cop2 % 10]++;//�������� ������ � ������ ���� �� ���������� ����
		  cop2 = cop2 / 10;
		  kol++;//�������� �� ���������� ���-�� ����
		}
		if (kol == n) {
		  f = 1;
		}
		for (k = 0; k < n; k++) {//������ ����������
		  if (a[k] > 1) {
			f = 0;
		  }
		}
		if (f == 0) {
		  printf("������������ ����, ���������� ��� ���\n");
		  scanf("%d", &nch);
		  for (k = 0; k < n; k++) {
			a[k] = 0;
		  }
		}
	  }
	  printf("%d\n", nch);

	  //������ � ����
	  bik = 0;
	  kor = 0;
	  cop2 = nk;//����� �����, ����� � ����� ����� ������������ 
	  for (k = 0; k < n; k++) {//�������� � ������� �������� �������� � ���������� 
		a[k] = nch % 10;
		nch = nch / 10;
		b[k] = cop2 % 10;
		cop2 = cop2 / 10;
	  }
	  //������� ����� � �����
	  for (k = 0; k < n; k++) {
		for (j = 0; j < n; j++) {
		  if ((b[k] == a[j]) && (k == j)) {//������ �����
			bik++;

		  }
		  if ((b[k] == a[j]) && (k != j)) {//������ �����
			kor++;
		  }
		}
	  }
	  printf("%d �����\n", kor);
	  printf("%d �����\n", bik);
	  if (bik == nk) {
	  	printf("�� ������� �����, �����������!\n");
		f = 0;
	  }
	  else {
		printf("���������� ������� ��� ���\n");
	  }
	}
}

