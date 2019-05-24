#pragma once

class Matrix
{
private:
	int rows; // stroka
	int cols; // ryad
	double *matrix;
public:
	//constuctors
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix& mtrx);
	Matrix(double *mtrx, int rows, int cols);
	//destructor
	~Matrix();
	//fuctions
	Matrix operator+(const Matrix& mtrx) const;
	Matrix operator+(double a) const;

	Matrix operator-(const Matrix& mtrx) const;
	Matrix operator-(double a) const;

	Matrix operator*(const Matrix& mtrx) const;
	Matrix operator*(double a) const;

	double* operator[](int number_of_row) const;

	Matrix& operator=(const Matrix& mtrx);

	bool operator==(const Matrix& mtrx)const;

	void Output()const;
	void Input()const;
};