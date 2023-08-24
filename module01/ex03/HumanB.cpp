//
// Created by Matteo Mariani on 13/08/23.
//

#include "HumanB.hpp"

HumanB::HumanB() {}

HumanB::~HumanB() {

}

HumanB::HumanB(const std::string &name) : _name(name) {}

void HumanB::attack() {
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;

}


