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

int	PhoneBook::addContact(void)
{
	std::string	str[5];

	str[0] = "";
	std::cout << "\nNew contact, please enter information" << std::endl;

	//First Name
	std::cout << "First Name: ";
	std::getline(std::cin, str[0]);
	if (str[0].size() == 0)
	{
		std::cout << "Empty argument (non valid) !" << std::endl;
		return 0;
	}
	eof_signal();

	//Last Name
	str[1] = "";
	std::cout << "Last Name: ";
	std::getline(std::cin, str[1]);
	if (str[1].size() == 0)
	{
		std::cout << "Empty argument (non valid) !" << std::endl;
		return 0;
	}
	eof_signal();

	//Nickname
	str[2] = "";
	std::cout << "Nickname: ";
	std::getline(std::cin, str[2]);
	if (str[2].size() == 0)
	{
		std::cout << "Empty argument (non valid) !" << std::endl;
		return 0;
	}
	eof_signal();

	//PhoneNumber
	str[3] = "";
	std::cout << "Phone number: ";
	std::getline(std::cin, str[3]);
	if (str[3].size() == 0)
	{
		std::cout << "Empty argument (non valid) !" << std::endl;
		return 0;
	}
	eof_signal();

	//Secret
	str[4] = "";
	std::cout << "Darkest secret: ";
	std::getline(std::cin, str[4]);
	if (str[4].size() == 0)
	{
		std::cout << "Empty argument (non valid) !" << std::endl;
		return 0;
	}
	eof_signal();
	this->arrayContact[this->currentIndex % 8].setFirstName(str[0]);
	this->arrayContact[this->currentIndex % 8].setLastName(str[1]);
	this->arrayContact[this->currentIndex % 8].setNickName(str[2]);
	this->arrayContact[this->currentIndex % 8].setPhoneNumber(str[3]);
	this->arrayContact[this->currentIndex % 8].setDarkestSecret(str[4]);

	std::cout << "new contact added !" << std::endl;
	this->currentIndex++;
	return (1);
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
