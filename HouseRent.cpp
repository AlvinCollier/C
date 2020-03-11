//Alvin Collier
//12.1.2017
//House Rent

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <windows.h> //this is os dependent but I used it to highlight the good deals. And Bad Ones.

using namespace std;

ifstream fin;
ofstream fout;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

double getHousingPE(int price, int rent);

int main()
{
	
	fin.open("housingPriceAndRent.txt");
	if (fin.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	fout.open("housingPriceOutput.txt");
	if (fout.fail())
	{
		cout << "Output file opening failed.\n";
		exit(1);
	}
	
	string line; //I am aware the problem specifically states the array should be 100
	int size = 0; //However I perfer to get the total number of lines from the file
	while(getline(fin, line)) //this allows the user to use multiple different lists
	{
		size++;
	}
	//cout << arraySize;
	
	fin.clear(); //brings us back to begining of the file after getting array size.
	fin.seekg(0, ios::beg);
	
	int housePrice[size];
	int rentalCost[size];
	double housePE[size];

	
	for(int i = 0; i < size; i++)
	{
		SetConsoleTextAttribute(hConsole, 7);
		fin >> housePrice[i];
		fin >> rentalCost[i];
		housePE[i] = getHousingPE(housePrice[i], rentalCost[i]);
		//cout << housePrice[i] << " " << rentalCost[i] << "\n";
		if(housePE[i] < 9)
		{
			SetConsoleTextAttribute(hConsole, 14);
			cout << "Buy House # "<< i << " it is a deal!\n";
			fout << "Buy House # "<< i << " it is a deal!\n";
		}
		else if(housePE[i] >= 9 &&housePE[i] < 12)
		{
			cout << "House # "<< i << " might be a good deal.\n";
			fout << "House # "<< i << " might be a good deal.\n";
		}
		else if(housePE[i] >= 12 &&housePE[i] <= 16)
		{
			cout << "House # "<< i << " is average.\n";
			fout << "House # "<< i << " is average.\n";
		}
		else if(housePE[i] > 16 &&housePE[i] <= 19)
		{
			cout << "House # "<< i << " is somewhat overpriced.\n";
			fout << "House # "<< i << " is somewhat overpriced.\n";
		}
		else if(housePE[i] > 19)
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "House # "<< i << " is WAY overpriced!\n";
			fout << "House # "<< i << " is WAY overpriced!\n";
		}
	}
	
	fin.close();
	fout.close():
	
}

double getHousingPE(int price, int rent)
{
	return(double(price/(rent*12.0)));
}
