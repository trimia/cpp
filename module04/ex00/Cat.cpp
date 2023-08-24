#include "Cat.hpp"

Cat::Cat()
{
    Animal::_type="Cat";
	std::cout << "Cat : Default Constructor Called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat : Destructor Called" << std::endl;
}

Cat::Cat(Cat const &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Cat	&Cat::operator= (const Cat &obj)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
	{
		//	this->attributes = obj.attributes;
		//	...
	}
	return (*this);
}

void Cat::makeSound() const {
//    Animal::makeSound();
    std::cout<<"meow"<<std::endl;
    std::system("say -v alice \"meoooow meoooow\"");

}
