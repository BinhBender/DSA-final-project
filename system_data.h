
#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include "city.h"
#include "hashtable.h"
#include "accounts.h"

class SystemData{
public:
	//Holds every city in the system
	static std::vector<std::string> ListOfCities;
	
	//Holds the path of each city
	static std::unordered_map<std::string, std::vector<std::string>> CityPaths;
	//Index of the city to its number
	static std::unordered_map<int,City> IndexToCity; //essentially the same thing as ListOfCities

	//To hold the PM2.5 info for each city
	static HashTable<std::string, double> PM25;

	//Maps the city name to their coordinates
	static HashTable<std::string, coord> cityCoordinates;

	//Get the index from the name
	//Because the pathfinder uses ints in order work, we need something to convert the strings to the ints the cities correspond to
	static std::unordered_map<std::string, int> CityNameToIndex;

	//This is the current that is being use at the instant.
	static Account* AccountInUse;

};

