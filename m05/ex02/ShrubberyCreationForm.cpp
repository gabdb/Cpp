
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

void    drawtree(std::ofstream& file)
{
    file << TREE << std::endl;
}

void    ShrubberyCreationForm::execute(const Bureaucrat& bcrat) const
{
    if (!this->getIsSigned())
        throw FormNotSignedException();
    if (bcrat.getGrade() > this->getGradeToExec())
        throw GradeTooLowException();
    std::ofstream file(((this->_target) + "_shrubbery").c_str());
    if (!(file.is_open()))
        throw std::runtime_error("Failed to open output file.");
    else
    {
        drawtree(file);
        file.close();
    }
}