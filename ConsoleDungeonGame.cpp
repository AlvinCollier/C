/*	Alvin Collier
	2017 Dragoon Domain All rights reserved
	Super Extra Console Dungeon Game
	Explore a rich text environment, where you will explore a
	dungeon consisting of infinite level, each with multiple
	paths, which are basically random, and your only objective
	is to collect treasure.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

ifstream fin;
ofstream fout;

int treasureFind(int currentFloor);
int monsterFight(int treasure, int currentFloor);
int deathTrap(int currentFloor);
int deathTreasureLoss(int treasure, int currentFloor);

int main()
{
	char response;
	bool save;
	string name, line, fileName;
	int treasure = 0, level = 0, maxFloor = 1, currentFloor = 1, randomEvent;
	
	cout << "Welcome adventurer!\n";
	cout << "What is your name hero?";
	cin >> name;
	fileName = name + "ConsoleDungeonSave.txt";
	char *cstr = new char[fileName.length() +1];
	strcpy(cstr, fileName.c_str());
	//cout << cstr; used for testing
	fileName.c_str();
	fin.open(cstr);
	if(fin.fail())
	{
		cout << "We could not find any saved data, create one now?(y/n)\n";
		cin >> response;
		while(response != 'y' && response != 'Y' && response != 'n' && response != 'N')
		{
			
			cout << "I did not understand your response.\n";
			cout << "We could not find any saved data, create one now?(y/n)\n";
			cin >> response;
		}
		if(response == 'y' || response == 'Y')
		{
			save = true;
			fout.open(cstr, ios::trunc);
			if(fout.fail())
			{
				//cout << "We had trouble creating save data.\n";
				//cout << "You can play without saving but you will loose any progress\n";
				//cout << "when you quit.\n";
				//save = false;
				
				//return -1;
			}
			fout << name << " " << treasure << " " << maxFloor << " " << currentFloor;
			
			fin.open(cstr);
			fin >> name >> treasure >> maxFloor >> currentFloor;
		}
		if(response == 'n' || response == 'N')
		{
			cout << "You can play without saving but you will loose any progress\n";
			cout << "when you quit.\n";
			save = false;
		}
	}
	else
	{
		while(getline(fin, line))
		{
			fin >> name >> treasure >> maxFloor >> currentFloor;
		}
		save = true;
	}
	fout.open(cstr, ios::trunc);
	if(fout.fail())
			{
				cout << "We had trouble creating save data.\n";
				cout << "You can play without saving but you will loose any progress\n";
				cout << "when you quit.\n";
				save = false;
				
				//return -1;
			}
	
	
	cout << "\n";
	//cout << "Welcome " << name << ", hit any key to enter the dungeon\n";
	//cin >> response;
	//currentFloor ++;

	cout << "You enter the dungeon, ready to face what ever dangers await...\n\n";
	system("pause");
	cout << endl << endl;
	do
	{
		cout << name << "\tTreasure: " << treasure << "\tCurrent Floor: " << currentFloor << "\tMax Floor: " << maxFloor << "\n\n";
		if(save)
		{
			fout << name << " " << treasure << " " << maxFloor << " " << currentFloor << "\n";
		}
			
		
		cout << "Before you lies three doors...\n\n";
		cout << "_______________________________________________\n";
		cout << "||----\\ /----||_||----\\ /----||_||----\\ /----||\n";
		cout << "||___________||_||___________||_||___________||\n";
		cout << "|| |       | ||_|| |       | ||_|| |       | ||\n";
		cout << "|| |  **   | ||_|| |  ***  | ||_|| |  ***  | ||\n";
		cout << "|| |   *   | ||_|| | *   * | ||_|| | *   * | ||\n";
		cout << "|| |   *   | ||_|| |     * | ||_|| |   **  | ||\n";
		cout << "|| |   *   | ||_|| |   **  | ||_|| | *   * | ||\n";
		cout << "|| | ***** | ||_|| | ***** | ||_|| |  ***  | ||\n";
		cout << "_______________________________________________\n";
		cout << "Press (1, 2 or 3) To Select a Door(o for other options):";
		cin >> response;
		
		srand (time(NULL));
		randomEvent = rand() %6;
		
		if(response == '1' || response == '2' || response == '3')
		{
			cout << "Behind door number " << response << "...\n";
			currentFloor++;
				if(currentFloor > maxFloor)
				{
					maxFloor = currentFloor;		
				}
			switch(randomEvent)
				{
					case 0:
						if(response == '1')
							treasure += monsterFight(treasure, currentFloor);
						if(response == '2')
							treasure += treasureFind(currentFloor);
						if(response == '3')
							currentFloor = deathTrap(currentFloor);
						
						break;
					case 1:
						if(response == '1')
							treasure += monsterFight(treasure, currentFloor);
						if(response == '3')
							treasure += treasureFind(currentFloor);
						if(response == '2')
							currentFloor = deathTrap(currentFloor);
							
						break;
					case 2:
						if(response == '2')
							treasure += monsterFight(treasure, currentFloor);
						if(response == '1')
							treasure += treasureFind(currentFloor);
						if(response == '3')
							currentFloor = deathTrap(currentFloor);
							
						break;
					case 3:
						if(response == '3')
							treasure += monsterFight(treasure, currentFloor);
						if(response == '1')
							treasure += treasureFind(currentFloor);
						if(response == '2')
							currentFloor = deathTrap(currentFloor);
						
						break;
					case 4:
						if(response == '2')
							treasure += monsterFight(treasure, currentFloor);
						if(response == '3')
							treasure += treasureFind(currentFloor);
						if(response == '1')
							currentFloor = deathTrap(currentFloor);
						
						break;
					default:
						if(response == '3')
							treasure += monsterFight(treasure, currentFloor);
						if(response == '2')
							treasure += treasureFind(currentFloor);
						if(response == '1')
							currentFloor = deathTrap(currentFloor);
						
						break;
				}
		}
		else if(response == 'o' || response == 'O')
		{
			cout << "Options: \n";
			cout << "'o'' for Options: Opens this menu.\n";
			cout << "'e'' for Exit: Quits the game.\n";
			cout << "'r' for Return: To return to floor 1.\n";
			cin >> response;
		}
		else if(response == 'r' || response == 'R')
		{
			cout << "You return safely to the entrace.\n";
			currentFloor = 1;
		}
		
	}while(response != 'e' && response != 'E');
	
	fin.close();
	fout.close();
}

int treasureFind(int currentFloor)
{
	cout << "\nYou find " << (currentFloor*3) << " treasure!\n\n";
	system("pause");
	cout << endl << endl;
	return(currentFloor*3);
}

int monsterFight(int treasure, int currentFloor)
{
	int num1, num2, mathOperator;
	double answer,  correctAnswer;
	
	cout << "You encounter a Monster!\n\n";
	cout << "|\\_______/|\n";
	cout << "|         |\n";
	cout << "| \\\\   // |\n";
	cout << "\\         /\n";
	cout << " \\ vvvvv / \n";
	cout << "  ^^^^^^^  \n";
	cout << "Solve the math problem to defeat it!\n";
	srand (time(NULL));
	num1 = rand() %currentFloor;
	num2 = rand() %currentFloor +1;
	mathOperator = num1 = rand() %4;
	switch(mathOperator)
	{
		case 0:
			correctAnswer = num1 + num2;
			cout << num1 << " + " << num2 << " = ";
			break;
		case 1:
			if(num1 > num2)
			{
				correctAnswer = num1 - num2;
				cout << num1 << " - " << num2 << " = ";
			}
			else
			{
				correctAnswer = num2 - num1;
				cout << num2 << " - " << num1 << " = ";
			}
			
			break;
		case 2:
			correctAnswer = num1 * num2;
			cout << num1 << " * " << num2 << " = ";
			break;
		default:
			correctAnswer = 1.0 * num1 / num2;
			cout << num1 << " / " << num2 << " = ";
			break;
	}
	cin >> answer;
	if(answer == correctAnswer)
	{
		cout << endl;
		cout << "Congratulations!~ You defeated the monster and got...\n";
		cout << (currentFloor *5) << " Treasure!\n\n";
		system("pause");
		cout << endl << endl;
		return(currentFloor*5);
	}
	else
	{
		cout << endl;
		cout << "Sorry the correct answer was " << correctAnswer << "\n\n";
		cout << "The monster defeated you and... ";
		
		return(deathTreasureLoss(treasure, currentFloor));
	}
	
}

int deathTrap(int currentFloor)
{
	cout << "You are caught in a trap and die!\n\n";
	cout << "You return to the begining of the dungeon";
	cout << "You enter the dungeon, ready to face\nwhat ever dangers await...\n\n";
	system("pause");
	cout << endl << endl;
	return(1);
}

int deathTreasureLoss(int treasure, int currentFloor)
{
	int lostTreasure = 0;
	lostTreasure = treasure * -(1.0-(1.0/currentFloor));
	cout << "You lost " << lostTreasure << " treasure.\n\n";
	system("pause");
	cout << endl << endl;
	return(lostTreasure);
}

