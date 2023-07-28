
#include <iostream>
#include <string>
#include <filesystem>
#include "RealParser.h"
int main() {
	RealParser App1;
		std::string command;

	bool IsOn = true;
	while (IsOn) {
		std::cout << __FILE__ << ">";

		std::getline(std::cin, command);
		if (command == "exit") {
			break;
		}
		App1.unit1(command);
	}



}
