#ifndef _Ice_HPP_
#define _Ice_HPP_

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class Ice :public AMateria{
public    :
    Ice();

    Ice(Ice const &obj);

    ~Ice();

    Ice &operator=(const Ice &obj);

    virtual AMateria *clone() const;

    virtual void use(ICharacter &target);

//    const std::string &getType() const;

private    :
    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
