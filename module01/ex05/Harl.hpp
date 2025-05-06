#pragma once

#include <iostream>
#include <string>

class Harl
{
    private:
        void            debug(void);
        void            info(void);
        void            warning(void);
        void            error(void);
        typedef void    (Harl::* harl_fct_ptr)(void);       
        harl_fct_ptr    array[4];    
    public:
        Harl();
        ~Harl() = default;
        void    complain(std::string level);
};