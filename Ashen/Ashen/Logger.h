#pragma once
#include <string>
#include <iostream>

class Logger {
public:
    void LogCommand(const std::string& Input); 
    void LogParameter(const std::string& Parameter); 
};
