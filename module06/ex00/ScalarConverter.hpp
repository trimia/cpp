#ifndef _ScalarConverter_HPP_
#define _ScalarConverter_HPP_

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class ScalarConverter {
public :
    ScalarConverter();

    ScalarConverter(ScalarConverter const &obj);

    ~ScalarConverter();

    ScalarConverter &operator=(const ScalarConverter &obj);

    void convert(const std::string &literal);

    void printChar(char c);

    void printInt(int i);

    void printFloat(float f);

    void printDouble(double d);

private :
    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
