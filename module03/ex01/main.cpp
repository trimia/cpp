#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

//#include "Borderlands.hpp"
int main() {
//    for (int i = 0; i < 20; i++) {
//        new ScavTrap("a");
//    }
//
//
//    ScavTrap ciao("ciao");
//    ScavTrap ciao2("ciao2");
//
//    std::cout << "HitPoints: " << ciao2.getHitPoints() << std::endl;
//    ciao.setAttackDamage(2);
//    ciao.attack("ciao2");
//    std::cout << "HitPoints: " << ciao2.getHitPoints() << std::endl;

    ScavTrap firstbot("Elayah");
    ScavTrap secondbot("Gevova");


    std::cout << "Name: " << firstbot.getName() << std::endl;
    std::cout << "HitPoints: " << firstbot.getHitPoints() << std::endl;
    std::cout << "EnergyPoints: " << firstbot.getEnergyPoints() << std::endl;
    std::cout << "AttackDamage: " << firstbot.getAttackDamage() << std::endl;

    std::cout << std::endl;

    std::cout << "Name: " << secondbot.getName() << std::endl;
    std::cout << "HitPoints: " << secondbot.getHitPoints() << std::endl;
    std::cout << "EnergyPoints: " << secondbot.getEnergyPoints() << std::endl;
    std::cout << "AttackDamage: " << secondbot.getAttackDamage() << std::endl;

    std::cout << std::endl;
//    std::cout << firstbot.getName() << " set attack damage to 3" << std::endl;
//    firstbot.setAttackDamage(3);
    firstbot.attack(secondbot.getName());
//    secondbot.takeDamage(3);
    secondbot.beRepaired(1);
    firstbot.beRepaired(1);

    std::cout << std::endl;

    std::cout << "Name: " << firstbot.getName() << std::endl;
    std::cout << "HitPoints: " << firstbot.getHitPoints() << std::endl;
    std::cout << "EnergyPoints: " << firstbot.getEnergyPoints() << std::endl;
    std::cout << "AttackDamage: " << firstbot.getAttackDamage() << std::endl;

    std::cout << std::endl;

    std::cout << "Name: " << secondbot.getName() << std::endl;
    std::cout << "HitPoints: " << secondbot.getHitPoints() << std::endl;
    std::cout << "EnergyPoints: " << secondbot.getEnergyPoints() << std::endl;
    std::cout << "AttackDamage: " << secondbot.getAttackDamage() << std::endl;
    firstbot.guardGate();
    secondbot.guardGate();

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
