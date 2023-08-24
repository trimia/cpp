//
// Created by Matteo Mariani on 16/08/23.
//

#include "Harl.hpp"

void Harl::debug(void) {

    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
              << std::endl;

}

void Harl::info(void) {

    std::cout
            << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!"
            << std::endl;

}

void Harl::warning(void) {
    std::cout
            << "I think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month."
            << std::endl;

}

void Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;

}

void Harl::complain(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    fp fptr[] = {
            &Harl::debug,
            &Harl::info,
            &Harl::warning,
            &Harl::error
    };
    int j = 0, flag = 0;
    for (int i = 0; i < 4; i++) {

        if (level.compare(levels[i]) == 0) {
            (this->*fptr[i])();
            flag = 1;
        }
        j++;
    }
    if (j == 4 && flag == 0) {
        std::cout << "wrong input" << std::endl;
    }
}
