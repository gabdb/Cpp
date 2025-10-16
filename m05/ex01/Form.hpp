#pragma once

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string   _name;
		bool                _isSigned;
		const unsigned int  _gradeToSign;
		const unsigned int  _gradeToExec;
		Form();

	public:
		Form(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExec);
		Form(const Form& other);
		~Form();
		Form& operator=(const Form& other);

		std::string 	getName() const;
		bool			getIsSigned() const;
		unsigned int	getGradeToSign() const;
		unsigned int	getGradeToExec() const;

		void			beSigned(const Bureaucrat& bcrat);

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream&   operator<<(std::ostream& out, const Form& other);