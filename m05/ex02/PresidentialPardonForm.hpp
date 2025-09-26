
#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;
		PresidentialPardonForm(); //pas cense etre utilise mais Orthodox CF oblige
	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		virtual void execute(const Bureaucrat& bcrat) const;
};