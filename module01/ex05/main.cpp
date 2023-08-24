//
// Created by Matteo Mariani on 16/08/23.
//
#include "Harl.hpp"
int main(){
    Harl        harl;
    std::string input;

    std::cout << "To close program type EXIT. Enjoy!" << std::endl;
    do {
        std::cout << "Insert Harl's complain: ";
        std::cin >> input;
        if (std::cin.eof()) {
            return (1);
        }
        harl.complain(input);
    } while (input.compare("EXIT"));
    return 0;
}