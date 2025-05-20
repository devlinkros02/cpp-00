#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	size = 0;
	std::cout << "Welcome to PhoneBook!" << std::endl;
}

void PhoneBook::add() {

	if (size >= 8) {
		size = 0;
	}

	std::string fn = get_valid_input("First name", true);
	std::string ln = get_valid_input("Last name", true);
	std::string nn = get_valid_input("Nickname", true);
	std::string pn = get_valid_input("Phone number", true);
	std::string ds = get_valid_input("Deepest secret", true);

	contacts[size] = Contact(fn, ln, nn, pn, ds);
	size++;
	std::cout << CLS;
}

bool PhoneBook::display_contact() {

	int			index;
	std::string	input = get_valid_input("Please choose a valid index to view full contact info", true);

	try {
		index = std::stoi(input);
	}
	catch (const std::invalid_argument &e) {
		std::cout << "Invalid input. Please enter a numeric value." << std::endl;
		return false;
	}
	catch (const std::out_of_range &e) {
		std::cout << "Index out of range. Please try again" << std::endl;
		return false;
	}

	if (index >= 0 && index < 8) {
		if (!contacts[index].first_name.empty()) {
			contacts[index].print();
		} else {
			return false;
		}
	} else {
		return false;
	}
	return true;
}

void PhoneBook::search() {

	if (contacts[0].first_name.empty()) {
		std::cout << "Contact list empty. Please add one first." << std::endl;
		return;
	}

	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < 8; i++) {
		if (!contacts[i].first_name.empty()) {
			std::cout << trunc(std::to_string(i)) << '|'
					  << trunc(contacts[i].first_name) << '|'
					  << trunc(contacts[i].last_name) << '|'
					  << trunc(contacts[i].nickname) << std::endl;
		}
	}

	bool success = false;

	while (success == false) {
		success = display_contact();
	}
}