#include <iostream>
#include "shop.h"

using namespace std;

int main(int argc, char** argv) {
    ShopLib* lib = nullptr;
    ShopLib result;

    if (argc < 2) {
        printf("Incorrect number of arguments\n");
        return 1;
    }

    try {
        lib = new ShopLib(string(argv[1]));
        lib->SortByName();
        lib->Filter24hGrocery(result);
        cout << result;
    }
    catch (const char* msg) {
        cerr << msg << endl;
        return 1;
    }

    delete lib;
    return 0;
}