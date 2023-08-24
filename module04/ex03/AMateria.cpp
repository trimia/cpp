#include "AMateria.hpp"

AMateria::AMateria() {
    this->_type="";
    std::cout << "AMateria : Default Constructor Called" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "AMateria : Destructor Called" << std::endl;
}

AMateria::AMateria(AMateria const &obj) {
    std::cout << "Copy Constructor Called" << std::endl;
    if (this != &obj)
        *this = obj;
}

AMateria &AMateria::operator=(const AMateria &obj) {
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this != &obj) {
        this->_type=obj._type;
        //	this->attributes = obj.attributes;
        //	...
    }
    return (*this);
}

const std::string &AMateria::getType() const {
    return _type;
}

AMateria::AMateria(const std::string &type) {
    std::cout << "Type constructor called" << std::endl;

    this->_type=type;

}

void AMateria::use(ICharacter &target) {
    (void)target;
}

void AMateria::setType(const std::string &type) {
    _type = type;
}
