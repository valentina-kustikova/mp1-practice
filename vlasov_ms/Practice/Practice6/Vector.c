#include "Vector.h"

int v_init(Vector* vec)
{
	vec->dim = 0;
	vec->v = NULL;
	return 0;
}

int v_create(size_t _dim, Vector* result)
{
	result->dim = _dim;
	if (_dim > 0)
	{
		size_t i;
		result->v = (double*)malloc(_dim * sizeof(double));
		for (i = 0; i < _dim; i++)
			result->v[i] = 0.0F;
		return 0;
	}
	return 1;
	result->v = NULL;
}

int v_destroy(Vector * _vec)
{
	if (_vec->dim && _vec->v)
		free(_vec->v);
	_vec->dim = 0;
	_vec->v = NULL;
	return 0;
}

int v_add(Vector v1, Vector v2, Vector* result)
{
	size_t i;
	if (!v_check2(v1, v2))
		return 1;
	v_destroy(result);
	v_create(v1.dim, result);
	for (i = 0; i < v1.dim; i++)
		result->v[i] = v1.v[i] + v2.v[i];
	return 0;
}

int v_mul(Vector vec, double num, Vector* result)
{
	size_t i;
	v_destroy(result);
	v_create(vec.dim, result);
	for (i = 0; i < vec.dim; i++)
		result->v[i] = vec.v[i] * num;
	return 0;
}

int v_sub(Vector v1, Vector v2, Vector* result)
{
	size_t i;
	if (!v_check2(v1, v2))
		return 1;
	v_destroy(result);
	v_create(v1.dim, result);
	for (i = 0; i < v1.dim; i++)
		result->v[i] = v1.v[i] - v2.v[i];
	return 0;
}

int v_scm(Vector v1, Vector v2, double* result)
{
	size_t i;
	if (!v_check2(v1, v2))
	{
		return 1;
	}
	*result = 0.0F;
	for (i = 0; i < v1.dim; i++)
		*result += v1.v[i] * v2.v[i];
	return 0;
}

int v_ang(Vector v1, Vector v2, double* result)
{
	if (!v_check2(v1, v2))
		return 1;
	else
	{
		double scal, lens = v_len(v1) * v_len(v2);
		v_scm(v1, v2, &scal);
		*result = acos(scal / lens);
		return 0;
	}
}

int v_deg(Vector v1, Vector v2, double* result)
{
	double ang;
	const double pi = 3.14159F;
	v_ang(v1, v2, &ang);
	*result = (ang * 180.0F) / pi;
	return 0;
}

double v_len(Vector vec)
{
	double result = 0.0F;
	size_t i;
	if (!vec.dim)
		return 0;
	for (i = 0; i < vec.dim; i++)
		result += vec.v[i] * vec.v[i];
	return sqrt(result);
}

void v_err(int id)
{
	switch (id)
	{
	case 0:
		printf("[WARN] Trying to create vector with 0 dimensions.\n");
	case 1:
		printf("[ERR]  Vectors' dimensions are not equal.\n");
	}
}

void v_input(Vector vec)
{
	size_t i;
	for (i = 0; i < vec.dim; i++)
		scanf("%lf", vec.v + i);
}

void v_output(Vector vec)
{
	size_t i;
	for (i = 0; i < vec.dim; i++)
		printf("%lf ", vec.v[i]);
	printf("\n");
}

int v_check(Vector vec)
{
	return vec.dim >= 0;
}

int v_check2(Vector v1, Vector v2)
{
	return (v1.dim == v2.dim) && (v1.dim >= 0) && (v2.dim >= 0);
}
