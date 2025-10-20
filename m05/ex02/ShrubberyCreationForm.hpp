
#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

# define TREE "	 /\\n\
    			/  \\n\
     		   /++++\\n\
    		  /  ()  \\n\
      		    ||||\n\
      			||||"

class ShrubberyCreationForm : public AForm
{
    private:
		const std::string _target;
		ShrubberyCreationForm();
	
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		void	execute(const Bureaucrat& bcrat) const; //fonction virtual = 0; parent
};

void	drawtree(std::ofstream& file);