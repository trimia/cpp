#include "Brain.hpp"

Brain::Brain() {
    this->_index = 0;
//    for (int i = 0; i < 100; i++)
//        this->_ideas[i] = "";
    std::cout << "Brain : Default Constructor Called" << std::endl;
}

Brain::~Brain() {
//    delete[] this->_ideas
//    for (int i = 0; i < 100; i++)
//        this->_ideas[i] = (std::string) NULL;
    std::cout << "Brain : Destructor Called" << std::endl;
}

Brain::Brain(Brain const &obj) {
    std::cout << "Copy Constructor Called" << std::endl;
    if (this != &obj)
        *this = obj;
}

Brain &Brain::operator=(const Brain &obj) {
    std::cout << "Brain: Copy Assignment Operator Called" << std::endl;
    if (this != &obj) {
        for(int i =0;i<100;i++)
            this->_ideas[i]=obj._ideas[i];
        this->_index=obj._index;
        //	this->attributes = obj.attributes;
        //	...
    }
    return (*this);
}

int Brain::getIndex() const {
    return this->_index;
}

void Brain::setIndex(int index) {
    this->_index += index;
}

void Brain::setIdea(std::string idea, int index) {
//    std::cout << "Brain: index " << index << std::endl;
    this->_ideas[index].assign(idea);
    this->_ideas[index]=idea;
    this->_index += 1;
    if (index >= 100) {
         this->_index=0;

        std::cout << "your brain is too small for all this information \"I feel like an idiot now.\"" << std::endl;
//        std::cout << "Brain: index " << index << std::endl;
    }

}

std::string Brain::getIdea(int index) {
    if(index>100)
        return "";
//    std::cout<<"Brain: index: "<<index<<std::endl;
//    std::cout<<"Brain: idea: "<< this->_ideas[index]<<std::endl;
    return this->_ideas[index];

}
