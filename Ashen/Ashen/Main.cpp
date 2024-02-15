// This is the entry point of Ashen
#include <iostream>
#include <filesystem> // For Displaying the Directory Path
#include <string>
#include <sstream>
#include <thread> //  <thread> header for sleep_for
#include <chrono> // header for milliseconds
#include <Windows.h> // Using Windows API 
#include "Parser.h" // Parser Header 
#include "Logger.h" // Logger Header 

// using namespace for std::filesystem
namespace fs = std::filesystem;
//Colors 
const std::string COLOR_PURPLE = "\033[35m";   // Purple for Path
const std::string COLOR_RESET = "\033[0m";     // Reset color

// Main Method
int main() {
	// instantiating a (Parser) object to call the Parser
	Parser Parse; 

	// Welcoming The User (UI) 
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

	
	// THE MAIN LOOP
	while (ASHEN_IS_ON) {
		// Defining the Command
		std::string Input;
		//displaying the current Working Directory
		std::cout << COLOR_PURPLE << fs::current_path().string() << ">" << COLOR_RESET;
		// User Enters the Command
		std::getline(std::cin, Input);

		//  handling white spaces before the command
		Input.erase(0, Input.find_first_not_of(" \t\n\r\f\v"));



		// Executing Simple Commands 



		//handling enter 
		 if (Input.empty()) {
			 continue;
		}

		//Exiting the App
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
		//making the app wait until adios displays
		std::this_thread::sleep_for(std::chrono::seconds(1));
		break;


	}
		
		// Else Pass it to the Parser and let the Carnage Begin
		Parse.parseInput(Input); 


	}
 


}


