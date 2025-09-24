
#pragma once

#include <iostream>
#include <fstream>
#include <string>


class Bureaucrat;

class AForm
{
	private:
		const				std::string _name;
		bool				_isSigned;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExec;

	protected:
		AForm();
	
	public:
		AForm(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute);
		AForm(const AForm& other);
		virtual ~AForm();
		AForm& operator=(const AForm& other);

		const				std::string getName() const;
		bool				getIsSigned() const;
		const unsigned int	getGradeToSign() const;
		const unsigned int	getGradeToExec() const;

		void				beSigned(const Bureaucrat& bcrat);

		virtual void		execute(const Bureaucrat& bcrat) const = 0;
};

std::ostream&	operator<<(std::ostream& out, const AForm& other);