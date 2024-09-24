#include "PmergeMe.hpp"
#include "include.h"

int main(int argc, char **argv)
{
//    if (argc != 2)
//    {
//        std::cout<<RED << "Usage: ./RPN \"rpn sequence with the chosen operator from + - / *\""<<NONE << std::endl;
//        return 1;
//    }

    std::cout<<argc%2<<std::endl;

    PmergeMe pmergeMe(argc);
    pmergeMe.fillVec(argv,argc);
    pmergeMe.sort(pmergeMe.get_Vec(),pmergeMe.get_VecSize());
    for (int i =0; i<argc; i++)
    {
        std::cout<<argv[i]<<std::endl;

    }

    return 0;
}