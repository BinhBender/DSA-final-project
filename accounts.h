#include <iostream> 
#include <fstream>
#include "city.h"
#include "system_data.h"
#include "validation.h"
#ifndef ACCOUNTS_H
#define ACCOUNTS_H

/* The class to save the account information for a user. 
 *
*/
 
class Account{
public: 
	Account();  //Constructor 
	Account (std::string user, int level); //Overloaded constructor
	void new_account(); //Create a new account
	void set_username(std::string user); //If they wanna change username
	void set_level(int level); //If they wanna change sensitivity levels
	std::string get_username() const; //getter for the username
	int get_level() const;  //getter for the sensitivity level

	bool set_start(std::string);
	bool set_destination(std::string);

	std::string get_start();
	std::string get_destination();

private: 
	std::string username;
	int sensitivity_level;
	std::string start;
	std::string end;
};

#endif