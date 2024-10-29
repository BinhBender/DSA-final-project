#include <string>
#include <utility>


#pragma once


typedef std::pair<long double,long double> coord;
class City
{

public:

	City();
  	City(std::string,coord, double);
  	std::string get_name() const;
  	coord get_coord() const;
  	double get_aqi() const;


private:
	std::string name;
	coord coordi;
	double aqi;
};
