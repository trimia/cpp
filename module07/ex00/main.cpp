#include <stdint.h>
#include <iostream>
#include "include.h"
#include "Wathever.hpp"

int			main(void)
{
    char	a = 'a';
    char	b = 'b';
    int		nb1, nb2, nb3;

    nb1 = 10;
    nb2 = 5;
    nb3 = 6;

    std::cout << CYAN << "Test swap function" << NONE << std::endl;
    std::cout << "before: " << a << std::endl;
    std::cout << "before: " << b << std::endl;
    swap<char>(a, b);
    std::cout << "- swap -" << std::endl;
    std::cout << "after: " << a << std::endl;
    std::cout << "after: " << b << std::endl;
    std::cout << GREEN << "OK" << NONE << std::endl << std::endl;

    std::cout << CYAN << "Test min function" << NONE << std::endl;
    std::cout << "nb1: " << nb1 << " | nb2: " << nb2 << std::endl;
    std::cout << "return: " << min<int>(nb1, nb2) << std::endl;
    std::cout << GREEN << "OK" << NONE << std::endl << std::endl;
    std::cout << "nb2: " << nb2 << " | nb3: " << nb3 << std::endl;
    std::cout << "return: " << min<int>(nb2, nb3) << std::endl;
    std::cout << GREEN << "OK" << NONE << std::endl << std::endl;
    std::cout << "char: " << a << " | char: " << b << std::endl;
    std::cout << "return: " << min<char>(a, b) << std::endl;
    std::cout << GREEN << "OK" << NONE << std::endl << std::endl;


    std::cout << CYAN << "Test max function" << NONE << std::endl;
    std::cout << "nb1: " << nb1 << " | nb2: " << nb2 << std::endl;
    std::cout << "return: " << max<int>(nb1, nb2) << std::endl;
    std::cout << GREEN << "OK" << NONE << std::endl << std::endl;
    std::cout << "nb2: " << nb2 << " | nb3: " << nb3 << std::endl;
    std::cout << "return: " << max<int>(nb2, nb3) << std::endl;
    std::cout << GREEN << "OK" << NONE << std::endl << std::endl;
    std::cout << "char: " << a << " | char: " << b << std::endl;
    std::cout << "return: " << max<char>(a, b) << std::endl;
    std::cout << GREEN << "OK" << NONE << std::endl << std::endl;

    std::cout << CYAN << "Test swap function" << NONE << std::endl;
    std::cout << "before: " << nb1 << std::endl;
    std::cout << "before: " << nb3 << std::endl;
    swap<int>(nb1, nb3);
    std::cout << "- swap -" << std::endl;
    std::cout << "after: " << nb1 << std::endl;
    std::cout << "after: " << nb3 << std::endl;
    std::cout << GREEN << "OK" << NONE << std::endl << std::endl;

    std::cout << "Main ex00" << std::endl;
    int e = 2;
    int f = 3;
    ::swap( e, f );
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
    std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    std::cout << GREEN << "OK" << NONE << std::endl << std::endl;
    return 0;
}