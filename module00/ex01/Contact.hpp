/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:02:34 by mmariani          #+#    #+#             */
/*   Updated: 2023/08/10 15:02:35 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "string"
//#include "Contact.hpp"
#include "iostream"
#include "iomanip"
#include "locale"
#include "array"

//The contact fields are: first _name, last _name, nickname, phone number, and
//darkest secret. A saved contact can’t have empty fields.
enum type {
    FIRST_NAME,
    LAST_NAME,
    NICKNAME,
    PHONE_NUMBER,
    DARKEST_SECRET
};

class Contact {

private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
public:
    Contact(void);

    ~Contact();

    void setValue(std::string value, type eNum);

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const std::string &getNickname() const;

    const std::string &getPhoneNumber() const;

    const std::string &getDarkestSecret() const;

};


#endif //CPP0_4_CONTACT_H
