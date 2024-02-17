
// This is the Parser File, Which Fetches The Command from the Main cpp, and Compare it against the command Base. 
// if the Entered Command is in the CommanBase Use the Executor and call it to execute the command
// else pass to the logger to handle the error 

// The Includes 
#include <filesystem>
#include <string>
#include <sstream>
#include "Logger.h"
#include "Parser.h"
#include "CommandBase.h"
#include "Executor.h"

// using fs as a namespace for std::fileSystem
namespace fs = std::filesystem;
CommandBase CB;

void Parser::parseInput(std::string& Input, std::string& Parameter) {
    std::transform(Input.begin(), Input.end(), Input.begin(), [](unsigned char c) { return std::tolower(c); });

 

    auto it = CommandBaseMap.find(Input);
    if (it != CommandBaseMap.end()) {
        // Check if the command function accepts two parameters
        if (it->second.first.target_type() == typeid(std::function<void(const std::string&, const std::string&)>)) {
            // Call the function with two parameters
            it->second.first(Input, Parameter);
        }
        else {
            // Call the function with one parameter
            it->second.first(Input, Parameter);
        }
    }
    else {
        // Handle error by the logger
        Logger Log = Logger(Input);
    }
}