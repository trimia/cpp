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
    Zombie();
    ~Zombie();

    Zombie(std::string name);

    void announce(void);
    void setName(std::string name);

};
void randomChump(std::string name);
Zombie *newZombie(std::string name);
Zombie* zombieHorde( int N, std::string name );


#endif //CPP0_4_ZOMBIE_HPP
