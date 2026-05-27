#include <iostream>
#include "Container.h"
#include "TestCont.h"
#include "TestPointerCont.h"

int main() {
    testConstructors();
    testIdx();
    testEq();
    testPushBack();
    testRemove();
    testFind();
    testPointerConstructors();
    testPointerIdx();
    testPointerEq();
    testPointerPushBack();
    testPointerRemove();
    testPointerFind();
    return 0;
}
