/*
 * Team Project by Kexin Chen, Binh Nguyen, Kaleb Villalaz
 * Cs 124 Spring 23
 */
#include <iostream>
#include "main_helper.h"

int main()
{
	
	system("clear");
	// The greeting: returns true of false to start program or end it.
	std::vector<Account> accounts;

	// Processes the accounts text file and pushes it into the vector
		
	read_accounts(accounts);
 	// Ask if the user is new or returning
	if (greeting())
	{
		if (new_user_greeting())
		{ 
			Account newAcc;
			newAcc.new_account();
			SystemData::AccountInUse = &newAcc;
			accounts.push_back(newAcc);
		}
	}
	else
	{
		// Now we choose the account we want
		SystemData::AccountInUse = &chooseAccount(accounts);
	}

	// This is the program's main process
	// Loop to enter and/or repeat program.
	main_menu();

	//updates all of the accounts in the accounts.txt to any updated accounts
	update_account(accounts);
	
	outro(); // Ends Program, Provides a farewell message.


	return 0;


}
