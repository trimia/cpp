#ifndef Borderlands_HPP
#define Borderlands_HPP

#include <iostream>
#include "ClapTrap.hpp"
class ClapTrap;

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class Borderlands {
public    :
    Borderlands();

    Borderlands(Borderlands const &obj);

    ~Borderlands();

    Borderlands &operator=(const Borderlands &obj);

    void checkResizeArray();

//    void fillArray(ClapTrap *clapTrap);
    void fillArray(ClapTrap *clapTrap);

    void setBorderlands(ClapTrap **borderlands);

//    ClapTrap *_borderlands[10];
    ClapTrap **_borderlands;
    static int _x;


private    :
    static int _size;

    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
