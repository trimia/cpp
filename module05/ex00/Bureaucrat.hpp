#ifndef _Bureaucrat_HPP_
#define _Bureaucrat_HPP_

#include <iostream>

// ******************************************************** //
//                         CLASSES                         //
// ****************************************************** //

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
