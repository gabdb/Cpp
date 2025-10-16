
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("no_name") {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::Bureaucrat(unsigned int grade, const std::string name) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (&other != this)
	{
		_grade = other._grade;
	}
	return (*this);
}

const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int		Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's grade is too high !!!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat's grade is too low !!!");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
	out << "Bureaucrat's name: " << other.getName() << ", and grade: " << other.getGrade();
	return (out);
}

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception& e)
	{
		std::cout << _name << " couldn't sign the form: " << form.getName()
		<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}