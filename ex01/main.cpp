#include <iostream>
#include "PhoneBook.hpp"

std::string get_valid_input(std::string prompt, bool validator) {

	std::string name;

	while (1)
	{
		std::cout << prompt << ": " << std::endl;
		if (!std::getline(std::cin, name)) {
			exit(0);
		}

		if (name.empty() && validator) {
			std::cout << prompt << " cannot be empty, please try again." << std::endl;
		} else if (name.empty()) {
			return ("");
		} else {
			return (name);
		}
	}
}

std::string trunc(const std::string &str) {
    std::string final_string(10, ' ');

    if (str.length() <= 10) {
        std::size_t start_index = 10 - str.length();
        for (std::size_t i = 0; i < str.length(); i++) {
            final_string[start_index + i] = str[i];
        }
    } else {
        for (int i = 0; i < 9; i++) {
            final_string[i] = str[i];
        }
        final_string[9] = '.';
    }
    return final_string;
}

int main(void) {
	std::cout << CLS;

	PhoneBook phonebook;

	while (1) {
		std::string command = get_valid_input("Pick one of three commands: ADD, SEARCH or EXIT", false);
		if (command == "ADD") {
			phonebook.add();
		} else if (command == "SEARCH") {
			phonebook.search();
		} else if (command == "EXIT") {
			break;
		}
	}
	return 0;
}