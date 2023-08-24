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

    ~WrongAnimal();

    WrongAnimal &operator=(const WrongAnimal &obj);

    virtual void makeSound() const;
    const std::string &getWrongType() const;

private    :
    std::string _wrongType;

    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
