#ifndef _WrongCat_HPP_
#define _WrongCat_HPP_

#include <iostream>
#include "WrongAnimal.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class WrongCat :public WrongAnimal{
public    :
    WrongCat();

    WrongCat(WrongCat const &obj);

    ~WrongCat();

    WrongCat &operator=(const WrongCat &obj);

    void makeSound() const;


private    :
    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
