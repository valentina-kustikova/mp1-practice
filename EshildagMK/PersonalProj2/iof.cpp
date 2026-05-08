#include"iof.h"
#include<iostream>
#include<fstream>
#include <iomanip>


void get_info(polynom& fpnom, polynom& spnom, std::string filename) {
    std::ifstream filep(filename);

    if (!filep.is_open()) {
        std::cerr << "Error while opening." << std::endl;
        return;
    }
    //1
    filep >> fpnom.power;
    fpnom.coefs = new int[fpnom.power + 1];
    for (int i = 0; i <= fpnom.power; i++) {
        filep >> fpnom.coefs[i];
    }
    //2
    filep >> spnom.power;
    spnom.coefs = new int[spnom.power + 1];
    for (int i = 0; i <= spnom.power; i++) {
        filep >> spnom.coefs[i];
    }
    filep.close();
}
void printer(polynom& pnom) {
    bool first = true;
    for (int i = pnom.power; i > 0; i--) {
        if (pnom.coefs[i] == 0) continue;

        if (first) {
            std::cout << pnom.coefs[i] << "*x^" << i;
            first = false;
        }
        else {
            std::cout << " ";
            if (pnom.coefs[i] > 0) std::cout << "+";
            std::cout << pnom.coefs[i] << "*x^" << i;
        }
    }

    if (first) {
        std::cout << pnom.coefs[0] << std::endl;
    }
    else {
        std::cout << " ";
        if (pnom.coefs[0] > 0) std::cout << "+";
        std::cout << pnom.coefs[0] << std::endl;
    }
}
void free_polynomial(polynom& pnom) {
    delete[] pnom.coefs;
    pnom.coefs = nullptr;
    pnom.power = 0;
}