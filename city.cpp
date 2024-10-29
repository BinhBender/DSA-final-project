#include "city.h"

City::City(){
	name = "";
	coordi = coord(0,0);
	aqi = 0;
}

City::City(std::string name, coord coordinates, double aqi){
	this->name = name;
	this->coordi = coordinates;
	this->aqi = aqi;
}
std::string City::get_name() const {
	return name;
} 
coord City::get_coord() const {
	return coordi;
}
double City::get_aqi() const {
	return aqi;
}