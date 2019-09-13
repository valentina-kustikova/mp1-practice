#include "vector.h"
#include <iostream>
using namespace std;

int main()
{
    int dim1, dim2;
    double scp, len1, eof;

    cout << "enter dimensions of vectors" << endl;
    cin >> dim1 >> dim2;

    vect v1 (dim1);
    vect v2 (dim2);
    vect v3;


    cout << "enter v1" << endl;
    v1.vect_read();
    cout << "enter v2" << endl;
    v2.vect_read();
        
    cout << "check: v1 is "<< endl;
    v1.vect_print();

    cout << "check: v2 is "<< endl;
    v2.vect_print();

    try 
    {
        v3 = v1 + v2;
        cout << "v1 + v2" << endl;
        v3.vect_print();
    }
    catch (const char* text)
    {
        cout << text << endl;
    }

    try
    {
        v3 = v1 - v2;
        cout << "v1 - v2" << endl;
        v3.vect_print();
    }
    catch (const char* text)
    {
        cout << text << endl;
    }

    cout << "v1" << endl;
    v1.vect_print();
    v1 -= 1;
    cout << "v1 -= 1" << endl;
    v1.vect_print();

    cout << "v1" << endl;
    v1.vect_print();
    v1 += 7;
    cout << "v1 += 7" << endl;
    v1.vect_print();

    cout << "v1" << endl;
    v1.vect_print();
    v1 *= 4;
    cout << "v1 *= 4" << endl;
    v1.vect_print();

    cout << "v2" << endl;
    v2.vect_print();
    v1 = v2 + 100;
    cout << "v1 = v2 + 100" << endl;
    v1.vect_print();
    
    cout << "v1" << endl;
    v1.vect_print();
    cout << "v2" << endl;
    v2.vect_print();
    try
    {
        scp = v1 * v2;
    }
    catch (const char* text)
    {
        cout << text << endl;
    }
    cout << "(v1, v2) = " << scp << endl;

    len1 = v1.vect_len();
    cout << "|v1| = " << len1 << endl;

    try
    {
        cout << "v2[1] = " << v2[1] << endl;
        v2[1] = 55.0;
        cout << "changing to 55.." << endl;
        cout << "v2[1] = " << v2[1] << endl;
    }
    catch (const char* text)
    {
        cout << text << endl;
    }
    cout << "v2" << endl;
    v2.vect_print();

	cout << "stream input: v2" << endl;
	cin >> v2;
	cout << endl << "stream output: v2"<< endl << v2 << endl;

	cout << "success" << endl;
    cin >> eof;   
    return 0;
}