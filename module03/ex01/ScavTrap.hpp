#ifndef _ScavTrap_HPP_
#define _ScavTrap_HPP_

#include <iostream>
#include "ClapTrap.hpp"
//#include "Borderlands.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class ScavTrap : public ClapTrap {
public    :
    ScavTrap();

    ScavTrap(std::string name);

    ScavTrap(ScavTrap const &obj);

    ~ScavTrap();
//    ClapTrap borderlands;
    using ClapTrap::getHitPoints;

    ScavTrap &operator=(const ScavTrap &obj);

    void attack(std::string target);

    void guardGate();

private    :
    std::string _name;
//    int _hitPoints, _energyPoints, _attackDamage;


    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
