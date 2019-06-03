#include "Matrix.h"
using namespace std;

int main()
{
	int x, y, a;
	cout << "Enter size of Matrix 1: " << endl;
	cin >> x >> y;
	Matrix A(x,y);

	cout << "Enter coefficients Matrix 1: " << endl;
    cin >> A;
	cout << "Your Matrix 1: " << A << endl;

	cout << "Enter size of Matrix 2: " << endl;
	cin >> x >> y;
	Matrix B(x, y);

	cout << "Enter coefficients Matrix 2: " << endl;
    cin >> B;
	cout << "Your Matrix 2: " << B << endl;

    cout << " Multiplication of this matrices: A * B = " << (A * B) << endl;

    try
    {
        cout << "Enter const:" << endl;
        cin >> a;
        cout << "Matrix1 + const a = " << (A + a) << endl;

        cout << "Matrix1 - const a = " << (A - a) << endl;

        cout << "Matrix1 * const a = " << (A * a) << endl;
    }
    catch (Matrix1)
    {
        cout << "Different size \n";
    }
    try
    {
        cout << " Addition of Matrix 1 and Matrix 2:  A + B = " << (A + B) << endl;
    }
    catch (Matrix1)
    {
        cout << "Different size \n";
    }
    try
    {
        cout << " Subtraction of Matrix 1 and Matrix 2: A - B = " << (A - B) << endl;

	}
    catch (Matrix1)
    {
        cout << "Different size \n";
    }
}