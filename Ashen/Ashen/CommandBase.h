#pragma once
#include <unordered_map>
#include <string>
#include "Executor.h"
#include "Parser.h"
#include <set>
using CommandFunction = std::function<void(const std::string&)>;

extern std::unordered_map<std::string, CommandFunction> CommandBaseMap;

class CommandBase {
public :
	bool hasCommand(const std::string& Input);

};