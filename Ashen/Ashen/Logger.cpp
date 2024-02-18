#include <iostream>
#include "Logger.h"
#include "Parser.h"
const std::string COLOR_RED = "\033[31m"; // Red for Errors
const std::string COLOR_RESET = "\033[0m"; // Reset Color


void Logger::LogCommand(const std::string& Input)
{
    std::cout << "Your Command \"" << Input << "\" is Not Valid" << std::endl;
}

void Logger::LogParameter(const std::string& Parameter)
{
    std::cerr << COLOR_RED << "Invalid Parameter pls validate The Entered Parameter and try again \n" << COLOR_RESET;
}
