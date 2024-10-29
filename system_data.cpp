#include "system_data.h"

//Defining the statics
std::vector<std::string>                SystemData::ListOfCities;
std::unordered_map<std::string,std::vector<std::string>> SystemData::CityPaths;
std::unordered_map<int,City>            SystemData::IndexToCity;
std::unordered_map<std::string, int> 	SystemData::CityNameToIndex;

HashTable<std::string, double> 	SystemData::PM25			= HashTable<std::string, double>();
HashTable<std::string, coord> 	SystemData::cityCoordinates = HashTable<std::string, coord>();
Account* 						SystemData::AccountInUse 	= nullptr;