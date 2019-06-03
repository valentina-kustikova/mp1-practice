#include "Matrix.h"
#include "Exception.h"
using namespace std;

int main()
{
	int a;
	try
	{
		int x, y;
		cout << "Enter size of Matrix 1: " << endl;
		cin >> x >> y;
		Matrix A(x,y);

		cout << "Enter coefficients Matrix 1: " << endl;
		A.Input();
		cout << "Your Matrix 1: " << endl;
		A.Output();

		cout << "Enter size of Matrix 2: " << endl;
		cin >> x >> y;
		Matrix B(x, y);

		cout << "Enter coefficients Matrix 2: " << endl;
		B.Input();
		cout << "Your Matrix 2: " << endl;
		B.Output();

		cout << " Multiplication of this matrices: A * B = " << endl;
		(A * B).Output();

		cout << "Enter const:" << endl;
		cin >> a;
		cout << "Matrix1 + const a = " << endl;
		(A + a).Output();

		cout << "Matrix1 - const a = " << endl;
		(A - a).Output();

		cout << "Matrix1 * const a = " << endl;
		(A * a).Output();
	
		cout << " Addition of Matrix 1 and Matrix 2:  A + B = " << endl;
		(A + B).Output();

		cout << " Subtraction of Matrix 1 and Matrix 2: A - B = " << endl;
		(A - B).Output();

	}
	catch (Exception ex)
	{
		ex.Print();
	}


}