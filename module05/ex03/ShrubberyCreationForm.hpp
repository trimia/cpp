#ifndef _ShrubberyCreationForm_HPP_
#define _ShrubberyCreationForm_HPP_

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //
class Bureaucrat;
class	ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm (std::string target);
        ShrubberyCreationForm (ShrubberyCreationForm const &obj);
        ~ShrubberyCreationForm ();
        ShrubberyCreationForm &operator= (const ShrubberyCreationForm &obj);
        void execute(Bureaucrat const &executor) const;
	private	:
        std::string _target;
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
