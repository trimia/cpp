//
// Created by Matteo Mariani on 13/08/23.
//
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    Weapon gun("beretta");
    Weapon rifle;

    rifle.setType("winchester");
    HumanA cowBoy("coccobill", gun);
    HumanB steampunk("vash the stampede");

    cowBoy.attack();
//    steampunk.attack(); //type not defined so sigh fault ;)

    steampunk.setWeapon(rifle);
    cowBoy.attack();
    steampunk.attack();
    std::cout << "when a man with a gun meet a man with the rifle, man with the gun is a dead man" << std::endl;


    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;


}