#include "include.h"
#include "Span.hpp"

int main()
{
    std::cout << std::endl << CYAN << "**** Span(5) ****  " << NONE << std::endl << std::endl;
    Span sp = Span(5);
    std::cout << YELLOW << "sp.addNumber(5); " << NONE << std::endl;
    std::cout << YELLOW << "sp.addNumber(3); " << NONE << std::endl;
    std::cout << YELLOW << "sp.addNumber(17); " << NONE << std::endl;
    std::cout << YELLOW << "sp.addNumber(9); " << NONE << std::endl;
    std::cout << YELLOW << "sp.addNumber(11); " << NONE << std::endl;
    std::cout << YELLOW << "sp.addNumber(18); " << NONE << std::endl << std::endl;
    try
    {
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(18);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Shortest Span -> " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span   -> " << sp.longestSpan() << std::endl << std::endl;

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << std::endl << CYAN << "**** Span(10) ****  " << NONE << std::endl << std::endl;

    Span sp1 = Span(10);
    sp1.addNumber(1, 9);
    std::cout << YELLOW << "sp1.addNumber(1, 9); " << NONE << std::endl << std::endl;
    std::cout << "Shortest Span -> " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest Span   -> " << sp1.longestSpan() << std::endl;

    std::cout << "-----------------------------------------------" << std::endl;
    Span sp2 = Span(2);
    std::cout << std::endl << CYAN << "**** Span(2) ****  " << NONE << std::endl << std::endl;
    std::cout << YELLOW << " //" << NONE << std::endl << std::endl;
    try
    {
        std::cout << "Shortest Span -> " << sp2.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Longest Span   -> " << sp2.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}