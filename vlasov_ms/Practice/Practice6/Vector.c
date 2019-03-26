#include "Vector.h"

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
	_vec->dim = 0;
	if (_vec->v)
		free(_vec->v);
	_vec->v = NULL;
	return 0;
}

int v_add(Vector _v1, Vector _v2, Vector* result)
{
	size_t i;
	if ((!_v1.dim && !_v2.dim) || (_v1.dim != _v2.dim))
	{
		return 1;
	}
	v_destroy(result);
	v_create(_v1.dim, result);
	for (i = 0; i < _v1.dim; i++)
		result->v[i] = _v1.v[i] + _v2.v[i];
	return 0;
}

int v_inv(Vector _vec, Vector* result)
{
	size_t i;
	v_destroy(result);
	v_create(_vec.dim, result);
	for (i = 0; i < _vec.dim; i++)
		result->v[i] *= -1;
	return 0;
}

int v_sub(Vector _v1, Vector _v2, Vector* result)
{
	size_t i;
	if ((!_v1.dim && !_v2.dim) || (_v1.dim != _v2.dim))
	{
		return 1;
	}
	v_destroy(result);
	v_create(_v1.dim, result);
	for (i = 0; i < _v1.dim; i++)
		result->v[i] = _v1.v[i] - _v2.v[i];
	return 0;
}

int v_scm(Vector _v1, Vector _v2, double* result)
{
	size_t i;
	if ((!_v1.dim && !_v2.dim) || (_v1.dim != _v2.dim))
	{
		return 1;
	}
	*result = 0.0F;
	for (i = 0; i < _v1.dim; i++)
		*result += _v1.v[i] * _v2.v[i];
	return 0;
}

int v_ang(Vector _v1, Vector _v2, double* result)
{
	if ((!_v1.dim && !_v2.dim) || (_v1.dim != _v2.dim))
	{
		return 1;
	}
	else
	{
		double scal, lens = v_len(_v1) * v_len(_v2);
		v_scm(_v1, _v2, &scal);
		*result = acos(scal / lens);
		return 0;
	}
}

int v_deg(Vector _v1, Vector _v2, double* result)
{
	double ang;
	const double pi = 3.14159F;
	v_ang(_v1, _v2, &ang);
	*result = (ang * 180.0F) / pi;
	return 0;
}

double v_len(Vector _vec)
{
	double result = 0.0F;
	size_t i;
	if (!_vec.dim)
		return 0;
	for (i = 0; i < _vec.dim; i++)
		result += _vec.v[i] * _vec.v[i];
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

void v_input(Vector _vec)
{
	size_t i;
	for (i = 0; i < _vec.dim; i++)
		scanf("%lf", _vec.v + i);
}

void v_output(Vector _vec)
{
	size_t i;
	for (i = 0; i < _vec.dim; i++)
		printf("%lf ", _vec.v[i]);
	printf("\n");
}
