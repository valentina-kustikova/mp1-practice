#include <iostream>
#include "template.h"
using namespace std;


int main() {
	Container <int> intCont1(3, 3);
	intCont1.InsertElem(3); intCont1.InsertElem(4); intCont1.InsertElem(5);
	intCont1.InsertElem(7); intCont1.InsertElem(1);
	cout << intCont1;


	return 0;
}