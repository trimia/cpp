#ifndef _WrongAnimal_HPP_
#define _WrongAnimal_HPP_

#include <iostream>

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class WrongAnimal {
public    :
    WrongAnimal();

    WrongAnimal(std::string wrongType);

    WrongAnimal(WrongAnimal const &obj);

    virtual ~WrongAnimal();

    WrongAnimal &operator=(const WrongAnimal &obj);

    const std::string &getWrongType() const;

    virtual void makeSound() const;

protected    :
    std::string _wrongType;

    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
