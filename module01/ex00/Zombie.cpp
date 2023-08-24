//
// Created by Matteo Mariani on 12/08/23.
//

#include "Zombie.hpp"

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << this->name << ": oh no! not again" << std::endl;
}

Zombie::Zombie(std::string name) {
    std::cout<<name<<": IT... COULD... WORK!"<<std::endl;
    this->name = name;
    return;
}
