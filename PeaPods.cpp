#include <iostream>

using namespace std;

int main()
{
	int numberOfPods, peasPerPod, totalPeas;
	cout << "Press return after entering a number. \n";
	cout << "Enter the number of pods:\n";
	
	cin >> numberOfPods;
	
	cout << "Enter the number of peas in a pod:\n";
	
	cin >> peasPerPod;
	totalPeas = numberOfPods * peasPerPod;
	
	cout << "If you have "<< numberOfPods<<" pea pods\n";
	cout << "and " << peasPerPod << " peas in each pod, then\n";
	cout << "you have " << totalPeas << " peas in all";
}
