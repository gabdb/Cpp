#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <string>
#include "contact.hpp"
#include "utils.hpp"

class PhoneBook
{

    private:

        int     currentIndex;
        Contact arrayContact[8];

    public:

        PhoneBook();
        ~PhoneBook() = default;
        void    addContact();
        void    searchContact();
        Contact getContact(int index);
        void    displayInfo(std::string str);
        void    displayContact(Contact _Contact, int i);
};


#endif