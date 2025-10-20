
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("no_name"), _isSigned(false), _gradeToSign(0), _gradeToExec(0) {} // pas cense etre appele

AForm::AForm(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExec)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name)
, _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
		//les autres var sont const
    }
    return (*this);
}

std::string AForm::getName() const
{
    return (_name);
}

bool AForm::getIsSigned() const
{
    return (_isSigned);
}

unsigned int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

unsigned int	AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

void	AForm::beSigned(const Bureaucrat& bcrat)
{
	if (bcrat.getGrade() <= _gradeToSign)
	{
		this->_isSigned = true;
		std::cout << bcrat.getName() << " signed " << _name << std::endl;
	}
	else
		throw AForm::GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

std::ostream&	operator<<(std::ostream& out, const AForm& other)
{
	out << "Name: " << other.getName() << ", and Is signed: " << other.getIsSigned()
		<< "\nGrade to sign: " << other.getGradeToSign() << ", and Grade to execute: "
		<< other.getGradeToExec() << std::endl;
	return out;
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed !");
}