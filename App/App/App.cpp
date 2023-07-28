#include <iostream>
#include <sstream>
#include <string>

//This unit will check the validity of this command 
void unit1(std::string command) {
	//extract the command
	std::stringstream ee(command);
	std::string action;
	//store the first word into action so we can know if its "show", "print", anything
	ee >> action; 
	// if it "show" then we will go to the remaining part of the string(command)
	if (action == "show") {
		//store the other part of the string (the target) which is either boobs or thighs 
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




