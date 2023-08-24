//
// Created by Matteo Mariani on 13/08/23.
//

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "iostream"
#include "string"

class Weapon {
private:
    std::string type;
public:
    Weapon();

    Weapon(const std::string &type);

    ~Weapon();

    const std::string &getType() const;

    void setType(const std::string &type);

};


#endif //CPP0_4_WEAPON_HPP
