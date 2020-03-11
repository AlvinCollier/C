//Alvin Collier
//9.5.2017
//BMI Calculations

#include <iostream>

using namespace std;

int main()
{
	double weight;
	double height;
	int age;
	char gender;
	double bmr;
	double numberOfChoco;
	
	cout << "This program will calculate how many chocolate bars you can eat without gaining weight, even if you do not exercise.\n";
	cout << "Let's start by gathering some information\nPlease enter your current weight(in pounds)";
	cin >> weight;
	cout << "\nWow\nThank you.. okay, may I have your height(in inches)";
	cin >> height;
	cout << "\nReally? " << weight << " pounds and " << height << " inches tall huh?\nSorry I am just trying to picture that";
	cout << "\nDon't worry I am a computer program, \nmeaning that I am not capable of judging you";
	cout << "\nHow old are you?";
	cin >> age;
	cout << "\nGross\nFinally what is your gender (m or f)\n";
	cin >> gender;
	cout << "\n...\nComputing...\n";
	system("pause");
	
	if(gender == 'm')
	{
		bmr = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
	}
	else if(gender == 'f')
	{
		bmr = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
	}
	else
	{			
		cout << "\nUnfortunately I require a binary gender response,/nI am a computer after all.";
		bmr = 0;
	}
	
	cout << "\nLooks like you can lay around all day, and still eat " << bmr / 230 << " chocolate bars,\nwhile maintaining your weight\n";
	cout << "\nMy final recommendation is to have a better diet.";
	
}
