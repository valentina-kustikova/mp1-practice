#include "matrix.h"

matrix::matrix()
{
    m = 0;
    n = 0;
    array = nullptr;
}

matrix::matrix(const matrix& temp)
{
    m = temp.m;
    n = temp.n;
    unsigned int total = m * n;
    array = new double[total];
    for (unsigned int i = 0; i < total; i++)
    {
        array[i] = temp.array[i];
    }
}

matrix::matrix(unsigned int _m, unsigned int _n)
{
    m = _m;
    n = _m;
    unsigned int total = m * n;
    array = new double[total];
    for (unsigned int i = 0; i < total; i++)
    {
        array[i] = 0;
    }
}

matrix::matrix(unsigned int _m, unsigned int _n, double* _array)
{
    m = _m;
    n = _n;
    unsigned int total = m * n;
    array = new double[total];
    for (unsigned int i = 0; i < total; i++)
    {
        array[i] = _array[i];
    }
}

matrix::~matrix()
{
    m = 0;
    n = 0;
    delete[] array;
}

void matrix::print()
{
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            cout << array[i * n + j] << " ";
        }
        cout << endl;
    }
}

void matrix::input()
{
    cout << "Enter count of rows ";
    cin >> m;
    cout << "Enter count of cols ";
    cin >> n;
    if (array != nullptr) delete[] array;
    unsigned int total = m * n;
    array = new double[total];
    cout << "Enter matrix by rows" << endl;
    for (unsigned int i = 0; i < total; i++)
    {
        cin >> array[i];
    }
}

const matrix& matrix::operator=(const matrix& temp)
{
    if (this == &temp)
    {
        return *this;
    }
    if (array != nullptr) delete[] array;
    m = temp.m;
    n = temp.n;
    unsigned int total = m * n;
    array = new double[total];
    for (unsigned int i = 0; i < total; i++)
    {
        array[i] = temp.array[i];
    }
}

matrix matrix::operator+(const matrix& temp)
{
    if ((m != temp.m) || (n != temp.n))
    {
        throw exeption(BadSize);
    }
    matrix out(m, n);
    unsigned int total = m * n;
    for (unsigned int i = 0; i < total; i++)
    {
        out.array[i] = array[i] + temp.array[i];
    }
    return out;
}

matrix matrix::operator+(double temp)
{
    matrix out(m, n);
    unsigned int total = m * n;
    for (unsigned int i = 0; i < total; i++)
    {
        out.array[i] = array[i] + temp;
    }
    return out;
}

matrix matrix::operator-(const matrix& temp)
{
    if ((m != temp.m) || (n != temp.n))
    {
        throw exeption(BadSize);
    }
    matrix out(m, n);
    unsigned int total = m * n;
    for (unsigned int i = 0; i < total; i++)
    {
        out.array[i] = array[i] - temp.array[i];
    }
    return out;
}

matrix matrix::operator-(double temp)
{
    matrix out(m, n);
    unsigned int total = m * n;
    for (unsigned int i = 0; i < total; i++)
    {
        out.array[i] = array[i] - temp;
    }
    return out;
}

matrix matrix::operator*(const matrix& temp)
{
    if ((m != temp.n) || (n != temp.m) || (n < m))
    {
        throw exeption(BadSize);
    }
    matrix out(m, temp.n);
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < temp.n; j++)
        {
            for (unsigned int k = 0; k < n; k++)
            {
                out.array[i * out.n + j] += array[i * n + k] * temp.array[k * temp.n + j];
            }
        }
    }
    return out;
}

matrix matrix::operator*(double temp)
{
    matrix out(m, n);
    unsigned int total = m * n;
    for (unsigned int i = 0; i < total; i++)
    {
        out.array[i] = array[i] * temp;
    }
    return out;
}

double* matrix::operator[](unsigned index)
{
    if (index > m * n)
    {
        throw exeption(BadIndex);
    }
    return (array + index * n);
}