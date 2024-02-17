#include <map>
#include <string>
#include "CommandBase.h"
#include "Executor.h"
#include <iostream>
#include <functional>

// using a namespace for CommandFunctions
using CommandFunction = std::function<void(const std::string&, const std::string&)>;

// Define a pair type that stores CommandFunction and description


// Define an unordered map that maps command names to CommandPair
std::unordered_map<std::string, std::pair<CommandFunction, std::string>> CommandBaseMap{
    {"ls", {[](const std::string& Input, const std::string& Parameter) { Executor executor; executor.ListDirectory(Input, Parameter); }, "Listing Directory Contents"}},
    {"list", {[](const std::string& Input, const std::string& Parameter) { Executor executor; executor.ListDirectory(Input, Parameter); }, "Listing Directory Contents"}},
    {"help", {[](const std::string& Input, const std::string& Parameter) { Executor executor; executor.Help(Input); }, "KHELPO "}},
    {"clear", {[](const std::string& Input, const std::string& Parameter) { Executor executor; executor.Clear(Input); }, "Clearing The Console"}}
};

bool CommandBase::hasCommand(const std::string& Input) {
    return CommandBaseMap.find(Input) != CommandBaseMap.end();
}
