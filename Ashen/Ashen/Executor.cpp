#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <filesystem>
#include "Executor.h"
#include "CommandBase.h"
#include "Logger.h"


//using fs as a namespace for std::filesystem
namespace fs = std::filesystem;

//COLORS
const std::string COLOR_RED = "\033[31m"; // Red for Error
const std::string COLOR_GREEN = "\033[32m"; // Green for directories
const std::string COLOR_RESET = "\033[0m"; // Reset Color
const std::string COLOR_YELLOW = "\033[33m"; // Yellow for Commands
const std::string COLOR_BLUE = "\033[1;34m"; // Lighter blue for files 
const std::string COLOR_GRAY = "\033[90m"; // Gray color

Logger Log; 


// List Directory Function
const void Executor::ListDirectory(const std::string Input, const std::string Parameter) {
    // Determine the directory to list
    auto directory = fs::current_path(); // Using auto to deduce type
    bool executeLoop = false;

    // using try/catch to handle different errors that interrupts the app to continue sometimes because of the provided Directory
    try {
        if (Parameter.empty()) {
            // No parameter provided, list current directory
            directory = fs::current_path();
            std::cout << COLOR_YELLOW << "Listing Current Directory : \n\n" << COLOR_RESET;
            executeLoop = true; 

        }
        // if the user provided a quoted Parameter/ remove it 
        else if (Parameter.front() == '"' && Parameter.back() == '"') {
            directory = Parameter.substr(1, Parameter.size() - 2);
            executeLoop = true; 
            
        }
        else if (!fs::exists(Parameter)) {
            //Directory Doesnt Exist/Invalid Parameter -> Warn the User and List Current Directory
            Log.LogParameter(Parameter);

        } 
        // if the stupid user wants to list a file
        else if (fs::is_regular_file(Parameter)) {
            std::cout << COLOR_RED<< "You Have Provided a File Idiot \n" <<COLOR_RESET ; 
        }
        else {
            // if its correct -> Use the provided directory
            directory = Parameter ;
            executeLoop = true; 
        }

        // List the directory 
        if (executeLoop){
        
        for (const auto& entryObj : fs::directory_iterator(directory)) {
            if (entryObj.is_directory()) {
                // if its a directory, give it a green Color and print it 
                std::cout  << "/" << COLOR_GREEN << entryObj.path().filename().string() << COLOR_RESET << "\n";
            }
            else {
                // else (file) , give it a Blue Color and print it 
                std::cout << COLOR_BLUE << entryObj.path().filename().string() << COLOR_RESET << "\n";
            }
        }
    }   
        
        }
             
            catch (const std::invalid_argument& e) {
            }
            catch (const std::filesystem::filesystem_error& e) {
            }
            catch (const std::exception& e) {
            }
            catch (const std::system_error& e) {}
        std::cout << "\n\n";
    }



const void Executor::Help(const std::string Input) {
    std::cout <<COLOR_GRAY << "ASHEN COMMANDS : \n ";
	for (const auto& Pair : CommandBaseMap) {
		if (Pair.first != "help") {
            
			std::cout << COLOR_YELLOW << Pair.first << "		" << Pair.second.second << COLOR_RESET << "\n";
		}
		}
}

const void Executor::Clear(const std::string Input) {
	system("cls");
}