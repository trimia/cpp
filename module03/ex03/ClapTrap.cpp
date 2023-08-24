#include "ClapTrap.hpp"
Borderlands *ClapTrap::borderlands = new Borderlands();

ClapTrap::ClapTrap() {
    this->_name = "";
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;

    borderlands->fillArray(this);
    std::cout << "ClapTrap : Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
    std::cout<<"ClapTrap : " << name << "Constructor Called" << std::endl;
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
//    borderlands->checkResizeArray();

    borderlands->fillArray(this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap : Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &obj) {
    std::cout << "Copy Constructor Called" << std::endl;
    if (this != &obj)
        *this = obj;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj) {
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this != &obj) {
        this->_hitPoints = obj._hitPoints;
        this->_energyPoints = obj._energyPoints;
        this->_name = obj._name;
        this->_attackDamage = obj._attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string &target) {
    /*
     * if (this->_energyPoints > 1 && this->_hitPoints > 1) {
     *   std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing" << this->_attackDamage
     *            << " points of damage!" << std::endl << "\"That looks like it hurts!\"" << std::endl;
     * this->_energyPoints--;
     *ClapTrap pippo(target);
     *pippo.takeDamage(this->_attackDamage);
     *}
     */
    if (this->_energyPoints > 1 && this->_hitPoints > 1) {

        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage
                  << " points of damage!" << std::endl << "\"That looks like it hurts!\"" << std::endl;
        this->_energyPoints--;
        for (int i = 0; i < borderlands->_x; i++) {
//            ClapTrap *temp;
//            temp=borderlands.getBorderlands(i);
            if (target.compare(borderlands->getBorderlands(i)->getName()) == 0) {
                borderlands->getBorderlands(i)->takeDamage(this->_attackDamage);
            }
        }
    }

}

void ClapTrap::takeDamage(unsigned int amount) {
    if (amount > this->_hitPoints) {
        this->_hitPoints = 0;
    } else {
        this->_hitPoints -= amount;
    }
    std::cout << this->_name << " lose " << amount << " of hit points " << std::endl
              << "\"Health! Ooo, what flavor is red?\"" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints > 1 && this->_hitPoints > 1) {
        std::cout << "ClapTrap " << this->_name << " is repairing himself, healing " << amount << " of hit points"
                  << std::endl
                  << "\"Where'd all my bullets go?\" \"Bullets are dumb.\" \"Who needs ammo anyway, am I right?\""
                  << std::endl;
        this->_energyPoints--;
//        if (this->_hitPoints + amount > 10)
//            this->_hitPoints = 10;
//        else
            this->_hitPoints += amount;
    } else if (this->_hitPoints == 0)
        std::cout << "hit points :" << this->_hitPoints << " \"Argh arghargh death gurgle gurglegurgle urgh... death.\""
                  << std::endl;
    else
        std::cout << "energy points " << this->_energyPoints
                  << "\"Oh. My. God. What if I'm like... a fish? And, if I'm not moving... I stop breathing? AND THEN I'LL DIE! HELP"
                  << std::endl;
}


void ClapTrap::setName(const std::string &name) {
    ClapTrap::_name = name;
}

void ClapTrap::setHitPoints(int hitPoints) {
    ClapTrap::_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints) {
    ClapTrap::_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage) {
    ClapTrap::_attackDamage = attackDamage;
}

const std::string &ClapTrap::getName() const {
    return _name;
}

int ClapTrap::getHitPoints() const {
    return _hitPoints;
}

int ClapTrap::getEnergyPoints() const {
    return _energyPoints;
}

int ClapTrap::getAttackDamage() const {
    return _attackDamage;
}




