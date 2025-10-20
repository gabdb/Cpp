
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPF", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& bcrat) const
{
    if (!this->getIsSigned())
		throw FormNotSignedException();
	if (bcrat.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}