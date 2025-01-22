#include <iostream>

class Contact {

	private:
		std::string darkest_secret;

	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;

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

std::string get_from_cin(std::string prompt) {

	char buffer[256];

	std::cout << prompt << ": " << std::endl;
	std::cin.getline(buffer, 256);
	return std::string(buffer);
}

class PhoneBook {

	private:
		int size = 0;

	public:
		Contact contacts[8];

		void add() {
			if (size == 9) {
				size = 0;
			}

			std::string fn = get_from_cin("First name");
			std::string ln = get_from_cin("Last name");
			std::string nn = get_from_cin("Nickname");
			std::string pn = get_from_cin("Phone number");
			std::string ds = get_from_cin("Deepest secret");

			contacts[size] = Contact(fn, ln, nn, pn, ds);
		}
};

int main(void) {

	Contact devlin("Devlin", "Kros", "Dev", "0612345678", "geheim");

	std::cout << "Contact info: " << std::endl << std::endl;
	std::cout << "  First name: " << devlin.first_name << std::endl;
	std::cout << "  Last name: " << devlin.last_name << std::endl;
	std::cout << "  Nickname: " << devlin.nickname << std::endl;
	std::cout << "  Phone Number: " << devlin.phone_number << std::endl;
	return 0;
}