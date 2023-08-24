#include "Fixed.hpp"


#include <iostream>
#include "iomanip"

int main(void) {
    Fixed a;
    Fixed c;
    Fixed const b(Fixed(5.05f) * Fixed(2));
//    printf("\nboooooo %d\n", b.getRawBits());
//    printf("\nbaaaaaa %f\n", b.toFloat());
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    c = a * b;
    std::cout << std::endl << c << std::endl;

    Fixed d(4), e(2), f;
    f = d / e;
    std::cout << std::endl << "divisione " << f << std::endl;


    return 0;
}