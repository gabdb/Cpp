#pragma once

#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		unsigned int		grade;
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

		void				signForm(Form& form) const;

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