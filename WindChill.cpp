//Alvin Collier
//10.25.2017
//Test2 Example
//Wind chill factor (also this is my new rap name.)

/* Algorythm time
calculate wind chill factor
input, windspeed, temperature
output, wind chill index
make a table
step 1: print table heading
step 2: for loop with temp values
step 3: run a function to calculate and print value to table.
step 4: run a function to convert values to celcius
step 5: party hard */

//included everything needed for printing, formatting and math
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

//declaring variables and functions
double const WINDSPEED = 8.5; //constant

static double windChill (double velocity, double temperature);
double convertCelcius (double temperature);

int main()
{
	//printing headers prior to for loop, so we only get one.
	cout << "Temperature(F)\tWindChill\n";
	
	//formatting stuffs
	cout << fixed;
	cout << setprecision(3);
	
	//i acts as both index and temperature value in this situation, it's not ideal but it works in this example really efficiently.
	for(int i = -100; i <=10; i += 10)
	{
		cout << i << "\t\t" << windChill(WINDSPEED, i) << "\n";
	}
	
	//same table but in celcius this time
	cout << "\nTemperature(C)\tWindChill\n";
	for(int i = -100; i <=10; i += 10)
	{
		cout << convertCelcius(i) << "\t\t" << convertCelcius(windChill(WINDSPEED, i))<< "\n";
	}
}

static double windChill (double velocity, double temperature)
{
	//return complex maths, I like putting my maths on one line.. 
	return ( 33 - (((10*sqrt(velocity)-velocity+10.5)*(33-temperature))/23.1));
	
}

double convertCelcius (double temperature)
{
	//more maths, added .0's because int math is lame
	return ((5.0/9.0)*(temperature -32.0));	
}
