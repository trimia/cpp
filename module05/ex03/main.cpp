#include "include.h"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    Bureaucrat	b;
    Intern		someRandomIntern;
    AForm		*rrf;
    AForm		*rra;
    AForm		*rrb;
    AForm		*rrc;

    std::cout << GREEN << "**** Constructor ****" << NONE << std::endl << std::endl;

    try
    {
        Bureaucrat Francesco("Francesco", 43);
        b = Francesco;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << CYAN << "**** Info ****  " << NONE << std::endl << std::endl;

    std::cout << b << std::endl;

    std::cout << std::endl << CYAN << "**** Testing ****  " << NONE << std::endl << std::endl;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    rra = someRandomIntern.makeForm("presidential pardon", "Fry");
    rrb = someRandomIntern.makeForm("shrubbery creation", "Lela");
    rrc = someRandomIntern.makeForm("ppunzo request", "Zoiberg");
    std::cout << rrf->getName() << std::endl;
    b.signForm(rrf);
    b.signForm(rra);
    b.signForm(rrb);
    b.signForm(rrc);

    b.executeForm(rrf);
    b.executeForm(rra);
    b.executeForm(rrb);
    b.executeForm(rrc);
    std::cout << std::endl << RED << "**** Destructor ****" << NONE << std::endl << std::endl;
    // delete *z;
    delete rrf;
    delete rra;
    delete rrb;
    delete rrc;
    return 0;
}

