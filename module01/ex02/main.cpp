//
// Created by Matteo Mariani on 13/08/23.
//
#include "string"
#include "iostream"

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR;
    /*
     *reference could not be declared without initialization and not need
     * the & operator to pass the address to it
     */
    std::string &stringREF = str;
    stringPTR = &str;

    std::cout << "memory address of the string " << &str << std::endl <<
              "memory address of the pointer " << &stringPTR << std::endl <<
              "memory address of the reference " << &stringREF << "\n" << std::endl;
    std::cout << "value  of the string " << str << std::endl <<
              "value  of the pointer " << *stringPTR << std::endl <<
              "value  of the reference " << stringREF << std::endl;


}
