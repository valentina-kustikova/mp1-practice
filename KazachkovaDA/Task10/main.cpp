#include <iostream>
#include "container.hpp"

using namespace std;

int main()
{
    Container <int> test1(2, 1);

    int a1 = 3;
    int b1 = 5;
    int c1 = 7;
    int d1 = 9;

    test1.push_back(a1);
    test1.push_back(b1);
    test1.push_back(c1);
    test1.push_back(d1);

    test1.remove(a1);
    test1.remove(c1);

    int find_a1 = test1.find(a1);
    int find_b1 = test1.find(b1);
    int find_c1 = test1.find(c1);
    int find_d1 = test1.find(d1);

    std::cout << "Find " << a1 <<" " << b1 << " "<< c1 << " "<< d1<<std::endl;
    std::cout << find_a1 << " " << find_b1<< 
        " " << find_c1<< " " << find_d1<<std::endl;

    std::cout << "Copy test"<<std::endl;
    Container <int> test3(test1);
    for (int i = 0; i < 2; i++)
    {
        std::cout << test3[i];
    }
    std::cout << std::endl;

    std::cout << "= test" << std::endl;
    Container <int> test5 = test3;
    for (int i = 0; i < 2; i++)
    {
        std::cout << test3[i];
    }
    std::cout << std::endl;

    /////////////////////////////
    Container <char> test2(1, 2);
    char a2 = 'a';
    char b2 = 'b';
    char c2 = 'c';
    char d2 = 'd';

    test2.push_back(a2);
    test2.push_back(b2);
    test2.push_back(c2);
    test2.push_back(d2);

    test2.remove(b2);
    test2.remove(d2);

    int find_a2 = test2.find(a2);
    int find_b2 = test2.find(b2);
    int find_c2 = test2.find(c2);
    int find_d2 = test2.find(d2);

    std::cout << "Find " << a2 << " " << b2 << " " << c2 << " " << d2 << std::endl;
    std::cout << find_a2 << " " << find_b2 <<
        " " << find_c2 << " " << find_d2<<std::endl;

    std::cout << "Copy test" << std::endl;
    Container <char> test4(test2);
    for (int i = 0; i < 2; i++)
    {
        std::cout << test4[i];
    }
    std::cout << std::endl;


    std::cout << "= test" << std::endl;
    Container <char> test6 = test4;
    for (int i = 0; i < 2; i++)
    {
        std::cout << test6[i];
    }
    std::cout << std::endl;

    ////////////////////////////
    Container <int*> test7(3, 1);

    int* a3 = new int(3);
    int* b3 = new int(5);
    int* c3 = new int(9);
    int* d3 = new int(8);

    test7.push_back(a3);
    test7.push_back(b3);
    test7.push_back(c3);
    test7.push_back(d3);

    test7.remove(a3);
    test7.remove(c3);

    int find_a3 = test7.find(a3);
    int find_b3 = test7.find(b3);
    int find_c3 = test7.find(c3);
    int find_d3 = test7.find(d3);

    std::cout << "Find " << a3 << " " << b3 << " " << c3 << " " << d3 << std::endl;
    std::cout << find_a3 << " " << find_b3 <<
        " " << find_c3 << " " << find_d3 << std::endl;

    std::cout << "Copy test" << std::endl;
    Container <int*> test8(test7);
    for (int i = 0; i < 2; i++)
    {
        std::cout << test3[i];
    }
    std::cout << std::endl;

    std::cout << "= test" << std::endl;
    Container <int*> test9 = test8;
    for (int i = 0; i < 2; i++)
    {
        std::cout << test3[i];
    }
    std::cout << std::endl;

    return 0;
}