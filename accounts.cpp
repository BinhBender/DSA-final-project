#include "accounts.h"

Account::Account(){
	username = "";
	sensitivity_level = 0;
}
 

 Account::Account (std::string user, int level){
	username = user;
	sensitivity_level = level;
}

void Account::new_account() {
	std::cout << "Hey there! Let's create an account for you.\n"
		<< "What do you want your username to be? \n";
	std::string user = word_val();
	username = user;
	std::cout << "Great! What is your sensitivity level?\n" 
	<< "(1) Low ( < 200 AQI)\n" << "(2) Average ( < 150 AQI)\n" << "(3) High ( < 50 AQI)\n";
	int level = (menu_val(3) * 50) + 50;
	sensitivity_level = level;

}

void Account::set_username(std::string user){
	username = user;
}

void Account::set_level(int level){
	sensitivity_level = level;
}

std::string Account::get_username() const {
	return username;
}

int Account::get_level() const {
	return sensitivity_level;
}

bool Account::set_start(std::string in){
	//CHECKS IF THE STRING EXISTS IN THE SYSTEM OR NOT
	if(SystemData::CityPaths.find(in.data()) != SystemData::CityPaths.end()){
		start = in;
		std::cout << "Found "<<in <<std::endl;
		return true;
	}
	return false;
}

bool Account::set_destination(std::string in){
	//CHECKS IF THE STRING EXISTS IN THE SYSTEM OR NOT
	if(SystemData::CityPaths.find(in.data()) != SystemData::CityPaths.end()){
		end = in;
		std::cout << "Found "<<in <<std::endl;
		return true;
	}
	return false;
}


std::string Account::get_start(){
	return start;
}
std::string Account::get_destination(){
	return end;	
}