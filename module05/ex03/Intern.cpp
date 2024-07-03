#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern : Default Constructor Called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern : Destructor Called" << std::endl;
}

Intern::Intern(Intern const &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Intern	&Intern::operator= (const Intern &obj)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
	{
		//	this->attributes = obj.attributes;
		//	...
	}
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm *form = NULL;
	std::map<std::string, AForm *> formMap;
	formMap["robotomy request"] = new RobotomyRequestForm(target);
	formMap["presidential pardon"] = new PresidentialPardonForm(target);
	formMap["shrubbery creation"] = new ShrubberyCreationForm(target);
	if (formMap.find(formName) != formMap.end())
		form = formMap[formName];
	else
		std::cout << "Intern : Form not found" << std::endl;
	return (form);
}
