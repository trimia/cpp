#ifndef _Intern_HPP_
#define _Intern_HPP_

#include <iostream>
#include <map>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

class	Intern
{
	public	:
		Intern ();
		Intern (Intern const &obj);
		~Intern ();
		Intern &operator= (const Intern &obj);
		AForm* makeForm(std::string formName, std::string target);

	private	:
		//	DataType	attributes.
};

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
