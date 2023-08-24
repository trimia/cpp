/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:02:15 by mmariani          #+#    #+#             */
/*   Updated: 2023/08/10 15:02:18 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "iostream"
#include "iomanip"
#include "locale"
#include "array"
#include "string"

class PhoneBook {

private:
    Contact contact[8];

    std::string reduceStr(std::string str);

public:

    PhoneBook(void);

    PhoneBook(const std::array<Contact, 8> &contact);

    ~PhoneBook();

    void addNewContact(PhoneBook *phoneBook);

    void searchContact(PhoneBook *phoneBook);

};


#endif //CPP0_4_PHONEBOOK_H
