#include <iostream>
#include "container.h"

using namespace std;

int main()
{
	Container<int> c1(2, 2);
	int a1 = 7;
	int a2 = 8;
	int a3 = 9;
	c1.push_back(a1);
	c1.push_back(a2);
	c1.push_back(a3);
	int ia1 = c1.find(a1);
	int ia2 = c1.find(a2);
	int ia3 = c1.find(a3);
	cout << ia1 << ia2 << ia3 << endl;
	c1.remove(a1);
	ia1 = c1.find(a1);
	ia2 = c1.find(a2);
	ia3 = c1.find(a3);
	cout << ia1 << ia2 << ia3 << endl;
	c1.remove(a2);
	ia1 = c1.find(a1);
	ia2 = c1.find(a2);
	ia3 = c1.find(a3);
	cout << ia1 << ia2 << ia3 << endl;
	c1.remove(a3);
	ia1 = c1.find(a1);
	ia2 = c1.find(a2);
	ia3 = c1.find(a3);
	cout << ia1 << ia2 << ia3 << endl;

	Container<double> c2(2, 1);
	double b1 = 3.6;
	double b2 = 4.5;
	c2.push_back(b1);
	c2.push_back(b2);
	int ib1 = c2.find(b1);
	int ib2 = c2.find(b2);
	cout << ib1 << ib2 << endl;
	c2.remove(b2);
	ib1 = c2.find(b1);
	ib2 = c2.find(b2);
	cout << ib1 << ib2 << endl;

	Container<int*> cc(1,1);
	int* d1 = new int(1);
	int* d2 = new int(3);
	cc.push_back(d1);
	cc.push_back(d2);
	int id1 = cc.find(d1);
	int id2 = cc.find(d2);
	cout << id1 << id2 << endl;
	cc.remove(d1);
	id1 = cc.find(d1);
	id2 = cc.find(d2);
	cout << id1 << id2 << endl;
	cc.remove(d2);
	id1 = cc.find(d1);
	id2 = cc.find(d2);
	cout << id1 << id2 << endl;
	return 0;
}