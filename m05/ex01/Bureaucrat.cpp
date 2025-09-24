
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("no_name") {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat::Bureaucrat(unsigned int grade, const std::string name) : name(name), grade(grade)
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
		this->grade = other.grade;
		//pas 'name' pcq cest un const (pas changeable)
	}
	return (*this);
}

const std::string	Bureaucrat::getName() const
{
	return (this->name);
}

unsigned int		Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->grade++;
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

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception& e)
	{
		std::cout << name << " couldn't sign the form: " << form.getName()
		<< " because " << e.what() << std::endl;
	}
}