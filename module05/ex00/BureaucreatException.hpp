//
// Created by mmariani on 7/2/24.
//


#ifndef BUREAUCRATEXCEPTION_HPP
#define BUREAUCRATEXCEPTION_HPP

#include <exception>

class GradeTooHighException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Grade too high";
    }
};

class GradeTooLowException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Grade too low";
    }
};

#endif