#pragma once
#include "menu.h"

class Data
{
public:
	Data(string newCommand = "", string newDescription = "");		//constructor 
	string getCommand();
	string getDescription();

	void setCommand(string newCommand);
	void setDescription(string newDescription);

private:
	string command;
	string description;



};

fstream& operator<<(std::fstream& lhs, Data& rhs);