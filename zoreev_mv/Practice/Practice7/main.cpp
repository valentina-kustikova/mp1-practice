#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "vector.h"
using namespace std;

int main() {
    vector a, b, c;
    int control, index;
    double m;
    a.input();
    b.input();
    cout << "Input m" << endl;
    cin >> m;
    cout << "Input index" << endl;
    cin >> index;
    cout << "a+b a+m +a a-b a-m -a a*b a*m *m c[index] |c|" << endl;
    do {
        cin >> control;
        try
        {
            switch (control)
            {
            case 1:
                c = a + b;
                c.print();
                break;
            case 2:
                c = a + m;
                c.print();
                break;
            case 3:
                c += a;
                c.print();
                break;
            case 4:
                c = a - b;
                c.print();
                break;
            case 5:
                c = a + m;
                c.print();
                break;
            case 6:
                c += a;
                c.print();
                break;
            case 7:
                cout << a*b << endl;
                break;
            case 8:
                c = a*m;
                c.print();
                break;
            case 9:
                c *= m;
                c.print();
                break;
            case 10:
                cout << c[index] << endl;
                break;
            case 11:
                cout << c.length() << endl;
                break;
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
    } while (control != 12);
}