#include "Dog.hpp"

Dog::Dog() {
    _brain = new Brain();
    Animal::type = "Dog";
    std::cout << "Dog : Default Constructor Called" << std::endl;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog : Destructor Called" << std::endl;
}

Dog::Dog(Dog const &obj) {
    std::cout << "Copy Constructor Called" << std::endl;
    if (this != &obj){
        *this = obj;
        this->_brain=new Brain(*obj.getBrain());
    }
}

Dog &Dog::operator=(const Dog &obj) {
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this != &obj) {
        this->_brain = obj._brain;
        this->type = obj.type;
        //	this->attributes = obj.attributes;
        //	...
    }
    return (*this);
}

void Dog::makeSound() const {
//    Animal::makeSound();
    std::cout << "bau" << std::endl;
    std::system("say -v luca \"wof wof\"");

}

void Dog::setIdeas(std::string idea) {
    _brain->setIdea(idea, _brain->getIndex());
}

Brain *Dog::getBrain() const {
    return _brain;
}
