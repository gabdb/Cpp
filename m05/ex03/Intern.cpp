
#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    (void) other;
}

Intern& Intern::operator=(const Intern& other) {
    (void) other;
    return (*this);
}

Intern::~Intern() {}

AForm*  makePresidential(const std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm*  makeRobotomy(const std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm*  makeShrubbery(const std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm*  Intern::makeForm(const std::string formName, const std::string target)
{
    std::string formArray[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm* (*fptrArray[])(const std::string) = {&makePresidential, &makeRobotomy, &makeShrubbery}; //array de pointers vers fonctions

    for (int i = 0; i < 3; i++)
    {
        if (formName == formArray[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (fptrArray[i](target));
        }
    }
    std::cout << "Form type not found !" << std::endl;
    return (NULL);
}