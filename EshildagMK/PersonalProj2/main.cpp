#include<iostream>
#include"struct.h"


int main(int argc, char* argv[]) {
    int pnom_choice, math_choice;
    double usernum;
    bool flag = true;

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    polynom first_pnom(file);
    polynom second_pnom(file);
    file.close();

    std::cout << "=============" << std::endl;
    std::cout << "1st polynom:" << std::endl;
    first_pnom.print_pnom();
    std::cout << "2nd polynom:" << std::endl;
    second_pnom.print_pnom();
    std::cout << "=============" << std::endl;

    do {
        std::cout << "MENU:" << std::endl;
        std::cout << "1 - SUM" << std::endl;
        std::cout << "2 - SUBTRACT" << std::endl;
        std::cout << "3 - MULTIPLY" << std::endl;
        std::cout << "4 - DIFF" << std::endl;
        std::cout << "5 - CALCULATE" << std::endl;
        std::cout << "0 - EXIT" << std::endl;
        std::cout << "Choose: ";
        std::cin >> math_choice;

        switch (math_choice) {
        case 0:
            std::cout << "Exiting..." << std::endl;
            return 0;

        case 1: {
            polynom res_pnom = first_pnom + second_pnom;
            std::cout << "Sum: ";
            res_pnom.print_pnom();
            break;
        }
        case 2: {
            polynom res_pnom = first_pnom - second_pnom;
            std::cout << "Subtraction: ";
            res_pnom.print_pnom();
            break;
        }
        case 3: {
            polynom res_pnom = first_pnom * second_pnom;
            std::cout << "Product: ";
            res_pnom.print_pnom();
            break;
        }
        case 4: {
            std::cout << "Choose polynom (1 or 2): ";
            std::cin >> pnom_choice;
            if (pnom_choice == 1) {
                polynom res_pnom = first_pnom.diff();
                std::cout << "Diff of 1st: ";
                res_pnom.print_pnom();
            }
            else if (pnom_choice == 2) {
                polynom res_pnom = second_pnom.diff();
                std::cout << "Diff of 2nd: ";
                res_pnom.print_pnom();
            }
            else {
                std::cout << "Error. Only 2 polynoms exist" << std::endl;
            }
            break;
        }
        case 5:{
            std::cout << "***************" << std::endl;
            std::cout << "Enter your NUM: ";
            std::cin >> usernum;
            std::cout << "Enter chosen POLYNOM (1 or 2): ";
            std::cin >> pnom_choice;
            switch (pnom_choice) {
            case 1:
                std::cout << "Result: " << first_pnom(usernum) << std::endl;
                break;
            case 2:
                std::cout << "Result: " << second_pnom(usernum) << std::endl;
                break;
            default:
                std::cout << "Error. Only 2 polynoms exist" << std::endl;
                break;
            }
            break;
        }
        default:
            std::cout << "Error, choose correct number (0-5)." << std::endl;
            break;
        }
        std::cout << "***************" << std::endl;

    } while (flag); 


    return 0;
}