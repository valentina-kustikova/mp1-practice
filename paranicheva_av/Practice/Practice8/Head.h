#ifndef HEAD_H
#define HEAD_H

class Matrix
{
	double *m;
	int rows, cols;
public:
	Matrix(int _rows, int _cols);
	Matrix(double* _m, int _rows, int _cols);
	Matrix(const Matrix& M);
	~Matrix();
	const Matrix operator= (const Matrix& M);
	Matrix operator+ (const Matrix& M)const;
	Matrix operator- (const Matrix& M)const;
	Matrix operator* (const Matrix&)const;
	Matrix operator+ (double a)const;
	Matrix operator- (double a)const;
	Matrix operator* (double a)const;
	const double*& operator[] (int ind) const;
	bool operator== (const Matrix& m) const;

	friend istream& operator>> (istream& input, Matrix& M); 
    	friend ostream& operator<< (ostream& output, const Matrix& M); 
};
