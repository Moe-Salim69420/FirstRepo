#include <map>
#include <string>
#include "CommandBase.h"
#include "Executor.h"
#include <iostream>
#include <functional>

//using a namespace for CommandFunctions
using CommandFunction = std::function<void(const std::string&)>;
std::unordered_map<std::string, CommandFunction> CommandBaseMap {
	{"ls", [](const std::string& Input) { Executor executor; executor.ListDirectory(Input); }},
	{"List", [](const std::string& Input) { Executor executor; executor.ListDirectory(Input); }},
	{"help", [](const std::string& Input) {Executor executor; executor.Help(Input); }},
	{"clear", [](const std::string& Input) {Executor executor; executor.Clear(Input); }}

};

bool CommandBase::hasCommand(const std::string& Input)  {
	return CommandBaseMap.find(Input) != CommandBaseMap.end();
}