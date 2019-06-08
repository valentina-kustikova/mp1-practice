#include "Container.h"
#include "Container_spec.h"
#include "Exception.h"
#include <iostream>
using namespace std;
int main()
{
    double arr1[4] = { 2.5, 3.75, 4.39, 5.92 };
    Container<double> A(arr1, 4);
    A.Add(6.41);
    A.Print();
    int i;
    try
    {
        i = A.Find(6.73);
    }
    catch (Exception s)
    {
        cout << s.what() << endl;
    }
    try
    {
        i = A.Find(3.75);
    }
    catch (Exception s)
    {
        cout << s.what() << endl;
    }
    cout << i << endl;
    try
    {
        A.Delete(8.46);
    }
    catch (Exception s)
    {
        cout << s.what() << endl;
    }
    try
    {
        A.Delete(4.39);
    }
    catch (Exception s)
    {
        cout << s.what() << endl;
    }
    A.Print();
    cout << endl;
    double* arr2[4];
    for (int i = 0; i < 4; i++)
        arr2[i] = &arr1[i];
    Container<double*> B(arr2, 4);
    double a = 8.29;
    double* a1 = &a;
    try
    {
        B.Add(a1);
    }
    catch (Exception s)
    {
        cout << s.what() << endl;
    }
    B.Print();
    try
    {
        i = B.Find(a1);
    }
    catch (Exception s)
    {
        cout << s.what() << endl;
    }
    cout << i << endl;
    try
    {
        B.Delete(a1);
    }
    catch (Exception s)
    {
        cout << s.what() << endl;
    }
    B.Print();
};