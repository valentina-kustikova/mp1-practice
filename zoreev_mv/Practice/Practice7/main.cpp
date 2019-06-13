#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "vector.h"
using namespace std;

int main() {
	vector a, b;
    int control, index;
    double m;
    a.input();
    b.input();
    cout << "Input m" << endl;
    cin >> m;
    cout << "Input index" << endl;
    cin >> index;
	vector c(a);
    cout << "a+b a+m +a a-b a-m -a a*b a*m *m c[index] |c| temp(a) a<b a>b a==b a!=b" << endl;
    do {
        cin >> control;
        try
        {
            switch (control)
            {
            case 1:
                c = a + b;
				cout << c;
                break;
            case 2:
                c = a + m;
                cout << c;
                break;
            case 3:
                c += a;
                cout << c;
                break;
            case 4:
                c = a - b;
                cout << c;
                break;
            case 5:
                c = a + m;
                cout << c;
                break;
            case 6:
                c += a;
                cout << c;
                break;
            case 7:
                cout << a*b << endl;
                break;
            case 8:
                c = a*m;
                cout << c;
                break;
            case 9:
                c *= m;
                cout << c;
                break;
            case 10:
                cout << c[index] << endl;
                break;
            case 11:
                cout << c.length() << endl;
                break;
			case 12:
				if (a < b)
				{
					cout << "true";
				}
				else
				{
					cout << "false";
				}
			case 13:
				if (a > b)
				{
					cout << "true";
				}
				else
				{
					cout << "false";
				}
			case 14:
				if (a == b)
				{
					cout << "true";
				}
				else
				{
					cout << "false";
				}
			case 15:
				if (a != b)
				{
					cout << "true";
				}
				else
				{
					cout << "false";
				}
            }

        }
        catch (exeption& exp)
        {
            switch (exp.exp_type)
            {
            case BadLength:
                cout << "|a| != |b|" << endl;
                break;
            case BadIndex:
                cout << "Wrong Index" << endl;
                break;
            }
        }
    } while (control != 16);
}