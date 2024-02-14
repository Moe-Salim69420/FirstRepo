#pragma once
#include <unordered_map>
#include <string>
#include "Executor.h"

using CommandFunction = std::function<void(Executor&)>;

// Declare extern commandBaseMap with correct function pointer type
extern std::unordered_map<std::string, CommandFunction> commandBaseMap;
