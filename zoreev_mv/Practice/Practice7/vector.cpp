#include "vector.h"


vector& vector::operator=(const vector& temp)
{
    if (this == &temp)
    {
        return *this;
    }
    size = temp.size;
    if (array != nullptr)
    {
        delete[] array;
    }
    array = new double[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = temp.array[i];
    }
    return *this;
}

double& vector::operator[](int index)
{
    if ((index < 0) || (index >= size))
    {
        throw exeption(BadIndex);
    }
    return array[index];
}

vector vector::operator+=( const vector& temp)
{
    if (size != temp.size)
    {
        throw exeption(BadLength);
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = array[i] + temp.array[i];
    }
    return *this;
}

vector vector::operator+=(const double temp)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = array[i] + temp;
    }
    return *this;
}

vector vector::operator-=(const vector& temp)
{
    if (size != temp.size)
    {
        throw exeption(BadLength);
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = array[i] - temp.array[i];
    }
    return *this;
}

vector vector::operator-=(const double temp)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = array[i] - temp;
    }
    return *this;
}

vector vector::operator*=(const double m)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = array[i] * m;
    }
    return *this;
}

double vector::length()
{
    double out = 0;
    for (int i = 0; i < size; i++)
    {
        out += array[i] * array[i];
    }
    out = sqrt(out);
    return out;
}

void vector::print()
{
    if (size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
        return;
    }
    cout << "Array is empty" << endl;
}

void vector::input()
{
    int _size;
    cout << "Input vector size ";
    do {
        cin >> size;
    } while (size <= 0);
    delete[] array;
    array = new double[size];
    cout << "Input vector" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> array[i];
    }
}

vector operator+(const vector& a, const vector& b)
{
    if (a.size != b.size)
    {
        throw exeption(BadLength);
    }
    vector out(a.size);
    for (int i = 0; i < a.size; i++)
    {
        out.array[i] = a.array[i] + b.array[i];
    }
    return out;
}

vector operator+(const vector& a, const double b)
{
    vector out(a.size);
    for (int i = 0; i < a.size; i++)
    {
        out.array[i] = a.array[i] + b;
    }
    return out;
}

vector operator-(const vector& a, const vector& b)
{
    if (a.size != b.size)
    {
        throw exeption(BadLength);
    }
    vector out(a.size);
    for (int i = 0; i < a.size; i++)
    {
        out.array[i] = a.array[i] - b.array[i];
    }
    return out;
}

vector operator-(const vector& a, const double b)
{
    vector out(a.size);
    for (int i = 0; i < a.size; i++)
    {
        out.array[i] = a.array[i] - b;
    }
    return out;
}

double operator*(const vector& a, const vector& b)
{
    if (a.size != b.size)
    {
        throw exeption(BadLength);
    }
    double out = 0;
    for (int i = 0; i < a.size; i++)
    {
        out += a.array[i] * b.array[i];
    }
    return out;
}

vector operator*(const vector& a, const double m)
{
    vector* out = new vector(a.size);
    for (int i = 0; i < a.size; i++)
    {
        out->array[i] = a.array[i] * m;
    }
    return *out;
}