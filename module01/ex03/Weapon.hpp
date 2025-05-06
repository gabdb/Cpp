#pragma once

#include <iostream>
#include <string>

class Weapon
{
    private:
        std::string type;

    public:
        //Weapon();
        Weapon(std::string type);
        ~Weapon() = default;
        const std::string&	getType(void);
        void    			setType(std::string name);
};