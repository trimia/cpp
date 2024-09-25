#include "PmergeMe.hpp"
#include "include.h"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout<<RED << "Usage: ./PmergeMe sequence of int "<<NONE << std::endl;
        return 1;
    }

    std::cout<<argc%2<<std::endl;

    PmergeMe pmergeMe(argc);
    pmergeMe.fillVec(argv,argc);
    pmergeMe.sort(pmergeMe.get_Vec(),pmergeMe.get_VecSize());
    pmergeMe.printVec(pmergeMe.get_chain(),"chain");
    for (int i =0; i<argc; i++)
    {
        std::cout<<argv[i]<<std::endl;

    }

    return 0;
}