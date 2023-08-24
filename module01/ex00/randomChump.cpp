//
// Created by Matteo Mariani on 12/08/23.
//

#include "Zombie.hpp"

void randomChump(std::string name) {
    Zombie zombie(name);
    zombie.announce();
}