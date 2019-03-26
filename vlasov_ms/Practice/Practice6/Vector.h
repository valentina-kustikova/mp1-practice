#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	size_t dim;
	double* v;
} Vector;

// �������������
int v_init(Vector*);
// ������� ������ � �������� ������������
int v_create(size_t, Vector*);
// ������� ������
int v_destroy(Vector*);

// ��������� �������� ��������
int v_add(Vector, Vector, Vector*);
// �������� ������ �� �����
int v_mul(Vector, double, Vector*);
// ��������� ��������� ��������
int v_sub(Vector, Vector, Vector*);
// ��������� ��������� ������������
int v_scm(Vector, Vector, double*);

// ���������� ���� ����� ��������� (� ���)
int v_ang(Vector, Vector, double*);
// ���������� ���� ����� ��������� (� ��������)
int v_deg(Vector, Vector, double*);
// ���������� ����� �������
double v_len(Vector);

// ���� ��������
void v_input(Vector);
// ����� ��������
void v_output(Vector);

// ��������� ������������
int v_check(Vector);
// ��������� ������ ������������
int v_check2(Vector, Vector);
// ������� �������� ��������� �� ������
void v_err(int);

#endif
