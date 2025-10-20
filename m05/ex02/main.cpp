

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void)
{

    std::cout << "\n\033[33m===== ShrubberyCreationForm =====\033[0m\n";
    try {
        Bureaucrat shrubGuy(130, "shrubGuy");
        ShrubberyCreationForm shrubForm("Garden");

        std::cout << shrubForm << std::endl;
        std::cout << std::endl;
        shrubGuy.signForm(shrubForm);
        std::cout << std::endl;
        std::cout << shrubForm << std::endl;
        shrubGuy.executeForm(shrubForm);
    }
    catch (std::exception& e) {
        std::cerr << "Error (Shrubbery test): " << e.what() << std::endl;
    }

    std::cout << "\n\033[33m===== RobotomyRequestForm =====\033[0m\n";
    try {
        Bureaucrat roboGuy(45, "Mr_Robo");
        RobotomyRequestForm roboForm("Bender");

        roboGuy.executeForm(roboForm);  // should fail (not signed)
        std::cout << std::endl;
        roboGuy.signForm(roboForm);     // sign form
        std::cout << std::endl;

        std::srand(std::time(NULL)); //init. un generateur aleatoire
        for (int i = 0; i < 5; ++i)     // run several times to see randomness
        {
            roboGuy.executeForm(roboForm);
            std::cout << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cerr << "Error (Robotomy test): " << e.what() << std::endl;
    }

    std::cout << "\n\033[33m===== PresidentialPardonForm =====\033[0m\n";
    try {
        Bureaucrat lowGuy(50, "lowGuy");
        Bureaucrat president(5, "president");
        PresidentialPardonForm pardonForm("Arthur Dent");

        lowGuy.signForm(pardonForm);       // should fail (grade too low)
        lowGuy.executeForm(pardonForm);    // should fail (not signed)
        president.signForm(pardonForm);    // should succeed
        president.executeForm(pardonForm); // should succeed
    }
    catch (std::exception& e) {
        std::cerr << "Error (Presidential test): " << e.what() << std::endl;
    }

    std::cout << "\n\033[32m===== All tests done. =====\033[0m\n";
    return 0;
}
