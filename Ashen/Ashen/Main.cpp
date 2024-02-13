// This is the entry point of Ashen
#include <iostream>
#include "Parser.h"
#include <string>
#include <thread> //  <thread> header for sleep_for
#include <chrono> // header for milliseconds
#include <filesystem> // For Displaying the Directory Path
#include <Windows.h>

int main() {

	// Welcoming The User 



	std::string Input;
	std::cout << R"(
  .----------------.    .----------------.    .----------------.    .----------------.    .-----------------.    
| .--------------. |  | .--------------. |  | .--------------. |  | .--------------. |  | .--------------. |    
| |      __      | |  | |    _______   | |  | |  ____  ____  | |  | |  _________   | |  | | ____  _____  | |    
| |     /  \     | |  | |   /  ___  |  | |  | | |_   ||   _| | |  | | |_   ___  |  | |  | ||_   \|_   _| | |    
| |    / /\ \    | |  | |  |  (__ \_|  | |  | |   | |__| |   | |  | |   | |_  \_|  | |  | |  |   \ | |   | |    
| |   / ____ \   | |  | |   '.___`-.   | |  | |   |  __  |   | |  | |   |  _|  _   | |  | |  | |\ \| |   | |    
| | _/ /    \ \_ | |  | |  |`\____) |  | |  | |  _| |  | |_  | |  | |  _| |___/ |  | |  | | _| |_\   |_  | |    
| ||____|  |____|| |  | |  |_______.'  | |  | | |____||____| | |  | | |_________|  | |  | ||_____|\____| | |    
| |              | |  | |              | |  | |              | |  | |              | |  | |              | |    
| '--------------' |  | '--------------' |  | '--------------' |  | '--------------' |  | '--------------' |    
 '----------------'    '----------------'    '----------------'    '----------------'    '----------------'     
)" << std::endl;

	bool ASHEN_IS_ON= true;
	std::cout << "Welcome to Ashen Terminal Distinguished Man\n";
	std::cout << "A Terminal App Developed By The Gentlemen >> Yazan - Mohammad: \n";
	std::cout << "Type /Help For More Information \n";

	while (ASHEN_IS_ON) {

		std::string Input;
	
		std::cout << __FILE__ << ">";
		std::getline(std::cin, Input);

		//Command Executing Test
		if (Input == "Show") {
			std::cout << "show is the command"<<std::endl; 
		
		}
		// Exiting The Application
		else if (Input == "exit" || Input == "Exit") {
			std::cout << R"(
 
/$$$$$$        /$$$$$$$        /$$$$$$        /$$$$$$         /$$$$$$       
/$$__  $$      | $$__  $$      |_  $$_/       /$$__  $$       /$$__  $$      
| $$  \ $$      | $$  \ $$        | $$        | $$  \ $$      | $$  \__/      
| $$$$$$$$      | $$  | $$        | $$        | $$  | $$      |  $$$$$$       
| $$__  $$      | $$  | $$        | $$        | $$  | $$       \____  $$      
| $$  | $$      | $$  | $$        | $$        | $$  | $$       /$$  \ $$      
| $$  | $$      | $$$$$$$/       /$$$$$$      |  $$$$$$/      |  $$$$$$/      
|__/  |__/      |_______/       |______/       \______/        \______/       
                                                                              
                                                                              
                                                                              
)" << std::endl;

			std::this_thread::sleep_for(std::chrono::seconds(1));
			break;


		}

	}
}
