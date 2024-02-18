#pragma once
#include <iostream>
#include <functional>
class Executor {

public: 
	//listing directory command function
	const void ListDirectory(const std::string Input, const std::string Parameter);
	// Help command to list the Registered Commands
	const void Help(const std::string Input );
	//clear console command 
	const void Clear(const std::string Input);
	const void ChangeDirectory(const std::string Input, const std::string Parameter);

};