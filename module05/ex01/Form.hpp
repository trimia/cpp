#ifndef _Form_HPP_
#define _Form_HPP_

#include <iostream>
#include "Bureaucrat.hpp"
//#include "FormException.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //
class Bureaucrat;
class	AForm
{
	public	:
		AForm ();
        AForm (std::string name, int requireToSign, int requireToExecute);
		AForm (Form const &obj);
		~AForm ();
		Form &operator= (const Form &obj);
        std::string getName()const;
        bool        isSigned()const;
        int         getRequiredGradeToSign()const;
        int         getRequiredGradeToExecute()const;
        void        beSigned(Bureaucrat &bureaucrat);
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade too high ";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade too low ";
        }
    };
    class AlredySignedException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Form is already be signed";
        }
    };
	private	:
        std::string _name;
        bool        _signed;
        int         _requireToSign;
        int         _requireToExecute;

		//	DataType	attributes.
};
std::ostream &operator<<(std::ostream &os,const Form &form);


// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
