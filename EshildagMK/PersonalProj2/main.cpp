#include<iostream>
#include"operations.h"


int main(int argc, char* argv[]) {
    int pnom_choice, math_choice;
    double usernum;
    bool flag = true;

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string pnom_filename = argv[1];

    polynom first_pnom;
    polynom second_pnom;
    polynom res_pnom;

    get_info(first_pnom, second_pnom, pnom_filename);

    std::cout << "=============" << std::endl;
    std::cout << "1st polynom:" << std::endl;
    printer(first_pnom);
    std::cout << "2nd polynom:" << std::endl;
    printer(second_pnom);
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
            free_polynomial(first_pnom);
            free_polynomial(second_pnom);
            return 0;

        case 1:
            sum(first_pnom, second_pnom, res_pnom);
            std::cout << "Sum: ";
            printer(res_pnom);
            free_polynomial(res_pnom);
            break;

        case 2:
            subtract(first_pnom, second_pnom, res_pnom);
            std::cout << "Subtraction: ";
            printer(res_pnom);
            free_polynomial(res_pnom);
            break;

        case 3:
            multiply(first_pnom, second_pnom, res_pnom);
            std::cout << "Product: ";
            printer(res_pnom);
            free_polynomial(res_pnom);
            break;

        case 4:
            std::cout << "Choose polynom (1 or 2): ";
            std::cin >> pnom_choice;
            switch (pnom_choice) {
            case 1:
                diff_pnom(first_pnom, res_pnom);
                std::cout << "Diff of 1st: ";
                printer(res_pnom);
                free_polynomial(res_pnom);
                break;
            case 2:
                diff_pnom(second_pnom, res_pnom);
                std::cout << "Diff of 2nd: ";
                printer(res_pnom);
                free_polynomial(res_pnom);
                break;
            default:
                std::cout << "Error. Only 2 polynoms exist" << std::endl;
                break;
            }
            break;

        case 5:
            std::cout << "***************" << std::endl;
            std::cout << "Enter your NUM: ";
            std::cin >> usernum;
            std::cout << "Enter chosen POLYNOM (1 or 2): ";
            std::cin >> pnom_choice;
            switch (pnom_choice) {
            case 1:
                calculate(first_pnom, usernum);
                std::cout << "***************" << std::endl;
                break;
            case 2:
                calculate(second_pnom, usernum);
                std::cout << "***************" << std::endl;
                break;
            default:
                std::cout << "Error. Only 2 polynoms exist" << std::endl;
                break;
            }
            break;

        default:
            std::cout << "Error, choose correct number (0-5)." << std::endl;
            break;
        }

    } while (flag);

    free_polynomial(first_pnom);
    free_polynomial(second_pnom);

    return 0;
}