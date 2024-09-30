#include "RPN.hpp"

RPN::RPN() {
}

RPN::~RPN() {
}
int toInt(std::string str)
{
    int number=0;
    char *p=NULL;
    number=(int)std::strtol(str.c_str(), &p, 10);
    if(*p!='\0')
        throw std::invalid_argument("toInt: invalid number");
    return number;
}

void RPN::calculate(std::string rpn) {
    std::istringstream isstr(rpn);
    std::string token;
    while (std::getline(isstr, token, ' ')) {
        if(token=="(" || token==")" || token=="[" || token=="]" || token=="{" || token=="}") {
            throw std::invalid_argument("Error: invalid RPN sequence");
        }
        if (token.size() > 1) {
            throw std::invalid_argument("Error: invalid RPN sequence");
        }
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (_rpn.size() < 2) {
                throw std::invalid_argument("Error: invalid RPN sequence");
            }
            int a = _rpn.back();
            _rpn.pop_back();
            int b = _rpn.back();
            _rpn.pop_back();
            if (token == "+") {
                _rpn.push_back(b + a);
            } else if (token == "-") {
                _rpn.push_back(b - a);
            } else if (token == "*") {
                _rpn.push_back(b * a);
            } else if (token == "/") {
                _rpn.push_back(b / a);
            }
        } else {
            _rpn.push_back(toInt(token));
        }
    }
    printResult();
}

void RPN::printResult() {
    if (_rpn.size() != 1) {
        std::cout << "Error: invalid RPN sequence" << std::endl;
        return;
    }
    std::cout << _rpn.front() << std::endl;
}