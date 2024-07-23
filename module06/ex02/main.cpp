#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>
#include "Base.hpp"
#include "include.h"
Base* generate(void) {
    switch (std::rand() % 3) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return NULL;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception& e) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        } catch (std::exception& e) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            } catch (std::exception& e) {
                std::cout << "Unknown type" << std::endl;
                // Should never reach here if p is of type A, B, or C
            }
        }
    }
}

int main()
{
    Base *a;
    Base *b;
    Base *c;

    std::cout << GREEN << "**** Constructor ****" << NONE << std::endl << std::endl;
    std::srand((unsigned int)std::time(NULL));
    std::cout << std::endl << CYAN << "**** Testing ****  " << NONE << std::endl << std::endl;
    a = generate();
    identify(a);
    identify(*a);
    sleep(std::rand() % 3);
    std::cout << std::endl;
    b = generate();
    identify(b);
    identify(*b);
    sleep(std::rand() % 3);
    std::cout << std::endl;
    c = generate();
    identify(c);
    identify(*c);
    std::cout << std::endl << RED << "**** Decostructor ****  " << NONE << std::endl << std::endl;
    delete a;
    delete b;
    delete c;
    return (0);
}