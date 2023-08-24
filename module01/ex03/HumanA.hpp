//
// Created by Matteo Mariani on 13/08/23.
//

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
//#include "iostream"
//#include "string"

class HumanA {
private:
    std::string _name;
    Weapon &_weapon;
public:

    HumanA(const std::string &name, Weapon &weapon);

    ~HumanA();


    void attack();
};


#endif //CPP0_4_HUMANA_HPP
