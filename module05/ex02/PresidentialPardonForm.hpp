#ifndef _PresidentialPardonForm_HPP_
#define _PresidentialPardonForm_HPP_

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
//#include "FormException.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //
class Bureaucrat;
class	PresidentialPardonForm : public AForm
{
//	public	:
//		PresidentialPardonForm ();
//        PresidentialPardonForm (std::string name,int requireToSign,int requireToExecute);
//		PresidentialPardonForm (PresidentialPardonForm const &obj);
//		~PresidentialPardonForm ();
//		PresidentialPardonForm &operator= (const PresidentialPardonForm &obj);
//        std::string     getName()const;
//        bool            isSigned()const;
//        int             getRequiredGradeToSign()const;
//        int             getRequiredGradeToExecute()const;
//        void            beSigned(Bureaucrat &bureaucrat);
//        virtual void    execute(Bureaucrat const &executor) const=0;
//    class GradeTooHighException : public std::exception {
//    public:
//        virtual const char* what() const throw() {
//            return "Grade too high ";
//        }
//    };
//
//    class GradeTooLowException : public std::exception {
//    public:
//        virtual const char* what() const throw() {
//            return "Grade too low ";
//        }
//    };
//    class AlredySigned : public std::exception {
//    public:
//        virtual const char* what() const throw() {
//            return "PresidentialPardonForm is already be signed";
//        }
//    };
    public:
        PresidentialPardonForm (std::string target);
        PresidentialPardonForm (PresidentialPardonForm const &obj);
        ~PresidentialPardonForm ();
        PresidentialPardonForm &operator= (const PresidentialPardonForm &obj);
        void execute(Bureaucrat const &executor) const;
	private	:
        std::string _target;
//        std::string _name;
//        bool        _signed;
//        int         _requireToSign;
//        int         _requireToExecute;

		//	DataType	attributes.
};
std::ostream &operator<<(std::ostream &os,const PresidentialPardonForm &form);


// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
