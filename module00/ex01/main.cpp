//
// Created by Matteo Mariani on 10/08/23.
//
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main() {
    std::string str;
    std::cout << "insert command (ADD,SEARCH,EXIT)" << std::endl;
    PhoneBook notes;
    do {
        std::getline(std::cin, str);
        if (str.compare("ADD") == 0) {
            notes.addNewContact(&notes);
        } else if (str.compare("SEARCH") == 0)
            notes.searchContact(&notes);
        }
        while (str.compare("EXIT") != 0);
    }