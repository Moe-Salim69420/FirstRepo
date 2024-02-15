#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <filesystem>
#include "Executor.h"
#include "CommandBase.h"


//using fs as a namespace for std::filesystem
namespace fs = std::filesystem; 

//COLORS
const std::string COLOR_RED = "\033[31m"; // Red for directories
const std::string COLOR_RESET = "\033[0m"; // Reset Color
const std::string COLOR_YELLOW = "\033[33m"; // Yellow for Commands
const std::string COLOR_BLUE = "\033[1;34m"; // Lighter blue for files 



// List Directory Function
const void Executor::ListDirectory(const std::string Input) {
	
	for (const auto& entryObj : fs::directory_iterator(fs::current_path().string())) {

		if (entryObj.is_directory()) {
			std::cout << COLOR_RED << entryObj.path().filename().string() << COLOR_RESET << " ";
		}
		else {

		std::cout << COLOR_BLUE << entryObj.path().filename().string() << COLOR_RESET <<"  ";
		}

	}
	std::cout << "\n\n";
}
const void Executor::Help(const std::string Input) {
	for (const auto& Pair : CommandBaseMap) {
		std::cout << COLOR_YELLOW <<Pair.first << COLOR_RESET<< "\n";
	}
}
const void Executor::Clear(const std::string Input) {
	system("cls");
}