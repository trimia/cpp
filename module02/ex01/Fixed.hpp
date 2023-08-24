#ifndef _Fixed_HPP_
#define _Fixed_HPP_

#include <iostream>
#include <cmath>

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class Fixed {
public    :
    Fixed();

    Fixed(Fixed const &obj);

    Fixed(const int nb);

    Fixed(const float nb);

    ~Fixed();

    Fixed &operator=(const Fixed &obj);

    int getRawBits(void) const;

    void setRawBits(int const raw);

    float toFloat(void) const;

    int toInt(void) const;

    bool operator==(const Fixed &rhs) const;

    bool operator!=(const Fixed &rhs) const;

//    friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

private    :
    int _nb;
    static const int _nb_fractionalbits = 8;
    //	DataType	attributes.
};
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif

