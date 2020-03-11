//Alvin Collier
//11.29.2017
//Search File for numbers

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

ifstream in_stream;
ofstream out_stream;


int main()
{
	
	in_stream.open("input.txt");
	if (in_stream.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	out_stream.open("output.txt");
	if (out_stream.fail())
	{
		cout << "Output file opening failed.\n";
		exit(1);
	}
	

	string currentNumber;
	int arraySize = 0;
	while(getline(in_stream, currentNumber))
	{
		arraySize++;
	}
	//cout << arraySize;
	
	in_stream.clear(); //brings us back to begining of the file after getting array size.
	in_stream.seekg(0, ios::beg);

	double number[arraySize];
	for(int i = 0; i < arraySize; i++)
	{
		in_stream >> number[i];
		getline(in_stream, currentNumber);
		//cout << number[i];
	}
	
	double max = 0;
	double min = 0;
	double sum = 0;
	double average;
	
	for(int i = 0; i < arraySize; i++)
	{
		if(max < number[i])
			max = number[i];
	}
	cout << "The Maximum Number in the File is " << max << ".\n";
	out_stream << "The Maximum Number in the File is " << max << ".\n";
	
	min = max; //to ensure min is a number in the subset of data.
	for(int i = 0; i < arraySize; i++)
	{
		if(min > number[i])
			min = number[i];
	}
	cout << "The Minimum Number in the File is " << min << ".\n";
	out_stream << "The Minimum Number in the File is " << min << ".\n";
	
	for(int i = 0; i < arraySize; i++)
	{
		sum += number[i];
	}
	cout << "The Average Number in the File is " << double(sum/arraySize) << ".\n";
	out_stream << "The Average Number in the File is " << double(sum/arraySize) << ".\n";
}
