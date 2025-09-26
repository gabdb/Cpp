#pragma once

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;
		Bureaucrat();

	public:
		Bureaucrat(unsigned int grade, const std::string name);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& other);

		const std::string	getName() const;
		unsigned int		getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		void				signForm(AForm& form) const;
		void				executeForm(AForm const & form) const;

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);