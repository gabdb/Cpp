#pragma once

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const unsigned int  _gradeToSign;
        const unsigned int  _gradeToExec;
    public:
        Form();
        Form(const std::string name, const unsigned int gradeToSign, const unsigned int _gradeToExec);
        Form(const Form& other);
        ~Form();
        Form& operator=(const Form& other);

        
};