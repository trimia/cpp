//
// Created by Matteo Mariani on 16/08/23.
//

#ifndef HARL_HPP
#define HARL_HPP
#include "string"
#include "iostream"


class Harl {
private:
    enum level {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
    };

    typedef void(Harl::*fp)(void);

//    using fp = void(*)(void);
    void debug(void);

    void info(void);

    void warning(void);

    void error(void);

public:
    void complain(std::string level);

};


#endif //CPP0_4_HARL_HPP
