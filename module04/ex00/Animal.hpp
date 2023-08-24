#ifndef _Animal_HPP_
#define _Animal_HPP_

#include <iostream>
#include "string"
#include "cstdlib"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class Animal {
public    :
    Animal();

    Animal(std::string type);


    Animal(Animal const &obj);

    ~Animal();

    Animal &operator=(const Animal &obj);

//   virtual void makeSound();
    virtual void makeSound() const;

    const std::string &getType() const;

protected    :
    std::string _type;
    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
