#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    setName("");
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);

	std::cout << "FragTrap : Default Constructor Called" << std::endl;
}

FragTrap::FragTrap(std::string name)  {
    setName(name);
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout<<name<<" ScavTrap Constructor Called"<<std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap : Destructor Called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

FragTrap	&FragTrap::operator= (const FragTrap &obj)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
	{
        this->_name = obj._name;
        this->_energyPoints = obj._energyPoints;
        this->_hitPoints = obj._hitPoints;
        this->_attackDamage = obj._attackDamage;

        //	this->attributes = obj.attributes;
		//	...
	}
	return (*this);
}

void FragTrap::highFivesGuys(void) {

    std::cout<<this->getName()<<" clap your hands and says: \"Secret handshake!\""<<std::endl;

}
