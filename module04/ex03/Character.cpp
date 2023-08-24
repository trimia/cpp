#include "Character.hpp"

Character::Character() {
    for (int i = 0; i < 4; i++)
        materia[i] = NULL;
    std::cout << "Character : Default Constructor Called" << std::endl;
}

Character::Character(std::string name) {
    this->name = name;
    for (int i = 0; i < 4; i++)
        materia[i] = NULL;
    std::cout << name << " Character constructor called" << std::endl;


}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        if (materia[i])
            delete materia[i];
    std::cout << "Character : Destructor Called" << std::endl;
}

Character::Character(Character const &obj) {
    std::cout << "Copy Constructor Called" << std::endl;
    if (this != &obj) {
        *this = obj;
        this->name = obj.getName();
    }
}

Character &Character::operator=(const Character &obj) {
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this != &obj) {
        for (int i = 0; i < 4; i++)
        {
            if (this->materia[i])
            {
                delete this->materia[i];
                this->materia[i] = NULL;
            }
            if (obj.materia[i])
                this->materia[i] = obj.materia[i]->clone();
        }
        name.assign(obj.getName());
        //	this->attributes = obj.attributes;
        //	...
    }
    return (*this);
}

const std::string &Character::getName() const {
    return name;
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++)
        if (!materia[i])
        {
            materia[i] = m;
            return ;
        }
}

void Character::unequip(int idx) {
    std::cout << materia[idx]->getType() << " unequipped at index " << idx << std::endl;
    materia[idx] = NULL;


}

void Character::use(int idx, ICharacter &target) {
    if (materia[idx])
        materia[idx]->use(target);
    else
        std::cout << "Materia doesn't exist" << std::endl;

}
