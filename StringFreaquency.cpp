//Alvin Collier
//11.1.2017
//test 2 practice yet again
//mersennes law

#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

//input: diameter, density
//output mass per unit
// print table header
// create for loop for diameter, print results each line
//

//global constants
double PI = 3.14159265;

//functions
double massPerUnitLength(double diameter, double density);
double frequency(double tension, double length, double diameter, double density);
double tension(double freqency, double length, double density, double diameter);

int main()
{
	//formatting stuff
	cout << fixed;
	//cout << setprecision(5);
	
	//table variables, header and loop
	double density = 0.5;
	cout << "Diameter\tDensity\tMass per unit\n";
	for (int i=1; i <= 49; i += 4)
	{
		cout << i << "\t\t" << setprecision(1) << density << "\t" << setprecision(5) << massPerUnitLength(i,density) << "\n";
	}
	
	//tension table
	int diameter =5;
	int length = 85;
	cout << "Tension\tLength\tFrequency\n";
	for (int i = 42; i >= 34; i --)
	{
		cout << i << "\t" << length << "\t" << frequency(i,length, diameter, density) << "\n";
		length -= 4;
	}
	
	cout << "\n\n";
	cout << "The Tension of g' If you have a string of length 0.59m, \na density of 1360 kg/m^3 and a diameterof 0.4 mm is...\n";
	cout << tension(392, 0.59, 1360, 0.4);
}

double massPerUnitLength(double diameter, double density)
{
	return (PI*pow(0.5*diameter,2)*density);
}

double frequency(double tension, double length, double diameter, double density)
{
	//what im getting in the table does not match what is in the example, even when I use your exact code...
	double mass = massPerUnitLength(diameter, density);
	double f = (1/(2.0 * length)) * (sqrt(tension)) * (1/sqrt(mass));
	return f;
}

double tension(double freq, double length, double density, double diameter)
{
	double t;
	double mass = massPerUnitLength(diameter, density);
	freq = freq	/(1.0/sqrt(mass));
	freq = freq /(1.0/(2.0 *length));
	t = pow(freq,2.0);
	return t;
}
