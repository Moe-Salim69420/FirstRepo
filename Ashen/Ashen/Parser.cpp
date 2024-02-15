
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
Logger Log;
CommandBase CB;


void Parser::parseInput(std::string &Input){
    std::transform(Input.begin(), Input.end(), Input.begin(), [](unsigned char c) { return std::tolower(c); });
    //Parser try to find the Command
    auto it = CommandBaseMap.find(Input);
    //if yes call the corresponding function
    if (it != CommandBaseMap.end()) {
        // Call the corresponding function from CommandBase
        it->second(Input);
    }
    else {
        // Handle error by the logger
        Log.LogCommand(Input); 
    }
}
    
		