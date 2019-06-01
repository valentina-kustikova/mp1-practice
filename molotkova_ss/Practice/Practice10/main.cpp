#pragma once
#include <iostream>
#include "Container1.h"
#include "Container2.h"
using namespace std;

void main()
{
	Container1<int,10> c1(4);
	try
	{
		c1.Fill();
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	Container1<int,10> c12(c1);
	try
	{
		c12.Print();
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	try
	{
		*c1[0] = 11;
		cout << *c1[0] << endl;
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	try
	{
		*c1[122] = 11;
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	try
	{
		c12.Delete(5);//вводила
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	try
	{
		c12.Print();
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	try
	{
		c12.Delete(12);//не вводила
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	
	try
	{
		c1.Add(101);//добавление числа
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	try
	{
		c1.Print();
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}




	Container2<int,10> c2(4);
	try
	{
		c2.Fill();
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	Container2<int,10> c22(c2);
	try
	{
		c22.Print();
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	try
	{
		*c2[0] = 11;
		cout << *c2[0] << endl;
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	try
	{
		*c2[122] = 11;
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	try
	{
		c22.Delete(5);//вводила
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	try
	{
		c22.Print();
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	try
	{
		c22.Delete(12);//не вводила
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	
	try
	{
		c2.Add(101);//добавление числа
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}
	try
	{
		c2.Print();
	}
	catch(char* errors)
	{
		cout << errors << endl;
	}

}
