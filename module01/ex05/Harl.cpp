
#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;

}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;    
}

void Harl::error()
{
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
    array[0] = &Harl::debug;
    array[1] = &Harl::info;
    array[2] = &Harl::warning;
    array[3] = &Harl::error;
}

void    Harl::complain(std::string level)
{
    std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (options[i] == level)
        {
            (this->*array[i])();
            return ;
        }
    }
    std::cout << "Try entering an existing option..." << std::endl;
}