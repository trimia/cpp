#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter : Default Constructor Called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter : Destructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &obj) {
    std::cout << "Copy Constructor Called" << std::endl;
    if (this != &obj)
        *this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) {
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this != &obj) {
        //	this->attributes = obj.attributes;
        //	...
    }
    return (*this);
}


void ScalarConverter::convert(const std::string &literal) {
        // Handling infinity
    if (literal == "inf" || literal == "-inf" || literal == "+inf" ||
        literal == "inff" || literal == "-inff" || literal == "+inff") {
        float f = std::numeric_limits<float>::infinity();
        double d = std::numeric_limits<double>::infinity();
        if (literal[0] == '-') {
            f = -f;
            d = -d;
        } else if (literal[0] != '+') {
            f = std::numeric_limits<float>::quiet_NaN();
            d = std::numeric_limits<double>::quiet_NaN();
        }
        printFloat(f);
        printDouble(d);
        return;
        }
    // Existing logic for other literals
        // ...
    if (literal.length() == 3 && literal[0] == '\'' && literal[literal.size() - 1] == '\'') {
        // Char literal
        char c = literal[1];
        printChar(c);
        printInt(c);
        printFloat(c);
        printDouble(c);
    } else if (literal.find('.') != std::string::npos || literal == "-inf" || literal == "+inf" || literal == "nan" ||
               literal == "-inff" || literal == "+inff" || literal == "nanf") {
        // Float or Double literal
        if (literal[literal.size() - 1] == 'f') {
            float f = static_cast<float>(std::atof(literal.c_str()));
            printFloat(f);
            printDouble(f);
        } else {
            double d = std::atof(literal.c_str());
            printFloat(d);
            printDouble(d);
        }
        // Attempt to print as char and int if possible
        try {
            int i = std::atoi(literal.c_str());
            printChar(i);
            printInt(i);
        } catch (...) {
            // Not convertible to int
        }
               } else {
                   // Int literal
                   try {
                       int i = std::atoi(literal.c_str());
                       printChar(i);
                       printInt(i);
                       printFloat(i);
                       printDouble(i);
                   } catch (...) {
                       std::cout << "Invalid or out of range integer literal." << std::endl;
                   }
               }
}
void ScalarConverter::printChar(char c) {
    if (std::isprint(c)) {
        std::cout << "char: " << c << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}
void ScalarConverter::printInt(int i) {
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
    std::cout << "float: " << std::fixed << std::setprecision(1) << f<< "f";
    if (!(std::isinf(f) || std::isnan(f))) {
        std::cout << "f";
    }
    std::cout << std::endl;
}

void ScalarConverter::printDouble(double d) {
    std::cout << "double: " << d << std::endl;
}
