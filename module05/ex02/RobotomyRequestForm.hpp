#ifndef _RobotomyRequestForm_HPP_
#define _RobotomyRequestForm_HPP_

#include <iostream>
#include <fstream>
#include <cstdlib> // for std::rand and std::srand
#include <ctime> // for std::time

#include "AForm.hpp"
#include "Bureaucrat.hpp"
//#include "FormException.hpp"

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //
class Bureaucrat;
class	RobotomyRequestForm : public AForm
{
//	public	:
//		RobotomyRequestForm ();
//        RobotomyRequestForm (std::string name,int requireToSign,int requireToExecute);
//		RobotomyRequestForm (RobotomyRequestForm const &obj);
//		~RobotomyRequestForm ();
//		RobotomyRequestForm &operator= (const RobotomyRequestForm &obj);
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
//            return "RobotomyRequestForm is already be signed";
//        }
//    };
    public:
        RobotomyRequestForm (std::string target);
        RobotomyRequestForm (RobotomyRequestForm const &obj);
        ~RobotomyRequestForm ();
        RobotomyRequestForm &operator= (const RobotomyRequestForm &obj);
        void execute(Bureaucrat const &executor) const;
	private	:
        std::string _target;
//        std::string _name;
//        bool        _signed;
//        int         _requireToSign;
//        int         _requireToExecute;

		//	DataType	attributes.
};
std::ostream &operator<<(std::ostream &os,const RobotomyRequestForm &form);


// ******************************************************** //
//                        FUNCTIONS                        //
// ****************************************************** //

#endif
