#include "AForm.hpp"

AForm::AForm()
{
    this->_name="Default";
    this->_requireToSign=150;
    this->_requireToExecute=150;
    this->_signed=false;
	std::cout << "AForm : Default Constructor Called" << std::endl;
}
AForm::AForm(std::string name, int requireToSign, int requireToExecute) {
    this->_name=name;
    if(requireToSign<1 || requireToExecute<1) throw GradeTooHighException();
    if(requireToSign>150 || requireToExecute>150) throw GradeTooLowException();
    this->_requireToSign=requireToSign;
    this->_requireToExecute=requireToExecute;
    this->_signed=false;
}
AForm::~AForm()
{
	std::cout << "AForm : Destructor Called" << std::endl;
}

AForm::AForm(AForm const &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

AForm	&AForm::operator= (const AForm &obj)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
	{
        this->_name=obj._name;
        this->_requireToExecute=obj._requireToExecute;
        this->_requireToSign=obj._requireToSign;
        this->_signed=obj._signed;

		//	this->attributes = obj.attributes;
		//	...
	}
	return (*this);
}
std::string AForm::getName() const{
    return _name;
}
bool AForm::isSigned() const {
    return _signed;
}
int AForm::getRequiredGradeToSign() const {
    return _requireToSign;
}
int AForm::getRequiredGradeToExecute() const {
    return _requireToExecute;
}
void AForm::beSigned(Bureaucrat &bureaucrat) {
    try {
        if(bureaucrat.getGrade() >= this->_requireToSign)
            throw GradeTooLowException();
        if(this->_signed)
            throw AlredySignedException();
    } catch (const std::exception &e) {
        std::cout<<bureaucrat.getName()<<" couldn´t sign "<< this->getName()<<" because "<<e.what()<<std::endl;
        return;
    }

    this->_signed = true;
}
std::ostream &operator<<(std::ostream &os,const AForm &form) {
    os << form.getName() << ",  form is signed: " <<std::boolalpha <<form.isSigned() << ", required grade to sign: " << form.getRequiredGradeToSign() << ", required grade to execute: " << form.getRequiredGradeToExecute() << std::endl;
//    std::cout<<os<<std::endl;
    return os;
}

