#include "addition.hpp"
int main() {
  try {
    system("color F0"); //5-violet 0-black

    Storage<int> trial_1{3,2};
    cout <<"trial_1 ---> "<< trial_1 << endl;

    Storage<int> trial_2{3};
    cout << "trial_2 ---> " << trial_2 << endl;


  }
  catch (const char* error_message) {
    cout << error_message << endl;
  }
  return 0;
}