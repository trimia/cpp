#ifndef _Character_HPP_
#define _Character_HPP_

#include <iostream>
#include "ICharacter.hpp"
// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class Character :public ICharacter{
public    :
    Character();
    Character(std::string name);

    const std::string &getName() const ;

    void equip(AMateria *m) ;

    void unequip(int idx) ;

    void use(int idx, ICharacter &target) ;

    Character(Character const &obj);

    ~Character();

    Character &operator=(const Character &obj);
protected:
    std::string name;
    AMateria *materia[4];

private    :
    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
