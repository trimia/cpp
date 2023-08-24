#include "Cure.hpp"

Cure::Cure() {
    AMateria::_type = "cure";
    std::cout << "Cure : Default Constructor Called" << std::endl;
}

Cure::~Cure() {
    std::cout << "Cure : Destructor Called" << std::endl;
}

Cure::Cure(Cure const &obj) {
    std::cout << "Copy Constructor Called" << std::endl;
    if (this != &obj)
        *this = obj;
}

Cure &Cure::operator=(const Cure &obj) {
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this != &obj) {
        this->_type = obj._type;
        //	this->attributes = obj.attributes;
        //	...
    }
    return (*this);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;


//    AMateria::use(target);
}

//const std::string &Cure::getType() const {
//    return AMateria::getType();
//}

AMateria *Cure::clone() const {
//    Cure	*cure = new Cure();
//    return cure;
//    this =new Cure();
    return new Cure();
}
