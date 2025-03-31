#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>


class Contact
{

    private:

        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

    public:

        Contact() = default;
        ~Contact() = default;
        // Getters
        std::string getFirstName(void);
        std::string getLastName(void);
        std::string getNickName(void);
        std::string getPhoneNumber(void);
        std::string getDarkestSecret(void);
        //Setters
        void        setFirstName(std::string str);
        void        setLastName(std::string str);
        void        setNickName(std::string str);
        void        setPhoneNumber(std::string str);
        void        setDarkestSecret(std::string str);
        
};

#endif