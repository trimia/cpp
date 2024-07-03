#ifndef _AForm_HPP_
#define _AForm_HPP_

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
        AForm (std::string name,int requireToSign,int requireToExecute);
		AForm (AForm const &obj);
		~AForm ();
		AForm &operator= (const AForm &obj);
        std::string     getName()const;
        bool            isSigned()const;
        int             getRequiredGradeToSign()const;
        int             getRequiredGradeToExecute()const;
        void            beSigned(Bureaucrat &bureaucrat);
        virtual void    execute(Bureaucrat const &executor) const=0;
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
    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Form is not yet signed";
        }
    };
	private	:
        std::string _name;
        bool        _signed;
        int         _requireToSign;
        int         _requireToExecute;

		//	DataType	attributes.
};
std::ostream &operator<<(std::ostream &os,const AForm &form);


// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
