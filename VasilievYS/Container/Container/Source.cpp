#include <iostream>
#include "Container.h"
#include "TestCont.h"
#include "TestPointerCont.h"

int main() {
	try {
		testConstructors();
		testIdx();
		testEq();
		testPushBack();
		testRemove();
		testFind();
		testPointerConstructors();
		testPointerPushBack();
		testPointerRemove();
	}
	catch (std::exception& er) { std::cout << er.what(); }
    return 0;
}
