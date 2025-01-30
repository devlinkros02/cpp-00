#include <iostream>

std::string trunc(const std::string &str);
std::string get_valid_input(std::string prompt, bool validator);

class Contact {

	private:
		std::string darkest_secret;

	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;

		Contact() {}
		Contact(std::string fn, std::string ln,
			std::string nn, std::string pn, std::string ds) {

			first_name = fn;
			last_name = ln;
			nickname = nn;
			phone_number = pn;
			darkest_secret = ds;
		}

		void print() {
			std::cout << "Contact info: " << std::endl << std::endl;
			std::cout << "  First name: " << first_name << std::endl;
			std::cout << "  Last name: " << last_name << std::endl;
			std::cout << "  Nickname: " << nickname << std::endl;
			std::cout << "  Phone Number: " << phone_number << std::endl;
			std::cout << std::endl;
		}
};

class PhoneBook {

	private:
		int size;

	public:
		Contact contacts[8];

		PhoneBook() {
			size = 0;
			std::cout << "Welcome to PhoneBook!" << std::endl;
		}

		void add()
		{
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
		}

		bool display_contact() {
			std::string input = get_valid_input("Please choose a valid index to view full contact info", true);
			int index;
			try {
				index = std::stoi(input);
			}
			catch (const std::invalid_argument &e) {
				std::cout << "Invalid input. Please enter a numeric value." << std::endl;
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

		void search() {
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
};