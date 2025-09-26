
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPF", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other); //_isSigned is a base class private member so unaccessible here directly
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& bcrat) const
{
    if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (bcrat.getGrade() > this->getGradeToExec())
		throw GradeTooHighException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}