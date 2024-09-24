#include "RPN.hpp"

RPN::RPN() {
}

RPN::~RPN() {
}
//think if would insert an enum to substitute the if else with switch case
void RPN::calculate(std::string rpn) {
    std::istringstream isstr(rpn);
    std::string token;
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
            _rpn.push_back(std::stoi(token));
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
