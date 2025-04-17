#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	this->currentIndex = 0;
	return ;
}

void	PhoneBook::addContact(void)
{
	std::string	str;

	str = "";
	std::cout << "\nNew contact, please enter information" << std::endl;

	//First Name
	std::cout << "First Name: ";
	std::getline(std::cin, str);
	eof_signal();
	this->arrayContact[this->currentIndex % 8].setFirstName(str);

	//Last Name
	std::cout << "Last Name: ";
	std::getline(std::cin, str);
	eof_signal();
	this->arrayContact[this->currentIndex % 8].setLastName(str);

	//Nickname
	std::cout << "Nickname: ";
	std::getline(std::cin, str);
	eof_signal();
	this->arrayContact[this->currentIndex % 8].setNickName(str);

	//...

	std::cout << "new contact added !" << std::endl;
	this->currentIndex++;
}
