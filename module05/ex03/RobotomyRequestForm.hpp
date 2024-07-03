#ifndef _RobotomyRequestForm_HPP_
#define _RobotomyRequestForm_HPP_

#include <iostream>
#include <fstream>
#include <cstdlib> // for std::rand and std::srand
#include <ctime> // for std::time

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //
class Bureaucrat;
class	RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm (std::string target);
        RobotomyRequestForm (RobotomyRequestForm const &obj);
        ~RobotomyRequestForm ();
        RobotomyRequestForm &operator= (const RobotomyRequestForm &obj);
        void execute(Bureaucrat const &executor) const;
	private	:
        std::string _target;
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
