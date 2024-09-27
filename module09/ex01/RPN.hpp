#ifndef RPN_HPP
#define RPN_HPP
#include "include.h"
#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include <ctype.h>
#include <sstream>
#include <list>

class RPN {
private:
    std::list<int> _rpn;
public:
    RPN();
    ~RPN();
    void calculate(std::string rpn);
    void printResult();
};

#endif