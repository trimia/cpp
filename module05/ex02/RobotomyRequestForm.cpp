#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 145, 137) {
    this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm : Destructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj): AForm(obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

RobotomyRequestForm	&RobotomyRequestForm::operator= (const RobotomyRequestForm &obj)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
	{
//        this->_name=obj._name;
//        this->_requireToExecute=obj._requireToExecute;
//        this->_requireToSign=obj._requireToSign;
//        this->_signed=obj._signed;

            this->AForm::operator=(obj);
            this->_target = obj._target;
		//	this->attributes = obj.attributes;
		//	...
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    try {
        if (executor.getGrade() > this->getRequiredGradeToExecute())
            throw GradeTooLowException();
        if (!this->isSigned())
            throw FormNotSignedException();
        std::srand(std::time(0)); // use current time as seed for random generator
        double randomNumber = static_cast<double>(std::rand()) / RAND_MAX; // generates a random number between 0 and 1

        if (randomNumber <= 0.5) {
            std::cout << "\a" << this->_target << " has been robotomized successfully" << std::endl;
        } else {
            throw std::runtime_error("Robotomization failed");
        }
    } catch (std::exception &e) {
        std::cout<<executor.getName()<<" cannot execute "<<this->getName()<<" because: "<<e.what()<<std::endl;
    }

}

std::ostream &operator<<(std::ostream &os,const RobotomyRequestForm &form) {
    os << form.getName() << ",  form is signed: " <<std::boolalpha <<form.isSigned() << ", required grade to sign: " << form.getRequiredGradeToSign() << ", required grade to execute: " << form.getRequiredGradeToExecute() << std::endl;
//    std::cout<<os<<std::endl;
    return os;
}

