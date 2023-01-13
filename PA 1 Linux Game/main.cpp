
#include "profiles.h"
bool deleteNode(string nodeName, List<Data>* list, int listSize);
int playGame(int listSize, List<Data>* list);
int main(void)
{
	fstream commandsFile, profilesFile;
	List<Data>* commandsList = new List<Data>(nullptr);
	Profiles profileList[10];
	srand(time(NULL));


	commandsFile.open("commands.csv", std::ios::in);
	while (!commandsFile.eof())
	{
		string command, description;
		getline(commandsFile, command, ',');
		getline(commandsFile, description, '\n');

		Data temp(command, description);
		commandsList->insertNode(temp);

	}
	commandsFile.close();

	int menuAnswer = 0;

	do {
		system("CLS");

		srand((unsigned)time(NULL));
		int listSize = 0;
		listSize = commandsList->countNodes();
		Menu mainMenu;
		menuAnswer = mainMenu.choice();
			system("CLS");
			profilesFile.open("profiles.csv", std::ios::in);
			int i = 0;
			while (!profilesFile.eof())
			{
				string profileName, profilePoints;
				getline(profilesFile, profileName, ',');
				getline(profilesFile, profilePoints, '\n');
			
				profileList[i].setName(profileName);
				int profilePointsInt = '/0';
				if (profilePoints != "")
				{
					profilePointsInt = stoi(profilePoints);
				}
				profileList[i].setPoints(profilePointsInt);
				i++;
			}
			profilesFile.close();
		if (menuAnswer == 1)
		{
			//display rules 

			cout << "RULES" << endl << "in the game, you chose how many commands you want to be prompted with " << endl <<
				"You will be shown one at a time and be given 3 descriptions, 1 of which is correct" << endl<<
				"Pick the correct description, you can a point, pick the wrong oneand you lose a point"<<endl;		//ADD RULES
			cout << "Enter any key to continue" << endl;
			string input;
			cin >> input;
		}
		if (menuAnswer == 2)
		{

			cout << "Enter name" << endl << endl;
			string name;
			getline(cin, name);
			getline(cin, name);
			Profiles temp(name, 0);
			int points;
			points = playGame(listSize, commandsList);
			temp.setPoints(temp.getPoints() + points);
			profileList[i+1] = temp;

			//profilesFile.open("profiles.csv", std::ios::in);
			//while (!profilesFile.eof())
			//{
			//	string profileName, profilePoints;
			//	getline(profilesFile, profileName, ',');
			//	getline(profilesFile, profilePoints, '\n');
			//	int i =	1;
			//	if (profileName != "" && profileName != profileList[0].getName())
			//	{
			//		profileList[i].setName(profileName);
			//		profileList[i].setPoints(stoi(profilePoints));
			//	}
			//
			//	i++;
			//}
			//profilesFile.close();

		}
		if (menuAnswer == 3)
		{
			
			cout << "Enter name" << endl;
			string enteredName;
			getline(cin, enteredName);
			getline(cin, enteredName);
			bool found = false;
			int profileNumber;
			
			for (int i = 0; i < 10; i++)
			{
				if (profileList[i].getName() == enteredName)
				{
					profileNumber = i;
					cout << "found your profile. Game will begin" << endl;
					i = 10;
					found = true;
				}

			}
			if (found == false)
			{
				cout << "profile could not be found. sending back to main menu." << endl <<
					"press any key to continue" << endl;
				string responce;
				getline(cin, responce);
			}
			int points;
			points = playGame(listSize, commandsList);
			profileList[profileNumber].setPoints(profileList[profileNumber].getPoints() + points);
			
		}
		if (menuAnswer == 4)
		{

			cout << "You chose to add a command" << endl << "Enter the command name: " << endl;
			string newCommandName;
			getline(cin, newCommandName);
			getline(cin, newCommandName);
			cout << "Enter the command description name: " << endl;
			string newDescriptionName;
			getline(cin, newDescriptionName);
			Data newDataNode = Data(newCommandName, newDescriptionName);
			commandsList->insertNode(newDataNode);
	
		

		}
		if (menuAnswer == 5)
		{
			cout << "You chose to delete a command" << endl << "Enter the command name: " << endl;
			string newCommandName;
			getline(cin, newCommandName);
			getline(cin, newCommandName);
			deleteNode(newCommandName, commandsList, listSize);
		

		}
		if (menuAnswer == 6)
		{
			
			//print profiles back to csv file

			//prints linked list back to file with edits made (commands added/deleted)
			commandsFile.open("commands.csv", std::ios::out);
			profilesFile.open("profiles.csv", std::ios::out);
			Node<Data>* pCur = commandsList->getHead();
			for (int i = 0; i < listSize; i++)
			{
				Data temp = pCur->getData();

				commandsFile << temp;


				pCur = pCur->getNext();
			}
			for (int i = 0; i < 10; i++)
			{
				if (profileList[i].getName() != "")
				{
					profilesFile << profileList[i];
				}

			}
			commandsFile.close();
			profilesFile.close();
			menuAnswer = 7;
		}

	
	} while (menuAnswer > 0 && menuAnswer < 7);		//this will make choice  6 and any invalid choice exit the game



	return 0;

}



int playGame(int listSize, List<Data>* list)
{
	int pointsEarned = 0;
	cout << "How many commands would you like to generate?" << endl;
	int commandNumberChoice;
	cin >> commandNumberChoice;
	cout << "Your game is starting! Generating " << commandNumberChoice << " commands" << endl;
	int randomNumberArray[100] = {};
	for (int i = 0; i < commandNumberChoice; i++)	//generates as many random numbers as there are commands requested
	{
		int tempRand = 1 + (rand() % listSize);
		if (randomNumberArray[tempRand] == 1)
		{
			do
			{
				tempRand = 1 + (rand() % listSize);
			} while (randomNumberArray[tempRand] == 1);

		}
		//above is all generation of random commands

		randomNumberArray[tempRand] = 1;
	}
	//above has all the spots needed in the array set to 1

	//now the game begins
	for (int j = 0; j < listSize; j++)	//Runs game as requested
	{
		Node<Data>* pCur = list->getHead();

		if (randomNumberArray[j] == 1)
		{
			for (int i = 0; i < j; i++)	//goes to the spot in the linked list where the array said to go
			{
				pCur = pCur->getNext();
			}
			cout << pCur->getData().getCommand() << endl;	//prints the random command

			// add 2 random descriptions and the correct one
			int randomCommandTemp1 = 1 + (rand() % listSize);
			int randomCommandTemp2 = 1 + (rand() % listSize);

			string commands[3] = { "","","" };
			Node<Data>* commandTemp1 = list->getHead();
			for (int i = 0; i < randomCommandTemp1; i++)
			{
				commandTemp1 = commandTemp1->getNext();
			}

			Node<Data>* commandTemp2 = list->getHead();
			for (int i = 0; i < randomCommandTemp2; i++)
			{
				commandTemp2 = commandTemp2->getNext();
			}

			int arrayRand1 = (rand() % 3);
			commands[arrayRand1] = commandTemp1->getData().getDescription();
			int arrayRand2 = 0;
			do
			{
				arrayRand2 = (rand() % 3);

			} while (arrayRand2 == arrayRand1);
			commands[arrayRand2] = commandTemp2->getData().getDescription();
			int correctChoice = 0;
			do
			{
				correctChoice = (rand() % 3);
			} while (correctChoice == arrayRand1 || correctChoice == arrayRand2);
			commands[correctChoice] = pCur->getData().getDescription();

			cout << "1. " << commands[0] << endl << "2. " << commands[1] << endl << "3. " << commands[2] << endl <<
				"enter which choice you think matches with the commands name" << endl;
			int descChoice = 0;
			cin >> descChoice;
			if (descChoice == 1)
			{
				descChoice = 0;
			}
			if (descChoice == 2)
			{
				descChoice = 1;
			}
			if (descChoice == 3)
			{
				descChoice = 2;
			}

			if (descChoice == correctChoice)
			{
				cout << "that's correct! +1 point" << endl;
				pointsEarned++;
			}
			else
			{
				cout << "that's incorrect! -1 point" << endl;
				pointsEarned--;
			}


		}
	}




	return pointsEarned;
}

bool deleteNode(string nodeName, List<Data>* list, int listSize)
{
	Node<Data>* pCur = list->getHead();
	Node<Data>* pDel = list->getHead();
	int i = 0;
	if (i < listSize)
	{
		if (pDel->getData().getCommand() == nodeName)
		{
			pCur = pDel->getNext();
			if (pDel->getData().getCommand() == list->getHead()->getData().getCommand())
			{
				list->setHead(pCur);
			}
			delete pDel;
			return true;
		}
		else
		{
			pCur = pCur->getNext();
			pDel = pCur->getNext();
		}
		i++;
	}
	cout << "Command was not found" << endl;
	return false;
}
 