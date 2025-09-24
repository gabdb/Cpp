
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== Constructor tests ===" << std::endl;
    try {
        Form ok("OkForm", 75, 75);
        std::cout << ok << std::endl;
        Form fail("BadForm", 0, 100);   // too high
    }
    catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Form fail2("BadForm2", 120, 200); // too low
    }
    catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Signing tests ===" << std::endl;
    Bureaucrat alice(50, "Alice");
    Bureaucrat bob(120, "Bob");

    Form tax("TaxForm", 100, 80);
    Form permit("PermitForm", 40, 30);

    alice.signForm(tax);    // should succeed
    alice.signForm(permit); // should fail
    bob.signForm(tax);      // should fail

    std::cout << "\n=== Grade modification tests ===" << std::endl;
    try {
        Bureaucrat chief(2, "Chief");
        std::cout << chief << std::endl;
        chief.incrementGrade();  // grade becomes 1
        std::cout << chief << std::endl;
        chief.incrementGrade();  // exception
    }
    catch (std::exception &e) {
        std::cout << "Exception while incrementing: " << e.what() << std::endl;
    }

    try {
        Bureaucrat intern(149, "Intern");
        std::cout << intern << std::endl;
        intern.decrementGrade(); // 150
        std::cout << intern << std::endl;
        intern.decrementGrade(); // exception
    }
    catch (std::exception &e) {
        std::cout << "Exception while decrementing: " << e.what() << std::endl;
    }

    return 0;
}
