#define _CRT_SECURE_NO_WARNINGS
#include "rofl.h"
#include <iostream>

Vector::Vector()
{
	this->size = 2;
	this->elements = new double[size];
	for (int i = 0; i < this->size; i++)
	{
		elements[i] = 0;
	}
};
void Vector::PrintVector()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << elements[i] << std::endl;
	}
};
double Vector::Skalyar(Vector b)
{
	int i;
	if (size < b.size)
	{
		throw exeption(BadLength);
	}
	int sum = 0;
	if (this->size == b.size)
	{
		for (i = 0; i < this->size; i++)
		{
			sum += (this->elements[i] * b.elements[i]);
		}
		printf("\n %d", sum);
		return sum;
	}
	else
	{
		printf("dlini ne sovpadayut");
	}
}
double Vector::Length()
{
	double length = 0, lengthout = 0;
	for (int i = 0; i < this->size; i++)
	{
		length += this->elements[i] * this->elements[i];
	}
	lengthout = sqrt(length);
	return lengthout;
};
void Vector::operator+=(int k)
{
	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = this->elements[i] + k;
	}
}
void Vector::operator-=(int k)
{
	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = this->elements[i] - k;
	}
}
void Vector::operator*=(int k)
{
	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = this->elements[i] * k;
	}
}
void Vector::operator*=(Vector a)
{
	if (this->size == a.size)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->elements[i] = this->elements[i] * a.elements[i];
		}
	}
	else
	{
		{
			throw exeption(BadLength);
		}
	}
}
void Vector::Delete()
{
	for (int i = 0; i < size; i++)
	{
		elements[i] = 0;
	}
}
const double & Vector::operator[](int index) const
{
	if ((index < 0) || (index >= size))
		throw exeption(BadIndex);

	return elements[index];
}
;
void Vector::Input()
{
	int _size;
	cout << "Input vector size ";
	do {
		cin >> size;
	} while (size <= 0);
	delete[] elements;
	elements = new double[size];
	cout << "Input vector" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> elements[i];
	}

};
Vector::Vector(Vector& tmp)
{
	this->size = tmp.size;
	this->elements = new double[size];
	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = tmp.elements[i];
	}
};
Vector::Vector(int _size)
{
	this->size = _size;
	this->elements = new double[size];
	for (int i = 0; i < 10; i++)
	{
		elements[i] = 0;
	}
}
Vector::Vector(int n, double * aarray)
{
	if ((*aarray == NULL) || (n <= 0))
		throw 0;

	this->size = n;
	elements = new double[size];
	for (int i = 0; i < n; i++)
		elements[i] = aarray[i];
}
;
Vector::~Vector()
{
	{
		delete[] elements;
		size = 0;
	}
};
Vector Vector::operator=(const Vector & x)
{
	if (size < x.size)
	{
		throw exeption(BadLength);
	}
	this->size = x.size;
	elements = new double[size];
	for (int i = 0; i < size; i++)
	{
		elements[i] = x.elements[i];
	}
	return *this;
};
Vector Vector::operator*(double k)
{
	for (int i = 0; i < size; i++)
	{
		elements[i] = elements[i] * k;
	}
	return *this;
}
Vector Vector::operator*(const Vector & x)
{
	if (size < x.size)
	{
		throw exeption(BadLength);
	}
	for (int i = 0; i < size; i++)
	{
		elements[i] = x.elements[i] * elements[i];
	}
	return *this;
};
Vector Vector::operator+(const Vector & x)
{
	if (size < x.size)
	{
		throw exeption(BadLength);
	}
	if (this->size == x.size)
	{
		for (int i = 0; i < size; i++)
		{
			elements[i] = x.elements[i] + elements[i];
		}
		return *this;
	}
	else
		cout << "error";
};
Vector Vector::operator=(double k)
{
	for (int i = 0; i < size; i++)
	{
		elements[i] = k;
	}
	return *this;
};
bool Vector::operator>(Vector & x)
{
	bool a;
	if (size < x.size)
	{
		throw exeption(BadLength);
	}
	int k = 0, rofl = 0, konec, roflan;
	for (int i = 0; i < size; i++)
	{
		k += elements[i] * elements[i];
		rofl += x.elements[i] * x.elements[i];
	}
	konec = sqrt(k);
	roflan = sqrt(rofl);
	if (konec > roflan)
		return true;
	else
		printf("error");
	return false;
};
bool Vector::operator>(double k)
{
	int ko = 0, konec;
	for (int i = 0; i < size; i++)
	{
		ko += elements[i] * elements[i];
	}
	konec = sqrt(ko);
	if (konec > k)
	{
		printf("true");
		return true;
	}
	else
	{
		printf("false");
		return false;
	}
};
bool Vector::operator<(Vector & x)
{
	if (size < x.size)
	{
		throw exeption(BadLength);
	}
	int k = 0, rofl = 0, konec, roflan;
	for (int i = 0; i < size; i++)
	{
		k += elements[i] * elements[i];
		rofl += x.elements[i] * x.elements[i];
	}
	konec = sqrt(k);
	roflan = sqrt(rofl);
	if (konec < roflan)
		return true;
	else
		printf("error");
	return false;
};
bool Vector::operator<(double k)
{
	int ko = 0, konec;
	for (int i = 0; i < size; i++)
	{
		ko += elements[i] * elements[i];
	}
	konec = sqrt(ko);
	if (konec < k)
	{
		printf("true");
		return true;
	}
	else
	{
		printf("false");
		return false;
	}
	return 0;
}
bool Vector::operator>=(double k)
{
	int ko = 0, konec;
	for (int i = 0; i < size; i++)
	{
		ko += elements[i] * elements[i];
	}

	if (ko >= (k*k))
	{

		return true;
	}
	else
	{

		return false;
	}
}
bool Vector::operator>=(Vector &x)
{
	bool a;
	if (size < x.size)
	{
		throw exeption(BadLength);
	}
	int k = 0, rofl = 0, konec, roflan;
	for (int i = 0; i < size; i++)
	{
		k += elements[i] * elements[i];
		rofl += x.elements[i] * x.elements[i];
	}
	if (k >= rofl)
	{
		return true;
	}
	else
		return false;
}
bool Vector::operator<=(double k)
{
	int ko = 0, konec;
	for (int i = 0; i < size; i++)
	{
		ko += elements[i] * elements[i];
	}
	if (ko <= (k*k))
	{
		return true;
	}
	else
	{
		return false;
	}
}
;
bool Vector::operator<=(Vector & x)
{
	bool a;
	if (size < x.size)
	{
		throw exeption(BadLength);
	}
	int k = 0, rofl = 0, konec, roflan;
	for (int i = 0; i < size; i++)
	{
		k += this->elements[i] * this->elements[i];
		rofl += x.elements[i] * x.elements[i];
	}
	if (k <= rofl)
	{
		return true;
	}
	else
	{
		return false;
	}
};
Vector Vector::operator-(double k)
{
	for (int i = 0; i < size; i++)
	{
		elements[i] = elements[i] - k;
	}
	return *this;
}
Vector Vector::operator-(const Vector & x)
{
	if (this->size == x.size)
	{
		for (int i = 0; i < size; i++)
		{
			elements[i] = x.elements[i] + elements[i];
		}
		return *this;
	}
	else

		throw exeption(BadLength);

};
Vector Vector::operator+(double k)
{
	for (int i = 0; i < size; i++)
	{
		elements[i] = elements[i] + k;
	}
	return *this;
};
double& Vector::operator[](int index)
{
	if ((index < 0) || (index >= size))
	{
		throw exeption(BadIndex);
	}

	return elements[index];
}

istream & operator>>(istream &in, Vector &_vector)
{
	for (int i = 0; i < _vector.size; i++)
		in >> _vector.elements[i];

	return in;
}

ostream & operator<<(ostream &out, const Vector &_vector)
{
	if (_vector.size == 0)
	{
		out << "Empty vector.";
		return out;
	}

	out << "(";

	for (int i = 0; i < _vector.size; i++)
		out << _vector[i] << ", ";

	out << _vector[_vector.size - 1] << ")";

	return out;
}
