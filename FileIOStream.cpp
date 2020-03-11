//Alvin Collier
//11.27.2017
//File Input/Output
//Yes I know I missed class and I am really sorry.

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

ifstream in_stream;
ofstream out_stream;

int main()
{

	in_stream.open("input.dat");
	if (in_stream.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	out_stream.open("output.dat");
	if (out_stream.fail())
	{
		cout << "Output file opening failed.\n";
		exit(1);
	}	
	int first, second, third;
	in_stream >> first >> second >> third;
	out_stream << "The sum of the first 3\n"
	<< "numbers in input.dat\n"
	<< "is " << (first + second +third)
	<< endl;
	
	cout << "The sum of the first 3\n"
	<< "numbers in input.dat\n"
	<< "is " << (first + second +third) << endl;
	
	cout << "the numbers are.. " << first << ", " << second << ", " << third << endl;
	in_stream.close( );
	out_stream.close( );
	return 0;

}
