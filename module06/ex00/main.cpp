#include "ScalarConverter.hpp"
#include "include.h"
int			main(int ac, char **av)
{
	std::string	s;

	if (ac != 2)
	{
		std::cout << RED << "Usage: ./convert [string]" << NONE << std::endl;
		return (1);
	}
	s = av[1];
	ScalarConverter sc;
	sc.convert(s);
	return 0;
}