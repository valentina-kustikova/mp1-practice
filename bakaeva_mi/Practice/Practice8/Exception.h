#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include "iostream"
#include "string"

using namespace std;

class Exception
{
private:
    string mes;
public:
    Exception(string _mes) : mes(_mes) {};

    void Print()
    {
        cout << "  Error: " << mes << endl;
    }
};
#endif 