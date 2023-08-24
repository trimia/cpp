//
// Created by Matteo Mariani on 12/08/23.
//

#include "Zombie.hpp"

Zombie *newZombie(std::string name) {
    Zombie *generate = new Zombie(name);
    return generate;
}