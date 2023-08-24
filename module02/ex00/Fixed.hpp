#ifndef _Fixed_HPP_
#define _Fixed_HPP_

#include <iostream>

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class Fixed {
public    :
    Fixed();

    Fixed(Fixed const &obj);


    ~Fixed();

    Fixed &operator=(const Fixed &obj);

    int getRawBits(void) const;

    void setRawBits(int const raw);


private    :
    int _nb;
    static const int _nb_fractionalbits = 8;
    //	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
