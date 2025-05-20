#include <iostream>
#include "Contact.hpp"

class PhoneBook {

	private:
		int size;

	public:
		Contact contacts[8];

		PhoneBook();

		void add();
		bool display_contact();
		void search();
};