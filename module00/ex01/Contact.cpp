/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:02:38 by mmariani          #+#    #+#             */
/*   Updated: 2023/08/10 15:02:39 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "string"


Contact::Contact(void) {
    this->first_name.assign("");
    this->last_name.assign("");
    this->nickname.assign("");
    this->phone_number.assign("");
    this->darkest_secret.assign("");
}

void Contact::setValue(std::string value, type eNum) {
    if (eNum == FIRST_NAME) {
        first_name = value;
    } else if (eNum == LAST_NAME) {
        Contact::last_name = value;
    } else if (eNum == NICKNAME) {
        Contact::nickname = value;
    } else if (eNum == PHONE_NUMBER) {
        Contact::phone_number = value;
    } else if (eNum == DARKEST_SECRET) {
        Contact::darkest_secret = value;
    }
}


const std::string &Contact::getFirstName() const {
    return first_name;
}

const std::string &Contact::getLastName() const {
    return last_name;
}

const std::string &Contact::getNickname() const {
    return nickname;
}

const std::string &Contact::getPhoneNumber() const {
    return phone_number;
}

const std::string &Contact::getDarkestSecret() const {
    return darkest_secret;
}

Contact::~Contact() {}

