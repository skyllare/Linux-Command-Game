#include "data.h"

Data::Data(string newCommand, string newDescription)
{
	this->description = newDescription;
	this->command = newCommand;
}

string Data::getCommand()
{
	return this->command;
}

string Data::getDescription()
{
	return this->description;
}

void Data::setCommand(string newCommand)
{
	this->command = newCommand;
}

void Data::setDescription(string newDescription)
{
	this->description = newDescription;
}

fstream& operator<<(std::fstream& lhs, Data& rhs)
{
	lhs << rhs.getCommand() << ","
		<< rhs.getDescription()  << endl;
	return lhs;
}