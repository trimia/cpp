#include "Ice.hpp"

Ice::Ice()
{
    AMateria::_type="ice";
	std::cout << "Ice : Default Constructor Called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice : Destructor Called" << std::endl;
}

Ice::Ice(Ice const &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Ice	&Ice::operator= (const Ice &obj)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
	{
        this->_type=obj._type;
		//	this->attributes = obj.attributes;
		//	...
	}
	return (*this);
}

void Ice::use(ICharacter &target) {
    std::cout<<"* shoots an ice bolt at" <<target.getName()<< " *"<<std::endl;
//    AMateria::use(target);
}

//const std::string &Ice::getType() const {
//    return AMateria::getType();
//}

AMateria *Ice::clone() const {
//    Ice *ice=new Ice;
//    return ice;
    return new Ice();
}
