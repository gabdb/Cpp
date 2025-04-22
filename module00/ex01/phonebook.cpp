#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	this->currentIndex = 0;
	return ;
}

Contact	PhoneBook::getContact(int index)
{
	return (this->arrayContact[index]);
}

void	PhoneBook::addContact(void)
{
	std::string	str;

	str = "";
	std::cout << "\nNew contact, please enter information" << std::endl;

	//First Name
	std::cout << "First Name: ";
	std::getline(std::cin, str);
	if (str.size() == 0)
		str = "/";
	eof_signal();
	this->arrayContact[this->currentIndex % 8].setFirstName(str);

	//Last Name
	std::cout << "Last Name: ";
	std::getline(std::cin, str);
	if (str.size() == 0)
		str = "/";
	eof_signal();
	this->arrayContact[this->currentIndex % 8].setLastName(str);

	//Nickname
	std::cout << "Nickname: ";
	std::getline(std::cin, str);
	if (str.size() == 0)
		str = "/";
	eof_signal();
	this->arrayContact[this->currentIndex % 8].setNickName(str);

	//PhoneNumber
	std::cout << "Phone number: ";
	std::getline(std::cin, str);
	if (str.size() == 0)
		str = "/";
	eof_signal();
	this->arrayContact[this->currentIndex % 8].setPhoneNumber(str);

	//Secret
	std::cout << "Darkest secret: ";
	std::getline(std::cin, str);
	if (str.size() == 0)
		str = "/";
	eof_signal();
	this->arrayContact[this->currentIndex % 8].setDarkestSecret(str);

	std::cout << "new contact added !" << std::endl;
	this->currentIndex++;
}

void	PhoneBook::displayContact(Contact _Contact, int i)
{
	std::cout << i;
	for (int j = 0; j < 3; j++)
	{
		std::cout << "|";
		if (j == 0)
			print_word(_Contact.getFirstName());
		if (j == 1)
			print_word(_Contact.getLastName());
		if (j == 2)
			print_word(_Contact.getNickName());
	}
	std::cout << "|" << std::endl;
}

void	PhoneBook::displayInfo(std::string str)
{
	int i;

	i = str[0] - 48;
	std::cout << "First name: " << this->arrayContact[i].getFirstName() << std::endl;
	std::cout << "Last name: " << this->arrayContact[i].getLastName() << std::endl;
	std::cout << "Nickname: " << this->arrayContact[i].getNickName() << std::endl;
	std::cout << "Phonenumber: " << this->arrayContact[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->arrayContact[i].getDarkestSecret() << std::endl;
}
