#pragma once

#include <iostream>
#include "ClapTrap.hpp"

// ******************************************************** //

// ****************************************************** //
//                         CLASSES                         //
class ClapTrap;

class Borderlands {
public    :
    Borderlands();

    Borderlands(Borderlands const &obj);

    ~Borderlands();

    Borderlands &operator=(const Borderlands &obj);

    void checkResizeArray();

//    void fillArray(ClapTrap *clapTrap);
    void fillArray(ClapTrap *clapTrap);

    static void setSize(int size);

    static void setX(int x);

//    static void setBorderlands(ClapTrap **borderlands);
//    void setBorderlands(ClapTrap *borderlands);
//    void setBorderlands(ClapTrap *borderlands);

    ClapTrap *getBorderlands(int i);

//    ClapTrap *_borderlands[10];
//    ClapTrap **_borderlands;
    static int _x;


private    :
    static int _size;
    ClapTrap **_borderlands;

    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //
