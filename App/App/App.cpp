#include <iostream>
#include <sstream>
#include <string>

// this unit will check the validity of this command 
void unit1(std::string command) {
	//extract the command
	std::stringstream ee(command);
	std::string action;
	//store the first word into action so we can now if its "show", "print", anything
	ee >> action; 
	// if its "show" the we will go to the remaining part of the string(command)
	if (action == "show") {
		//store the other part of the string (the target) which is eaither boobs or thighs 
		std::string target;
		ee >> target;

		// we check here what is the target(the second part of the string) 
		if (target == "boobs") {
			std::cout << "the command is show boobs";

		}
		else if (target == "thighs") {
			std::cout << "the command is not show boobs, its thighs";
		}
		else {
			std::cout << "the command is not show boobs nor thighs";
		}
	}
}	

int main() {
	std::cout << "Enter a command MOTHER_FUCKER!, I CAN HANDLE IT " << std::endl; 
	std::string command;
	std::getline(std::cin, command);
	//les go to the parser
	unit1(command); 

	



	}
	




