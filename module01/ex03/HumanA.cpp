//
// Created by Matteo Mariani on 13/08/23.
//

#include "HumanA.hpp"

void HumanA::attack() {
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}


HumanA::~HumanA() {

}

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon) {}


