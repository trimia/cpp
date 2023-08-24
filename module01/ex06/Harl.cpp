//
// Created by Matteo Mariani on 16/08/23.
//

#include "Harl.hpp"

void Harl::debug(void) {

    std::cout << "[DEBUG]" << std::endl
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
              << std::endl;

}

void Harl::info(void) {

    std::cout << "[INFO]" << std::endl
              << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!"
              << std::endl;

}

void Harl::warning(void) {
    std::cout << "[WARNING]" << std::endl
              << "I think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month."
              << std::endl;

}

void Harl::error(void) {
    std::cout << "[ERROR]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;

}

void Harl::complain(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    fp fptr[] = {
            &Harl::debug,
            &Harl::info,
            &Harl::warning,
            &Harl::error
    };
    //inutile se solo si potessero usare le mappe!!!!
    int i = 0;
    while (i < 4 && levels[i].compare(level)) {
        i++;
    }
    switch (i) {
        case DEBUG:
            (this->*fptr[DEBUG])();
            break;
        case INFO:
            (this->*fptr[INFO])();
            break;
        case WARNING:
            (this->*fptr[WARNING])();
            break;
        case ERROR:
            (this->*fptr[ERROR])();
            break;
        default:
            std::cout << "Probably complaining about insignificant problems" << std::endl;
    }

}
