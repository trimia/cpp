#include "ClapTrap.hpp"
//#include "Borderlands.hpp"
extern Borderlands *borderlands;
int main() {
//    for (int i = 0; i < 20; i++) {
//        new ClapTrap("a");
//    }


    ClapTrap firstItem("Elayah");
    ClapTrap secondItem("Gevova");

    std::cout << "Name: " << firstItem.getName() << std::endl;
    std::cout << "HitPoints: " << firstItem.getHitPoints() << std::endl;
    std::cout << "EnergyPoints: " << firstItem.getEnergyPoints() << std::endl;
    std::cout << "AttackDamage: " << firstItem.getAttackDamage() << std::endl;

    std::cout << std::endl;

    std::cout << "Name: " << secondItem.getName() << std::endl;
    std::cout << "HitPoints: " << secondItem.getHitPoints() << std::endl;
    std::cout << "EnergyPoints: " << secondItem.getEnergyPoints() << std::endl;
    std::cout << "AttackDamage: " << secondItem.getAttackDamage() << std::endl;

    std::cout << std::endl;
    std::cout << firstItem.getName() << " set attack damage to 3" << std::endl;
    firstItem.setAttackDamage(3);
    firstItem.attack(secondItem.getName());
//    secondItem.takeDamage(3);
    secondItem.beRepaired(1);
    firstItem.beRepaired(1);

    std::cout << std::endl;

    std::cout << "Name: " << firstItem.getName() << std::endl;
    std::cout << "HitPoints: " << firstItem.getHitPoints() << std::endl;
    std::cout << "EnergyPoints: " << firstItem.getEnergyPoints() << std::endl;
    std::cout << "AttackDamage: " << firstItem.getAttackDamage() << std::endl;

    std::cout << std::endl;

    std::cout << "Name: " << secondItem.getName() << std::endl;
    std::cout << "HitPoints: " << secondItem.getHitPoints() << std::endl;
    std::cout << "EnergyPoints: " << secondItem.getEnergyPoints() << std::endl;
    std::cout << "AttackDamage: " << secondItem.getAttackDamage() << std::endl;

//
//    std::cout << std::endl;
//
//    std::cout << "Name: " << firstItem.getName() << std::endl;
//    std::cout << "HitPoints: " << firstItem.getHitPoints() << std::endl;
//    std::cout << "EnergyPoints: " << firstItem.getEnergyPoints() << std::endl;
//    std::cout << "AttackDamage: " << firstItem.getAttackDamage() << std::endl;
//
//    std::cout << std::endl;
//
//    std::cout << "Name: " << secondItem.getName() << std::endl;
//    std::cout << "HitPoints: " << secondItem.getHitPoints() << std::endl;
//    std::cout << "EnergyPoints: " << secondItem.getEnergyPoints() << std::endl;
//    std::cout << "AttackDamage: " << secondItem.getAttackDamage() << std::endl;
//
//    std::cout << std::endl;
//
//    secondItem.attack(firstItem.getName());
    delete borderlands;

    return (0);
}
