#include <iostream>

#define CLS "\033[2J\033[1;1H";

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

		Contact() {};
		Contact(std::string fn, std::string ln,
				std::string nn, std::string pn, std::string ds);

		void print();
};