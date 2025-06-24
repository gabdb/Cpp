
#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat a(42, "Alice");
        Bureaucrat b(1,  "Boss");
        Bureaucrat c(150,"Clerk");

        std::cout << a << "\n" << b << "\n" << c << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    std::cout << "\n=== Increment/Decrement limit ===\n";
    try {
        Bureaucrat up(2, "Up");
        std::cout << up;            // 2
        up.incrementGrade();        // goes to 1
        std::cout << " -> " << up << "\n";
        up.incrementGrade();        // throws GradeTooHighException
    }
    catch (std::exception& e) {
        std::cerr << "Increment failed: " << e.what() << "\n";
    }

    try {
        Bureaucrat down(149, "Down");
        std::cout << down;          // 149
        down.decrementGrade();      // goes to 150
        std::cout << " -> " << down << "\n";
        down.decrementGrade();      // throws GradeTooLowException
    }
    catch (std::exception& e) {
        std::cerr << "Decrement failed: " << e.what() << "\n";
    }

    std::cout << "\n=== Construction with invalid grades ===\n";
    try {
        Bureaucrat tooHigh(0,   "TooHigh");  // grade<1
    }
    catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }
    try {
        Bureaucrat tooLow(151,  "TooLow");   // grade>150
    }
    catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "\n=== Copy & assignment ===\n";
    try {
        Bureaucrat orig(50, "Original");
        Bureaucrat copy(orig);
        Bureaucrat assigned = orig;
        std::cout << "orig     : " << orig     << "\n"
                  << "copy     : " << copy     << "\n"
                  << "assigned : " << assigned << "\n";
    }
    catch (std::exception& e) {
        std::cerr << "Copy/assign error: " << e.what() << "\n";
    }

    return 0;
}