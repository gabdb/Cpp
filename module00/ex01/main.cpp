#include "phonebook.hpp"

int main(void)
{
	PhoneBook	Directory;
	std::string	str;
	int			i;
	int			nb_contacts = 0;

	std::cout << "Welcome to the PhoneBook program, choose a command between ADD, SEARCH and EXIT \n" << std::endl;
	while (str != "EXIT")
	{
		std::cout << "COMMAND: ";
		std::getline(std::cin, str);
		eof_signal();
		if (str == "EXIT")
			break;
		else if (str == "ADD")
		{
			Directory.addContact();
			if (nb_contacts < 8)
				nb_contacts++;
		}
		else if (str == "SEARCH")
		{
			i = 0;
			while (i < nb_contacts)
			{
				Directory.displayContact(Directory.getContact(i), i);
				i++;
			}
			if (i > 0)
			{
				std::cout << "Enter index of contact you wish to see: ";
				std::getline(std::cin, str);
				std::cout << "STR.SIZE() IS " << str.size() << std::endl;
				while (str.size() > 1 || str[0] - 48 > nb_contacts - 1 || str[0] - 48 < 0)
				{
					std::cout << "Please enter a valid number: ";
					std::getline(std::cin, str);
				}
				Directory.displayInfo(str);
			}
		}
		else
			std::cout << "Please enter only ADD/SEARCH/EXIT" << std::endl;
	}

	return (0);
}