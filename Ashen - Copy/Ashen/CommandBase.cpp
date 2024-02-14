#include <unordered_map>
#include <string>
#include "CommandBase.h"
#include "Executor.h"
#include <iostream>
#include <functional>

//using a namespace for CommandFunctions
using CommandFunction = std::function<void(Executor&)>;

// This is the command base : 
std::unordered_map <std::string, CommandFunction> CommandBaseMap = {
	// "List" Command and its acceptable Formats
	{"ls", &Executor::ListDirectory},
	{"List", &Executor::ListDirectory},
	{"LS", &Executor::ListDirectory},


};
