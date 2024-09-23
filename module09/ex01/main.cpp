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
    rpn.calculate(argv[1]);


    return 0;
}