#include "profiles.h"

Profiles::Profiles(string newName, int newPoints)
{
	this->name = newName;
	this->points = newPoints;
}

string Profiles::getName()
{
	return this->name;
}

int Profiles::getPoints()
{
	return this->points;
}

void Profiles::setName(string newName)
{
	this->name = newName;
}

void Profiles::setPoints(int newPoints)
{
	this->points = newPoints;
}


fstream& operator<<(std::fstream& lhs, Profiles& rhs)
{
	lhs << rhs.getName() << ","
		<< rhs.getPoints() << endl;
	return lhs;
}