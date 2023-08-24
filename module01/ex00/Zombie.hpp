//
// Created by Matteo Mariani on 12/08/23.
//

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "iostream"
#include "string"
#include "iomanip"


class Zombie {
private:
    std::string name;
public:
    Zombie(std::string name);

    ~Zombie();

    void announce(void);

};
void randomChump(std::string name);
Zombie *newZombie(std::string name);


#endif //CPP0_4_ZOMBIE_HPP
