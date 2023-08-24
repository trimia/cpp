#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>
#include "string"
#include "Borderlands.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //
//class Borderlands;
//
//Borderlands *blands;


class ClapTrap {
public    :
    ClapTrap();

    ClapTrap(ClapTrap const &obj);

    ~ClapTrap();

    void attack(const std::string &target);

    void takeDamage(unsigned int amount);

    ClapTrap &operator=(const ClapTrap &obj);


    ClapTrap(std::string name);

    void beRepaired(unsigned int amount);

    void setName(const std::string &name);

    void setHitPoints(int hitPoints);

    void setEnergyPoints(int energyPoints);

    void setAttackDamage(int attackDamage);

    const std::string &getName() const;

    int getHitPoints() const;

    int getEnergyPoints() const;

    int getAttackDamage() const;

private:
    std::string _name;
    unsigned int _hitPoints;
    int _energyPoints;
    int _attackDamage;

};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
