#include "Cat.hpp"

Cat::Cat() {
    _brain=new Brain();
    Animal::type = "Cat";
    std::cout << "Cat : Default Constructor Called" << std::endl;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat : Destructor Called" << std::endl;
}

Cat::Cat(Cat const &obj) {
    std::cout << "Copy Constructor Called" << std::endl;
    if (this != &obj){
        *this = obj;
        this->_brain=new Brain(*obj.getBrain());
    }
}

Cat &Cat::operator=(const Cat &obj) {
    std::cout << "cat :Copy Assignment Operator Called" << std::endl;
    if (this != &obj) {
        this->_brain=obj._brain;
//        for(int i=0;i<100;i++)
//            this->_brain[i]=obj._brain[i];
        this->type=obj.type;
        //	this->attributes = obj.attributes;
        //	...
    }
    return (*this);
}

void Cat::makeSound() const {
//    Animal::makeSound();
    std::cout << "meow" << std::endl;
    std::system("say -v alice \"meoooow meoooow\"");

}

void Cat::setIdeas(std::string idea) {
//    std::cout<<"CAt: index "<<_brain->getIndex()<<std::endl;

    _brain->setIdea(idea,_brain->getIndex());
//    _brain->setIndex(1);
}

Brain *Cat::getBrain() const {
    return _brain;
}
