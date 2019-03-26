#include "Vector.h"

Vector v_create(size_t _dim)
{
	Vector vec;
	vec.dim = _dim;
	if (_dim)
		vec.v = (double*)malloc(_dim * sizeof(double));
	else
	{
		v_err(0);
		vec.v = NULL;
	}
	return vec;
}

int v_destroy(Vector * _vec)
{
	_vec->dim = 0;
	if (_vec->v)
		free(_vec->v);
	_vec->v = NULL;
	return 0;
}

int v_add(Vector _v1, Vector _v2, Vector* _vec)
{
	if ((!_v1.dim && !_v2.dim) || (_v1.dim != _v2.dim))
	{
		return 1;
	}
	v_destroy(_vec);
	*_vec = v_create(_v1.dim);
	size_t i;
	for (i = 0; i < _v1.dim; i++)
		_vec->v[i] = _v1.v[i] + _v2.v[i];
	return 0;
}

int v_inv(Vector _vec, Vector* _vec_result)
{
	size_t i;
	v_destroy(_vec_result);
	*_vec_result = v_create(_vec.dim);
	for (i = 0; i < _vec.dim; i++)
		_vec_result->v[i] *= -1;
	return 0;
}

int v_sub(Vector _v1, Vector _v2, Vector* _vec)
{
	if ((!_v1.dim && !_v2.dim) || (_v1.dim != _v2.dim))
	{
		return 1;
	}
	v_destroy(_vec);
	*_vec = v_create(_v1.dim);
	size_t i;
	for (i = 0; i < _v1.dim; i++)
		_vec->v[i] = _v1.v[i] - _v2.v[i];
	return 0;
}

int v_scm(Vector _v1, Vector _v2, double* result)
{
	if ((!_v1.dim && !_v2.dim) || (_v1.dim != _v2.dim))
	{
		return 1;
	}
	*result = 0.0F;
	size_t i;
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
	double scal;
	v_scm(_v1, _v2, &scal);
	double lens = v_len(_v1) * v_len(_v2);
	*result = acos(scal / lens);
	return 0;
}

int v_deg(Vector _v1, Vector _v2, double* result)
{
	double ang;
	v_ang(_v1, _v2, &ang);
	const double pi = 3.14159F;
	*result = (ang * 180.0F) / pi;
	return 0;
}

double v_len(Vector _vec)
{
	if (!_vec.dim)
		return 0;
	double result = 0.0F;
	size_t i;
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
