#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() {
    this->ScavTrap::setName("");
    this->FragTrap::setHitPoints(this->FragTrap::getHitPoints());
    this->ScavTrap::setEnergyPoints(this->ScavTrap::getEnergyPoints());
    this->ScavTrap::setAttackDamage(this->ScavTrap::getAttackDamage());
    std::cout << "DiamondTrap : Default Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):_name(name) {
//    this->ScavTrap::setName("");
    this->FragTrap::setHitPoints(this->FragTrap::getHitPoints());
    this->ScavTrap::setEnergyPoints(this->ScavTrap::getEnergyPoints());
    this->ScavTrap::setAttackDamage(this->ScavTrap::getAttackDamage());
    ClapTrap::setName(ClapTrap::getName()+"_clap_name");
    std::cout << "DiamondTrap : Default Constructor Called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap : Destructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &obj) {
    std::cout << "Copy Constructor Called" << std::endl;
    if (this != &obj)
        *this = obj;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj) {
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this != &obj) {
        //	this->attributes = obj.attributes;
        //	...
    }
    return (*this);
}

void DiamondTrap::whoAmI() {

    std::cout<<ClapTrap::getName()<<" Who -- uh, me sir? "<< this->_name<<std::endl;

}

//DiamondTrap::DiamondTrap(const std::string &name, const std::string &name1, const std::string &name2) : ScavTrap(name),
//                                                                                                        FragTrap(name1),
//                                                                                                        name(name2) {}
