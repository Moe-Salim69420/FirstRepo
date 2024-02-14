#include <iostream>
#include <string>
#include <filesystem>
#include "Executor.h"
#include "CommandBase.h"


//using fs as a namespace for std::filesystem
namespace fs = std::filesystem; 

// List Directory Function
void Executor::ListDirectory(std::string Input) {
	for (const auto& entryObj : fs::directory_iterator(fs::current_path().string())) {
		std::cout << entryObj.path().filename() << "\n"; 
	}
}
