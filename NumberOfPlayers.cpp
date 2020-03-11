//Use what you know so far to write some code
//we will be adding arrays and for loops

#include <iostream>

using namespace std;

int main()
{
	
	int numOfPlayers;
	
	cout << "How many people will be playing the game (1-4)";
	cin >> numOfPlayers;
	
	while(numOfPlayers > 4 || numOfPlayers < 1)
	{
		//this while loop makes sure the user doesnt put
		//a negative number of players or too many players
		cout << "That is not a valid response/n";
		cout << "How many people will be playing the game (1-4)";
		cin >> numOfPlayers;
	}
	
	//now that we know how many players are in our game, we can make an array
	//or a group of data to hold all of thier names.
	string playerNames[numOfPlayers];
	
	cout << endl;
	
	//this is a for loop
		//it means that for each i, do everything in this area
		//it will run i until i equals the number of players
		//so once per player
	
	for(int i = 0; i < numOfPlayers; i++)
	{
		
		cout << "What is Player " << (i+1) << "'s Name?";
		//we use i +1 because the computer starts counting from zero
		cin >> playerNames[i]; //now each player name variable is filled with a name
		
	}
	
}
