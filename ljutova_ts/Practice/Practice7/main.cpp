#include "Vector.h"
#include "Exception.h"

using namespace std;

int main()
{
	try
	{
		int n1;
		cout << "Enter size vector 1: ";
		cin >> n1;
		Vector v1(n1);
		cout << " Enter coordinats" << " V1 = " << endl;
		v1.Input();
		cout << "Coordinates of your vector: ";
		v1.Output();
		cout << endl << endl;

		int n2;

		cout << "Enter size vector 2: ";
		cin >> n2;
		Vector v2(n2);
		cout << " Enter coordinates" << " V2 = " << endl;
		v2.Input();
		cout << "Coordinates of your vector: ";
		v2.Output();
		cout << endl << endl;

		int a;
		float l, m;

		cout << "Addition of this vector: ";
		cout << " V1 + V2 = V ( " << (v1 + v2) <<")"<< endl;

		cout << "Subtraction of this vector: ";
		cout << " V1 - V2 = V ( " << (v1 - v2) << ")" << endl << endl;

		cout << "Enter const for addition with Vector 1: ";
		cin >> a;
		cout << " V1 + const = V ( " << (v1 + a) << ")" << endl;

		cout << "Enter const for subtraction with Vector 1: ";
		cin >> a;
		cout << " V1 - const = V ( " << (v1 - a) <<")" << endl;

		cout << "Enter const for multiplication with Vector 1: ";
		cin >> a;
		cout << " V1 * const = V ( " << (v1 * a) <<")" << endl;

		cout << endl;
		v1 += v2;
		cout << " V1 += V2 = V ( " << v1 << ")" << endl;

		v1 -= v2;
		cout << " V1 -= V2 = V ( " << v1 << ")" << endl;

		cout << endl;
		cout << "Enter const for addition with Vector 1 (+=): ";
		cin >> a;
		v1 += a;
		cout << " V1 += const = V ( " << v1 << ")" << endl;

		cout << "Enter const for subtraction with Vector 1(-=): ";
		cin >> a;
		v1 -= a;
		cout << " V1 -= const = V ( " << v1 << ")" << endl << endl;

		l = v1.Lenght(v1);
		cout << "Lenght of vector 1: " << l << endl;

		m = v2.Lenght(v2);
		cout << "Lenght of vector 2: " << m << endl;
	}
	catch (Exception ex)
	{
		ex.Print();
	}
}