#ifndef PHONEBOOK_H
# define PHONEBOOK_H

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
		int		addContact();
		//void	searchContact();
		Contact	getContact(int index);
		void	displayInfo(std::string str);
		void	displayContact(Contact _Contact, int i);
};

#endif