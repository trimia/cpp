#include "Bureaucrat.hpp"
#include "include.h"
Bureaucrat::Bureaucrat()
{
    this->_name="Default";
    this->_grade=150;
	std::cout << "Bureaucrat : Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) {
    this->_name=name;
    if(grade<1) throw GradeTooHighException();
    if(grade>150) throw GradeTooLowException();
    this->_grade=grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat : Destructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj){
        this->_name=obj._name;
        this->_grade=obj._grade;
    }

//		*this = obj;
}

Bureaucrat	&Bureaucrat::operator= (const Bureaucrat &obj)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
	{
        this->_grade=obj._grade;
        this->_name=obj._name;

		//	this->attributes = obj.attributes;
		//	...
	}
	return (*this);
}
 std::string Bureaucrat::getName() const{
     return _name;
}
int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {

    try
    {
        if (this->getGrade() <= 1)
            throw GradeTooHighException();
    }
    catch(GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
        return;
    }
    this->_grade--;

}

void Bureaucrat::decrementGrade() {
    try
    {
        if (this->getGrade() >= 150)
            throw GradeTooLowException();
    }
    catch(GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
        return;
    }
    this->_grade++;
}
void Bureaucrat::signForm(AForm &form) {
    try {
        if(this->getGrade() > form.getRequiredGradeToSign()){
            throw GradeTooLowException();
        }
        if(form.isSigned()){
            throw AForm::AlredySignedException();
        }


    } catch(const std::exception &e){
        std::cout<<this->getName()<<" couldn´t sign "<<form.getName()<<" because "<<e.what()<<std::endl;
        return;
    }
    form.beSigned(*this);
    std::cout<<this->getName()<<" signed "<<form.getName()<<std::endl;
}

void Bureaucrat::executeForm(AForm const &form) {
    try {
        if(this->getGrade() > form.getRequiredGradeToExecute()){
            throw GradeTooLowException();
        }
        if(!form.isSigned()){
            throw AForm::FormNotSignedException();
        }
    } catch(const std::exception &e){
        std::cout<<this->getName()<<" couldn´t execute "<<form.getName()<<" because "<<e.what()<<std::endl;
        return;
    }
    form.execute(*this);
    std::cout<<this->getName()<<" executed "<<form.getName()<<std::endl;
}

std::ostream &operator<<(std::ostream &os,const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ",  bureaucrat grade " << bureaucrat.getGrade()<<"\n";
//    std::cout<<os<<std::endl;
    return os;
}
