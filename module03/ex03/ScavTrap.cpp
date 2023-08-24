#include "ScavTrap.hpp"

//Borderlands *borderlands = new Borderlands();

ScavTrap::ScavTrap() {
    this->setName("");
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);

    std::cout << "ScavTrap : Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);

    std::cout << "ScavTrap : " << name << " : Constructor Called" << std::endl;
}


ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap : Destructor Called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &obj) : ClapTrap(obj) {
    std::cout << "Copy Constructor Called" << std::endl;
    if (this != &obj)
        *this = obj;
    std::cout << "Copy ScavTrap " << this->getName() << " has been constructed!" << std::endl;

}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj) {
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this != &obj) {
        this->_name = obj._name;
        this->_energyPoints = obj._energyPoints;
        this->_hitPoints = obj._hitPoints;
        this->_attackDamage = obj._attackDamage;
        //	this->attributes = obj.attributes;
        //	...
    }
    return (*this);
}

void ScavTrap::guardGate() {

    std::cout << "ScavTrap is now in Gatekeeper mode." << std::endl;

}

void ScavTrap::attack(std::string target) {

    if (this->_energyPoints > 1 && this->_hitPoints > 1) {

        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage
                  << " points of damage!" << std::endl << "\"Stop me before I kill again, except don't!\"" << std::endl;
        this->_energyPoints--;
        for (int i = 0; i < borderlands->_x; i++) {
            ClapTrap *temp;
            temp = borderlands->getBorderlands(i);
            if (target.compare(temp->getName()) == 0) {
                temp->takeDamage(this->_attackDamage);
            }
        }
    }

}
