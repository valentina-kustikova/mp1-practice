#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    matrix a, b, c;
    int control, index;
    double m;
    a.input();
    b.input();
    cout << "Input m" << endl;
    cin >> m;
    cout << "Input index" << endl;
    cin >> index;
    cout << "a+b a+m a-b a-m a*b a*m" << endl;
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
                c = a - b;
                c.print();
                break;
            case 4:
                c = a - m;
                c.print();
                break;
            case 5:
                c = a * b;
                c.print();
                break;
            case 6:
                c = a * m;
                c.print();
                break;
            }
        }
        catch (exeption & exp)
        {
            switch (exp.exp_type)
            {
            case BadSize:
                cout << "Bad size, It's shold be good if you will use square matrix" << endl;
                break;
            case BadIndex:
                cout << "Wrong Index" << endl;
                break;
            }
        }
    } while (control != 7);
}