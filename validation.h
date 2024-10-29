/* 
  * Functions I reuse to save time in reprogramming basic validation and the program loop.
  * Comments inside function definitions are the parts that get altered when adapted for a new program.
*/
#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cctype>
#ifndef VALIDATION_H
#define VALIDATION_H

/* 
  * Validates yes and no responses to accurately progress program, 
  * loops until valid answer is entered. 
  * @RETURN True for yes, false for no
*/
bool yn_val();

/* 
  * Asks the user if their string entry/ word is spelt correctly. Loops until their confirm correct spelling.
  * Main use for getting the user's name to provide a friendly expirence. 
  * @RETURN The correct spelling of their word 
*/
std::string word_val();

/* 
  * Validates the integer response to menu options provided.
  * @PARAM The max amount of options in the menu 
  * @RETRURN The valid integer that corresponds to an option in the menu. 
*/
int menu_val(int size);

/* 
  * Checks every character to see if there 
  * @PARAM The max amount of options in the menu 
  * @RETRURN The valid integer that corresponds to an option in the menu. 
*/
bool isNum(std::string s);
#endif
