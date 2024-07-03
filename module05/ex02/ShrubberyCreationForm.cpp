#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
    this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm : Destructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj): AForm(obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator= (const ShrubberyCreationForm &obj)
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

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    std::cout << "ShrubberyCreationForm::execute" << std::endl;
    try {
        if (executor.getGrade() > this->getRequiredGradeToExecute())
            throw GradeTooLowException();
        if (!this->isSigned())
            throw FormNotSignedException();
        std::string fileNAme= "./ex02/"+this->_target+ "_shrubbery.txt";
        std::cout<<"ShrubberyCreationForm::execute: creating file"<< fileNAme.c_str()<<std::endl;
        std::ofstream file(fileNAme.c_str(), std::ios::out | std::ios::trunc);
        if (!file.is_open()){
            std::cout<<"ShrubberyCreationForm::execute: failed to open file"<<std::endl;
            throw std::runtime_error("Failed to open the file");

        }
        file << "       _-_\n"
                "    /~~   ~~\\\n"
                " /~~         ~~\\\n"
                "{               }\n"
                " \\  _-     -_  /\n"
                "   ~  \\\\ //  ~\n"
                "_- -   | | _- _\n"
                "  _ -  | |   -_\n"
                "      // \\\\" << std::endl;
        std::cout<<"ShrubberyCreationForm::execute: file created"<<file<<std::endl;
        file.close();
    } catch (std::exception &e) {
        std::cout<<executor.getName()<<" cannot execute "<<this->getName()<<" because: "<<e.what()<<std::endl;
    }

}

std::ostream &operator<<(std::ostream &os,const ShrubberyCreationForm &form) {
    os << form.getName() << ",  form is signed: " <<std::boolalpha <<form.isSigned() << ", required grade to sign: " << form.getRequiredGradeToSign() << ", required grade to execute: " << form.getRequiredGradeToExecute() << std::endl;
//    std::cout<<os<<std::endl;
    return os;
}

