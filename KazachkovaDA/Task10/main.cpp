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

    std::cout << find_a1 << " " << find_b1<< 
        " " << find_c1<< " " << find_d1;

    return 0;
}