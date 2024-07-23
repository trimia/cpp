//#include "ScalarConverter.hpp"
#include "include.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>
#include <ctype.h>
#include <sstream>

class ScalarConverter {
public:
    static void convert(const std::string &literal) {
        float f = 0;
        double d = 0;
        bool isFloat = false, isDouble = false;

        if (literal == "inf" || literal == "+inf") {
            f = std::numeric_limits<float>::infinity();
            d = std::numeric_limits<double>::infinity();
            isFloat = true; isDouble = true;
        } else if (literal == "-inf") {
            f = -std::numeric_limits<float>::infinity();
            d = -std::numeric_limits<double>::infinity();
            isFloat = true; isDouble = true;
        } else if (literal == "inff" || literal == "+inff") {
            f = std::numeric_limits<float>::infinity();
            isFloat = true;
        } else if (literal == "-inff") {
            f = -std::numeric_limits<float>::infinity();
            isFloat = true;
        } else if (literal == "nan" || literal == "nanf") {
            f = std::numeric_limits<float>::quiet_NaN();
            d = std::numeric_limits<double>::quiet_NaN();
            isFloat = true; isDouble = true;
        } else {
            std::istringstream isstr(literal);
            if (!(isstr >> d)) {
                isFloat = false; isDouble = false;
            } else {
                f = static_cast<float>(d);
                isFloat = true; isDouble = true;
            }
        }

        if (isFloat) {
            printFloat(f);
        } else {
            std::cout << "float: impossible" << std::endl;
        }
        if (isDouble) {
            printDouble(d);
        } else {
            std::cout << "double: impossible" << std::endl;
        }
        if (literal.length() == 3 && literal[0] == '\'' && literal[literal.size() - 1] == '\'') {
            char c = literal[1];
            printChar(c);
            printFloat(c);
            printDouble(c);
        }
        try {
            int i = std::atoi(literal.c_str());

            printChar(i);
            printInt(literal);
        } catch (...) {
            std::cout << "int: impossible" << std::endl;
            std::cout << "char: impossible" << std::endl;
        }
    }
    static void printChar(char c) {
        if (std::isprint(c)) {
            std::cout << "char: " << c << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
    }

    static void printInt(const std::string& literal) {
        std::istringstream iss(literal);
        float f;
        if (!(iss >> f)) { // Attempt to read as float
            std::cout << "int: impossible" << std::endl;
        } else {
            int i = static_cast<int>(f);
            if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max() && f == static_cast<float>(i)) {
                std::cout << "int: " << i << std::endl;
            } else {
                std::cout << "int: impossible" << std::endl;
            }
        }
    }

    static void printFloat(float f) {
        std::cout << "float: " << std::fixed << std::setprecision(1) << f<< "f";
        if (!(std::isinf(f) || std::isnan(f))) {
            std::cout << "f";
        }
        std::cout << std::endl;
    }

    static void printDouble(double d) {
        std::cout << "double: " << d << std::endl;
    }
};

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