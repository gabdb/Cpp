
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("no_name"), _gradeToSign(0), _gradeToExec(0) {}

Form::Form(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExec) :
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name)
, _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{

}

Form::~Form() {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
		//pas le reste pcq 'const'
	}
	return (*this);
}

const std::string Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

unsigned int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

unsigned int	Form::getGradeToExec() const
{
	return (_gradeToExec);
}

void	Form::beSigned(const Bureaucrat& bcrat)
{
	if (bcrat.getGrade() <= _gradeToSign)
	{
		this->_isSigned = true;
		std::cout << bcrat.getName() << " signed " << _name << std::endl;
	}
	else
		throw Form::GradeTooHighException();
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form Grade Too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form Grade Too Low");
}

std::ostream& operator<<(std::ostream& out, const Form& other)
{
	out << "Name: " << other.getName() << "\nIs signed: " << other.getIsSigned()
		<< "\nGrade to sign: " << other.getGradeToSign() << "\nGrade to execute: "
		<< other.getGradeToExec() << std::endl;
	return out;
}