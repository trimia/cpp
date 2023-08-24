#ifndef _Animal_HPP_
#define _Animal_HPP_

#include <iostream>
#include "string"
#include "cstdlib"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class Animal {
public:
    Animal();

    Animal(std::string type);
public    :


    Animal(Animal const &obj);

    virtual ~Animal();

    Animal &operator=(const Animal &obj);

//   virtual void makeSound();
    virtual void makeSound() const=0;

    const std::string &getType() const;

protected    :
    std::string type;
    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
