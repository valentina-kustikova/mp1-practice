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

// ������� ������ � �������� ������������
Vector v_create(size_t);
// ������� ������
int v_destroy(Vector*);
// ��������� �������� ��������
int v_add(Vector, Vector, Vector*);
// �������� ������ �� -1
int v_inv(Vector, Vector*);
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
// ������� �������� ��������� �� ������
void v_err(int);
// ���� ��������
void v_input(Vector);
// ����� ��������
void v_output(Vector);

#endif
