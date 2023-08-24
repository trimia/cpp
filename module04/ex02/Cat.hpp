#ifndef _Cat_HPP_
#define _Cat_HPP_

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class Cat : public Animal {
public    :
    Cat();

    Cat(Cat const &obj);

    ~Cat();

    Cat &operator=(const Cat &obj);

    void makeSound() const;
    void setIdeas(std::string idea);

    Brain *getBrain() const;

private    :
    Brain *_brain;

    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
