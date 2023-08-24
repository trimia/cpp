//
// Created by Matteo Mariani on 16/08/23.
//
#include "Harl.hpp"
int error(std::string str) {
    std::cout << "Error : " << str << std::endl;
    return -1;
}
int main(int argc, char **argv) {
    Harl harl;

    if (!(argc == 2)) {
        return error("need one argument");
    } else {
        std::cout << std::endl;
        harl.complain(argv[1]);
    }
    return 0;
}