#include "Terminal.h"
#include <iostream>
#include "Parser.h"
#include <string>

void Terminal::run() 
{
	//create parser object 
	Parser parser;

	std::string command;

	//welcome message
	std::cout << "Ashin is ON";

	//main loop
	while (true) 
	{
	//get user input
		std::cout << ">";
		std::getline(std::cin,command);

		if (command == "exit") 
		{

			break;
		
		}
	
	//proccess user input
	parser.processCommand(command);
	}


	

	//output
	
}