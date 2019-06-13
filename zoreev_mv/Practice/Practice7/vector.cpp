#include "vector.h"

vector::vector() {
	size = 0;
	array = nullptr;
} //Передаём привет закрытым полям, и input методу, впрочему можно использовать >>

vector::vector(int _size)
{
	size = _size;
	array = new double[size];
	memset(array, 0, sizeof(double) * size);
}

vector::vector(double* _array, int _size)
{
	size = _size;
	array = new double[size];
	memcpy(array, _array, size * sizeof(double));
}

vector::vector(vector& temp)
{
	size = temp.size;
	array = new double[size];
	memcpy(array, temp.array, size * sizeof(double));
}

vector::~vector()
{
	size = 0;
	if (array != nullptr)
	{
		delete[] array;
	}
}

const vector& vector::operator=(const vector& temp)
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
	memcpy(array, temp.array, size * sizeof(double));
    return *this;
}

void* vector::operator new(size_t _size)
{
	return malloc(_size);
}

void* vector::operator new[](size_t _size)
{
	return malloc(_size);
}

void operator delete(void* temp)
{
	free(temp);
}

void operator delete[](void* temp)
{
	free(temp);
}

double& vector::operator[](int index)
{
    if ((index < 0) || (index >= size))
    {
        throw exeption(BadIndex);
    }
    return array[index];
}

double vector::operator[](int index) const
{
	if ((index < 0) || (index >= size))
	{
		throw exeption(BadIndex);
	}
	return array[index];
}

const vector& vector::operator+=( const vector& temp)
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

const vector& vector::operator+=(const double temp)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = array[i] + temp;
    }
    return *this;
}

const vector& vector::operator-=(const vector& temp)
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

const vector& vector::operator-=(const double temp)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = array[i] - temp;
    }
    return *this;
}

const vector& vector::operator*=(const double m)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = array[i] * m;
    }
    return *this;
}

double vector::length() const
{
    double out = 0;
    for (int i = 0; i < size; i++)
    {
        out += array[i] * array[i];
    }
    out = sqrt(out);
    return out;
}

std::ostream& operator<< (std::ostream& out, const vector& temp)
{
	if (temp.size)
	{
		for (int i = 0; i < temp.size; i++)
		{
			cout << temp.array[i] << " ";
		}
		cout << endl;
		return;
	}
	cout << "Array is empty" << endl;
}

std::istream& operator>> (std::istream& in, vector& temp)
{
	int _size;
	cin >> temp.size;
	if (temp.size <= 0) throw exeption(BadLength);
	delete[] temp.array;
	temp.array = new double[temp.size];
	for (int i = 0; i < temp.size; i++)
	{
		cin >> temp.array[i];
	}
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

vector& vector::operator+(const vector& temp) const
{
    if (size != temp.size)
    {
        throw exeption(BadLength);
    }
    vector out(size);
    for (int i = 0; i < size; i++)
    {
        out.array[i] = array[i] + temp.array[i];
    }
    return out;
}

vector& vector::operator+(const double temp) const
{
    vector out(size);
    for (int i = 0; i < size; i++)
    {
        out.array[i] = array[i] + temp;
    }
    return out;
}

vector& vector::operator-(const vector& temp) const
{
    if (size != temp.size)
    {
        throw exeption(BadLength);
    }
    vector out(size);
    for (int i = 0; i < size; i++)
    {
        out.array[i] = array[i] - temp.array[i];
    }
    return out;
}

vector& vector::operator-(const double temp) const
{
    vector out(size);
    for (int i = 0; i < size; i++)
    {
        out.array[i] = array[i] - temp;
    }
    return out;
}

double& vector::operator*(const vector& temp) const
{
    if (size != temp.size)
    {
        throw exeption(BadLength);
    }
    double out = 0;
    for (int i = 0; i < size; i++)
    {
        out += array[i] * temp.array[i];
    }
    return out;
}

vector& vector::operator*(const double temp) const
{
    vector* out = new vector(size);
    for (int i = 0; i < size; i++)
    {
        out->array[i] = array[i] * temp;
    }
    return *out;
}

bool vector::operator>(const vector& temp) const
{
	if (length() < temp.length()) return true;
	return false;
}
bool vector::operator<(const vector& temp) const
{
	if (length() > temp.length()) return true;
	return false;
}
bool vector::operator==(const vector& temp) const
{
	if (length() == temp.length()) return true;
	return false;
}
bool vector::operator!=(const vector& temp) const
{
	if (length() != temp.length()) return true;
	return false;
}