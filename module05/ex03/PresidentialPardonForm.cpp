#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 145, 137) {
    this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm : Destructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj): AForm(obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

PresidentialPardonForm	&PresidentialPardonForm::operator= (const PresidentialPardonForm &obj)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
	{
            this->AForm::operator=(obj);
            this->_target = obj._target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    try {
        if (executor.getGrade() > this->getRequiredGradeToExecute())
            throw GradeTooLowException();
        if (!this->isSigned())
            throw FormNotSignedException();
        std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
    } catch (std::exception &e) {
        std::cout<<executor.getName()<<" cannot execute "<<this->getName()<<" because: "<<e.what()<<std::endl;
    }
}
