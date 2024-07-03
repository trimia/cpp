#ifndef _ShrubberyCreationForm_HPP_
#define _ShrubberyCreationForm_HPP_

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
//#include "FormException.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //
class Bureaucrat;
class	ShrubberyCreationForm : public AForm
{
//	public	:
//		ShrubberyCreationForm ();
//        ShrubberyCreationForm (std::string name,int requireToSign,int requireToExecute);
//		ShrubberyCreationForm (ShrubberyCreationForm const &obj);
//		~ShrubberyCreationForm ();
//		ShrubberyCreationForm &operator= (const ShrubberyCreationForm &obj);
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
//            return "ShrubberyCreationForm is already be signed";
//        }
//    };
    public:
        ShrubberyCreationForm (std::string target);
        ShrubberyCreationForm (ShrubberyCreationForm const &obj);
        ~ShrubberyCreationForm ();
        ShrubberyCreationForm &operator= (const ShrubberyCreationForm &obj);
        void execute(Bureaucrat const &executor) const;
	private	:
        std::string _target;
//        std::string _name;
//        bool        _signed;
//        int         _requireToSign;
//        int         _requireToExecute;

		//	DataType	attributes.
};
std::ostream &operator<<(std::ostream &os,const ShrubberyCreationForm &form);


// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
