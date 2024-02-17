#pragma once

#include <unordered_map>
#include <string>
#include "Executor.h"
#include <functional>

// Define the CommandFunction type
using CommandFunction = std::function<void(const std::string&, const std::string&)>;

// Declare the CommandBaseMap as an external variable
extern std::unordered_map<std::string, std::pair<CommandFunction, std::string>> CommandBaseMap;

class CommandBase {
public:
    bool hasCommand(const std::string& Input);
};
