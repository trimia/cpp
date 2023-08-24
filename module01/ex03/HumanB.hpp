//
// Created by Matteo Mariani on 13/08/23.
//

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
    std::string _name;
    Weapon *_weapon;
public:
    HumanB();

    ~HumanB();


    HumanB(const std::string &name);

    void attack();

    void setWeapon(Weapon &weapon);

};


#endif //CPP0_4_HUMANB_HPP
