
#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>
#include <ctime>


class RobotomyRequestForm : public AForm
{
    private :
        const std::string _target;
        RobotomyRequestForm();

    public :
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void execute(const Bureaucrat& bcrat) const;
};

