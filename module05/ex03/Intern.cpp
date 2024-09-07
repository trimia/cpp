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

enum FormType
{
    ROBOTOMY_REQUEST,
    PRESIDENTIAL_PARDON,
    SHRUBBERY_CREATION,
    UNKNOWN_FORM
};

FormType getFormType(const std::string &formName)
{
    if (formName == "robotomy request")
        return ROBOTOMY_REQUEST;
    else if (formName == "presidential pardon")
        return PRESIDENTIAL_PARDON;
    else if (formName == "shrubbery creation")
        return SHRUBBERY_CREATION;
    else
        return UNKNOWN_FORM;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    AForm *form = NULL;
    FormType formType = getFormType(formName);

    switch (formType)
    {
        case ROBOTOMY_REQUEST:
            form = new RobotomyRequestForm(target);
            break;
        case PRESIDENTIAL_PARDON:
            form = new PresidentialPardonForm(target);
            break;
        case SHRUBBERY_CREATION:
            form = new ShrubberyCreationForm(target);
            break;
        default:
            std::cout << "Intern : Form not found" << std::endl;
            break;
    }

    return form;
}
