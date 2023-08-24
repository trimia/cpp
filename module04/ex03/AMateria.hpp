#ifndef _AMateria_HPP_
#define _AMateria_HPP_

#include <iostream>
#include "Character.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //
class ICharacter;
class AMateria {
public    :
    AMateria();

    AMateria(std::string const &type);

    AMateria(AMateria const &obj);

    virtual ~AMateria();

    AMateria &operator=(const AMateria &obj);

    virtual AMateria *clone() const = 0;

    virtual void use(ICharacter &target);

    const std::string &getType() const;

    void setType(const std::string &type);

protected    :
    std::string _type;
    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
