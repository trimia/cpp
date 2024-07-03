#ifndef _PresidentialPardonForm_HPP_
#define _PresidentialPardonForm_HPP_

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //
class Bureaucrat;
class	PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm (std::string target);
        PresidentialPardonForm (PresidentialPardonForm const &obj);
        ~PresidentialPardonForm ();
        PresidentialPardonForm &operator= (const PresidentialPardonForm &obj);
        void execute(Bureaucrat const &executor) const;
	private	:
        std::string _target;
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
