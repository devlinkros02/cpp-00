#include "Contact.hpp"

Contact::Contact(std::string fn, std::string ln,
	std::string nn, std::string pn, std::string ds) {

	first_name = fn;
	last_name = ln;
	nickname = nn;
	phone_number = pn;
	darkest_secret = ds;
}

void Contact::print() {

	std::cout << "Contact info: " << std::endl << std::endl;
	std::cout << "  First name: " << first_name << std::endl;
	std::cout << "  Last name: " << last_name << std::endl;
	std::cout << "  Nickname: " << nickname << std::endl;
	std::cout << "  Phone Number: " << phone_number << std::endl;
	std::cout << std::endl;
}