#include "menu.h"

Menu::Menu()
{
	cout << "Please select an option listed below" << endl << "1. Game Rules" << endl << "2. Play Game"
		<< endl << "3. Load Previous Game" << endl << "4. Add Command" << endl <<
		"5. Remove Command" << endl << "6. Exit" << endl;
}

int Menu::choice()
{
	int answer;
	cin >> answer;
	return answer;
}