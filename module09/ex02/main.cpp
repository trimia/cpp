#include "PmergeMe.hpp"
#include "include.h"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout<<RED << "Usage: ./PmergeMe sequence of int "<<NONE << std::endl;
        return 1;
    }

    PmergeMe pmergeMe(argc);
    try{
        pmergeMe.merge_insertion_sort_impl(argc,argv);
    }catch(std::exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
//    pmergeMe.merge_insertion_sort_impl(argc,argv);
    return 0;
}
