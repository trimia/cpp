#ifndef _FragTrap_HPP_
#define _FragTrap_HPP_

#include <iostream>
#include "ClapTrap.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class FragTrap : virtual public ClapTrap {
public    :
    FragTrap();

    FragTrap(std::string name);


    FragTrap(FragTrap const &obj);

    ~FragTrap();

    FragTrap &operator=(const FragTrap &obj);

    void highFivesGuys(void);

private    :
    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
