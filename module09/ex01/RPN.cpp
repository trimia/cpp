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
    int again = 0;
    while (std::getline(isstr, token, ' ')) {
        if(token=="(" || token==")" || token=="[" || token=="]" || token=="{" || token=="}") {
            std::cout << "Error: invalid RPN sequence" << std::endl;
            return;
        }
        if (token.size() > 1) {
            std::cout << "Error: invalid RPN sequence" << std::endl;
            return;
        }
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (again) {
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
            again=1;
        } else {
            _rpn.push_back(toInt(token));
            again=0;
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