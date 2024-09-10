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
    static void convert(const std::string literal) {
        float f = 0.0f;
        double d = 0.0;
        bool isFloat = false;
        bool isDouble = false;
        std::string str;

        if (literal[0] == '\'' && literal[literal.size() - 1] == '\'') {
            str = literal.substr(0, literal.size() - 1);
        } else str = literal;
        if (str == "inf" || str == "+inf") {
            f = std::numeric_limits<float>::infinity();
            d = std::numeric_limits<double>::infinity();
            isFloat = true;
            isDouble = true;
        } else if (str == "-inf") {
            f = -std::numeric_limits<float>::infinity();
            d = -std::numeric_limits<double>::infinity();
            isFloat = true;
            isDouble = true;
        } else if (str == "inff" || str == "+inff") {
            f = std::numeric_limits<float>::infinity();
            isFloat = true;
        } else if (str == "-inff") {
            f = -std::numeric_limits<float>::infinity();
            isFloat = true;
        } else if (str == "nan" || str == "nanf") {
            f = std::numeric_limits<float>::quiet_NaN();
            d = std::numeric_limits<double>::quiet_NaN();
            isFloat = true;
            isDouble = true;
        } else {
            std::istringstream isstr(str);
            if (!(isstr >> d)) {
                isFloat = false;
                isDouble = false;
            } else {
                f = static_cast<float>(d);
                isFloat = true;
                isDouble = true;
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
        if(!isDigits(str) || str.size()<4){
            char c = std::strtol(str.c_str(), NULL, 10);
            try {
                printChar(c);

            }catch (std::exception &e) {
                std::cout << "char: impossible" << std::endl;
            }
            try {
                printInt(str);
            }catch (std::exception &e) {
                std::cout << "int: impossible" << std::endl;
            }
        }
    }

    static bool isDigits(const std::string &str) {
        for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
            if (!std::isdigit(*it))
                return false;
        }
        return true;
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