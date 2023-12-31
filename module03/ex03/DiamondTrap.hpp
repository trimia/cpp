#ifndef _DiamondTrap_HPP_
#define _DiamondTrap_HPP_

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class DiamondTrap : public ScavTrap, public FragTrap {
public    :
    DiamondTrap();

    DiamondTrap(std::string name);

    DiamondTrap(DiamondTrap const &obj);

    ~DiamondTrap();

    DiamondTrap &operator=(const DiamondTrap &obj);

    using ScavTrap::attack;

    void whoAmI();

private    :
    std::string _name;
    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
