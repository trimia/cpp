#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

//#include "Borderlands.hpp"
int main() {
//    for (int i = 0; i < 20; i++) {
//        new ScavTrap("a");
//    }
//

    FragTrap firstfrag("Elayah");

    FragTrap secondfrag("Gevova");


    std::cout << "Name: " << firstfrag.getName() << std::endl;
    std::cout << "HitPoints: " << firstfrag.getHitPoints() << std::endl;
    std::cout << "EnergyPoints: " << firstfrag.getEnergyPoints() << std::endl;
    std::cout << "AttackDamage: " << firstfrag.getAttackDamage() << std::endl;

    std::cout << std::endl;

    std::cout << "Name: " << secondfrag.getName() << std::endl;
    std::cout << "HitPoints: " << secondfrag.getHitPoints() << std::endl;
    std::cout << "EnergyPoints: " << secondfrag.getEnergyPoints() << std::endl;
    std::cout << "AttackDamage: " << secondfrag.getAttackDamage() << std::endl;

    std::cout << std::endl;
//    std::cout << firstfrag.getName() << " set attack damage to 3" << std::endl;
//    firstbot.setAttackDamage(3);
    firstfrag.attack(secondfrag.getName());
//    secondbot.takeDamage(3);
    secondfrag.beRepaired(1);
    firstfrag.beRepaired(1);

    std::cout << std::endl;

    std::cout << "Name: " << firstfrag.getName() << std::endl;
    std::cout << "HitPoints: " << firstfrag.getHitPoints() << std::endl;
    std::cout << "EnergyPoints: " << firstfrag.getEnergyPoints() << std::endl;
    std::cout << "AttackDamage: " << firstfrag.getAttackDamage() << std::endl;

    std::cout << std::endl;

    std::cout << "Name: " << secondfrag.getName() << std::endl;
    std::cout << "HitPoints: " << secondfrag.getHitPoints() << std::endl;
    std::cout << "EnergyPoints: " << secondfrag.getEnergyPoints() << std::endl;
    std::cout << "AttackDamage: " << secondfrag.getAttackDamage() << std::endl;
    firstfrag.highFivesGuys();
    secondfrag.highFivesGuys();

//
//
//    ScavTrap firstbot("Elayah");
//
//    ScavTrap secondbot("Gevova");
//
//
//    std::cout << "Name: " << firstbot.getName() << std::endl;
//    std::cout << "HitPoints: " << firstbot.getHitPoints() << std::endl;
//    std::cout << "EnergyPoints: " << firstbot.getEnergyPoints() << std::endl;
//    std::cout << "AttackDamage: " << firstbot.getAttackDamage() << std::endl;
//
//    std::cout << std::endl;
//
//    std::cout << "Name: " << secondbot.getName() << std::endl;
//    std::cout << "HitPoints: " << secondbot.getHitPoints() << std::endl;
//    std::cout << "EnergyPoints: " << secondbot.getEnergyPoints() << std::endl;
//    std::cout << "AttackDamage: " << secondbot.getAttackDamage() << std::endl;
//
//    std::cout << std::endl;
////    std::cout << firstfrag.getName() << " set attack damage to 3" << std::endl;
////    firstbot.setAttackDamage(3);
//    firstbot.attack(secondbot.getName());
////    secondbot.takeDamage(3);
//    secondbot.beRepaired(1);
//    firstbot.beRepaired(1);
//
//    std::cout << std::endl;
//
//    std::cout << "Name: " << firstbot.getName() << std::endl;
//    std::cout << "HitPoints: " << firstbot.getHitPoints() << std::endl;
//    std::cout << "EnergyPoints: " << firstbot.getEnergyPoints() << std::endl;
//    std::cout << "AttackDamage: " << firstbot.getAttackDamage() << std::endl;
//
//    std::cout << std::endl;
//
//    std::cout << "Name: " << secondbot.getName() << std::endl;
//    std::cout << "HitPoints: " << secondbot.getHitPoints() << std::endl;
//    std::cout << "EnergyPoints: " << secondbot.getEnergyPoints() << std::endl;
//    std::cout << "AttackDamage: " << secondbot.getAttackDamage() << std::endl;
//    firstbot.guardGate();
//    secondbot.guardGate();

//    ClapTrap firstItem("Elayah");
//    ClapTrap secondItem("Gevova");
//
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
//    std::cout << firstItem.getName() << " set attack damage to 3" << std::endl;
//    firstItem.setAttackDamage(3);
//    firstItem.attack(secondItem.getName());
////    secondItem.takeDamage(3);
//    secondItem.beRepaired(1);
//    firstItem.beRepaired(1);
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



    return (0);
}
