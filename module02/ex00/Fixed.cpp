#include "Fixed.hpp"

Fixed::Fixed() : _nb(0) {
//    this->_nb=0;
    std::cout << "Fixed : Default Constructor Called" << std::endl;
}


Fixed::~Fixed() {
    std::cout << "Fixed : Destructor Called" << std::endl;
}

Fixed::Fixed(Fixed const &obj) {
    std::cout << "Copy Constructor Called" << std::endl;
    if (this != &obj)
        *this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj) {
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this != &obj) {
        this->_nb = obj._nb;

//        this->_nb = obj.getRawBits();

    }
    return (*this);
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_nb;
}

void Fixed::setRawBits(const int raw) {
    this->_nb = raw;

}
