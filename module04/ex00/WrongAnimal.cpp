#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal : Default Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string wrongType) : _wrongType(wrongType) {
    std::cout << "WrongAnimal: "<<wrongType<<" Constructor Called" << std::endl;

}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal : Destructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

WrongAnimal	&WrongAnimal::operator= (const WrongAnimal &obj)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
	{
		//	this->attributes = obj.attributes;
		//	...
	}
	return (*this);
}

const std::string &WrongAnimal::getWrongType() const {
    return _wrongType;
}

void WrongAnimal::makeSound() const {
    std::cout<<"Frau Blucher"<<std::endl;
    std::system("say -v anna \"Frau Blücher\"");


}
