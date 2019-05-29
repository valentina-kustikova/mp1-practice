#include <iostream>
#include "Vector.h"
#include <locale.h>
using namespace std;

int main() 
{

    setlocale(LC_ALL, "Russian");
    int d, c;

    cout << "Введите размерность векторов v1 и v2: ";
    do {
        cin >> d;
        if (d < 1)
            cout << "Размерность должна быть больше 0. Попробуйте ввести число ещё раз." << endl;
    } while (d < 1);
    Vector v1(d);
    Vector v2(d);
    Vector v(d);

    cout << "Введите ккординаты вектора v1:" << endl;
    v1.Fill();
    cout << "|v1| = ";
    v1.Length();

    cout << "Введите ккординаты вектора v2:" << endl;
    v2.Fill();
    cout << "|v2| = ";
    v2.Length();

    do{
    int n;
    Menu();
    do {
        cin >> n;
        if((n < 1) || (n > 13))
        cout << "Операции с таким номером нет. Попробуйте ввести ещё раз."<< endl;
    } while ((n < 1) || (n > 13));
    double dig;
    switch (n)
        {
        case 1:
        {
            v = v1 + v2;
            cout << "v = ( ";
            v.Print();
            cout << ")" << endl;
            break;
        }
        case 2:
        {
            v = v1 - v2;
            cout << "v = ( ";
            v.Print();
            cout << ")" << endl;
            break;
        }
        case 3:
        {
            double scal = v1 * v2;
            cout << "scal = " << scal << endl;
            break;
        }
        case 4:
        {
            dig = Digital();
            v = v1 + dig;
            cout << "v = ( ";
            v.Print();
            cout << ")" << endl;
            break;
        }
        case 5:
        {
            dig = Digital();
            v = v1 - dig;
            cout << "v = ( ";
            v.Print();
            cout << ")" << endl;
            break;
        }
        case 6:
        {
            dig = Digital();
            v = v1 * dig;
            cout << "v = ( ";
            v.Print();
            cout << ")" << endl;
            break;
        }
        case 7:
        {
            v1 += v2;
            cout << "v1 = ( ";
            v1.Print();
            cout << ")" << endl;
            break;
        }
        case 8:
        {
            v1 -= v2;
            cout << "v1 = ( ";
            v1.Print();
            cout << ")" << endl;
            break;
        }
        case 9:
        {
            v1 *= v2;
            cout << "v1 = ( ";
            v1.Print();
            cout << ")" << endl;
            break;
        }
        case 10:
        {
            dig = Digital();
            v1 += dig;
            cout << "v1 = ( ";
            v1.Print();
            cout << ")" << endl;
            break;
        }
        case 11:
        {
            dig = Digital();
            v1 -= dig;
            cout << "v1 = ( ";
            v1.Print();
            cout << ")" << endl;
            break;
        }
        case 12:
        {
            dig = Digital();
            v1 *= dig;
            cout << "v1 = ( ";
            v1.Print();
            cout << ")" << endl;
            break;
        }
        case 13:
        {
            int i;
            cout << "Введите индекс: ";
            cin >> i;
            cout << "v1["<< i << "] = " << v1[i] << endl;
        }
        }
        cout << "Если вы хотите сделать ещё какие-то действия с векторами, введите 1" << endl;
        cout << "Если нет, любое другое число." << endl;
        cin >> c;
    } while (c == 1);

    system("pause");
}