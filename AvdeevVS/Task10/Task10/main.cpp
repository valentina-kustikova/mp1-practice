#include "addition.hpp"

int main() {
  try {
    system("color F0"); //5-violet 0-black

    Storage<int> trial_1(3,2);
    cout <<"trial_1 ---> "<< trial_1 << endl;

    Storage<int> trial_2 = trial_1;
    cout << "trial_2 ---> " << trial_2 << endl;

    Storage<int> trial_3(3,2, true) , trial_4(5, 9, true);
    cout << "trial_3 ---> " << trial_3 << endl;

    trial_3 = trial_4;
    cout << "trial_4 ---> " << trial_3 << endl;

    int a = 100 , b = 50;
    trial_1.Push_back(a);
    trial_1.Push_back(b);
    cout << "trial_5 ---> " << trial_1 << endl;

    cout << "trial_6 ---> " << trial_1.Find(b) << endl;

    trial_1.Remove(100);
    cout << "trial_7---> " << trial_1 << endl;

    cout << "------------------------------------------------------"<<endl;

    Storage<int*> test1(5, 3);
    cout << "test_1 --->   " << test1 << endl;

    test1.Push_back(&a, 1);
    cout << "test_2 --->   " << test1 << endl;

  }
  catch (const char* error_message) {
    cout << error_message << endl;
  }
  return 0;
}