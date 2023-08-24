#include "Animal.hpp"

Animal::Animal()
{
    _type="how do you feel?";
	std::cout << "Animal : Default Constructor Called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
    std::cout << "Animal: "<<type<<" Constructor Called" << std::endl;

}

Animal::~Animal()
{
	std::cout << "Animal : Destructor Called" << std::endl;
}

Animal::Animal(Animal const &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Animal	&Animal::operator= (const Animal &obj)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
	{
		//	this->attributes = obj.attributes;
		//	...
	}
	return (*this);
}

void Animal::makeSound() const {
    std::cout<<"what sound does a crocodile make?"<<std::endl;
    std::system("say -v alice \"what sound does a crocodile make?\"");


}

const std::string &Animal::getType() const {
    return _type;
}
