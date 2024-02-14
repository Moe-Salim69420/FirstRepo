
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


// using fs as a namespace for std::fileSystem
namespace fs = std::filesystem; 



void Parser::parseInput(std::string &Input){
	
		
}