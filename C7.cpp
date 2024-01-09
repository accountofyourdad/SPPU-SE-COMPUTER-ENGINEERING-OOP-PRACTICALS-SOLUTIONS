/*
  Write a program in C++ to use map associative container.
  The keys will be the names of states and the values will be the populations of the states.
  When the program runs, the user is prompted to type the name of a state. +
  The program then looks in the map, using the state name as an index and returns the population of the state.
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	// Create a map of state names and populations
	map<string, int> statePopulations;			// map created with name statepopulation
	{
		// Add some states and populations (modify as needed)statePopulations.insert(make_pair("Maharashtra", 125));
		statePopulations.insert(make_pair("Uttar Pradesh", 225));
		statePopulations.insert(make_pair("Bihar", 120));
		statePopulations.insert(make_pair("West Bengal", 100));
		statePopulations.insert(make_pair("Madhya Pradesh", 90));
		statePopulations.insert(make_pair("Tamil Nadu", 80));
		statePopulations.insert(make_pair("Rajasthan", 78));
		statePopulations.insert(make_pair("Andhra Pradesh", 53));
		statePopulations.insert(make_pair("Odisha", 47));
		statePopulations.insert(make_pair("Kerala", 38));
		statePopulations.insert(make_pair("Telangana", 37));
		statePopulations.insert(make_pair("Assam", 35));
		statePopulations.insert(make_pair("Jharkhand", 38));
		statePopulations.insert(make_pair("Karnataka", 68));
		statePopulations.insert(make_pair("Gujarat", 70));
		statePopulations.insert(make_pair("Punjab", 31));
		statePopulations.insert(make_pair("Chhattisgarh", 30));
		statePopulations.insert(make_pair("Haryana", 29));
		statePopulations.insert(make_pair("UT Delhi", 19));
		statePopulations.insert(make_pair("UT Jammu and Kashmir", 14));
		statePopulations.insert(make_pair("Uttarakhand", 12));
		statePopulations.insert(make_pair("Himachal Pradesh", 8));
		statePopulations.insert(make_pair("Tripura", 04));
		statePopulations.insert(make_pair("Meghalaya", 4));
		statePopulations.insert(make_pair("Manipur[", 3));
		statePopulations.insert(make_pair("Nagaland", 2));
		statePopulations.insert(make_pair("Goa", 2));
		statePopulations.insert(make_pair("Arunachal Pradesh", 2));
		statePopulations.insert(make_pair("UT Puducherry", 2));
		statePopulations.insert(make_pair("Mizoram", 1));
		statePopulations.insert(make_pair("UT Chandigarh", 1));
		statePopulations.insert(make_pair("Sikkim", 1));
		statePopulations.insert(make_pair("UT Dadra and Nagar Haveli and Daman and Diu", 1));
		statePopulations.insert(make_pair("UT Andaman and Nicobar Islands", 1));
		statePopulations.insert(make_pair("UT Lakshadweep", 0.0003));
		statePopulations.insert(make_pair("UT Ladakh", 0.00006));
		// ... Add other states ...
	}
	// Prompt user for state name
	string stateName;
	cout << "Enter the name of a state: ";
	cin >> stateName;

	// Check if state exists in the map
	if (statePopulations.count(stateName) > 0)
	{
		int population = statePopulations[stateName];		// here key is passed with the mapname so that the value will be returned
		cout << "The population of " << stateName << " is " << population << endl;
	}
	else
	{
		cout << "State not found in the map!" << endl;
	}

	return 0;
}