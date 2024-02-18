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
        // current path displays, and user enters the command with its parameter
        std::cout << COLOR_PURPLE << fs::current_path().string() << ">" << COLOR_RESET;
        std::getline(std::cin, Input);
        size_t firstNonSpaceIndex = Input.find_first_not_of(" \t\n\r\f\v");

        // Extracting the command starting from the first non-whitespace character
        std::string Command = (firstNonSpaceIndex != std::string::npos) ? Input.substr(firstNonSpaceIndex) : "";

        // Finding the index of the first space character after the command
        size_t spaceIndex = Command.find(' ');

        // Extracting the parameter starting from the character after the command
        std::string Parameter = "";
        if (spaceIndex != std::string::npos) {
            // If space is found, extract parameter from the character after the space
            Parameter = Command.substr(spaceIndex + 1);
            // Update the Command to contain only the command without the parameter
            Command = Command.substr(0, spaceIndex);
        }
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
        Parse.parseInput(Command, Parameter);
    }

 


}


