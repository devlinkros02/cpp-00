/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:11:51 by dkros             #+#    #+#             */
/*   Updated: 2025/01/16 19:42:48 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char **argv) {

	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; argv[i]; i++) {
		std::string str = argv[i];
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		std::cout << str;
	}
	std::cout << std::endl;
	return 0;
}

