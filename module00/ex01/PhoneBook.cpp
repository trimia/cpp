/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:02:25 by mmariani          #+#    #+#             */
/*   Updated: 2023/08/10 15:02:26 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {}

int x = 0;

void PhoneBook::addNewContact(PhoneBook *phoneBook) {
    Contact newCon;
    std::string str = "";
    int i = 0;
    std::cout << "insert one and press start _name, last _name, nickname, phone number, darkest secret in this order."
              << std::endl;
    while (i < 5) {
        label:
        getline(std::cin, str);
        if (str.empty()) {
            goto label;
        }
        phoneBook->contact[x].setValue(str, (type) i);
        i++;
    }
    x += 1;
    if (x == 8)
        x = 0;
    std::cout << "contact succesfully added type ADD, SEARCH or EXIT" << std::endl;
}

void PhoneBook::searchContact(PhoneBook *phoneBook) {
    int n;
    int i = 0;
    while (!phoneBook->contact[i].getFirstName().empty()) {
        std::cout << std::setw(10) << i << "|" << std::setw(10) << reduceStr(phoneBook->contact[i].getFirstName())
                  << "|" <<
                  std::setw(10) << reduceStr(phoneBook->contact[i].getLastName()) << "|" <<
                  std::setw(10) << reduceStr(phoneBook->contact[i].getNickname()) << "|" << std::endl;
        i += 1;
    }
    std::cout << "insert position of contact you want to display" << std::endl;
    while (true) {
        std::cin >> n;
        if (std::cin.fail()) {
            std::cout << "only number are accepted" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        } else
            break;
    }
    if (n >= 0 && n >= 8) {
        std::cout << "number exceed phonebook memory" << std::endl;
        return;
    } else if (phoneBook->contact[n].getFirstName().empty()) {
        std::cout << "not yet registered" << std::endl;
        return;
    } else {
        std::cout << phoneBook->contact[n].getFirstName() << std::endl <<
                  phoneBook->contact[n].getLastName() << std::endl <<
                  phoneBook->contact[n].getNickname() << std::endl <<
                  phoneBook->contact[n].getPhoneNumber() << std::endl <<
                  phoneBook->contact[n].getDarkestSecret() << std::endl;
    }
    std::cout << "contact displayed type ADD, SEARCH or EXIT" << std::endl;
}


PhoneBook::~PhoneBook() {

}

std::string PhoneBook::reduceStr(std::string str) {
    if (str.length() <= 10)
        return (str);
    return (str.substr(0, 9) + ".");
}



