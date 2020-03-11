//Alvin Collier
//9.5.17
//Math Example Problem
//Solving quadradic equations

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	
	double a, b, c, r1, r2, descrim;
	
	cout << "Find the two roots of a quadratic equation\n";
	cout << "\nPlease Eneter a value for a: ";
	cin >> a;
	cout << "\nPlease Eneter a value for b: ";
	cin >> b;
	cout << "\nPlease Eneter a value for c: ";
	cin >> c;
	
	//Tried using Math.pow, kept getting Math is not defined
	//I probably did something wrong, put it works if I include
	//the math.h library.
	
	r1 = ((-1.0 *b) + sqrt(pow(b, 2.0) - 4.0 * a * c))/(2.0 * a);
	r2 = ((-1.0 *b) - sqrt(pow(b, 2.0) - 4.0 * a * c))/(2.0 * a);
	
	descrim = pow(b, 2) - (4 * a * c);
	
	if(descrim > 0)
	{
		cout << "\nThe equation has two roots " << r1 << " and "<< r2;
	}
	else if(descrim == 0)
	{
		cout << "\nThe equation has one root " << r1 << " and "<< r2;
	}
	else if(descrim < 0)
	{
		cout << "\nThe equation has no real roots. ";
	}
	
}
