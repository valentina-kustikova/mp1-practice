#include "Header.h"
#include <iostream>
using namespace std;
void main()
{
	int a[3] = { 1, 2, 3 };
	int b[3] = { 3, 4, 5 };
	Vector V1(3, a);
	Vector V2(3, b);
	cout << "V1=" << V1 << endl;
	cout << "V2=" << V2 << endl;
	cout << "V1+V2=" << V1 + V2 << endl;
	cout << "V1-V2=" << V1 - V2 << endl;
	cout << "V1*5=" << V1 * 5 << endl;
	cout << "V1+5=" << V1 + 5 << endl;
	cout << "V1-5=" << V1 - 5 << endl;
	cout << "V1[0]=" << V1[0] << ", " << "V1[1]=" << V1[1] << ", " << "V1[2]=" << V1[2] << endl;
	cout << boolalpha << "V1==V2" << (V1 == V2) << endl;
	cout << boolalpha << "V1!=V2" << (V1 != V2) << endl;
	cout << boolalpha << "V1>V2" << (V1 > V2) << endl;
	cout << boolalpha << "V1<V2" << (V1 < V2) << endl;
	system("pause");
}