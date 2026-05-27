#include"TestCont.h"
void testConstructors() {
    Container<int> c1;
    std::cout << "\ndefault constructor:\n size=" << c1.getSize()
        << ", capacity=" << c1.getCapacity() << std::endl;

    Container<int> c2(5);
    std::cout << "size constructor (5):\n size=" << c2.getSize()
        << ", capacity=" << c2.getCapacity() << std::endl;

    Container<int> c3(3, 42);
    std::cout << "size+value constructor (3, 42):\n size=" << c3.getSize()
        << ", capacity=" << c3.getCapacity() << std::endl;
    std::cout << "elements: ";
    for (size_t i = 0; i < c3.getSize(); i++) {
        std::cout << c3[i] << " ";
    }
    std::cout << std::endl;

    Container<int> c4(c3);
    std::cout << "copy constructor:\n size=" << c4.getSize()
        << ", capacity=" << c4.getCapacity() << std::endl;
    std::cout << "elements: ";
    for (size_t i = 0; i < c4.getSize(); i++) {
        std::cout << c4[i] << " ";
    }
    std::cout << std::endl;
}

void testIdx()
{
    std::cout << "\noperator[]:\n";
    Container<int> c5(5, 2);
    for (int i = 0; i < 5; i++) {
        c5[i] = i * 10;
        std::cout << c5[i] << " ";
    }
    std::cout << std::endl;
}

void testPushBack()
{
    std::cout << "\npush_back:\n";
    Container<int> c6;
    for (int i = 1; i <= 10; i++) {
        c6.push_back(i);
        std::cout << "pushed " << i << ": size=" << c6.getSize()
            << ", capacity=" << c6.getCapacity() << std::endl;
    }
}

void testRemove()
{
    std::cout << "\nremove:\n";
    Container<int> c7;
    for (int i = 1; i <= 5; i++) {
        c7.push_back(i);
    }
    for (size_t i = 0; i < c7.getSize(); i++) {
        std::cout << c7[i] << " ";
    }
    std::cout << " (size=" << c7.getSize() << ")\n";
    c7.remove(3);
    std::cout << "removed 3: ";
    for (size_t i = 0; i < c7.getSize(); i++) {
        std::cout << c7[i] << " ";
    }
    std::cout << " (size=" << c7.getSize() << ")\n";
}

void testEq()
{
    std::cout << "\noperator=:\n";
    Container<int> c8;
    for (int i = 1; i <= 5; i++) {
        c8.push_back(i);
    }
    std::cout << "c8: ";
    for (size_t i = 0; i < c8.getSize(); i++) {
        std::cout << c8[i] << " ";
    }
    std::cout << std::endl;
    Container<int> c9(6, 6);
    std::cout << "c9: ";
    for (size_t i = 0; i < c9.getSize(); i++) {
        std::cout << c9[i] << " ";
    }
    std::cout << std::endl;
    c9 = c8;
    std::cout << "c9=c8: ";
    for (size_t i = 0; i < c9.getSize(); i++) {
        std::cout << c9[i] << " ";
    }
    std::cout << std::endl;
}
void testFind()
{
    std::cout << "\nfind:\n";
    Container<int> c10(3, 4);
    c10.push_back(100);
    std::cout << "elements: ";
    for (size_t i = 0; i < c10.getSize(); i++) {
        std::cout << c10[i] << " ";
    }
    std::cout << std::endl;
    int idx1 = c10.find(100);
    std::cout << "find(100) = " << idx1 << std::endl;
    int idx3 = c10.find(999);
    std::cout << "find(999) = " << idx3 << std::endl;
}