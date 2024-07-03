#ifndef _Bureaucrat_HPP_
#define _Bureaucrat_HPP_

#include <iostream>
#include "Form.hpp"
// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //
class AForm;
class	Bureaucrat
{
	public	:
        Bureaucrat();
		Bureaucrat (std::string name,int grade);
		Bureaucrat (Bureaucrat const &obj);
		~Bureaucrat ();
		Bureaucrat &operator= (const Bureaucrat &obj);

    std::string getName() const;
        int         getGrade()const;
        void incrementGrade();
        void decrementGrade();
        void signForm(Form & form);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade too high";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade too low";
        }
    };

	private	:
        std::string _name;
        int         _grade;
		//	DataType	attributes.
};
std::ostream &operator<<(std::ostream &os,const Bureaucrat &bureaucrat);

// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
