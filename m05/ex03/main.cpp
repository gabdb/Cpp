

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	AForm* form1;
	AForm* form2;
	AForm* form3;

	form1 = intern.makeForm("robotomy request", "Target");
	form2 = intern.makeForm("presidential pardon", "Target");
	form3 = intern.makeForm("probleme", "Target");

	if (form1)
		delete form1;
	if (form2)
		delete form2;
	if (form3)
		delete form3;
		
    return (0);
}
