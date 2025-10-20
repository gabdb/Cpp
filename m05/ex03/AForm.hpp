
#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Bureaucrat.hpp"
//class Bureaucrat;

class AForm
{
	private:
		const				std::string _name;
		bool				_isSigned;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExec;

	protected:
		AForm();
	
	public:
		AForm(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExec);
		AForm(const AForm& other);
		virtual ~AForm();
		AForm& operator=(const AForm& other);

		std::string 	getName() const;
		bool			getIsSigned() const;
		unsigned int	getGradeToSign() const;
		unsigned int	getGradeToExec() const;

		void				beSigned(const Bureaucrat& bcrat);

		virtual void		execute(const Bureaucrat& bcrat) const = 0; //makes class abstract

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const AForm& other);