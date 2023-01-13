#pragma once

#include "data.h"

class Profiles
{
public:
	Profiles(string newName = "", int newPoints = 0);

	string getName();
	int getPoints();

	void setName(string newName);
	void setPoints(int newPoints);

private:
	string name;
	int points;

};

fstream& operator<<(std::fstream& lhs, Profiles& rhs);