
#include "Easyfind.hpp"

static  void	print(bool printMessage, std::string type)
{
    if (printMessage)
        std::cout << "Element found in " << type << std::endl;
    else
        std::cout << "Element not found in " << type << std::endl;
}

int		main(void)
{
    std::vector<int> a;
    for (int i = 0; i < 10; i++)
        a.push_back(i + 1);

    std::cout << std::endl << CYAN << "**** Vector ****  " << NONE << std::endl << std::endl;
    std::cout << "Vector info: " << std::endl;
    for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << std::endl << YELLOW << "easyfind(a, 5) " << NONE << std::endl;
    print(easyfind(a, 5), "VECTOR");

    std::cout << std::endl << YELLOW << "easyfind(a, 50) " << NONE << std::endl ;
    print(easyfind(a, 50), "VECTOR");

    std::cout <<  std::endl << "-----------------------------------------------" << std::endl;
    std::cout << std::endl << CYAN << "**** List ****  " << NONE << std::endl ;
    std::list<int> b;
    for (int i = 0; i < 10; i++)
        b.push_back(i + 1);

    std::cout << "List info: " << std::endl;
    for (std::list<int>::iterator it = b.begin(); it != b.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << std::endl << YELLOW << "easyfind(a, 5) " << NONE << std::endl;
    print(easyfind(b, 5), "LIST");
    std::cout << std::endl << YELLOW << "easyfind(a, 50) " << NONE << std::endl;
    print(easyfind(b, 50), "LIST");
}