#include"TestPointerCont.h"
void testPointerConstructors() {
    std::cout << "\nPointer Constructors:\n";
    Container<int*> c1;
    std::cout << "default constructor:\n size=" << c1.getSize()
        << ", capacity=" << c1.getCapacity() << std::endl;
    Container<int*> c2(5);
    std::cout << "size constructor (5):\n size=" << c2.getSize()
        << ", capacity=" << c2.getCapacity() << std::endl;
    int value = 42;
    Container<int*> c3(3, &value);
    std::cout << "size+value constructor (3, &value):\n size=" << c3.getSize()
        << ", capacity=" << c3.getCapacity() << std::endl;
    std::cout << "elements (values): ";
    for (size_t i = 0; i < c3.getSize(); i++) {
        std::cout << *c3[i] << " ";
    }
    std::cout << std::endl;
    Container<int*> c4(c3);
    std::cout << "copy constructor:\n size=" << c4.getSize()
        << ", capacity=" << c4.getCapacity() << std::endl;
    std::cout << "elements (values): ";
    for (size_t i = 0; i < c4.getSize(); i++) {
        std::cout << *c4[i] << " ";
    }
    std::cout << std::endl;
}

void testPointerIdx() {
    std::cout << "\nPointer operator[]:\n";
    int value = 0;
    Container<int*> c5(5, &value);
    int a = 10, b = 20, c = 30, d = 40, e = 50;
    c5[0] = &a;
    c5[1] = &b;
    c5[2] = &c;
    c5[3] = &d;
    c5[4] = &e;
    std::cout << "values: ";
    for (int i = 0; i < 5; i++) {
        std::cout << *c5[i] << " ";
    }
    std::cout << std::endl;
    *c5[2] = 999;
    std::cout << "after *c5[2]=999: ";
    for (int i = 0; i < 5; i++) {
        std::cout << *c5[i] << " ";
    }
    std::cout << std::endl;
}

void testPointerPushBack() {
    std::cout << "\nPointer push_back:\n";
    Container<int*> c6;
    int x1 = 10, x2 = 20, x3 = 30, x4 = 40, x5 = 50;
    std::cout << "size=" << c6.getSize()
        << ", capacity=" << c6.getCapacity() << std::endl;
    c6.push_back(&x1);
    std::cout << "pushed 10: size=" << c6.getSize()
        << ", capacity=" << c6.getCapacity() << std::endl;
    c6.push_back(&x2);
    std::cout << "pushed 20: size=" << c6.getSize()
        << ", capacity=" << c6.getCapacity() << std::endl;
    c6.push_back(&x3);
    std::cout << "pushed 30: size=" << c6.getSize()
        << ", capacity=" << c6.getCapacity() << std::endl;
    c6.push_back(&x4);
    std::cout << "pushed 40: size=" << c6.getSize()
        << ", capacity=" << c6.getCapacity() << std::endl;
    c6.push_back(&x5);
    std::cout << "pushed 50: size=" << c6.getSize()
        << ", capacity=" << c6.getCapacity() << std::endl;
}

void testPointerRemove() {
    std::cout << "\nPointer remove:\n";
    Container<int*> c7;
    int r1 = 1, r2 = 2, r3 = 3, r4 = 4, r5 = 5;
    c7.push_back(&r1);
    c7.push_back(&r2);
    c7.push_back(&r3);
    c7.push_back(&r4);
    c7.push_back(&r5);
    std::cout << "before remove: ";
    for (size_t i = 0; i < c7.getSize(); i++) {
        std::cout << *c7[i] << " ";
    }
    std::cout << " (size=" << c7.getSize() << ")\n";
    c7.remove(&r3);
    std::cout << "removed 3: ";
    for (size_t i = 0; i < c7.getSize(); i++) {
        std::cout << *c7[i] << " ";
    }
    std::cout << " (size=" << c7.getSize() << ")\n";
}

void testPointerFind() {
    std::cout << "\nPointer find:\n";
    Container<int*> c8;
    int f1 = 100, f2 = 200, f3 = 300;
    c8.push_back(&f1);
    c8.push_back(&f2);
    c8.push_back(&f3);
    std::cout << "elements: ";
    for (size_t i = 0; i < c8.getSize(); i++) {
        std::cout << *c8[i] << " ";
    }
    std::cout << std::endl;
    int idx1 = c8.find(&f2);
    std::cout << "find(200) = " << idx1 << std::endl;
    int not_found = 999;
    int idx3 = c8.find(&not_found);
    std::cout << "find(999) = " << idx3 << std::endl;
}

void testPointerEq() {
    std::cout << "\nPointer operator=:\n";
    Container<int*> c9;
    int p1 = 1, p2 = 2, p3 = 3, p4 = 4, p5 = 5;
    c9.push_back(&p1);
    c9.push_back(&p2);
    c9.push_back(&p3);
    c9.push_back(&p4);
    c9.push_back(&p5);
    std::cout << "c9: ";
    for (size_t i = 0; i < c9.getSize(); i++) {
        std::cout << *c9[i] << " ";
    }
    std::cout << std::endl;
    Container<int*> c10(3, &p1);
    std::cout << "c10: ";
    for (size_t i = 0; i < c10.getSize(); i++) {
        std::cout << *c10[i] << " ";
    }
    std::cout << std::endl;
    c10 = c9;
    std::cout << "c10 = c9: ";
    for (size_t i = 0; i < c10.getSize(); i++) {
        std::cout << *c10[i] << " ";
    }
    std::cout << std::endl;
}