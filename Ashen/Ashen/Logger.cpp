#include <iostream>
#include "Logger.h"
#include "Parser.h"


Logger::Logger(const std::string& input) {
    std::cout << "Your Command \"" << input << "\" is Not Valid" << std::endl;
}

