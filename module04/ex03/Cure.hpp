#ifndef _Cure_HPP_
#define _Cure_HPP_

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class Cure :public AMateria{
public    :
    Cure();

    Cure(Cure const &obj);

    ~Cure();

    Cure &operator=(const Cure &obj);
    virtual AMateria *clone() const;
    virtual void use(ICharacter& target);
//    const std::string &getType() const;

private    :
    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
