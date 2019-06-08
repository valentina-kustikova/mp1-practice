#pragma once
#include <exception>
#include <iostream>
#include <string>
using namespace std;
class Exception: public exception
{
    string s;
public:
    Exception(const string& _s) : s(_s) {};
    virtual const char* what() const noexcept override
    {
        return s.c_str();
    };
};