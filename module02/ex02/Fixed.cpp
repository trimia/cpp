#include "Fixed.hpp"

Fixed::Fixed() : _nb(0) {
//    this->_nb=0;
    std::cout << "Fixed : Default Constructor Called" << std::endl;
}

Fixed::Fixed(const int nb) : _nb(nb << this->_nb_fractionalbits) {
    std::cout << "Fixed : Int conversion Constructor Called" << std::endl;
}

Fixed::Fixed(const float nb) : _nb(roundf(nb * (1 << this->_nb_fractionalbits))) {
    std::cout << "Fixed : Float conversion Constructor Called" << std::endl;
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
//        this->_nb=obj.getRawBits();
        //	this->attributes = obj.attributes;
        //	...
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

float Fixed::toFloat(void) const {
    float c_fl;
    c_fl = (float) this->_nb / (1 << this->_nb_fractionalbits);
    return c_fl;
}

int Fixed::toInt(void) const {
    int c_i;
    c_i = this->_nb >> this->_nb_fractionalbits;
    return c_i;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}


bool Fixed::operator<(const Fixed &rhs) const {
    return _nb < rhs._nb;
}

bool Fixed::operator>(const Fixed &rhs) const {
    return rhs < *this;
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return !(rhs < *this);
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return !(*this < rhs);
}

bool Fixed::operator==(const Fixed &rhs) const {
    return _nb == rhs._nb;
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return !(rhs == *this);
}

Fixed Fixed::operator+(const Fixed &src) {
    Fixed ret;
    ret.setRawBits(this->_nb + src.getRawBits());
    return ret;
}

Fixed Fixed::operator-(const Fixed &src) {
    Fixed ret;
    ret.setRawBits(this->_nb - src.getRawBits());
    return ret;
}

Fixed Fixed::operator*(const Fixed &src) {
    Fixed result(*this);
    long hBit;
    long lBit;

    hBit = (long) this->getRawBits();
    lBit = (long) src.getRawBits();

    result.setRawBits((hBit * lBit) >> Fixed::_nb_fractionalbits);
    return (result);
}

Fixed Fixed::operator/(const Fixed &src) {
    Fixed ret;
    ret.setRawBits((this->_nb / src._nb) << _nb_fractionalbits);
    return ret;
}

//PREincrement
Fixed Fixed::operator++(int) {
    Fixed ret(*this);
    this->_nb += 1;
    return ret;
}

//POSTincrement
Fixed &Fixed::operator++() {
    this->_nb+=1 ;
    return *this;
}

//POSTdecrement
Fixed Fixed::operator--(int) {
    Fixed ret(*this);
    this->_nb -= 1;
    return ret;
}

//PREdecrement
Fixed &Fixed::operator--() {
    this->_nb -= 1;
    return *this;
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2) {

    return n1<n2?n1:n2;
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2) {
    return n1>n2?n1:n2;
}

const Fixed &Fixed::min(const Fixed &n1, const Fixed &n2) {
    return n1<n2?n1:n2;
}

const Fixed &Fixed::max(const Fixed &n1, const Fixed &n2) {
    return n1>n2?n1:n2;
}

