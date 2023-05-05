#include "Parser.h"
#include <sstream>
#include <vector>
#include <iostream>

void Parser::processCommand(std::string command) 
{
    std::stringstream ss(command);
    std::string token;
    std::vector<std::string> tokens;

    while (ss >> token) {
        tokens.push_back(token);
    }


        for (size_t i = 0; i < tokens.size(); i++)
        {
            std::cout << tokens[i]<<" ";
        }
    
}