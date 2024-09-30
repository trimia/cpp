#include "RPN.hpp"
#include "include.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout<<RED << "Usage: ./RPN \"rpn sequence with the chosen operator from + - / *\""<<NONE << std::endl;
        return 1;
    }
    RPN rpn;
    try {
        rpn.calculate(argv[1]);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
//        std::cout << "Error: invalid RPN sequence" << std::endl;
    }


    return 0;
}